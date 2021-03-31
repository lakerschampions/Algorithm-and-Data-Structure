#include <iostream>
#include <cstring>
using namespace std;
int hx[9] = { 0,-2,-1,1,2,2,1,-1,-2 };
int hy[9] = { 0,1,2,2,1,-1,-2,-2,-1 };
long long f[25][25];

int main() {
	int bx, by, mx, my;
	cin >> bx >> by >> mx >> my;
	bx += 2; by += 2; mx += 2; my += 2;
	memset(f, -1, sizeof(f));
	f[2][2] = 1;

	for (int i = 1; i <= bx; i++) f[i][1] = 0;
	for (int i = 1; i <= by; i++) f[1][i] = 0;
	for (int i = 0; i <= 8; i++) {
		f[mx + hx[i]][my + hy[i]] = 0;
	}

	for (int i = 2; i <= bx; i++) {
		for (int j = 2; j <= by; j++) {
			if (f[i][j] == -1) {
				f[i][j] = f[i - 1][j] + f[i][j - 1];
			}
		}
	}
	cout << f[bx][by] << endl;
	return 0;
}
