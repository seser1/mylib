#include <iostream>
#include <map>

#define NUM 12345

using namespace std;

namespace mylib {


	//test for hash method of integer
	class intHash {
	private:
		map<int, int> table[NUM] = {};

	public:
		void add(int key, int value);
		int search(int key);
	};

	void intHash::add(int key, int value) {
		auto t = key % NUM;
		table[t].insert(pair<int, int>(key, value));
	}
	int intHash::search(int key) {
		auto t = key % NUM;

		auto it = table[t].find(key) ;
		return it -> second;
	}









}
