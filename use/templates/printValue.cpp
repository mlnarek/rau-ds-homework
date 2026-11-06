#include <iostream>
#include <cassert>
template <typename T>
void printValue(const T& v) { std::cout << v << "\n"; }
template <>
void printValue<bool>(const bool& v) { std::cout << (v ? "true" : "false") << "\n"; }
template <>
void printValue<char*>(char* const& v) { std::cout << "\"" << v << "\"\n"; }
void test_printValue() {
    printValue(true);
    char s[] = "test";
    printValue(s);
    assert(true);
    std::cout << "printValue passed\n";
}
int main() { test_printValue(); return 0; }
