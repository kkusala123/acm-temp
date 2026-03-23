/*
 * 功能：ACM竞赛通用基础模板，包含常用宏定义、类型别名、基础工具函数
 * 适用：所有C++算法题的基础框架，加速输入输出，预定义常用常量与工具
 */
#include<bits/stdc++.h>
#define fi first
#define se second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ri register
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define rFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define ET '\n'
using namespace std;

using ll=long long;
using ull=unsigned long long;
using ld=long double;

// 常量定义
ll INF=((ull)~0)>>2;
ll M=1e9+7;
const int N=200005;
const ld PI=acos(ld(-1));

// 取模归一化函数，保证结果非负
template<typename T>T MO(T x){return (x%M+M)%M;}
// 快速输出Yes/No
void ANS(bool x){cout<<(x?"Yes\n":"No\n");}

// 随机数生成器
mt19937 myrand(time(0));
ll rnd(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(myrand);
}

// 核心解题函数，写题时将逻辑写在这里
void solve() {
    // 在此处编写解题逻辑
}

signed main(){
    // 关闭同步流，加速cin/cout
    cout.tie(0);cin.tie(0)->sync_with_stdio(false);
    // 预处理函数（如需）
    // pre();
    // 多组测试用例
    // int t;cin>>t;while(t--)
    solve();
    return 0;
}