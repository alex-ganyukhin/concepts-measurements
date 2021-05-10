#include <type_traits>
#include <string>

template<typename T>
struct OptionalLike
{
    ~OptionalLike() {
        /* Calls d-tor manually */
    }
    ~OptionalLike() requires (std::is_trivially_destructible<T>::value) = default;
};

void later() {
    OptionalLike<int>         oli;
    OptionalLike<std::string> ols;
}
