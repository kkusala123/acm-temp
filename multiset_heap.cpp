/*
 * 功能：基于multiset实现大顶堆/小顶堆，支持O(logn)插入、删除、查询极值
 * 优势：相比priority_queue，支持任意元素的快速查找与删除，无需自定义结构体
 */
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
using ll=long long;

int main() {
    // 大顶堆：降序排列，begin()指向最大值
    multiset<ll,greater<ll>> max_heap;
    // 小顶堆：升序排列，begin()指向最小值
    multiset<ll,less<ll>> min_heap;

    // ========== 常用操作 ==========
    // 1. 插入元素，自动排序
    max_heap.insert(123);
    max_heap.insert(456);
    min_heap.insert(789);

    // 2. 获取堆顶元素（极值）
    ll max_val = *max_heap.begin(); // 大顶堆最大值
    ll min_val = *min_heap.begin(); // 小顶堆最小值

    // 3. 判断元素是否存在
    ll target = 123;
    if(max_heap.find(target) != max_heap.end()) {
        cout << "元素存在" << endl;
    }

    // 4. 统计元素出现次数
    int cnt = max_heap.count(target);

    // 5. 删除指定元素（必须先判断存在，否则会RE）
    if(max_heap.find(target) != max_heap.end()) {
        max_heap.erase(max_heap.find(target)); // 只删除一个匹配元素
        // max_heap.erase(target); // 会删除所有匹配的元素，慎用
    }

    // 6. 其他常用属性
    int size = max_heap.size(); // 堆大小
    bool is_empty = max_heap.empty(); // 是否为空

    return 0;
}