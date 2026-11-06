#include <iostream>
#include <cassert>
#include <string>
template <typename T1, typename T2>
class Pair {
    T1 first; T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    void print() const { std::cout << "(" << first << ", " << second << ")\n"; }
};
void test_Pair() {
    Pair<int, std::string> p(1, "one");
    p.print();
    assert(true);
    std::cout << "Pair passed\n";
}
int main() { test_Pair(); return 0; }
