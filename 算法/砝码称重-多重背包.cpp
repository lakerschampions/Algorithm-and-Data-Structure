#include <iostream>
#include <cstdio>
using namespace std;

int f[1005] = { 0 };
int main() {
	int n[7];
	int a[7] = { 0,1,2,3,5,10,20 };
	for (int i = 1; i <= 6; i++) {
		cin >> n[i];
	}
    f[0] = 1;
	for (int i = 1; i <= 6; i++) {
		for (int k = 1; k <= n[i]; k++) {
			for (int j = 1000; j >= a[i]; j--) {
				f[j] = f[j] + f[j - a[i]];
			}
		}
	}

	int count = 0;
	for (int i = 1; i <= 1000; i++) {
		if (f[i]) count++;
	}
	cout << "Total=" << count << endl;
	return 0;
}
