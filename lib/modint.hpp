#ifndef CPLIB_LIB_MODINT_H_
#define CPLIB_LIB_MODINT_H_

#include <iostream>

// Modint
struct Mint {
    static const long long mod = (long long)1e9 + 7;
    long long val;

    Mint() { val = 0; }
    Mint(long long a) { val = a; verify_value(); }

    void verify_value() {
        if (val >= mod) val %= mod;
        if (val < 0) val %= mod, val += mod;
    }

    Mint pow(long long p) const {
        Mint cur = Mint(val), ret = 1;
        while (p > 0) {
            if (p & 1) ret *= cur;
            cur *= cur;
            p >>= 1LL;
        }
        return ret;
    }
    Mint inv() const {
        if (val == 0)
            std::cerr << "WARNING: inv() is called with 0." << std::endl;
        return pow(mod - 2);
    }

    Mint operator+() const { return *this; }
    Mint operator-() const { return Mint(mod - val); }

    Mint operator+=(const Mint &a) {
        val += a.val;
        if (val >= mod) val -= mod;
        return Mint(val);
    }
    Mint operator*=(const Mint &a) {
        val *= a.val;
        if (val >= mod) val %= mod;
        return Mint(val);
    }
    Mint operator-=(const Mint &a) { return *this += -a; }
    Mint operator/=(const Mint &a) { return *this *= a.inv(); }

    Mint operator++() { return *this += Mint(1); }
    Mint operator--() { return *this -= Mint(1); }
    Mint operator++(int) {
        Mint ret = *this;
        ++(*this);
        return ret;
    }
    Mint operator--(int) {
        Mint ret = *this;
        --(*this);
        return ret;
    }

    operator long long() const { return val; }
};

Mint operator+(const Mint &a, const Mint &b) {
    long long ret = a.val + b.val;
    if (ret >= Mint::mod) ret -= Mint::mod;
    return Mint(ret);
}
Mint operator*(const Mint &a, const Mint &b) {
    long long ret = a.val * b.val;
    if (ret >= Mint::mod) ret %= Mint::mod;
    return Mint(ret);
}
Mint operator-(const Mint &a, const Mint &b) { return a + (-b); }
Mint operator/(const Mint &a, const Mint &b) { return a * b.inv(); }

std::ostream &operator<<(std::ostream &out, const Mint &a) { return out << a.val; }
std::istream &operator>>(std::istream &in, Mint &a) {
    in >> a.val;
    a.verify_value();
    return in;
}

Mint pow(Mint a, long long b) {
    return a.pow(b);
}

#endif  // CPLIB_LIB_MODINT_H_
