#include <type_traits>

template<class, class = std::void_t<>>
struct IsInc : std::false_type {};

template<class T>
struct IsInc<T, std::void_t<decltype( ++std::declval<T&>() )>>
	: std::true_type
{};

template<class Ty>
std::enable_if_t<IsInc<Ty>::value> increment(Ty &);
template<class Ty>
std::enable_if_t<!IsInc<Ty>::value> increment(Ty &);

struct Incrementable { Incrementable & operator++() { return *this; } };
struct NonIncrementable {};

void later() {
    Incrementable     i;
    NonIncrementable ni;
    increment(i);
    increment(ni);
}
