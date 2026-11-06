#include <vector>
#include <cassert>
#include <iostream>

int removeElementsGreaterThan(std::vector<int>& vec, int threshold) {
    int removed = 0;
    while (!vec.empty() && vec.back() > threshold) {
        vec.pop_back();
        removed++;
    }
    return removed;
}

void test_removeElementsGreaterThan() {
    std::vector<int> v = {1, 3, 5, 7, 9};
    int removed = removeElementsGreaterThan(v, 5);
    assert(removed == 2);
    assert(v == std::vector<int>({1, 3, 5}));
    std::cout << "removeElementsGreaterThan passed\n";
}

int main() {
    test_removeElementsGreaterThan();
    return 0;
}
