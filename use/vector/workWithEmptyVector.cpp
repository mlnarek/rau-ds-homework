#include <iostream>
#include <vector>
#include <cassert>

void workWithEmptyVector() {
    std::vector<int> vec;
    for (int i = 1; i <= 10; ++i) {
        vec.push_back(i);
        std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << "\n";
    }
}

void test_workWithEmptyVector() {
    workWithEmptyVector();
    assert(true);
    std::cout << "workWithEmptyVector passed\n";
}

int main() {
    test_workWithEmptyVector();
    return 0;
}
