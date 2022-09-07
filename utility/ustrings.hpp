#ifndef __USTRINGS_HPP__
#define __USTRINGS_HPP__
#include <vector>
#include <string>
#include "typesdef.hpp"
#include "ufunctions.hpp"

/**
 * @brief header with ustring class for string utilities functions
 *
 */
namespace utilities {

	class Ustring;
	using ustr = Ustring;
	using utilities::for_each;

	class Ustring {

	private:
		static std::vector<std::string> __cdecl _split(const std::string& text, const std::string& _sep) {
			std::string line(text);
			std::string _split = "";
			std::vector<std::string> splited = std::vector<std::string>();
			ll begin = 0;
			ll end = 0;
			while (true)
			{
				end = line.find(_sep);
				if (end == -1) {
					splited.push_back(line.substr(begin, line.size()));
					return splited;
				}
				splited.push_back(line.substr(begin, end));
				line = line.substr(end + 1, line.size() - end);
			}

			/*
			* Second Versión, for _sep equal to one char
			long long index = 0;
			char _char = ' ';
			for (size_t i = 0; i < line.size(); ++i) {
				_char = line[i];
				if (_char != _sep)
					_split += _char;
				else {
					splited.push_back(_split);
					_split = "";
				}
			}
			if (_char != _sep)
				splited.push_back(_split);
			*/

			return splited;
		}

		static cll __cdecl _pchar_size(const char*& start) {
			if (start == nullptr)
				return 0;

			const char* end = start;
			for (; *end != '\0'; ++end);

			return end - start;
		}

		static cchar& __cdecl _to_lower(cchar& character) { return character >= 'A' && character <= 'Z' ? character - 'A' + 'a' : character; }

		static cchar& __cdecl _to_upper(cchar& character) { return character >= 'a' && character <= 'z' ? character - 'a' + 'A' : character; }

		//apply function to every character until count, _function is a function that return a char
		template<typename Function>
		static char* __cdecl _transform_char_count(const char*& chars, cll& size, cll& count, const Function& _function, cll&start = 0) {
			char* arr = new char[size + 1];
			for (ll i = start; i < size; ++i)
				arr[i] = i < count ? _function(chars[i]) : chars[i];

			arr[size] = '\0';

			return arr;

		}
	public:
		Ustring() {}

		//split a string with _sep string as separator 
		static std::vector<std::string> __cdecl split(const std::string& text, const std::string& _sep) { return ustr::_split(text, _sep); }

		//split a string with _sep char as separator 
		static std::vector<std::string> __cdecl split(const std::string& text, cchar& _sep) {
			std::string sep = "";
			sep += _sep;
			return ustr::_split(text, sep);
		}

		//split a const char pointer with _sep char as separator
		static std::vector<std::string> __cdecl split(cchar_p& text, cchar& _sep) {
			std::string sep = "";
			sep += _sep;
			return ustr::_split(std::string(text), sep);
		}

		//split a const char pointer with _sep char pointer as separator
		static std::vector<std::string> __cdecl split(cchar_p& text, cchar_p& _sep) { return ustr::_split(std::string(text), std::string(_sep)); }

		//return how many chars have a char array
		static cll __cdecl pchar_size(cchar_p chars) { return ustr::_pchar_size(chars); }

		//return the lower value of character
		static cchar __cdecl to_lower(cchar character) { return ustr::_to_lower(character); }

		//return the lower value of every character
		static cchar_p __cdecl to_lower(cchar_p characters) { cll size = ustr::pchar_size(characters); return ustr::_transform_char_count(characters, size, size, ustr::_to_lower); }
		
		//return the lower value of every character until count
		static cchar_p __cdecl to_lower(cchar_p characters, cll& count) { cll size = ustr::pchar_size(characters); return ustr::_transform_char_count(characters, size, count, ustr::_to_lower); }

		//return the lower value of every character since start until count
		static cchar_p __cdecl to_lower(cchar_p characters, cll& start, cll& count) { cll size = ustr::pchar_size(characters); return ustr::_transform_char_count(characters, size, count, ustr::_to_lower, start); }

		//return the lower value of every character in string
		const std::string& __cdecl to_lower(std::string& text) {
			for_each(text.begin(), text.end(), [](char& i) {i = ustr::_to_lower(i); });
			return text;
		}

		//return the lower value of every character in string until count
		const std::string& __cdecl to_lower(std::string& text, cll& count) {
			for (ll i = 0; i < text.size(); ++i)
				text.at(i) = i < count ? ustr::_to_lower(text.at(i)) : text.at(i);

			return text;
		}

		//return the lower value of every character in string since start until count
		const std::string& __cdecl to_lower(std::string& text, cll& start, cll& count) {
			for (ll i = start; i < text.size(); ++i)
				text.at(i) = i < count ? ustr::_to_lower(text.at(i)) : text.at(i);

			return text;
		}
		
		//return the upper value of character
		static cchar __cdecl to_upper(cchar character) { return ustr::_to_upper(character); }

		//return the lower value of every character
		cchar_p __cdecl to_upper(cchar_p characters) { cll size = ustr::pchar_size(characters); return ustr::_transform_char_count(characters, size, size, ustr::_to_upper); }

		//return the upper value of every character until count
		cchar_p __cdecl to_upper(cchar_p characters, cll& count) { cll size = ustr::pchar_size(characters); return ustr::_transform_char_count(characters, size, count, ustr::_to_upper); }

		//return the upper value of every character since start until count
		cchar_p __cdecl to_upper(cchar_p characters, cll& start, cll& count) { cll size = ustr::pchar_size(characters); return ustr::_transform_char_count(characters, size, count, ustr::_to_upper); }
		
		//return the upper value of every character in string
		const std::string __cdecl to_upper(std::string& text) { for_each(text.begin(), text.end(), [](char& i) {i = ustr::_to_upper(i); }); return text; }

		//return the upper value of every character in string until count
		const std::string __cdecl to_upper(std::string& text, cll& count) {
			for (ll i = 0; i < text.size(); ++i)
				text[i] = i < count ? ustr::_to_upper(text[i]) : text[i];

			return text;
		}

		//return the upper value of every character in string since start until count
		const std::string __cdecl to_upper(std::string& text, cll& start, cll& count) {
			for (ll i = start; i < text.size(); ++i)
				text[i] = i < count ? ustr::_to_upper(text[i]) : text[i];

			return text;
		}

	};
}

#endif //__USTRINGS_HPP__