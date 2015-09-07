#ifndef RABIN_KARP_H
#define RABIN_KARP_H

#include <vector>

using namespace std;

/*!
 *  Implementation of the Karp-Rabin Algorithms
 *
 ***/

class Espr
{
private:
    vector<int> T;/// the text T
    int numFalseMatch;/// the number of  false match during the last execution

public:
    /// Initialize T with a random text
    Espr(int size);
    /// Initialise T with text
    Espr(const vector<int>& text):T(text),numFalseMatch(-1){}
    /// idem
    Espr(int* text, int textSize);

    /// getters
    int getFalseMatch(){return numFalseMatch;}
    const vector<int>& getText(){return T;}

    /// Ghe proper algorithms
    vector<int> karpRabin( const vector<int>& P,int d, int q);
    /// Extract a random pattern from T
    vector<int> getPattern(int size);

private:
    /// Check whether T[pos..pos+m]==P
    bool equality(int pos, const vector<int>& P);
    /// Generate a random text
    void randomTxt(int size);
};


#endif
