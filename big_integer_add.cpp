/*
 * 功能：高精度大整数加法，支持超长整数的加法运算
 * 适用：超过64位整数范围的大整数运算
 */
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define rFOR(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;

struct BigInt {
    int len;
    int num[5000]; // 最大支持5000位，按需调整

    // 构造函数：从long long初始化
    BigInt(long long x = 0) {
        len = 0;
        memset(num, 0, sizeof(num));
        while(x) {
            num[++len] = x % 10;
            x /= 10;
        }
    }

    // 构造函数：从字符串初始化
    BigInt(string s) {
        len = s.size();
        memset(num, 0, sizeof(num));
        for(int i=0; i<len; ++i) {
            num[len - i] = s[i] - '0';
        }
    }

    // 处理进位
    void carry() {
        for(int i=1; i<=len; ++i) {
            if(num[i] >= 10) {
                num[i+1] += num[i] / 10;
                num[i] %= 10;
                if(num[len+1]) len++;
            }
        }
    }

    // 重载加法运算符
    BigInt operator+(const BigInt& b) const {
        BigInt res = *this;
        int max_len = max(len, b.len);
        for(int i=1; i<=max_len; ++i) {
            res.num[i] += b.num[i];
        }
        res.len = max_len;
        res.carry();
        return res;
    }

    // 重载+=运算符
    BigInt& operator+=(const BigInt& b) {
        *this = *this + b;
        return *this;
    }
};

// 重载输出运算符
ostream& operator<<(ostream& out, const BigInt& a) {
    if(a.len == 0) {
        out << 0;
        return out;
    }
    rFOR(i, a.len, 1) {
        out << a.num[i];
    }
    return out;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    BigInt a(s1), b(s2);
    BigInt c = a + b;
    cout << c << endl;
    return 0;
}