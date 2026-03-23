/*
 * 功能：并查集（Disjoint Set Union），支持路径压缩，快速合并集合、查询连通性
 * 时间复杂度：近似O(1)（阿克曼函数反函数，可视为常数）
 * 适用：最小生成树、连通性问题、动态连通性等场景
 */
#include<bits/stdc++.h>
using namespace std;

const int N=200005; // 按需调整数组大小
int f[N];

// 查找根节点，带路径压缩
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

// 合并两个节点所在的集合
void join(int u, int v) {
    f[find(u)] = find(v);
}

// 初始化：每个节点的父节点是自己
void init(int n) {
    for(int i=1; i<=n; ++i) {
        f[i] = i;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    init(n); // 初始化n个节点

    for(int i=1; i<=m; ++i) {
        int op, u, v;
        cin >> op >> u >> v;
        if(op == 1) {
            // 合并u和v
            join(u, v);
        } else {
            // 查询u和v是否连通
            if(find(u) == find(v)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}