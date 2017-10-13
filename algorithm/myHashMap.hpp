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
	//(not implemented the function there is no value connected the key
	template <typename K, typename V>
	V HashMap<K, V>::get(K key) {
		int hash = mylib::myHash(key, EL_NUM);

		auto it = table[hash].find(key) ;
		return it->second;
	}

}
