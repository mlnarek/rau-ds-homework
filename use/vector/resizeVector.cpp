#include <vector>
#include <cassert>
#include <iostream>

template <typename T>
void resizeVector(std::vector<T>& vec, size_t newSize, T defaultValue) {
    vec.resize(newSize, defaultValue);
}

void test_resizeVector() {
    std::vector<int> v = {1, 2, 3};
    resizeVector(v, 5, 42);
    assert(v == std::vector<int>({1, 2, 3, 42, 42}));
    std::cout << "resizeVector passed\n";
}

int main() {
    test_resizeVector();
    return 0;
}
