template<bool C, typename T = void>
struct enable_if { typedef T type; };
template<typename T>
struct enable_if<false, T> {};

namespace is_inc {
	typedef char (&yes)[1]; typedef char (&no)[2];

	struct tag {};
	struct any { template <class T> any(T const&); };
	tag operator++(any const &);

	template<typename T>
	static yes test(T const &);
	static no test(tag);

	template<typename _T> struct IsInc
	{
		static _T & type_value;
		static const bool value = sizeof(yes) == sizeof(test(++type_value));
	};
}
template<typename T>
struct IsInc : public is_inc::IsInc<T> {};

template<class Ty>
typename enable_if<IsInc<Ty>::value>::type increment(Ty &);
template<class Ty>
typename enable_if<!IsInc<Ty>::value>::type increment(Ty &);

struct Incrementable { Incrementable & operator++() { return *this; } };
struct NonIncrementable {};

void later() {
    Incrementable     i;
    NonIncrementable ni;
    increment(i);
    increment(ni);
}
