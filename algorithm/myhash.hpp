#pragma once


namespace mylib {
	template <typename T>
	int myHash(T t, int elemNum) {
		auto a = std::hash(t);
		return a % elemNum;
	}

}