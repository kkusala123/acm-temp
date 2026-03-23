/*
 * 功能：归并排序，同时计算数组的逆序数
 * 时间复杂度：O(nlogn)，是求逆序数的最优算法之一
 * 逆序数定义：对于数组a，若i<j且a[i]>a[j]，则(i,j)为一个逆序对
 */
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
using ll=long long;

template<typename T>
class MergeSort {
public:
    ll inversion_count; // 逆序数
    vector<T> sorted_arr; // 排序后的数组

    // 重置逆序数
    void reset() {
        inversion_count = 0;
    }

    // 排序入口：a为数组，s为起始下标，e为结束下标（1-based）
    void sort(T* a, int s, int e) {
        sorted_arr.resize(e + 1);
        inversion_count = 0;
        merge_sort(a, s, e);
    }

private:
    // 核心归并排序函数
    void merge_sort(T* a, int s, int e) {
        if(s >= e) return;
        int mid = (s + e) >> 1;
        // 分治
        merge_sort(a, s, mid);
        merge_sort(a, mid+1, e);
        // 合并
        int i = s, j = mid + 1, k = s;
        while(i <= mid && j <= e) {
            if(a[i] <= a[j]) {
                sorted_arr[k++] = a[i++];
            } else {
                sorted_arr[k++] = a[j++];
                // 核心：左区间剩余的数都比a[j]大，逆序数增加
                inversion_count += mid - i + 1;
            }
        }
        // 处理剩余元素
        while(i <= mid) sorted_arr[k++] = a[i++];
        while(j <= e) sorted_arr[k++] = a[j++];
        // 复制回原数组
        for(int i=s; i<=e; ++i) {
            a[i] = sorted_arr[i];
        }
    }
};

int main() {
    int n;
    cin >> n;
    int* a = new int[n+1];
    FOR(i,1,n) cin >> a[i];

    MergeSort<int> ms;
    ms.sort(a, 1, n);

    cout << "逆序数：" << ms.inversion_count << endl;
    cout << "排序后的数组：";
    FOR(i,1,n) cout << ms.sorted_arr[i] << " ";

    delete[] a;
    return 0;
}