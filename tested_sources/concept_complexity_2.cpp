template<typename T>
concept ConceptA = sizeof(T) >= 1;

template<typename T>
concept ConceptB =  requires(T i) {
    { i++     } noexcept -> ConceptA;
    { ++i     } noexcept -> ConceptA;
    { i--     } noexcept -> ConceptA;
    { --i     } noexcept -> ConceptA;
    { i + i   } noexcept -> ConceptA;
    { i - i   } noexcept -> ConceptA;
    { i += i  } noexcept -> ConceptA;
    { i -= i  } noexcept -> ConceptA;
};


template<typename T>
concept ConceptC =  requires(T i) {
    { i * i      } noexcept -> ConceptB;
    { i / i      } noexcept -> ConceptB;
    { i % i      } noexcept -> ConceptB;
    { i *= i     } noexcept -> ConceptB;
    { i /= i     } noexcept -> ConceptB;
    { i %= i     } noexcept -> ConceptB;

    { i |  i     } noexcept -> ConceptB;
    { i &  i     } noexcept -> ConceptB;
    { i |= i     } noexcept -> ConceptB;
    { i &= i     } noexcept -> ConceptB;
};

template<typename T>
concept TestedConcept = ConceptA<T> && ConceptB<T> && ConceptC<T>;


void foo(TestedConcept auto const &) {}
void foo(auto const &) {}

void later() {
    int i { 0 };
    int * ip = &i;

    foo(i);
    foo(ip);
}
