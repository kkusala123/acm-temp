/*
 * 功能：Z函数，O(n)求解字符串每个位置的最长公共前缀(LCP)长度
 * 适用：字符串匹配、周期串查找、前缀匹配等场景
 * 定义：z[i]表示字符串s从i开始的子串，与s本身的最长公共前缀长度
 */
#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(const string &s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n; // 整个字符串与自身的LCP为长度n
    for(int i=1, l=0, r=0; i<n; ++i) {
        // 利用已有区间初始化
        if(i < r) {
            z[i] = min(z[i - l], r - i);
        }
        // 暴力扩展
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        // 更新最右区间
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    // 示例：字符串匹配，查找模式串t在文本串s中的所有出现位置
    string s, t;
    cin >> s >> t;
    // 拼接字符串：t + '#' + s，分隔符避免越界
    string total = t + "#" + s;
    vector<int> z = z_function(total);
    int t_len = t.size();

    cout << "模式串出现的起始下标（0-based）：" << endl;
    for(int i = t_len + 1; i < total.size(); ++i) {
        if(z[i] == t_len) {
            cout << i - t_len - 1 << " ";
        }
    }

    return 0;
}