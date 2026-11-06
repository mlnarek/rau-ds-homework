#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>

int evaluateRPN(const std::vector<std::string>& tokens) {
    std::stack<int> s;
    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        } else {
            s.push(std::stoi(token));
        }
    }
    return s.top();
}

void test_evaluateRPN() {
    assert(evaluateRPN({"2", "1", "+", "3", "*"}) == 9);
    assert(evaluateRPN({"4", "13", "5", "/", "+"}) == 6); // 4 + (13/5) = 4 + 2 = 6
    std::cout << "evaluateRPN passed\n";
}

int main() {
    test_evaluateRPN();
    return 0;
}
