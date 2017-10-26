#pragma once


using namespace std;

namespace mylib {

	template <typename T>
	struct node {
	public:
		T value;
		T* next;

		node(T val) {
			this->value = val;
			this->next = null;
		}
	};

	//my forward linked list class
	//(used in myHashSet to get order to use myHashSetIterator)
	template <typename T>
	class myForwardList {

	private:

	public:


	};


}
