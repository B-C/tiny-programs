#ifndef ZALG_H
#define ZALG_H

#include <string>
#include <vector>
#include <iostream>
#include "pos.h"

using namespace std;

/**
  * Implementation of the Z algorithm
  *
  */

class Zalg
{
private:
    string T; /// the text
    const static char DELIM='$'; /// the delimiter between P and T
    int cases[4]; /// Count the number of occurrences of each case
    int lastNumberOfMatches; /// The number of Pattern P found in T

public:
    /// Initialise T with tect
    Zalg(const string& text):T(text),lastNumberOfMatches(-1){}

    /// The algo. with no wildcard
    vector<int> patternRecognition(const string& P);
    /// The algo with wildcard
    vector< Pos* > patternRecognition(const string& P,char wildCard);

    /// Print the stats of the algorithm
    /// number of occurrences of P in T, probability of each case
    void showStats();

private:
    /// THe computation of the Z boxes
    vector<int> zAlg(const string& S);
    /// Return the length of the biggest prefix of T[start..|T|] starting at pos
    inline unsigned int biggestPrefix(const string& S, unsigned int pos, unsigned int start=0);
};

#endif
