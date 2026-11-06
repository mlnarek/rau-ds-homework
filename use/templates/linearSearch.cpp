#include <vector>
#include <cassert>
#include <iostream>
template <typename T>
int linearSearch(const std::vector<T>& vec, const T& target) {
    for (size_t i = 0; i < vec.size(); ++i) if (vec[i] == target) return i;
    return -1;
}

void test_linearSearch() {
    std::vector<int> v = {10, 20, 30};
    assert(linearSearch(v, 20) == 1);
    assert(linearSearch(v, 99) == -1);
    std::cout << "linearSearch passed\n";
}

int main() { test_linearSearch(); return 0; }
