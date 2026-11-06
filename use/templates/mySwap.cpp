#include <cassert>
#include <iostream>
template <typename T>
void mySwap(T& a, T& b) { T t = a; a = b; b = t; }
void test_mySwap() {
    int a = 1, b = 2;
    mySwap(a, b);
    assert(a == 2 && b == 1);
    std::cout << "mySwap passed\n";
}
int main() { test_mySwap(); return 0; }
