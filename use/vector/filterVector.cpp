#include <vector>
#include <cassert>
#include <iostream>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& vec, Predicate pred) {
    std::vector<T> result;
    for (const auto& item : vec) {
        if (pred(item)) result.push_back(item);
    }
    return result;
}

void test_filterVector() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto res = filterVector(v, [](int x) { return x % 2 == 0; });
    assert(res == std::vector<int>({2, 4}));
    std::cout << "filterVector passed\n";
}

int main() {
    test_filterVector();
    return 0;
}
