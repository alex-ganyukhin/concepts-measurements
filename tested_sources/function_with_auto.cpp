template<typename T>
concept IsBig = sizeof(T) >= 4;

void foo(IsBig auto const &) { }

void foo(auto const &) {}

void later() {
    foo<char>('a');
    foo<int>(1);
}
