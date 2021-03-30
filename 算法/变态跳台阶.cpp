/*
有N级台阶，每次可以向上跳最多K步，问到达第N级台阶总共有多少种不同方式。

分析：
f(n) = f(n-1) + f(n-2) + ... + f(n-k)

前k项: f(n) = 2 ^ (n-1)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int f[100005] = { 0 };
const int mod = 100003;
int main() {
	int n, k;
	cin >> n;
	cin >> k;
	f[1] = 1;
	for (int i = 2; i <= k; i++) {
		f[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			f[i] = (f[i] + f[j]) % mod;
		}
	}
	for (int i = k + 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			f[i] = (f[i] + f[i - j]) % mod;
		}
	}
	cout << f[n] << endl;
	return 0;
}
