#pragma once

#include <map>
#include"myHash.hpp"

using namespace std;

namespace mylib {

	//my class for using hashmap
	template <typename K, typename V>
	class HashMap {
	private:
		map<K, V> table[EL_NUM];
	public:
		~HashMap();
		void add(K key, V value);
		V get(K key);
		void remove(K key);
		bool contains(K key);
	};

	//destructor
	template <typename K, typename V>
	HashMap<K, V>::~HashMap() {
		delete[]table;
	}

	//add to hash table
	//using map.insert to add
	template <typename K, typename V>
	void HashMap<K, V>::add(K key, V value) {
		int hash = mylib::myHash(key, EL_NUM);
		table[hash].insert(pair<K, V>(key, value));
	}

	//get V from K
	//(if there is no value associated to the key, return NULL)
	template <typename K, typename V>
	V HashMap<K, V>::get(K key) {
		int hash = mylib::myHash(key, EL_NUM);

		auto it = table[hash].find(key) ;
		if (it != table[hash].end())
			return it->second;
		else
			return NULL;
	}

	//remove by K
	template <typename K, typename V>
	void HashMap<K, V>::remove(K key) {
		int hash = mylib::myHash(key, EL_NUM);

		auto it = table[hash].find(key);
		if (it != table[hash].end())
			table[hash].erase(it);
	}

	//k(primary key) is contained in hash table or not
	template <typename K, typename V>
	bool HashMap<K, V>::contains(K k) {
		int hash = mylib::myHash(k, EL_NUM);
		return table[hash].count(k);
	}

}
