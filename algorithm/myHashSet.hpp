#pragma once
#include<vector>
#include"myHash.hpp"

//numbers of elements of hashtable
#define EL_NUM 1024

using namespace std;

namespace mylib {

	//test method for creating hashset
	template <typename T>
	class HashSet {
	private:
		vector<T> table[EL_NUM];
	public:
		//HashSet();
		~HashSet();
		void add(T t);
		bool contains(T t);
	};

	//constructor
	/*
	template <typename T>
	HashSet<T>::HashSet() {
	}*/

	//destructor
	template <typename T>
	HashSet<T>::~HashSet() {
		delete []table;
	}

	//add
	template <typename T>
	void HashSet<T>::add(T t) {
		int hash = mylib::myHash(t, EL_NUM);

		table[hash].push_back(t);
	}

	//if t is contained in hash table
	template <typename T>
	bool HashSet<T>::contains(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		auto it = find(table[hash].begin(), table[hash].end(), t);

		return it != table[hash].end();
	}

}
