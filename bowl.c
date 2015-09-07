/******************************************************************************
 *
 * BitTorrent challenge
 * --------------------
 *
 * Bertrand Chazot, 01-13-12
 *
 ******************************************************************************/

/*You have 40 bowls, all placed in a line at exact intervals of 1 meter.
You also have 9 oranges. You wish to place all the oranges in the
bowls, no more than one orange in each bowl, so that there are no
three oranges A, B, and C such that the distance between A and B is
equal to the distance between B and C. How many ways can you arrange
the oranges in the bowls? */


#include <stdio.h>
#include <stdlib.h>

#define NUM_BOWL 40
#define NUM_ORANGE 9

static int oranges[NUM_ORANGE];
// oranges[i] = position of orange i

int addOrange(int num); // Num [0..NUM_ORANGE[
int newOrange(int num, int pos);

int main() {
	int arrangFound = 0;

	// iterate on the position of the first orange
	for(int i = 0 ; i <= NUM_BOWL-NUM_ORANGE ; i++) {
		oranges[0] = i;
		arrangFound += addOrange(1);
	}

	printf("Arrangement%s found: %d\n", arrangFound<2?"":"s", arrangFound);
	return 0;
}

/* return number of possible arrangements
   with the oranges [0..num[ already placed */
int addOrange(int num) {
	if(num == NUM_ORANGE) // no more oranges
		return 1;

	int arrangFound = 0;

	// Try all bowls on the right of the last one used,
	// while leaving enought space on the right for the remaining oranges
	for(int i = oranges[num-1] +1 ; i <= (NUM_BOWL - (NUM_ORANGE-num)) ; i++)
		if(newOrange(num, i))
			arrangFound += addOrange(num+1);

	return arrangFound;
}

/* place the num-th orange at position pos and return 1,
   if not possible return 0 */
int newOrange(int num, int pos) {
	static int distances[NUM_ORANGE][NUM_ORANGE];
	// distances[i][j], i<=j = distance between oranges i and j

	int delta = pos - oranges[num-1];
	for(int i = 0 ; i < num ; i++) {
		distances[i][num] = distances[i][num-1] + delta;
		for(int j = 0; j < i ; j++)
			if(distances[i][num] == distances[j][i])
				return 0;
	}

	oranges[num] = pos;
	return 1;
}
