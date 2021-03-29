/*
1,1,2,3,5,8......

递推问题的一般步骤：
1.建立递推关系式：F(n)=F(n-1)+F(n-2)
2.确定边界条件：f(1)=f(2)=1，循环从3开始。

*/

#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	int n;
	int a, b, c;
	cin >> n;
	c = a = b = 1;
	for (int i = 3; i <= n; i++) {
		c = (b + a) % mod;
		a = b;
		b = c;
	}
	cout << c << endl;
	return 0;
}
