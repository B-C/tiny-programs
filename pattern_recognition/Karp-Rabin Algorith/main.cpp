#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include <gsl/gsl_statistics.h>
#include <gsl/gsl_sort.h>

#include "rabin_karp.h"

using namespace std;

double test(int q);
double stat(vector<int> falseMatches,vector<int> nbOfGoodMatches,int txtSize, int pSize);
double* vectorToArray(vector<int> v);
void printVect(const vector<int>& v);

int main()
{
    srand((unsigned)time(0));

    /*********************************************/

    int q[10]={97,257,509,641,1049,2137,3221,4099,4111,4457};
    vector<int> means;

    for(int i=0 ; i<10 ; i++)
        means.push_back(test(q[i]));

    /*********************************************/

    return 0;
}

double test(int q)
{
    Espr text(5000);
    vector<int> falseMatches;
    vector<int> nbOfGoodMatches;

    for(int i=0 ; i<100 ; i++)
    {
        nbOfGoodMatches.push_back(text.karpRabin(text.getPattern(5),50,q).size());
        falseMatches.push_back(text.getFalseMatch());
    }

    return stat(falseMatches,nbOfGoodMatches,5000,50);
}

double stat(vector<int> falseMatches,vector<int> nbOfGoodMatches,int txtSize, int pSize)
{
    double* fm=vectorToArray(falseMatches);
    double mean=gsl_stats_mean(fm,1,falseMatches.size());
    cout<<"Mean : "<<mean<<endl;
    cout<<"variance : "<<gsl_stats_variance(fm,1,falseMatches.size())<<endl;
    gsl_sort(fm,1,falseMatches.size());
    cout<<"Median : "<<gsl_stats_median_from_sorted_data( fm,1,falseMatches.size())<<endl;

    cout<<"Probability of false matches : "<<mean/(double)(txtSize-pSize)<<endl;

    delete[] fm;

    return mean;
}

double* vectorToArray(vector<int> v)
{
    double*a=new double[v.size()];

    for(unsigned int i=0 ; i<v.size() ; i++)
        a[i]=(double)v[i];

    return a;
}

void printVect(const vector<int>& v)
{
    for(unsigned int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}
