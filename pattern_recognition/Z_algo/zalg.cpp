#include "zalg.h"

vector<int> Zalg::zAlg(const string& S)
{
    // Inititalisation
    cases[0]=cases[1]=cases[2]=cases[3]=0;
    vector<int> z(S.size(),-1);
    unsigned int r, l;

    int k2,b;

    // Computing z1
    z[1]=biggestPrefix(S,1);
    l=1;
    r=z[1];

    // The other z
    for(unsigned int k=2 ; k<S.size() ; k++)
    {
        // Case 1 :
        if(k>r)
        {
            cases[0]++;

            z[k]=biggestPrefix(S,k);
            if(z[k]!=0)
            {
                l=k;
                r=l+z[k]-1;
            }
        }
        // case 2 :
        else
        {
            k2=k-l;
            b=r-k+1;

            //case 2a :
            if(z[k2]<b)
            {
                cases[1]++;

                z[k]=z[k2];
            }
            //case 2b1 :
            else if(z[k2]>b)
            {
                cases[2]++;

                z[k]=b;
            }
            //case 2b2 :
            else
            {
                cases[3]++;

                z[k]=b+biggestPrefix(S,k+b,b);
                l=k;
                r=l+z[k]-1;
            }
        }
    }
    return z;
}

/////////////////////////////////////////////////////////////////////////:

vector<int> Zalg::patternRecognition(const string& P)
{
    vector<int> pos,z=zAlg(P+DELIM+T);
    int m=P.size();

    for(unsigned int i=0 ; i<(m+1+T.size()) ; i++)
        if(z[i]==m)
            pos.push_back(i-m-1);

    lastNumberOfMatches=pos.size();

    return pos;
}

vector< Pos* > Zalg::patternRecognition(const string& P,char wildCard)
{
    vector<string> patterns;
    string temp=P;
    int pos=0;
    int _cases[4]={0,0,0,0,};

    // Extraction of the subpatterns
    while(pos!=-1)
    {
        pos=temp.find_first_of(wildCard);

        if(pos!=-1)
        {
            patterns.push_back(temp.substr(0,pos));
            temp=temp.substr(pos+1);
        }
        else
            patterns.push_back(temp);
    }

    // Search of each subpatern in T
    vector< vector<int> > vectPos;

    for(unsigned int i=0 ; i <patterns.size() ; i++)
    {
        vectPos.push_back(patternRecognition(patterns[i]));
        for(int i=0 ; i<4 ; i++)
            _cases[i]+=cases[i];
    }

    for(int i=0 ; i<4 ; i++)
        cases[i]=_cases[i];

    ////////// Construction of the tree  //////////////
    vector< Pos* > finalPos,tempPos;

    for(unsigned int i =0 ; i< vectPos[vectPos.size()-1].size() ; i++)
        finalPos.push_back(new Pos( vectPos[vectPos.size()-1][i],patterns[patterns.size()-1].size()));

    for(int i= vectPos.size()-2 ; i>=0 ; i-- )
    {
        tempPos=finalPos;
        finalPos.clear();

        for(unsigned int j =0 ; j< vectPos[i].size() ; j++)
        {
            Pos* current=new Pos(vectPos[i][j],patterns[i].size());

            for(unsigned int k=0 ; k<tempPos.size() ; k++)
                current->addNext(tempPos[k]);

            if(current->nexts.size()!=0)
                //if it is possible to find all the remaining subpaterns in T after current,
                //current is kept
                finalPos.push_back(current);
        }
    }

    lastNumberOfMatches=0;

    for(unsigned int i=0 ; i<finalPos.size() ; i++)
        lastNumberOfMatches+=finalPos[i]->nb();

    return finalPos;
}

////////////////////////////////////////////////////////////////////

void Zalg::showStats()
{
    double sum=cases[0]+cases[1]+cases[2]+cases[3];

    if(lastNumberOfMatches==0)
        cout<<"P is not in T"<<endl;
    else
        cout<<"There is "<<lastNumberOfMatches<<" occurrences of P in T"<<endl;

    cout<<"Percentage of case 1 : "<<cases[0]/sum<<endl;
    cout<<"Percentage of case 2a : "<<cases[1]/sum<<endl;
    cout<<"Percentage of case 2b1 : "<<cases[2]/sum<<endl;
    cout<<"Percentage of case 2b2 : "<<cases[3]/sum<<endl;

}

inline unsigned int Zalg::biggestPrefix(const string& S, unsigned int pos, unsigned int start)
{
    unsigned int i=0;

    while(S[i+start]==S[i+pos] && (i+pos) <S.size())
        i++;

    return i;
}
