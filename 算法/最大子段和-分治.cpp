/*
* 题目描述：
* 给出一个长度为n的序列a，选出其中连续且非空的一段使和最大。
* 
* 输入格式：
* 第一行是一个整数，序列长度n。
* 第二行有n个整数。
* 
* 枚举优化：
* 可以用s[i]表示第一个数到第i个数的和，那么s[i-j]=s[j]-s[i]+a[i]。
* 
* 分治：
* 假定a序列对应的区间[l,r]，中间位置为mid，最大和的子序列为[i,j]，最大连续子序列的位置只有三种可能：
* 1.完全处于左半：l<=i<=j<=mid
* 2.跨越中间：i<=mid<=j<=r
* 3.完全处于右半：mid<i<=j<=r
* 
* 第一种和第三章用递归。
* 第二种情况就是求出以mid结尾的最大值maxx1和以mid开头的最大值maxx2，则最大值就是maxx1+maxx2-mid。
* 
* 
* https://www.luogu.com.cn/problem/P1115
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[200005];

int find(int l, int r) {
	if (l == r) return a[l];
	int mid = (l + r) / 2;
    //第二种
	int maxx1 = -0x7fffffff;
	int sum1 = 0;
	int maxx2 = -0x7fffffff;
	int sum2 = 0;
	for (int k = mid; k >= 1; k--) {
		sum1 += a[k];
		maxx1 = max(sum1, maxx1);
	}
	for (int k = mid; k <= r; k++) {
		sum2 += a[k];
		maxx2 = max(sum2, maxx2);
	}
	return max(max(find(l, mid), find(mid + 1, r)), maxx1 + maxx2 - a[mid]);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << find(1, n) << endl;
	return 0;
} 
