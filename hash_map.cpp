#include <stdio.h>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using std::string;
using std::list;
using std::vector;
using std::cout;

template <typename K, typename V>
struct Pair	{
	K key;
	V value;
	Pair(K _key, V _value) : key(_key), value(_value)	{}
	Pair(K _key) : key(_key), value(V())	{}			// Dummy pair for search/sort
	bool operator<(const Pair &o) const {
		return key < o.key;
	}
	bool operator==(const Pair &o) const	{
		return key == o.key;
	}
};

template <typename K, typename V>
class HashMap	{
public:
	typedef unsigned int (*HashFunc)(const K &, int);
	
private:
	typedef list<Pair<K,V> > mapList ;
	vector<mapList> array;
	static const int INIT_SIZE = 2;
	HashFunc hashFunc;

	unsigned int getHashIndex(K key) const	{
		return hashFunc(key, array.size()) % array.size();
	}
		
public:
	HashMap(HashFunc _hashFunc) : hashFunc(_hashFunc)	{
		// assert(hashFunc);
		array.resize(INIT_SIZE);
	}
	
	void add(K key, V value)	{
		if(contains(key))
			remove(key);
		unsigned int idx = getHashIndex(key);
		Pair<K,V> pair(key, value);
		array[idx].push_back(pair);
	}
	
	bool contains(K key) const	{
		unsigned int idx = getHashIndex(key);
		Pair<K,V> pair(key);
		return (std::find(array[idx].begin(), array[idx].end(), pair) != array[idx].end());
	}
	
	void remove(K key)	{
		unsigned int idx = getHashIndex(key);
		Pair<K,V> pair(key);
		typename mapList::iterator it = std::find(array[idx].begin(), array[idx].end(), pair);
		if(it == array[idx].end())
			return;
		array[idx].erase(it);
	}
	
	void print() const	{
		for(unsigned int i=0; i<array.size(); ++i)	{
			typename mapList::const_iterator it = array[i].begin();
			while(it != array[i].end())	{
				cout << (*it).key << " -> " << (*it).value << "\n";
				++it;
			}
		}
	}
};

unsigned int intFunc(const string &str, int hashArrayLen)	{
	if(str.length() == 0)
		return hashArrayLen-2;			// dumb
	return str[0];		// dumb
}

int main()	{
	HashMap<string, int> myMap(intFunc);
	myMap.add("butt",3);
	myMap.add("cool",1);
	myMap.add("hi",4);
	myMap.add("lo",3);
	myMap.add("hi",2);
//	myMap.remove("lo");
	myMap.print();
}

