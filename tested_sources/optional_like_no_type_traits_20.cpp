#include <string>

template<typename T>
struct OptionalLike
{
    ~OptionalLike() {
        /* Calls d-tor manually */
    }
    ~OptionalLike() requires (sizeof(T) <= 4) = default;
};

void later() {
    OptionalLike<int>         oli;
    OptionalLike<std::string> ols;
}
