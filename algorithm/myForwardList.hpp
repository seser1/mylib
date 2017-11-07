#pragma once


using namespace std;

namespace mylib {

	//!!!!!!
	//myForwordList implementation
	//Not completed yet
	//!!!!!!

	template <typename T>
	struct Node {
	public:
		T value;
		T* next;

		Node(T val) {
			this->value = val;
			this->next = null;
		}
		Node(T val, T* ne) {
			this->value = val;
			this->next = ne;
		}
	};

	//my forward linked list class
	//(used in myHashSet to get order to use myHashSetIterator)
	template <typename T>
	class myForwardList {

	private:
		Node* node;

	public:
		myForwardList();
		myForwardList(T t);
		void add(T t);
	};


	//default constructor
	template <typename T>
	myForwardList<T>::myForwardList() {
	}

	//constructor with t
	template <typename T>
	myForwardList<T>::myForwardList(T t) {
		node = new Node(t);
	}

	//add t to List
	template <typename T>
	void myForwardList<T>::add(T t) {
			node* tmp = new Node(t);
			tmp->next = node;
			node = tmp;
	}


}
