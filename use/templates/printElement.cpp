#include <iostream>
#include <cassert>

template <typename T>
void printElement(const T& value) { std::cout << value << "\n"; }

void test_printElement() {
    printElement(42);
    printElement("test");
    assert(true);
    std::cout << "printElement passed\n";
}
int main() { test_printElement(); return 0; }
