#include <type_traits>
#include <string>

template<typename T, typename = void>
struct OptionalLike {
    ~OptionalLike() {
        /* Calls d-tor manually */
    }
};

template<typename T>
struct OptionalLike<T, std::enable_if_t<std::is_trivially_destructible<T>::value>>
{
    ~OptionalLike() = default;
};


void later() {
    OptionalLike<int>         oli;
    OptionalLike<std::string> ols;
}
