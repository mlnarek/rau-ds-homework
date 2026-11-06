#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

std::vector<int> mergeSortedVectors(const std::vector<int>& v1, const std::vector<int>& v2) {
    std::vector<int> result;
    result.reserve(v1.size() + v2.size());
    std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(result));
    return result;
}

void test_mergeSortedVectors() {
    std::vector<int> v1 = {1, 3, 5};
    std::vector<int> v2 = {2, 4, 6};
    auto res = mergeSortedVectors(v1, v2);
    assert(res == std::vector<int>({1, 2, 3, 4, 5, 6}));
    std::cout << "mergeSortedVectors passed\n";
}

int main() {
    test_mergeSortedVectors();
    return 0;
}
