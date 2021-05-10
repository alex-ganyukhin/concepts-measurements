template<typename T>
concept IsBig = sizeof(T) >= 4;

template<typename T>
void foo(T const &) requires IsBig<T> { }

template<typename T>
void foo(T const &) {}

void later() {
    foo<char>('a');
    foo<int>(1);
}
