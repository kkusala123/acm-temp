/*
 * 功能：用小顶堆维护数据流中的前k大元素，大顶堆维护前k小元素
 * 时间复杂度：插入元素O(logk)，获取结果O(klogk)
 * 优势：无需存储全部数据，空间复杂度O(k)，适合大数据流场景
 */
#include<bits/stdc++.h>
using namespace std;

// 维护前k大元素的桶
template<typename T>
struct TopKBucket {
    int k;
    // 小顶堆：堆顶是前k大中的最小值
    priority_queue<T, vector<T>, greater<T>> q;

    TopKBucket(int k_) : k(k_) {}

    // 插入元素
    void push(T x) {
        if(q.size() >= k) {
            // 比堆顶大，替换堆顶
            if(q.top() < x) {
                q.pop();
                q.push(x);
            }
        } else {
            q.push(x);
        }
    }

    // 获取前k大元素，降序排列
    vector<T> get() {
        vector<T> res;
        while(!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 维护前k小元素的桶
template<typename T>
struct BottomKBucket {
    int k;
    // 大顶堆：堆顶是前k小中的最大值
    priority_queue<T, vector<T>, less<T>> q;

    BottomKBucket(int k_) : k(k_) {}

    void push(T x) {
        if(q.size() >= k) {
            if(q.top() > x) {
                q.pop();
                q.push(x);
            }
        } else {
            q.push(x);
        }
    }

    vector<T> get() {
        vector<T> res;
        while(!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    TopKBucket<int> topk(k);
    BottomKBucket<int> bottomk(k);

    for(int i=0; i<n; ++i) {
        int x;
        cin >> x;
        topk.push(x);
        bottomk.push(x);
    }

    vector<int> topk_res = topk.get();
    cout << "前" << k << "大元素：";
    for(int x : topk_res) cout << x << " ";
    cout << endl;

    vector<int> bottomk_res = bottomk.get();
    cout << "前" << k << "小元素：";
    for(int x : bottomk_res) cout << x << " ";

    return 0;
}