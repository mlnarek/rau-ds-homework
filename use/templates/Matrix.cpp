#include <cassert>
#include <iostream>
template <typename T, int N, int M>
class Matrix {
    T data[N][M];
public:
    void set(int r, int c, T val) { data[r][c] = val; }
    T get(int r, int c) const { return data[r][c]; }
    Matrix<T, N, M> operator+(const Matrix<T, N, M>& o) const {
        Matrix<T, N, M> res;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                res.set(i, j, data[i][j] + o.get(i, j));
        return res;
    }
};
void test_Matrix() {
    Matrix<int, 2, 2> m1, m2;
    m1.set(0, 0, 1); m2.set(0, 0, 2);
    auto m3 = m1 + m2;
    assert(m3.get(0, 0) == 3);
    std::cout << "Matrix passed\n";
}
int main() { test_Matrix(); return 0; }
