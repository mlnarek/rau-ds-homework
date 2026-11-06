#include <iostream>
#include <cstring>
#include <cassert>
template <typename T>
bool isEqual(const T& a, const T& b) { return a == b; }
template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) {
    return std::strcmp(a, b) == 0;
}
void test_isEqual() {
    assert(isEqual(5, 5));
    const char* s1 = "hello";
    const char* s2 = "hello";
    assert(isEqual(s1, s2));
    std::cout << "isEqual passed\n";
}
int main() { test_isEqual(); return 0; }
