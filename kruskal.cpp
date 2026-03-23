/*
 * 功能：Kruskal算法求解无向图的最小生成树(MST)
 * 核心原理：贪心+并查集，按边权从小到大排序，依次选不形成环的边
 * 时间复杂度：O(mlogm)，m为边数，适合稀疏图
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MAXN=5005;    // 最大节点数
const int MAXM=200005;  // 最大边数

// 边结构体
struct edge{
    int u, v;
    ll w;
    // 按边权升序排序
    bool operator<(const edge& a) const {
        return w < a.w;
    }
} edge[MAXM];

int f[MAXN]; // 并查集父节点数组
int n, m;    // n个节点，m条边
ll ans = 0;  // 最小生成树总权值

// 并查集查找+路径压缩
int find(int x) {
    while(x != f[x]) x = f[x] = f[f[x]];
    return x;
}

// Kruskal核心算法
void kruskal() {
    // 1. 所有边按权值升序排序
    sort(edge, edge + m);
    // 2. 初始化并查集
    for(int i=1; i<=n; ++i) f[i] = i;
    
    int cnt = 0; // 已选边数
    for(int i=0; i<m; ++i) {
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        // 两个节点不在同一集合，选这条边
        if(u != v) {
            ans += edge[i].w;
            f[v] = u;
            cnt++;
            // 选够n-1条边，生成树完成，提前退出
            if(cnt == n-1) break;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<m; ++i) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    kruskal();
    // 输出最小生成树总权值，若cnt<n-1说明图不连通
    cout << ans << endl;
    return 0;
}