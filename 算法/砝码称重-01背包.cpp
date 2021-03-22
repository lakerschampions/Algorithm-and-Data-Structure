/*
* 直接用重量来表示数据，比如1 1 0 0 0 0的输入，就是1 2。
* 用f[i][j]表示前i件物品中总重量为j的方案是否存在。
* 当第i件物品不取的时候，如果f[i-1][j]存在，f[i][j] = 1,
* 当第i件物品取的时候，如果f[i-1][j-w[i]]存在，f[i][j] = 1,
* f[i][j] = f[i-1][j] || f[i-1][j-w[i]]
* 
* 初始状态：f[k][0] = 1
* 终止状态：f[num][1000]
*/
#include <iostream>
#include <cstdio>
using namespace std;

int f[1005][1005] = { 0 };
int main() {
	int num = 0; //总个数
	int w[1005]; //新序列
	int a[7] = { 0,1,2,3,5,10,20 };
	for (int i = 1; i <= 6; i++) {
		int x; cin >> x;
		for (int j = 1; j <= x; j++) w[++num] = a[i];
	}
	for (int i = 0; i <= 1000; i++) f[i][0] = 1;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= 1000; j++) {
			if (j - w[i] >= 0) {
				f[i][j] = f[i - 1][j] + f[i - 1][j - w[i]];
			}
			else {
				f[i][j] = f[i - 1][j];
			}
			
		}
	}
	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		if (f[num][i]) count++;
	}
	cout << "Total=" << count << endl;
	return 0;
}
