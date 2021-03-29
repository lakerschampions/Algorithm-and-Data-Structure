/*
[f(n)         [1 1  n-2      [1
 f(n-1)]  =    1 0]       *   1]
 */

#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1000000007;

struct Matrix {
	int row, column;
	long long v[3][3];
	Matrix() {
		memset(v, 0, sizeof(v));
	}
};

Matrix multiply(Matrix a, Matrix b) {
	Matrix ans;
	ans.row = a.row;
	ans.column = b.column;
	for (int i = 1; i <= a.row; i++) {
		for (int j = 1; j <= b.column; j++) {
			for (int k = 1; k <= a.column; k++) {
				ans.v[i][j] += (a.v[i][k] * b.v[k][j]) % mod;
				ans.v[i][j] %= mod;
			}
		}
	}
	return ans;
}

Matrix pow(Matrix a, long long n) {
	Matrix ans, base = a;
	ans.row = 2; ans.column = 2;
	ans.v[1][1] = ans.v[2][2] = 1;
	while (n) {
		if (n % 2 == 1) ans = multiply(ans, base);
		base = multiply(base, base);
		n /= 2;
	}
	return ans;
}

int main() {
	long long n;
	cin >> n;
	Matrix ans, base, last;
	base.row = 2;
	base.column = 2;
	base.v[1][1] = base.v[1][2] = base.v[2][1] = 1;
	last.row = 2; last.column = 2;
	last.v[1][1] = last.v[2][1] = 1;
	if (n == 1 || n == 2) {
		cout << 1 << endl;
	}
	else {
		ans = pow(base, n - 2);
		ans = multiply(ans, last);
		cout << ans.v[1][1] << endl;
	}
	return 0;
}
