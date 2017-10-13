#pragma once


namespace mylib {

	//my hash method
	//would be optimized in future
	template <typename T>
	int myHash(T t, int elemNum) {
		auto a = std::hash<T>()(t);
		return a % elemNum;
	}

}