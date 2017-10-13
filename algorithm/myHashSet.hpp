#pragma once
#include<vector>
#include"myHash.hpp"

using namespace std;

namespace mylib {

	//my class for using hashset
	template <typename T>
	class HashSet {
	private:
		vector<T> table[EL_NUM];
	public:
		//HashSet();
		~HashSet();
		void add(T t);
		void remove(T t);
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

	//add t to hash table
	template <typename T>
	void HashSet<T>::add(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		table[hash].push_back(t);
	}

	//remove t from hash table
	template <typename T>
	void HashSet<T>::remove(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		vector<T>::iterator it = find(table[hash].begin(), table[hash].end(), t);
		if (it != table[hash].end())
			table[hash].erase(it);
	}

	//t is contained in hash table or not
	template <typename T>
	bool HashSet<T>::contains(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		auto it = find(table[hash].begin(), table[hash].end(), t);

		return it != table[hash].end();
	}

}
