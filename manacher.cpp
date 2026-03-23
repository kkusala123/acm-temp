/*
 * 功能：Manacher算法，O(n)时间求解字符串的最长回文子串、任意子串是否为回文
 * 优势：相比中心扩展法，时间复杂度从O(n²)降至O(n)，适配奇偶长度回文
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> PR; // 存储马拉车算法的回文半径数组

// 核心算法：输入原字符串，返回每个位置的最大回文半径
vector<int> manacher(string s) {
    // 插入分隔符，统一奇偶长度回文处理
    string t = "#";
    for(auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n, 0); // 回文半径数组
    for(int i=0, j=0; i<n; ++i) {
        // 利用对称性初始化半径
        if(2*j - i >= 0 && j + r[j] > i) {
            r[i] = min(r[2*j - i], j + r[j] - i);
        }
        // 中心扩展
        while(i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i]++;
        }
        // 更新最右回文中心
        if(i + r[i] > j + r[j]) {
            j = i;
        }
    }
    return r;
}

// 判断原字符串[l, r]区间是否为回文（下标从1开始）
inline bool is_palindrome(int l, int r) {
    // 改为>=可判断是否为回文子串，==仅判断是否为最大回文中心
    return PR[r + l - 1] - 1 >= (r - l + 1);
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    PR = manacher(s);

    // 1. 求最长回文子串长度
    int max_len = 0;
    for(int x : PR) {
        max_len = max(max_len, x - 1);
    }
    cout << "最长回文子串长度：" << max_len << endl;

    // 2. 判断任意子串是否为回文
    int l, r;
    cin >> l >> r; // 输入1-based的左右下标
    cout << "是否为回文：" << (is_palindrome(l, r) ? "Yes" : "No") << endl;

    return 0;
}