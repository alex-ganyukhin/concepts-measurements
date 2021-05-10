template<typename T>
void foo() requires (sizeof(T) >= 4) { }

template<typename T>
void foo() {}

void later() {
    foo<char>();
    foo<int>();
}
