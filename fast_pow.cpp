/*
 * 功能：快速幂（快速幂取模），O(logn)时间计算a^n mod M
 * 适用：大指数幂运算、模运算场景，是数论的基础工具
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;

const ll INF = (((ull)~0)>>2);

// 快速幂：计算a^n mod M，默认M为无穷大（不取模）
ll fast_pow(ll a, ll n, ll M = INF) {
    ll ans = 1;
    a %= M; // 先对底数取模，避免溢出
    while(n) {
        if(n & 1) {
            ans = ans * a % M;
        }
        a = a * a % M;
        n >>= 1;
    }
    return ans;
}

int main() {
    ll a, n, M;
    cin >> a >> n >> M;
    cout << a << "^" << n << " mod " << M << " = " << fast_pow(a, n, M) << endl;
    return 0;
}