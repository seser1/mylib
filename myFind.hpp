#pragma once


namespace mylib {

	//my find
	//used with container
	template<typename Container>
	bool myFind(const Container& c, const typename Container::value_type& v) {
		return c.end() !=
			std::find(c.begin(), c.end(), v);
	}

}