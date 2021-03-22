/*
* 有1克，2克，3克，5克，10克，20克的砝码，总重量小于1000克，求能组成不同重量的数量。
* 思路：用数组flag[1000]表示不同的重量，用整数编码表示取法码的数量。
*/
#include <iostream>
#include <cstdio>
using namespace std;

int flag[1005] = {0};
int main() { 
	int n1, n2, n3, n5, n10, n20;
	cin >> n1 >> n2 >> n3 >> n5 >> n10 >> n20;
	for (int i1 = 0; i1 <= n1; i1++) {
		for (int i2 = 0; i2 <= n2; i2++) {
			for (int i3 = 0; i3 <= n3; i3++) {
				for (int i5 = 0; i5 <= n5; i5++) {
					for (int i10 = 0; i10 <= n10; i10++) {
						for (int i20 = 0; i20 <= n20; i20++) {
							int sum = i1 * 1 + i2 * 2 + i3 * 3 + i5 * 5 + i10 * 10 + i20 * 20;
							flag[sum] = 1;
						}
					}
				}
			}
		}
	}
	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		if (flag[i] == 1) {
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
