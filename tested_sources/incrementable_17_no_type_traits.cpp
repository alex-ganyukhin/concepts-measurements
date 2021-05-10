template<bool C, typename T = void>
struct enable_if { typedef T type; };
template<typename T>
struct enable_if<false, T> {};
template<bool B, typename T = void>
using enable_if_t = typename enable_if<B, T>::type;
template<typename ...>
using void_t = void;
template<class T>
T && declval() noexcept;


template<class, class = void_t<>>
struct IsInc {
    constexpr static bool value = false;
};
template<class T>
struct IsInc<T, void_t<decltype( ++declval<T&>() )>>
{
    constexpr static bool value = true;
};

template<class Ty>
enable_if_t<IsInc<Ty>::value> increment(Ty &);
template<class Ty>
enable_if_t<!IsInc<Ty>::value> increment(Ty &);

struct Incrementable { Incrementable & operator++() { return *this; } };
struct NonIncrementable {};

void later() {
    Incrementable     i;
    NonIncrementable ni;
    increment(i);
    increment(ni);
}
