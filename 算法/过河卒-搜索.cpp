/*
A点有个过河卒，可以向下或者向右，C点有个马，马走日。棋盘用坐标表示，A(0,0),B(n,m)。卒不能碰到马控制的点。
输入四个整数，表示B点坐标和马的坐标。

递归：
终止条件：起点或马的控制条件
递推表达式：f[i][j] = f[i-1][j] + f[i][j-1]
*/


#include <iostream>
#include <cstring>
using namespace std;
int hx[9] = { 0,-2,-1,1,2,2,1,-1,-2 };
int hy[9] = { 0,1,2,2,1,-1,-2,-2,-1 };
long long f[25][25];
long long find(int x,int y) {
	if (f[x][y] != -1) return f[x][y];
	else return f[x][y] = find(x - 1, y) + find(x, y - 1);
}

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
	cout << find(bx, by) << endl;
	return 0;
}
