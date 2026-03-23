/*
 * 功能：矩阵快速幂，O(logn)时间计算矩阵的n次幂
 * 适用：线性递推求解（如斐波那契数列）、矩阵快速幂优化DP
 */
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
using ll=long long;

ll MOD = 10000; // 模数，按需修改

class Matrix {
public:
    int n, m; // 矩阵行数、列数
    vector<vector<ll>> a;

    // 构造函数：n行m列的零矩阵
    Matrix(int n_, int m_) {
        n = n_;
        m = m_;
        a = vector<vector<ll>>(n+1, vector<ll>(m+1, 0));
    }

    // 构造函数：从二维数组初始化
    Matrix(vector<vector<ll>> tmp) {
        n = tmp.size();
        m = tmp[0].size();
        a = vector<vector<ll>>(n+1, vector<ll>(m+1, 0));
        FOR(i,1,n) FOR(j,1,m) a[i][j] = tmp[i-1][j-1];
    }

    // 重载[]运算符，方便访问元素
    vector<ll>& operator[](int i) {
        return a[i];
    }

    // 重载矩阵乘法
    Matrix operator*(const Matrix& b) const {
        Matrix tmp(n, b.m);
        FOR(i,1,n) FOR(j,1,b.m) FOR(k,1,m) {
            tmp.a[i][j] = (tmp.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        }
        return tmp;
    }

    // 重载矩阵快速幂
    Matrix operator^(ll n) const {
        Matrix ans = unit(this->n); // 单位矩阵
        Matrix a = *this;
        while(n) {
            if(n & 1) {
                ans = ans * a;
            }
            a = a * a;
            n >>= 1;
        }
        return ans;
    }

    // 生成n阶单位矩阵
    static Matrix unit(int n) {
        Matrix res(n, n);
        FOR(i,1,n) res.a[i][i] = 1;
        return res;
    }

    // 矩阵转置
    Matrix transpose() const {
        Matrix tmp(m, n);
        FOR(i,1,n) FOR(j,1,m) tmp.a[j][i] = a[i][j];
        return tmp;
    }

    // 打印矩阵
    void print() const {
        FOR(i,1,n) {
            FOR(j,1,m) cout << a[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    // 示例1：求斐波那契数列第n项，模MOD
    ll n;
    cin >> n;
    if(n == 0 || n == 1) {
        cout << n << endl;
        return 0;
    }
    // 斐波那契转移矩阵
    Matrix mat({
        {1, 1},
        {1, 0}
    });
    // 矩阵快速幂
    Matrix res = mat ^ (n - 1);
    cout << "斐波那契第" << n << "项：" << res[1][1] << endl;

    return 0;
}