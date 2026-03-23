/*
 * 功能：最大公约数GCD、最小公倍数LCM计算
 * 算法：欧几里得算法（辗转相除法）
 * 时间复杂度：O(log(min(a,b)))
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// 递归实现欧几里得算法求GCD
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

// 非递归实现欧几里得算法
ll gcd_iter(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 求最小公倍数LCM，先除后乘避免溢出
ll lcm(ll a, ll b) {
    if(a == 0 || b == 0) return 0;
    return a / gcd(a, b) * b;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    cout << "LCM(" << a << ", " << b << ") = " << lcm(a, b) << endl;
    return 0;
}