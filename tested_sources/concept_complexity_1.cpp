template<typename T>
concept ConceptA = sizeof(T) >= 1;

template<typename T>
concept TestedConcept = ConceptA<T>;

void foo(TestedConcept auto const &) {}
void foo(auto const &) {}

struct S {};
void later() {
    foo(int { 1 });
    struct S {};
    foo(S{});
}
