#pragma once
#include<vector>
#include<memory>
#include"myHash.hpp"
#include"myHashSetIterator.hpp"


using namespace std;

namespace mylib {

	//---------------------------
	//
	//****My Hash Set****
	//
	//Search: O(1)
	//Insert: O(1)
	//Delete: O(1)
	//Refer: O(n) (using iterator)
	//
	//Random access: not allowed
	//
	//---------------------------


	//Keys put into hash table
	//next* is for iterator::next
	template <typename T>
	struct key {
		vector<T> value;
		key* next;

		key() {
			this->next = nullptr;
		}
		//At this time, there is no point struct:key is created with some arguments
		//So below methods wont be used
		/*
		key(T val) {
			this->value.push_back(val);
			this->next = nullptr;
		}
		key(T val, key* ne) {
			this->value.push_back(val);
			this->next = ne;
		}*/
	};

	//My class for using hashset
	template <typename T>
	class HashSet {
		friend HashSetIterator<T>;

	private:
		key<T> table[EL_NUM];
		size_t size = {};
		key<T>* index;

	public:
		typedef HashSetIterator<T> it;

		HashSet();
		~HashSet();
		void add(T t);
		void remove(T t);
		size_t getSize();
		bool contains(T t);

		//For implementing iterator
		const key<T>& operator*();
		key<T>& operator++();
		bool operator!=(const key<T>& v);
	};

	//constructor
	template <typename T>
	HashSet<T>::HashSet() {
//		for (int i=0; i<(sizeof(table)/sizeof(key<T>)); i++)
//			table[i]=nullptr;
	}

	//destructor
	template <typename T>
	HashSet<T>::~HashSet() {
	}

	//add t to hash table
	template <typename T>
	void HashSet<T>::add(T t) {
		//if there is already same value, do not add
		if (this->contains(t))
			return;

		int hash = mylib::myHash(t, EL_NUM);
		vector<T>* val = &table[hash].value;

		//if there is no key corresponding to the hash, add new key
		if (val->empty()) {
			table[hash].next = index;
			index = &(table[hash]);
		}
		val->push_back(t);
		size++;
	}

	//remove t from hash table
	template <typename T>
	void HashSet<T>::remove(T t) {
		int hash = mylib::myHash(t, EL_NUM);
		vector<T>* val = &table[hash].value;

		if (it != val->end()) {
			val->erase(it);
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
		vector<T>* val = &table[hash].value;

		auto it = find(val->begin(), val->end(), t);

		return it != val->end();
	}

}
