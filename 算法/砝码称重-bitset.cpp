#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;

bitset<1005> f;
int main() {
	int n[7];
	int a[7] = { 0,1,2,3,5,10,20 };
	for (int i = 1; i <= 6; i++) {
		cin >> n[i];
	}
	f[0] = 1;
	for (int i = 1; i <= 6; i++) {
		for (int k = 1; k <= n[i]; k++) {
			f = f | f << a[i];
		}
	}

	cout << "Total=" << f.count()-1 << endl;
	return 0;
}
