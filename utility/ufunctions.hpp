#ifndef __UFUNCTIONS_HPP__
#define __UFUNCTIONS_HPP__
/**
 * @brief header with utilities functions for Ty generics types
 *
 */

namespace utilities {
    //apply function to every value between start and end iterator
	template<typename Iterator, typename Function>
	const Function& __cdecl for_each(Iterator start, Iterator end, const Function& _function) {
		while (start != end) {
			_function(*start);
			++start;
		}

		return _function;
	}

	//swap values of two variables between them
	template<typename Ty>
	void __cdecl swap(Ty& first, Ty& second) {
		Ty c = first;
		first = second;
		second = c;
	}

	//return max between two variables
	template<typename Ty>
	const Ty& __cdecl max(const Ty& first, const Ty& second) { return first >= second ? first : second; }

	//return max between two variables swich a predicate (bool_function)
	template<typename Ty, typename BoolFunction>
	const Ty& __cdecl max(const Ty& first, const Ty& second, BoolFunction bool_function) { return bool_function(first, second) ? first : second; }

	//return min between two variables
	template<typename Ty>
	const Ty& __cdecl min(const Ty& a, const Ty& b) { return a >= b ? b : a; }

	//return min between two variables swich a predicate (bool_function)
	template<typename Ty, typename BoolFunction>
	const Ty& __cdecl min(const Ty& first, const Ty& second, BoolFunction bool_function) { return bool_function(first, second) ? first : second; }

	//return true, only use 1 template
	template<class Ty>
	const bool __cdecl same_type(const Ty& first, const Ty& second) { return true; }

	//return false, use 2 template parameters
	template<class Ty1, class Ty2>
	const bool __cdecl same_type(const Ty1& first, const Ty2& second) { return false; }

}
#endif //__UFUNCTIONS_HPP__