/*
 * 功能：二分查找全模板，包含STL原生二分、C++20极简二分、手写二分适配
 * 适用：有序数组的查找、分界点查找、单调性问题求解
 */
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// C++20极简二分宏（来自jiangly）
// 功能：返回第一个使ck(v)为false的v，查找范围[l, r]
#define PP(r,l,CK) *ranges::partition_point(ranges::iota_view(l, r+1),CK)

// 手写通用二分模板（兼容C++11及以上，无C++20依赖）
// 功能：查找第一个使ck(x)为false的x，左闭右闭区间[l, r]
ll binary_search(ll l, ll r, function<bool(ll)> ck) {
    ll ans = r + 1;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        if(ck(mid)) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11, 13};
    int n = a.size();
    int v = 7;

    // ========== STL原生二分 ==========
    // 1. lower_bound：返回第一个 >= v 的元素迭代器
    auto low = lower_bound(a.begin(), a.end(), v);
    if(low != a.end()) {
        cout << "第一个大于等于" << v << "的元素下标：" << low - a.begin() << endl;
    }

    // 2. upper_bound：返回第一个 > v 的元素迭代器
    auto up = upper_bound(a.begin(), a.end(), v);
    if(up != a.end()) {
        cout << "第一个大于" << v << "的元素下标：" << up - a.begin() << endl;
    }

    // 3. 查找元素是否存在
    bool exist = binary_search(a.begin(), a.end(), v);
    cout << "元素是否存在：" << (exist ? "Yes" : "No") << endl;

    // ========== C++20 极简二分（需开启C++20） ==========
    // 示例：查找第一个大于5的数
    ll ans1 = PP(0, n-1, [&](int x) {
        return a[x] <= 5;
    });
    cout << "C++20二分结果：" << ans1 << endl;

    // ========== 手写通用二分 ==========
    // 示例：查找第一个大于5的数
    ll ans2 = binary_search(0, n-1, [&](ll x) {
        return a[x] <= 5;
    });
    cout << "手写二分结果：" << ans2 << endl;

    return 0;
}