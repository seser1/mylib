#pragma once
#include<vector>
#include"myHash.hpp"
#include"myHashSetIterator.hpp"


using namespace std;

namespace mylib {

	//keys put into hash table
	//next* is for iterator::next
	template <typename T>
	struct key {
		vector<T> value;
		key* next;

		key() {
			this->value = NULL;
			this->next = nullptr;
		}
		key(T val) {
			this->value = val;
			this->next = nullptr;
		}
		key(T val, key* ne) {
			this->value = val;
			this->next = ne;
		}
	};

	//my class for using hashset
	template <typename T>
	class HashSet {
		friend HashSetIterator<T>;

	private:
		key table[EL_NUM];
		size_t size = {};
		key* index;

	public:
		typedef HashSetIterator<T> it;

		HashSet();
		~HashSet();
		void add(T t);
		void remove(T t);
		size_t getSize();
		bool contains(T t);
	};

	//constructor
	template <typename T>
	HashSet<T>::HashSet() {
		for (int i=0; i<(sizeof(table)/sizeof(key)); i++)
			table[i]=nullptr;
	}

	//destructor
	template <typename T>
	HashSet<T>::~HashSet() {
		delete []table;
	}

	//add t to hash table
	template <typename T>
	void HashSet<T>::add(T t) {
		//if there is already same value, do not add
		if (this->contains(t))
			return;

		int hash = mylib::myHash(t, EL_NUM);
		//if there is no key corresponding to the hash, add new key
		if (table[hash] == nullptr) {
			table[hash] = new key<T>();
			table[hash].next = index;
			index = &(table[hash]);
		}
		table[hash].value->push_back(t);
		size++;
	}

	//remove t from hash table
	template <typename T>
	void HashSet<T>::remove(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		vector<T>::iterator it = find(table[hash].value.begin(), table[hash].value.end(), t);
		if (it != table[hash].value.end()) {
			table[hash].value.erase(it);
			size--;
		}
	}

	//get numbers of elements the hashset contains
	template <typename T>
	size_t HashSet<T>::getSize() {
		return size;
	}

	//t is contained in hash table or not
	template <typename T>
	bool HashSet<T>::contains(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		auto it = find(table[hash].value->begin(), table[hash].value->end(), t);

		return it != table[hash].value.end();
	}

}
