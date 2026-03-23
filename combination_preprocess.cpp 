/*
 * 功能：预处理阶乘和逆元阶乘，O(1)查询组合数C(n,m)
 * 适用：组合计数、概率计算、卢卡斯定理等场景
 * 前提：模数MOD为质数
 */
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
using ll=long long;

const int MAXN=2e5+5; // 按需调整最大范围
const ll MOD=1e9+7;   // 模数，必须为质数

ll fac[MAXN];    // 阶乘数组：fac[i] = i! mod MOD
ll invfac[MAXN]; // 逆元阶乘数组：invfac[i] = (i!)^{-1} mod MOD

// 模运算归一化
ll MO(ll x) {
    return (x % MOD + MOD) % MOD;
}

// 快速幂
ll fast_pow(ll a, ll n) {
    ll ans = 1;
    while(n) {
        if(n & 1) ans = MO(ans * a);
        a = MO(a * a);
        n >>= 1;
    }
    return ans;
}

// 预处理阶乘和逆元阶乘
void pre() {
    fac[0] = fac[1] = 1;
    invfac[0] = invfac[1] = 1;
    FOR(i,2,MAXN-1) {
        fac[i] = MO(fac[i-1] * i);
    }
    // 逆元阶乘：先算最大的阶乘的逆元，再倒推
    invfac[MAXN-1] = fast_pow(fac[MAXN-1], MOD-2);
    rFOR(i,MAXN-2,0) {
        invfac[i] = MO(invfac[i+1] * (i+1));
    }
}

// 计算组合数C(n,m)：从n个中选m个
ll C(ll m, ll n) {
    if(m < 0 || m > n) return 0;
    return MO(MO(fac[n] * invfac[m]) * invfac[n - m]);
}

// 计算排列数A(n,m)：从n个中选m个排列
ll A(ll m, ll n) {
    if(m < 0 || m > n) return 0;
    return MO(fac[n] * invfac[n - m]);
}

int main() {
    pre(); // 预处理，只需执行一次
    int t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        cout << "C(" << n << "," << m << ") = " << C(m, n) << endl;
        cout << "A(" << n << "," << m << ") = " << A(m, n) << endl;
    }
    return 0;
}