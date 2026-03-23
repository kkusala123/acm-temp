/*
 * 功能：模运算基础规则，费马小定理求乘法逆元
 * 适用：模意义下的除法运算，是组合数、模运算的核心工具
 * 前提：模数p为质数，且b与p互质（b不是p的倍数）
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MOD = 1e9+7; // 常用模数，质数

// 快速幂
ll fast_pow(ll a, ll n, ll M) {
    ll ans = 1;
    a %= M;
    while(n) {
        if(n & 1) ans = ans * a % M;
        a = a * a % M;
        n >>= 1;
    }
    return ans;
}

// 费马小定理求乘法逆元：inv(b) = b^(p-2) mod p
ll mod_inverse(ll b, ll p) {
    return fast_pow(b, p-2, p);
}

// 模运算归一化，保证结果非负
ll mod_normalize(ll x, ll p) {
    return (x % p + p) % p;
}

int main() {
    // 模运算基础示例
    ll a, b;
    cin >> a >> b;
    ll p = MOD;

    // 模加
    ll add = mod_normalize(a + b, p);
    cout << "(" << a << " + " << b << ") mod " << p << " = " << add << endl;

    // 模减
    ll sub = mod_normalize(a - b, p);
    cout << "(" << a << " - " << b << ") mod " << p << " = " << sub << endl;

    // 模乘
    ll mul = mod_normalize(a * b, p);
    cout << "(" << a << " * " << b << ") mod " << p << " = " << mul << endl;

    // 模除：a/b mod p = a * inv(b) mod p
    ll inv_b = mod_inverse(b, p);
    ll div = mod_normalize(a * inv_b, p);
    cout << "(" << a << " / " << b << ") mod " << p << " = " << div << endl;

    return 0;
}