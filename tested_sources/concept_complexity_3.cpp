template<typename T>
concept ConceptA = sizeof(T) >= 1;
template<typename T>
concept ConceptB =  requires(T i, int x) {
    { i++     } noexcept -> ConceptA;
    { ++i     } noexcept -> ConceptA;
    { i--     } noexcept -> ConceptA;
    { --i     } noexcept -> ConceptA;
    { i + i   } noexcept -> ConceptA;
    { i - i   } noexcept -> ConceptA;
    { i += i  } noexcept -> ConceptA;
    { i -= i  } noexcept -> ConceptA;

    { i * i      } noexcept -> ConceptA;
    { i / i      } noexcept -> ConceptA;
    { i % i      } noexcept -> ConceptA;
    { i *= i     } noexcept -> ConceptA;
    { i /= i     } noexcept -> ConceptA;
    { i %= i     } noexcept -> ConceptA;

    { i |  i     } noexcept -> ConceptA;
    { i &  i     } noexcept -> ConceptA;
    { i |= i     } noexcept -> ConceptA;
    { i &= i     } noexcept -> ConceptA;

    { ~i          } noexcept -> ConceptA;

    { i ^  i      } noexcept -> ConceptA;
    { i << x      } noexcept -> ConceptA;
    { i >> x      } noexcept -> ConceptA;

    { i ^=  i      } noexcept -> ConceptA;
    { i <<= x      } noexcept -> ConceptA;
    { i >>= x      } noexcept -> ConceptA;
};


template<typename T>
concept ConceptC =  requires(T i, int x) {
    { i++     } noexcept -> ConceptB;
    { ++i     } noexcept -> ConceptB;
    { i--     } noexcept -> ConceptB;
    { --i     } noexcept -> ConceptB;
    { i + i   } noexcept -> ConceptB;
    { i - i   } noexcept -> ConceptB;
    { i += i  } noexcept -> ConceptB;
    { i -= i  } noexcept -> ConceptB;

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

    { ~i          } noexcept -> ConceptB;

    { i ^  i      } noexcept -> ConceptB;
    { i << x      } noexcept -> ConceptB;
    { i >> x      } noexcept -> ConceptB;

    { i ^=  i      } noexcept -> ConceptB;
    { i <<= x      } noexcept -> ConceptB;
    { i >>= x      } noexcept -> ConceptB;
};


template<typename T>
concept ConceptD =  requires(T i, int x) {
    { i++     } noexcept -> ConceptC;
    { ++i     } noexcept -> ConceptC;
    { i--     } noexcept -> ConceptC;
    { --i     } noexcept -> ConceptC;
    { i + i   } noexcept -> ConceptC;
    { i - i   } noexcept -> ConceptC;
    { i += i  } noexcept -> ConceptC;
    { i -= i  } noexcept -> ConceptC;

    { i * i      } noexcept -> ConceptC;
    { i / i      } noexcept -> ConceptC;
    { i % i      } noexcept -> ConceptC;
    { i *= i     } noexcept -> ConceptC;
    { i /= i     } noexcept -> ConceptC;
    { i %= i     } noexcept -> ConceptC;

    { i |  i     } noexcept -> ConceptC;
    { i &  i     } noexcept -> ConceptC;
    { i |= i     } noexcept -> ConceptC;
    { i &= i     } noexcept -> ConceptC;

    { ~i          } noexcept -> ConceptC;

    { i ^  i      } noexcept -> ConceptC;
    { i << x      } noexcept -> ConceptC;
    { i >> x      } noexcept -> ConceptC;

    { i ^=  i      } noexcept -> ConceptC;
    { i <<= x      } noexcept -> ConceptC;
    { i >>= x      } noexcept -> ConceptC;
};

