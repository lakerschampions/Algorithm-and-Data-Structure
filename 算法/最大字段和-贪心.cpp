/*
* 贪心：每次选择的都是局部最优解。
* 
* 每增加一个数a[i]，如果a[i]之前的最大子序列和大于0，那么a[i]<a[i]+s[i-1],
* 反之，a[i]>=a[i]+s[i-1]。
* 所以，我们上面求到的最优解就是以a[i]结尾的局部最优解，这道题求的是a[1]-a[n]所有子序列的全局最优解。
* 
* 步骤：
* 1.找到以a[i-1]久违的做大和s[i-1].
* 2.如果序列为负数，那么以a[i]结尾的最大序列就是a[i]本身，如果是正数，就是a[i]+s[i-1]。
* 3.max(s[i]|1<=i<=n)
* 
* 时间复杂度：O(n)
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int sum;
	cin >> n;
	cin >> sum;
	int maxx = sum;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		if (sum < 0) sum = 0;
		sum += x;
		maxx = max(sum, maxx);
	}
	cout << maxx << endl;
	return 0;
}
