#pragma once
#include <iterator>

#include"myHashSet.hpp"

class HashSet;

namespace mylib {


	//Iterator of myHashSet
	template <typename T>
	class HashSetIterator : public std::iterator<std::forward_iterator_tag, T>
	{
		friend HashSet;

	private:
		size_t index;
		HashSet* hashSet;		
		HashSetIterator();

	public:
		HashSetIterator(const HashSetIterator& iterator);

	public:
		T& operator*();
		HashSetIterator<T>& next();
		//		HashSetIterator& operator++();
		//		HashSetIterator operator++(T);
	};

	template <typename T>
	HashSetIterator<T>::HashSetIterator(const HashSetIterator& iterator)
	{
		this.index = iterator.index;
		this.hashSet = iterator.hashSet;
	}

	template <typename T>
	T& HashSetIterator<T>::operator*()
	{
		//not considering about table[index] contains more than one vectors
		return this.hashSet->table[index];
	}

	template <typename T>
	HashSetIterator<T>& HashSetIterator<T>::next()
	{
		return null;
	}

}