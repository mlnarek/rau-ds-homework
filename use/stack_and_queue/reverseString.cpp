#include <iostream>
#include <string>
#include <stack>
#include <cassert>

void reverseString(std::string& str) {
    std::stack<char> s;
    for (char c : str) {
        s.push(c);
    }
    for (int i = 0; i < str.length(); i++) {
        str[i] = s.top();
        s.pop();
    }
}

void test_reverseString() {
    std::string s = "Hello";
    reverseString(s);
    assert(s == "olleH");
    std::cout << "reverseString passed\n";
}

int main() {
    test_reverseString();
    return 0;
}
