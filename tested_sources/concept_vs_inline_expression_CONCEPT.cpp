template<typename T>
concept IsBig = sizeof(T) >= 4;

template<typename T>
void foo() requires IsBig<T> { }

template<typename T>
void foo() {}

void later() {
    foo<char>();
    foo<int>();
}
