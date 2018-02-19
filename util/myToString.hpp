#pragma once
#include<memory>
#include "myUtil.hpp"

namespace mylib {

	//my toString
	// -----constructing-----

	//To_string of array
	template <typename T>
	static string* myUtil<T>::toString(T *data) {
		int c = sizeof(*data) / sizeof(T);

		std::unique_ptr<string[]> ptr(new string[c]);

		for (int i = 0; i < c; i++)
			ptr[i] = data[i].toString();

		return prt;
	}


}
