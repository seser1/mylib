#pragma once
#include<vector>

//numbers of elements of hashtable
#define EL_NUM 1024


using namespace std;

namespace mylib {

	//test method for creating hashset
	template <typename T>
	class HashSet {
	private:
		vector<T> table[];
	public:
		HashSet();
		void add(T value);
		int search(T value);
	};

	//constructor
	template <typename T>
	HashSet::HashSet() {
		table = new T[EL_NUM];
	}

	//destructor
	template <typename T>
	HashSet::~HashSet() {
		delete[]table;
	}


	//add
	template <typename T>
	void HashSet::add(T t) {
		auto hash = mylib::myHash(t);
		if (table[hash] != NULL)
			table[hash].push_back(t);
		else
			table[hash] = new vector<T>(t);
	}

	//search
	template <typename T>
	int HashSet::search(T t) {

	//	auto it = table[t].find(key);
	//	return it->second;
	}

}
