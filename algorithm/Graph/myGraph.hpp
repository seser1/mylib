#pragma once
#include<vector>

using namespace std;

namespace mylib {

	template <typename R>
	struct Node {
	};

	template <typename R>
	class Graph {
	private:
		vector<Node<R>> node;
	};

	//my class which handles undirected graph
	template <typename R>
	class Undir : public Graph {
	private:
	public:
	};



}
