#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;

                    



const int N = 20;

char arr[N][N];
int book[N][N];

int way[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int flag;
int n, m, t;				
int b1, b2;
void dfs(int x,int y,int time) {
	if (x == b1 && y == b2 && time == t) {
		flag = 1; return;
	}
	if (x<1 || x>n || y<1 || y>m)return;   //进来的坐标不符合就先去，不用后面再去（但是后面去除的不能删
	int pot1 = abs(x - b1) + abs(y - b2);
	if (time >= t || flag == 1)return;//时间可以剪枝，时间过了你就出不去，不用跑了    //但找到后快速退出递归的方法，只有flag为0才执行下面，不然一直跳
		for (int i = 0; i <= 3; ++i) {   
			int tx = x + way[i][0];int ty = y + way[i][1];  //注意，四种走法起点相同，所以不可以改变x，y，只能改变tx，ty这临时变量，因为一个x，y要用4次，值不能变
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !book[tx][ty]&& arr[tx][ty] != 'X') {//障碍物不用专门book标记，判断时来个不等于就好，节省时间
				book[tx][ty] = 1;
				dfs(tx, ty, time+1);  //time+1可以，++time不行，你必须返回时time也返回原来的值，不能一直增加
				book[tx][ty] = 0;
			}
		}
	
}


int main() {
	while (~scanf("%d%d%d", &n, &m, &t) && (n || m || t)) {
		memset(book, 0, sizeof(book));
		int a1 = 0, a2 = 0; int wall = 0;
		for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'S') {a1 = i; a2 = j;}
			if (arr[i][j] == 'D') { b1 = i; b2 = j; }
			if (arr[i][j] == 'X') wall++;
		}
		flag = 0;
		book[a1][a2] = 1;//起点记得封，不能回到起点
		if (t < abs(b1 - a1) + abs(b2 - a2))goto abc;//走的时间不够最短的曼哈顿距离，剪枝
		if (t >= n * m - wall)goto abc;//走的时间比可以走的距离大，剪枝
		if (((b1 + b2)%2 ^ (a1 + a2)%2) ^ (t % 2)) goto abc;  //奇偶性剪枝，如果起点坐标和与终点坐标和奇偶性不同，就应该走奇数步，同走偶数步，不符合直接剪枝

		dfs(a1,a2,0);
		if (flag)printf("YES\n");
		 
		else abc: printf("NO\n");

	}
	return 0;
}



//
//张晨乐在一个古老的迷宫中发现了一个手机，这个手机深深地吸引了他。
//
//然而，当他拾起手机，迷宫开始摇晃，张晨乐能感觉到地面下沉。他意识到：这个手机只是一个诱饵！于是，他不顾一切地试图冲出这个迷宫。
//
//迷宫是一个大小为N* M的矩形，有一扇门，一开始，门是关闭的，并在第T秒打开一瞬间（小于1秒的时间）。因此，张晨乐必须刚好在第T秒钟到达门口。
//每一秒，他都可以向上，下，左，右四个相邻的位置中的任意一个移动。一旦他进入一个新的地方，这个地方的地面就会开始下沉，并在下一秒消失。因此，他不能在一个地方停留超过一秒钟，也不能再进入曾经走过的地方。
//
//请问，可怜的张晨乐能够逃出迷宫吗？
//Input
//输入由多个测试用例组成。
//每个测试用例的第一行包含三个整数N，M和T（1 < N，M < 7; 0 < T < 50），分别表示迷宫的大小和门打开的时间。
//	接下来的N行给出迷宫布局，每行包含M个字符。
//
//	每个字符含义如下：
//
//	'X'：不能进入的墙
//	'S'：起点
//	'D'：门
//	'.'：可以行走的地方
//
//	输入以三个0结束，这个测试用例不被处理。
