#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include <iostream>
#include "../lib/matrix_power.hpp"
#include "../lib/modint.hpp"

int main() {
    int m, k; std::cin >> m >> k;
    Matrix<Mint> mat(m), v(m, 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            mat[(j + i) % m][j]++;
            mat[(j * i) % m][j]++;
        }
    }
    v[0][0] = 1;
    std::cout << matmul(matpow(mat, k), v)[0][0] << std::endl;
    return 0;
}
