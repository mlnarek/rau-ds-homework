#include <cassert>
#include <iostream>
template <typename T>
T sumArray(T* arr, int size) {
    T sum = T();
    for (int i = 0; i < size; ++i) sum += arr[i];
    return sum;
}
void test_sumArray() {
    int arr[] = {1, 2, 3};
    assert(sumArray(arr, 3) == 6);
    std::cout << "sumArray passed\n";
}
int main() { test_sumArray(); return 0; }
