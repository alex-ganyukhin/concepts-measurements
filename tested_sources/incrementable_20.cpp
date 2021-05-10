void increment(auto & arg) requires requires { ++arg; };
void increment(auto &);

struct Incrementable { Incrementable & operator++() { return *this; } };
struct NonIncrementable {};

void later() {
    Incrementable     i;
    NonIncrementable ni;
    increment(i);
    increment(ni);
}
