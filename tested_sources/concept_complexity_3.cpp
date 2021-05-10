template<typename T>
concept ConceptA = sizeof(T) >= 1;

template<typename T>
concept ConceptB = ConceptA<T> && sizeof(T) < 8;

template<typename T>
concept ConceptC = ConceptB<T> && requires (T v) { ++v; };

template<typename T>
concept TestedConcept = ConceptC<T>;

void foo(TestedConcept auto const &) {}
void foo(auto const &) {}

    struct S {};
void later() {
    foo(int { 1 });
    foo(S{});
}
