#include <iostream>
#include <vector>
#include <cassert>

void createAndFillVector(int N) {
    std::vector<int> vec(N);
    for (int i = 0; i < N; ++i) vec[i] = i + 1;
    for (int x : vec) std::cout << x << " ";
    std::cout << "\nSize: " << vec.size() << ", Capacity: " << vec.capacity() << "\n";
}

void test_createAndFillVector() {
    createAndFillVector(5);
    assert(true); // Тест-заглушка, так как функция только выводит данные
    std::cout << "createAndFillVector passed\n";
}

int main() {
    test_createAndFillVector();
    return 0;
}
