template<typename T>
concept IsBig = sizeof(T) >= 4;

template<typename T>
    requires IsBig<T>
void foo(T const &) { }

template<typename T>
void foo(T const &) {}

void later() {
    foo<char>('a');
    foo<int>(1);
}
