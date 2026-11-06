#include <cassert>
#include <iostream>
template <typename T, int N>
class FixedArray {
    T data[N];
public:
    void set(int i, T val) { if (i >= 0 && i < N) data[i] = val; }
    T get(int i) const { return data[i]; }
    int size() const { return N; }
};
void test_FixedArray() {
    FixedArray<int, 3> arr;
    arr.set(0, 10);
    assert(arr.get(0) == 10 && arr.size() == 3);
    std::cout << "FixedArray passed\n";
}
int main() { test_FixedArray(); return 0; }
