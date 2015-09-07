#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "zalg.h"

using namespace std;

void printVect(const vector<int>& v);
string readFile(string fileName);

void test(int num, char wildCard=-1);

int main()
{
        cout<<"TEST 1"<<endl;
        test(1);
        cout<<endl;

        cout<<"TEST 3"<<endl;
        test(3);
        cout<<endl;

        cout<<"TEST 4"<<endl;
        test(4);
        cout<<endl;

        cout<<"TEST 2"<<endl;
        test(2,'X');
        cout<<endl;

        cout<<"TEST 5"<<endl;
        test(5,'0');
        cout<<endl;


    return 0;
}

void test(int num, char wildCard)
{
    stringstream nameT, nameP;
    nameT<<"../data/Text"<<num<<".txt";
    string text=readFile(nameT.str());
    nameP<<"../data/Pattern"<<num<<".txt";
    string pattern=readFile(nameP.str());

    Zalg zalg(text);

    if(wildCard==-1)
        zalg.patternRecognition(pattern);
    else
        zalg.patternRecognition(pattern,wildCard);

    zalg.showStats();
}

void printVect(const vector<int>& v)
{
    for(unsigned int i=0 ; i<v.size() ; i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

string readFile(string fileName)
{
    string str;
    ifstream file( fileName.c_str(), ios::in);
    if(file.is_open())
    {
        file>>str;
        file.close();
    }
    else
        cerr<<"ERROR"<<endl;

    return str;
}
