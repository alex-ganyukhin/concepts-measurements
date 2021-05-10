template<typename T>
concept IsBig = sizeof(T) >= 4;

template<typename T>
void foo(IsBig auto const &) { }

template<typename T>
void foo(auto const &) {}

void later() {
    foo<char>('a');
    foo<int>(1);
}