template<typename T>
concept ConceptE =  requires(T i, int x) {
    { i++     } noexcept -> ConceptD;
    { ++i     } noexcept -> ConceptD;
    { i--     } noexcept -> ConceptD;
    { --i     } noexcept -> ConceptD;
    { i + i   } noexcept -> ConceptD;
    { i - i   } noexcept -> ConceptD;
    { i += i  } noexcept -> ConceptD;
    { i -= i  } noexcept -> ConceptD;

    { i * i      } noexcept -> ConceptD;
    { i / i      } noexcept -> ConceptD;
    { i % i      } noexcept -> ConceptD;
    { i *= i     } noexcept -> ConceptD;
    { i /= i     } noexcept -> ConceptD;
    { i %= i     } noexcept -> ConceptD;

    { i |  i     } noexcept -> ConceptD;
    { i &  i     } noexcept -> ConceptD;
    { i |= i     } noexcept -> ConceptD;
    { i &= i     } noexcept -> ConceptD;

    { ~i          } noexcept -> ConceptD;

    { i ^  i      } noexcept -> ConceptD;
    { i << x      } noexcept -> ConceptD;
    { i >> x      } noexcept -> ConceptD;

    { i ^=  i      } noexcept -> ConceptD;
    { i <<= x      } noexcept -> ConceptD;
    { i >>= x      } noexcept -> ConceptD;
};

template<typename T>
concept ConceptF =  requires(T i, int x) {
    { i++     } noexcept -> ConceptE;
    { ++i     } noexcept -> ConceptE;
    { i--     } noexcept -> ConceptE;
    { --i     } noexcept -> ConceptE;
    { i + i   } noexcept -> ConceptE;
    { i - i   } noexcept -> ConceptE;
    { i += i  } noexcept -> ConceptE;
    { i -= i  } noexcept -> ConceptE;

    { i * i      } noexcept -> ConceptE;
    { i / i      } noexcept -> ConceptE;
    { i % i      } noexcept -> ConceptE;
    { i *= i     } noexcept -> ConceptE;
    { i /= i     } noexcept -> ConceptE;
    { i %= i     } noexcept -> ConceptE;

    { i |  i     } noexcept -> ConceptE;
    { i &  i     } noexcept -> ConceptE;
    { i |= i     } noexcept -> ConceptE;
    { i &= i     } noexcept -> ConceptE;

    { ~i          } noexcept -> ConceptE;

    { i ^  i      } noexcept -> ConceptE;
    { i << x      } noexcept -> ConceptE;
    { i >> x      } noexcept -> ConceptE;

    { i ^=  i      } noexcept -> ConceptE;
    { i <<= x      } noexcept -> ConceptE;
    { i >>= x      } noexcept -> ConceptE;
};

template<typename T>
concept ConceptG =  requires(T i, int x) {
    { i++     } noexcept -> ConceptF;
    { ++i     } noexcept -> ConceptF;
    { i--     } noexcept -> ConceptF;
    { --i     } noexcept -> ConceptF;
    { i + i   } noexcept -> ConceptF;
    { i - i   } noexcept -> ConceptF;
    { i += i  } noexcept -> ConceptF;
    { i -= i  } noexcept -> ConceptF;

    { i * i      } noexcept -> ConceptF;
    { i / i      } noexcept -> ConceptF;
    { i % i      } noexcept -> ConceptF;
    { i *= i     } noexcept -> ConceptF;
    { i /= i     } noexcept -> ConceptF;
    { i %= i     } noexcept -> ConceptF;

    { i |  i     } noexcept -> ConceptF;
    { i &  i     } noexcept -> ConceptF;
    { i |= i     } noexcept -> ConceptF;
    { i &= i     } noexcept -> ConceptF;

    { ~i          } noexcept -> ConceptF;

    { i ^  i      } noexcept -> ConceptF;
    { i << x      } noexcept -> ConceptF;
    { i >> x      } noexcept -> ConceptF;

    { i ^=  i      } noexcept -> ConceptF;
    { i <<= x      } noexcept -> ConceptF;
    { i >>= x      } noexcept -> ConceptF;
};

template<typename T>
concept TestedConcept = ConceptA<T> && ConceptB<T> && ConceptC<T> && ConceptD<T> &&
                                       ConceptE<T> && ConceptF<T> && ConceptG<T>;


void foo(TestedConcept auto const &) {}
void foo(auto const &) {}

void later() {
    int i { 0 };
    int * ip = &i;

    foo(i);
    foo(ip);
}
