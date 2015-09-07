#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

string shuffle(string str);
string process(string str);

string process(string str)
{
	string result;
	static const string ponctuation("`~!@#$%^&*()_-+={[}]|\\:;|\"'<,>.?/");
	size_t found;

	found=str.find_first_of(ponctuation);
	if(found == string::npos)
		result = shuffle(str);
	else
	{
		if(found>0)
			result+=shuffle(str.substr(0, found));

		result+=str[found];

		if(found+1<str.size())
			result+=process(str.substr(found+1));
	}

	return result;
}

string shuffle(string str)
{
	string result;

	if(str.size()<=2)
		result = str;
	else
	{
		result+=str[0];
		char end = str[str.size()-1];
		str=str.substr(1, str.size()-2);

		for(int size=str.size() ; size>0 ; size--)
		{
			int i = (int)((double)rand() / ((double)RAND_MAX + 1) * size);
			result+=str[i];
			str[i]=str[size-1];
			str=str.substr(0,size-1);
		}
		result+=end;
	}

	return result;
}

int main(void)
{
	srand ( time(NULL) );

	string str;

	while(true)
	{
		cin >> str;
		if(cin.eof())
			break;
		cout << process(str) << " ";
	}
	cout << endl;
	return 0;
}

