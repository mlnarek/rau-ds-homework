#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>

std::vector<std::string> generateBinaryNumbers(int n) {
    std::vector<std::string> result;
    std::queue<std::string> q;
    q.push("1");
    
    for (int i = 0; i < n; i++) {
        std::string curr = q.front();
        q.pop();
        result.push_back(curr);
        
        q.push(curr + "0");
        q.push(curr + "1");
    }
    return result;
}

void test_generateBinaryNumbers() {
    auto res = generateBinaryNumbers(5);
    std::vector<std::string> expected = {"1", "10", "11", "100", "101"};
    assert(res == expected);
    std::cout << "generateBinaryNumbers passed\n";
}

int main() {
    test_generateBinaryNumbers();
    return 0;
}
