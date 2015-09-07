#include <iostream>
#include <string>
using namespace std;

template <class T>
struct LinkedList {
	const T item;
	const string key;
	LinkedList<T> *next;

	LinkedList(const string &key, const T &item):
		item(item), key(key), next(NULL){}

	LinkedList(LinkedList<T> *next, const string &key, const T &item): 
		item(item), key(key), next(next){}

	bool get(const string &key, T &item) const {
		if(this->key.compare(key) == 0) {
			item = this->item;
			return true;
		}
		else if(this->next == NULL)
			return false;
		else
			return next->get(key, item);
	}
};

template <class T>
class HashTable {

private:
	static const int TABLE_SIZE = 29;//Prime
	LinkedList<T> * hashtable[TABLE_SIZE];

public:
	bool get(const string &key, T &item) const {
		LinkedList<T> *list = hashtable[hashing(key)];
		if(list == NULL)
			return false;
		else
			return list->get(key, item);
	}

	void add(const string &key, const T &item) {
		//test if already presentXXX
		unsigned int hkey = hashing(key);
		LinkedList<T> *list = hashtable[hkey];
		 hashtable[hkey] = new LinkedList<T>(list, key, item);
		
	}

	HashTable() {
		for(int i = 0 ; i< TABLE_SIZE ; i++)
			hashtable[i] = NULL;

	}
	~HashTable() {
		for(int i = 0 ; i< TABLE_SIZE ; i++) {
			LinkedList<T> *list = hashtable[i];
			while(list) {
				LinkedList<T> *next = list->next;
				delete list;
				list = next;
			}
		}
			
	}

private:
	static unsigned int hashing(const string &key) {
		const char * str = key.c_str();
		unsigned int hkey = 0;
		cout<< str << endl;

		while(*str)
			hkey = aux_hasing(hkey, *str++);
		hkey%=TABLE_SIZE;
		cout << endl << "HASHING " <<key << " " <<hkey << endl;
		return hkey;
	}

	static int aux_hasing(unsigned int h, char k) {
		int hightorder = h & 0xf8000000;
		h = h << 5;
		h = h^(hightorder >> 27);
		h = h ^ k;
			
		return h;
	}


};




int main() {
	HashTable<string> table;

	table.add(string("bertrand"), string("chazot"));

	string val;
	if(table.get(string("bertrand"), val))
		cout << val;
	else
		cout << "not found";

	cout << "\ndone\n";
	return 0;
}
