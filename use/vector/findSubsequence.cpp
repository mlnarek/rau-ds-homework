#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>

int findSubsequence(const std::vector<int>& main_vec, const std::vector<int>& sub_vec) {
    if (sub_vec.empty()) return 0;
    auto it = std::search(main_vec.begin(), main_vec.end(), sub_vec.begin(), sub_vec.end());
    if (it != main_vec.end()) return std::distance(main_vec.begin(), it);
    return -1;
}

void test_findSubsequence() {
    std::vector<int> main_v = {1, 2, 3, 4, 5};
    std::vector<int> sub_v = {3, 4};
    assert(findSubsequence(main_v, sub_v) == 2);
    assert(findSubsequence(main_v, {9}) == -1);
    std::cout << "findSubsequence passed\n";
}

int main() {
    test_findSubsequence();
    return 0;
}
