#include <vector>
#include <cassert>
#include <iostream>

void manageCapacity(std::vector<int>& vec) {
    vec.reserve(vec.size() + 500);
    for (int i = 1; i <= 500; ++i) vec.push_back(i);
}

void test_manageCapacity() {
    std::vector<int> v = {1, 2, 3};
    manageCapacity(v);
    assert(v.size() == 503);
    assert(v.capacity() >= 503);
    std::cout << "manageCapacity passed\n";
}

int main() {
    test_manageCapacity();
    return 0;
}
