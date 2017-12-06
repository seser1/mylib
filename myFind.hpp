#pragma once


namespace mylib {

	//my find
	//used with container
	template<typename T>
	bool myFind(const T& c, const typename T::value_type& v) {
		return c.end() !=
			std::find(c.begin(), c.end(), v);
	}

}