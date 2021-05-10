#include <type_traits>
#include <string>


template<typename T, typename = void>
struct OptionalLikeBase1 {
    ~OptionalLikeBase1() { }
};

template<typename T>
struct OptionalLikeBase1<T, std::enable_if_t<std::is_trivially_destructible<T>::value>>
{
    ~OptionalLikeBase1() = default;
};

template<typename T, typename = void>
struct OptionalLikeBase2 {
    OptionalLikeBase2() = default;
    OptionalLikeBase2(OptionalLikeBase2 const &) { }
    OptionalLikeBase2(OptionalLikeBase2 &&) = default;
};

template<typename T>
struct OptionalLikeBase2<T, std::enable_if_t<std::is_trivially_copy_constructible<T>::value>>
{
    OptionalLikeBase2() = default;
    OptionalLikeBase2(OptionalLikeBase2 const &) = default;
    OptionalLikeBase2(OptionalLikeBase2 &&) = default;
};

template<typename T, typename = void>
struct OptionalLikeBase3 {
    OptionalLikeBase3() = default;
    OptionalLikeBase3(OptionalLikeBase3 const &) = default;
    OptionalLikeBase3(OptionalLikeBase3 &&) { }
};

template<typename T>
struct OptionalLikeBase3<T, std::enable_if_t<std::is_trivially_move_constructible<T>::value>>
{
    OptionalLikeBase3() = default;
    OptionalLikeBase3(OptionalLikeBase3 const &) = default;
    OptionalLikeBase3(OptionalLikeBase3 &&) = default;
};

template<typename T>
struct OptionalLike
    : OptionalLikeBase1<T>
    , OptionalLikeBase2<T>
    , OptionalLikeBase3<T>
{
};

void later() {
    OptionalLike<int>         oli;
    OptionalLike<std::string> ols;
    auto oli_ = oli;
    auto ols_ = ols;
}
