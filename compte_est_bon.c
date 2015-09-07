// http://cfun.salemioche.com/lce.htm

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GAP(a,b) (((a)>(b))?((a)-(b)):((b)-(a)))
#define SPRINTOP(a,b,k,res)						\
    ({strcpy(str_tmp,str_result);					\
     sprintf(str_result,"%3d %c %3d = %d\n%s",		\
     (((a)>(b))?(a):(b)),s[k],(((a)>(b))?(b):(a)),res,str_tmp);})

#define NBCH    6

int best_tot = 0, best_gap = 999;
char str_result[255],str_tmp[255];

int plus (int *a, int b) {
    return (*a += b);
}

int moins(int *a, int b) {
    return (*a = GAP(*a,b));
}

int multi(int *a, int b) {
    return (*a *= b );
}

int divis(int *a, int b) {
   if (*a < b) {
       *a^=b; b^=*a; *a^=b;
   }
   if (!(*a%b)) {
       return (*a /= b );
   }
   return 0;
}

#define NBOP    4
int (*f[])(int *,int) = { plus , moins , multi, divis };
char s[] = "+-*/";

int lcb(int *tab, int nb, int tot) {
    int i,j,k,t[NBCH];
    for ( i=0 ; i<nb-1 ; i++ )
        for ( j=i+1 ; j<nb ; j++)
            for ( k=0; k<NBOP; k++) {
                memcpy(t,tab,sizeof(int)*NBCH);
                if ( (*f[k])(&t[i],t[j]) ) {
                    if ( t[i] == tot )
                        return SPRINTOP(tab[i],tab[j],k,t[i]);
                    if ( GAP(t[i],tot) < best_gap) {
                        best_tot = t[i] ;
                        best_gap = GAP(best_tot,tot);
                    }
                    t[j]=t[nb-1];
                    if (lcb(t,nb-1,tot))
                        return SPRINTOP(tab[i],tab[j],k,t[i]);
                }
            }
    return 0;
}

int main(void) {
    int t[NBCH], i, tot;
    *str_result = 0x00;
    for ( i=0; i<NBCH ; scanf("%d",(printf("nombre %d : ",i+1),&t[i++]))) ;
    printf("total : ");
    scanf("%d",&tot);
    if ( ! lcb(t,NBCH,tot) ) lcb(t,NBCH,best_tot);
    else printf("Le compte est bon : \n");
    return ! printf("%s", str_result);
}
