#pragma once


namespace mylib {

	//my toString
	// -----constructing-----
	template<typename T>
	class myUtil {

	public:
		template<typename T>
		static string toString(T data);
	};

}