/*
 * 功能：字符串双哈希，两组不同的base和mod，极大降低哈希碰撞概率
 * 时间复杂度：预处理O(n)，查询O(1)
 * 适用：对防碰撞要求高的字符串匹配、子串对比场景
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct DoubleHash {
    const ll base[2] = {29, 31};
    const ll mod[2] = {(ll)1e9+9, 998244353};
    array<vector<ll>, 2> hash_val;
    array<vector<ll>, 2> base_pow;

    // 初始化：传入原字符串，自动预处理
    void init(const string &s) {
        int n = s.size();
        string str = " " + s; // 补前导空格，下标从1开始
        // 重置数组大小
        hash_val[0].resize(n+1); hash_val[1].resize(n+1);
        base_pow[0].resize(n+1); base_pow[1].resize(n+1);

        for(int i=0; i<2; ++i) {
            base_pow[i][0] = 1;
            for(int j=1; j<=n; ++j) {
                base_pow[i][j] = base_pow[i][j-1] * base[i] % mod[i];
                hash_val[i][j] = (hash_val[i][j-1] * base[i] + str[j]) % mod[i];
            }
        }
    }

    // 查询[l, r]区间的双哈希值（1-based）
    pair<ll, ll> get(int l, int r) {
        pair<ll, ll> res;
        res.first = (hash_val[0][r] - hash_val[0][l-1] * base_pow[0][r-l+1]) % mod[0];
        res.second = (hash_val[1][r] - hash_val[1][l-1] * base_pow[1][r-l+1]) % mod[1];
        // 保证结果非负
        res.first = (res.first + mod[0]) % mod[0];
        res.second = (res.second + mod[1]) % mod[1];
        return res;
    }
};

// 快速判断两个哈希对象的子串是否相等
bool is_same(DoubleHash &a, int la, int ra, DoubleHash &b, int lb, int rb) {
    return a.get(la, ra) == b.get(lb, rb);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    DoubleHash hash1, hash2;
    hash1.init(s1);
    hash2.init(s2);

    // 示例：判断子串是否相等
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if((r1-l1+1) == (r2-l2+1) && is_same(hash1, l1, r1, hash2, l2, r2)) {
        cout << "子串相等" << endl;
    }

    return 0;
}