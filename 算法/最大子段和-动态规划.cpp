/*
以i结尾的最大连续子序列只存在两种情况：
1. 只包含a[i](s[i-1]<0)。
2. 包含a[i]和以i结尾的最大连续和序列。

以f[i]表示以i结尾的子序列的最大值。
f[i] = max(f[i-1]+a[i], a[i]) (2<=i<=n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int f[200005] = { 0 };
int main() {
	int n;
	cin >> n;
	cin >> f[1];
	int maxx = f[1];
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		f[i] = max(f[i - 1] + x, x);
		maxx = max(f[i], maxx);
	}
	cout << maxx << endl;
	return 0;
}
