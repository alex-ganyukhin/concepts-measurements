#include <type_traits>
#include <string>

template<typename T>
struct OptionalLike
{
    OptionalLike() = default;

    ~OptionalLike() { }
    ~OptionalLike() requires (std::is_trivially_destructible<T>::value) = default;

    OptionalLike(OptionalLike const &) { }
    OptionalLike(OptionalLike const &) requires (std::is_trivially_copy_constructible<T>::value) = default;

    OptionalLike(OptionalLike &&) { }
    OptionalLike(OptionalLike &&) requires (std::is_trivially_move_constructible<T>::value) = default;
};


void later() {
    OptionalLike<int>         oli;
    OptionalLike<std::string> ols;
    auto oli1 = oli;
    auto ols1 = ols;
    auto oli2 = std::move(oli);
    auto ols2 = std::move(ols);
}
