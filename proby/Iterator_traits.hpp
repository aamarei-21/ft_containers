
#ifndef __ITTRAITS_HPP__
#define __ITTRAITS_HPP__

namespace ft {

	template <class T, T v>
	struct integral_constant {
		static T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template<typename> struct is_integral_base: std::false_type {};
	template<> struct is_integral_base<bool>: std::true_type {};
	template<> struct is_integral_base<char>: std::true_type {};
	template<> struct is_integral_base<char16_t>: std::true_type {};
	template<> struct is_integral_base<char32_t>: std::true_type {};
	template<> struct is_integral_base<wchar_t>: std::true_type {};
	template<> struct is_integral_base<signed char>: std::true_type {};
	template<> struct is_integral_base<short int>: std::true_type {};
	template<> struct is_integral_base<int>: std::true_type {};
	template<> struct is_integral_base<long int>: std::true_type {};
	template<> struct is_integral_base<long long int>: std::true_type {};
	template<> struct is_integral_base<unsigned char>: std::true_type {};
	template<> struct is_integral_base<unsigned short int>: std::true_type {};
	template<> struct is_integral_base<unsigned int>: std::true_type {};
	template<> struct is_integral_base<unsigned long int>: std::true_type {};
	template<> struct is_integral_base<unsigned long long int>: std::true_type {};

	template<typename T> struct is_integral: is_integral_base<T> {};


	template<class _Iter>
	struct iterator_traits {
		typedef typename _Iter::difference_type difference_type;
		typedef typename _Iter::value_type value_type;
		typedef typename _Iter::pointer pointer;
		typedef typename _Iter::reference reference;
		typedef typename _Iter::iterator_category iterator_category;
	};

	template<class T>
	struct iterator_traits<T*> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<class T>
	struct iterator_traits<const T*> {
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template<bool B, typename T = void>
	struct enable_if {
	};

	template<typename T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template<bool B, typename T, typename F>
	struct conditional {
		typedef F type;
	};

	template<typename T, typename F>
	struct conditional<true, T, F> {
		typedef T type;
	};

	template<class T>
	struct is_const {
		static const bool value = false;
	};

	template<class T>
	struct is_const<const T> {
		static const bool value = true;
	};

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}


} //namespace ft

#endif


