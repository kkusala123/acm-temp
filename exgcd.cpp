/*
 * 功能：扩展欧几里得算法，求解ax + by = gcd(a,b)的整数解
 * 适用：求解线性同余方程、乘法逆元（模数非质数）、贝祖定理相关问题
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// 扩展欧几里得算法
// 返回gcd(a,b)，x和y为输出参数，存储方程的一组解
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b) {
        x = 1;
        y = 0;
        return a;
    }
    ll g = exgcd(b, a % b, x, y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    return g;
}

// 求解线性同余方程 ax ≡ c mod m
// 有解返回true，解存储在x中，无解返回false
bool linear_equation(ll a, ll c, ll m, ll &x) {
    ll y, g;
    g = exgcd(a, m, x, y);
    // 方程有解的条件：c是gcd(a,m)的倍数
    if(c % g != 0) return false;
    // 特解
    x = x * (c / g) % m;
    // 最小正整数解
    x = (x % (m / g) + m / g) % (m / g);
    return true;
}

int main() {
    // 示例1：求解ax + by = gcd(a,b)
    ll a, b, x, y;
    cin >> a >> b;
    ll g = exgcd(a, b, x, y);
    cout << "GCD = " << g << endl;
    cout << "方程的一组解：x = " << x << ", y = " << y << endl;

    // 示例2：求解线性同余方程
    ll c, m;
    cin >> a >> c >> m;
    ll ans;
    if(linear_equation(a, c, m, ans)) {
        cout << "方程" << a << "x ≡ " << c << " mod " << m << "的最小正整数解：" << ans << endl;
    } else {
        cout << "方程无解" << endl;
    }

    return 0;
}