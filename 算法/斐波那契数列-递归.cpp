/*

递归的注意点：
终止条件：n=2和n=1
表达式： f[i]=f[i-1]+f[i-2]

记忆化递归：把已经计算的中间状态保存下来。
*/

#include <iostream>
#include "string.h"

using namespace std;
const int mod = 1000000007;
int cache[200000];
int find(int n) {
	if (cache[n] != -1) return cache[n];
	else {
		return cache[n] = (find(n - 1) + find(n - 2)) % mod;
	}

}

int main() {
	int n;
	cin >> n;
	memset(cache, -1, sizeof(cache));
	cache[2] = cache[1] = 1;
	cout << find(n) << endl;
	return 0;
}
