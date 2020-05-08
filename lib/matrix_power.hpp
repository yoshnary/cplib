#ifndef CPLIB_LIB_MATRIX_POWER_H_
#define CPLIB_LIB_MATRIX_POWER_H_

#include <iostream>
#include <vector>
#include <cassert>

// Matrix power
template<typename T>
class Matrix {
public:
    Matrix(int n, int m) : dat(n, std::vector<T>(m)) {}
    Matrix(int n, int m, T init_val) : dat(n, std::vector<T>(m, init_val)) {}
    Matrix(int n) : Matrix(n, n) {}
    Matrix(int n, T init_val) : Matrix(n, n, init_val) {}
    std::vector<T> &operator[](size_t idx) { return dat[idx]; }
    const std::vector<T> &operator[](size_t idx) const { return dat[idx]; }
    size_t size() const { return dat.size(); }

private:
    std::vector<std::vector<T>> dat;
};
template<typename T>
std::ostream &operator<<(std::ostream &out, const Matrix<T> &a) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            out << a[i][j] << " \n"[j == (int)a[i].size() - 1];
        }
    }
    return out;
}

template<typename T>
Matrix<T> matmul(const Matrix<T> &a, const Matrix<T> &b) {
    int n = (int)a.size();
    int m = (int)b[0].size();
    int r = (int)b.size();
    assert(a[0].size() == r);
    Matrix<T> ret(n, m);
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < r; k++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ret;
}

template<typename T>
Matrix<T> matpow(Matrix<T> a, long long p) {
    int n = (int)a.size();
    Matrix<T> ret(n);
    for (int i = 0; i < n; i++) ret[i][i] = 1;
    while (p > 0) {
        if (p & 1) ret = matmul(ret, a);
        a = matmul(a, a);
        p >>= 1LL;
    }
    return ret;
}

#endif  // CPLIB_LIB_MATRIX_POWER_H_
