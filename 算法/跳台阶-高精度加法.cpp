/*
有N级台阶，每次可以向上跳一步或者两步，问到达第N级台阶总共有多少种不同方式。

分析：
第n级台阶由第n-2级走两步或者n-1走一步。
f(n) = f(n-1) + f(n-2)

*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct BigNum {
	int length = 0;
	int v[5000];
	BigNum() {
		memset(v, 0, sizeof(v));
	}
};

BigNum add(BigNum a, BigNum b) {
	BigNum ans;
	ans.length = (max(a.length, b.length));
	for (int i = 0; i < ans.length; i++) {
		ans.v[i] = a.v[i] + b.v[i];
	}
	for (int i = 0; i < ans.length; i++) {
		if (ans.v[i] / 10) {
			ans.v[i + 1] += ans.v[i] / 10;
			ans.v[i] %= 10;
		}
	}
	if (ans.v[ans.length]) ans.length++;
	return ans;
} 

int main() {
	int n;
	BigNum a, b, c;
	cin >> n;
	a.length = 1;
	b.length = 1;
	a.v[0] = 1;
	b.v[0] = 2;
	for (int i = 3; i <= n; i++) {
		c = add(b, a);
		a = b;
		b = c;
	}
	if (n == 0) cout << 0 << endl;
	else if (n == 1) cout << 1 << endl;
	else if (n == 2) cout << 2 << endl;
	else {
		for (int i = c.length - 1; i >= 0; i--) {
			cout << c.v[i];
		}
		cout << endl;
	}
	return 0;
}
