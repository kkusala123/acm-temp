/*
 * 功能：试除法分解质因数，得到一个数的所有不同质因数
 * 时间复杂度：O(√n)，n为待分解的数
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// 分解质因数，返回所有不同的质因数
vector<ll> prime_factorization(ll n) {
    vector<ll> factors;
    ll tmp = n;
    for(ll i=2; i*i <= tmp; ++i) {
        if(tmp % i == 0) {
            factors.push_back(i);
            // 除尽该质因数
            while(tmp % i == 0) {
                tmp /= i;
            }
        }
    }
    // 剩余的大于1的数也是质因数
    if(tmp > 1) {
        factors.push_back(tmp);
    }
    return factors;
}

// 分解质因数，返回质因数和对应的指数
vector<pair<ll, int>> prime_factorization_with_count(ll n) {
    vector<pair<ll, int>> factors;
    ll tmp = n;
    for(ll i=2; i*i <= tmp; ++i) {
        if(tmp % i == 0) {
            int cnt = 0;
            while(tmp % i == 0) {
                tmp /= i;
                cnt++;
            }
            factors.emplace_back(i, cnt);
        }
    }
    if(tmp > 1) {
        factors.emplace_back(tmp, 1);
    }
    return factors;
}

int main() {
    ll n;
    cin >> n;
    // 1. 获取所有不同质因数
    vector<ll> factors = prime_factorization(n);
    cout << "质因数：";
    for(ll p : factors) cout << p << " ";
    cout << endl;

    // 2. 获取质因数和指数
    vector<pair<ll, int>> factors_cnt = prime_factorization_with_count(n);
    cout << "质因数和指数：" << endl;
    for(auto &p : factors_cnt) {
        cout << p.first << "^" << p.second << " ";
    }

    return 0;
}