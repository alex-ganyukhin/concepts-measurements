template<typename T>
concept ConceptA = sizeof(T) >= 1;

template<typename T>
concept TestedConcept =
    ConceptA<T> &&
    requires(T i, int n) {
        { i += n } -> std::same_as<T&>;
        { i -= n } -> std::same_as<T&>;
        { i +  n } -> std::same_as<T>;
        { n +  i } -> std::same_as<T>;
        { i -  n } -> std::same_as<T>;
        { i -  i } -> std::same_as<decltype(n)>;
        {  i[n]  } -> std::convertible_to<std::iter_reference_t<T>>;
    } && requires(T i) {
        {  --i } -> std::same_as<T&>;
        {  i-- } -> std::convertible_to<const T&>;
        { *i-- } -> std::same_as<std::iter_reference_t<T>>;
    };

void foo(TestedConcept auto const &) {}
void foo(auto const &) {}

void later() {
    int i { 0 };
    int * ip = &i;

    foo(i);
    foo(ip);
}
