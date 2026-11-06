#include <cassert>
#include <iostream>
template <typename T>
class Range {
    T start, end;
public:
    Range(T s, T e) : start(s), end(e) {}
    bool contains(const T& v) const { return v >= start && v <= end; }
    T length() const { return end - start; }
};
void test_Range() {
    Range<int> r(3, 10);
    assert(r.contains(5) && !r.contains(1));
    assert(r.length() == 7);
    std::cout << "Range passed\n";
}
int main() { test_Range(); return 0; }
