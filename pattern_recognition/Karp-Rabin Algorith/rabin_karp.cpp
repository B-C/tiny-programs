#include <cmath>
#include <cstdlib>

#include "rabin_karp.h"

/// Calculate n^p mod q
int expMod(int n, int p, int q)
{
    int result=1;
    for(int i=0 ; i<p ; i++)
    {
        result=(result*n)%q;
    }

    return result;
}

////////////////////////////////////////
//  Constructors
////////////////////////////////////////

Espr::Espr(int size)
    :numFalseMatch(-1)
{
    randomTxt(size);
}

Espr::Espr(int* text, int textSize)
    :numFalseMatch(-1)
{
    for(int i=0 ; i<textSize ; i++)
        T.push_back(text[i]);
}

/////////////////////////////////////////

vector<int> Espr::karpRabin( const vector<int>& P,int d, int q)
{
    vector<int> positions;

    // Initialisation

    int n=T.size(), m=P.size();
    int a=expMod(d,m-1,q);//modular exponentiation in order to not exceed 2^w
    int p=0, t=0;

    numFalseMatch=0;

    for(int i=0 ; i<m ; i++)
    {
        p=((d*p)%q+P[i])%q; // %q is here twice in order to not exceed 2^w
        t=((d*t)%q+T[i])%q;
    }

    //Algoriths

    for(int s=0 ; s<=n-m ; s++)
    {
        int temp;

        if(t==(p%q))
        {
            if(equality(s,P))
                positions.push_back(s);
            else
                numFalseMatch++;
        }
        if(s-1<n-m)
        {
            temp=((t-T[s]*a)%q);//  ! can be <0
            if(temp<0)
                temp+=q;
            t=(d*temp +T[s+m])%q;
        }
    }
    return positions;
}


//Check whether T[pos..pos+m]==P
bool Espr::equality(int pos, const vector<int>& P)
{
    bool test=true;

    for(unsigned int i=0 ; i<P.size()&&test ; i++)
        test=(T[pos+i]==P[i]);

    return test;
}


//Generate a random text
void Espr::randomTxt(int size)
{
    for(int i=0 ; i<size ; i++)
        T.push_back(rand()%10);
}

//Extract a random string from the text T
vector<int> Espr::getPattern(int size)
{
    int pos=rand()%(T.size()-size);
    vector<int> pattern;

    for(int i=0 ; i<size ; i++)
        pattern.push_back(T[pos+i]);

    return pattern;
}
