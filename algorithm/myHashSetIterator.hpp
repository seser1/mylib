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
//		HashSetIterator& operator++();
//		HashSetIterator operator++(T);

		HashSetIterator next();

		T& operator*();
	};

	template <typename T>
	HashSetIterator::HashSetIterator(const HashSetIterator& iterator)
	{
		this.index = iterator.index;
		this.hashSet = iterator.hashSet;
	}

	template <typename T>
	T& HashSetIterator::operator*()
	{
		//not considering about table[index] contains more than one vectors
		return this.hashSet->table[index];
	}

	template <typename T>
	HashSetIterator HashSetIterator::next()
	{
	}

}