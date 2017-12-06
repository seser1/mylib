#pragma once
#include "myUtil.hpp"

#define ARR_LEN(ARR) (sizeof(ARR) / sizeof((ARR)[0]))

namespace mylib {

	/*
	template<typename T>
	T* copyArr(T* arr) {
		T _arr[ARR_LEN(arr)] = {};
		for (int i = 0; i < ARR_LEN(arr); i++)_arr[i] = arr[i];
		return _arr;
	}*/

}