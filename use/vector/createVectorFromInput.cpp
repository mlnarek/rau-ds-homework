#include <iostream>
#include <vector>
#include <cassert>
#include <sstream>

std::vector<int> createVectorFromInput(std::istream& in) {
    std::vector<int> vec;
    int val;
    while (in >> val && val != 0) {
        vec.push_back(val);
    }
    return vec;
}

void test_createVectorFromInput() {
    std::istringstream input("7 8 9 0");
    std::vector<int> res = createVectorFromInput(input);
    assert(res.size() == 3);
    assert(res[0] == 7 && res[1] == 8 && res[2] == 9);
    std::cout << "createVectorFromInput passed\n";
}

int main() {
    test_createVectorFromInput();
    return 0;
}
