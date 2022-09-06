#ifndef __NUMBERS_HPP__
#define __NUMBERS_HPP__
#include "typesdef.hpp"
/*header with Number class for utilitie function with numbers*/
namespace utilities {
    using namespace utilities;
    //class with utilities function for number traits
    class Number;
    //Number
    using nbr = Number;

    //class with utilities function for number traits
    class Number
    {
    private:
        template<typename Ty>
        static const ll __cdecl _digits(const Ty& integer, bool& negative) {
			ll digits = 0;
			Ty number = integer;
			if (integer < 0)
				number *= -1, negative = true;

			while (number != 0) { number /= 10; ++digits; }

			return digits;
		}

        template<typename Ty>
        static cchar_p __cdecl _to_string(const Ty& integer) {
			bool negative = false;
			const ll digits = nbr::_digits(integer, negative);
			short digit = 0;

			Ty number = integer;
			if (negative)
				number *= -1;
			char* chars = new char[digits + 1 + negative];

			for (ull i = 0; i < digits; ++i) {
				digit = number % 10;
				number /= 10;
				chars[digits - i - !negative] = '0' + digit;
			}

			if (negative)
				chars[0] = '-';

			chars[digits + negative] = '\0';

			return chars;
		}

    public:
        //class with utilities function for number traits
        Number() {}

        static cchar_p __cdecl to_string(const int& number) { return nbr::_to_string<int>(number); }
        static cchar_p __cdecl to_string(const short& number) { return nbr::_to_string<short>(number); }
        static cchar_p __cdecl to_string(cll& number) { return nbr::_to_string<ll>(number); }
        static cchar_p __cdecl to_string(const ull& number) { return nbr::_to_string<ull>(number); }
        static cchar_p __cdecl to_string(const ul& number) { return nbr::_to_string<ul>(number); }
        static cchar_p __cdecl to_string(const ushort& number) { return nbr::_to_string<ushort>(number); }
        static cchar_p __cdecl to_string(const uint& number) { return nbr::_to_string<uint>(number); }

        /*
        static cchar_p __cdecl to_string(cdouble& number) {}
        static cchar_p __cdecl to_string(cfloat& number) {}
        */

    };

}

#endif //__NUMBERS_HPP__