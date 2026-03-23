/*
 * 功能：获取一个正整数的所有正约数
 * 时间复杂度：O(√n)
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// 获取n的所有正约数，无序
vector<ll> get_divisors(ll n) {
    vector<ll> divisors;
    for(ll i=1; i*i <= n; ++i) {
        if(n % i == 0) {
            divisors.push_back(i);
            // 避免平方数重复添加
            if(i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> divisors = get_divisors(n);
    // 排序后输出
    sort(divisors.begin(), divisors.end());
    cout << n << "的所有正约数：" << endl;
    for(ll d : divisors) {
        cout << d << " ";
    }
    return 0;
}