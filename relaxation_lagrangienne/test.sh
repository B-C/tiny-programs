#! /bin/bash
set -u
set -e

PROG="./tsp"
GRAPH="$1"
GRAPH_NAME="${GRAPH##*/}"

ALPHAS=(0.1 0.2 0.4 0.7 0.8 0.9 1.0 1.2 1.3 1.4 1.5 1.6 1.7 2 2.5 3)
NB_ITERATIONS=(5 8 9 10 11 12 15 20 30 50 100)
BORNE_INIT=5000

BEST_ALPHA=${ALPHAS[0]}
BEST_NBIT=10

BEST_TIME=9999999999.0

function compute() {
	alpha="$1"
	nb_it="$2"

	result=`$PROG $GRAPH 1 $alpha $nb_it $BORNE_INIT | tail -n 2`

	nb_node=`echo "$result" | awk -F "[^0-9]*" 'NR == 1 {print $2}'`
	time=`echo "$result" | awk -F "[^0-9.]*" 'NR == 2 {print $2}'`

	echo $alpha $nb_it $nb_node $time >> $PLOT_FILE

	if [ $(echo "$time < $BEST_TIME"|bc) -eq 1 ]; then
		BEST_TIME=$time
		BEST_ALPHA=$alpha
		BEST_NBIT=$nb_it
	fi

	echo "$result"
	echo
}

echo "Tests sur le graph $GRAPH_NAME ; Borne initial: $BORNE_INIT"
echo "------------------------------------------------------------"
echo

echo "*Recherche du meilleur alpha avec $BEST_NBIT itérations"
echo " Alphas testés: ${ALPHAS[@]}"
echo

PLOT_FILE="./${GRAPH_NAME}_it=$BEST_NBIT.data"
rm -rf $PLOT_FILE
for alpha in "${ALPHAS[@]}"; do
	echo "Alpha=$alpha:"
	compute $alpha $BEST_NBIT
done

echo "Résultats: meilleur temps ($BEST_TIME) pour alpha=$BEST_ALPHA"
echo "------------------------------------------------------------"
echo
gnuplot -p -e "set xlabel 'alpha ($BEST_NBIT itérations)'; plot '$PLOT_FILE' using 1:3 title 'nb_nodes' w lines"
gnuplot -p -e "set xlabel 'alpha ($BEST_NBIT itérations)'; plot '$PLOT_FILE' using 1:4 title 'temps' w lines"

echo "*Recherche du meilleur nombre d'itérations avec alpha=$BEST_ALPHA"
echo " Valeurs testées: ${NB_ITERATIONS[@]}"
echo

PLOT_FILE="./${GRAPH_NAME}_alpha=$BEST_ALPHA.data"
rm -rf $PLOT_FILE
for nb in "${NB_ITERATIONS[@]}"; do
	echo "$nb itératons"
	compute $BEST_ALPHA $nb
done

echo "Résultats: meilleur temps ($BEST_TIME) pour alpha=$BEST_ALPHA et $BEST_NBIT itérations"

gnuplot -p -e "set xlabel 'Nb itérations (alpha=$BEST_ALPHA)'; plot '$PLOT_FILE' using 2:3 title 'nb_nodes' w lines"
gnuplot -p -e "set xlabel 'Nb itérations (alpha=$BEST_ALPHA)'; plot '$PLOT_FILE' using 2:4 title 'temps' w lines"