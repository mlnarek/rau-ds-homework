#include <vector>
#include <cassert>
#include <iostream>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> result;
    if (vec.empty()) return result;
    std::vector<int> current = {vec[0]};
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] == vec[i - 1]) current.push_back(vec[i]);
        else {
            result.push_back(current);
            current = {vec[i]};
        }
    }
    result.push_back(current);
    return result;
}

void test_groupAdjacent() {
    std::vector<int> v = {1, 1, 2, 3, 3};
    auto res = groupAdjacent(v);
    assert(res.size() == 3);
    assert(res[0] == std::vector<int>({1, 1}));
    assert(res[1] == std::vector<int>({2}));
    assert(res[2] == std::vector<int>({3, 3}));
    std::cout << "groupAdjacent passed\n";
}

int main() {
    test_groupAdjacent();
    return 0;
}
