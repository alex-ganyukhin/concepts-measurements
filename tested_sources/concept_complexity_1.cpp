#include <concepts>
template<typename T>
concept ConceptA = sizeof(T) >= 1;

template<typename T>
concept TestedConcept = ConceptA<T>;

void foo(TestedConcept auto const &) {}
void foo(auto const &) {}

void later() {
    int i { 0 };
    int * ip = &i;

    foo(i);
    foo(ip);
}
