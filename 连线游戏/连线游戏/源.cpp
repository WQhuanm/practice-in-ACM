#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;


const int N = 40;

ll a[N];

ll dfs(int x) {
	if (a[x])return a[x];         //递推，把大图像一条线隔成俩小图像，小图形大小前面已经求了
	int tx = x;
	while (tx>1) {
		if (tx == x)
		{
			a[x] += 2*dfs(tx - 1); tx--;
		}
		else {
			a[x] += dfs(tx - 1) * dfs(x - tx); tx--;    
		}
			
	}

	return a[x];
}


int main() {
	ll n;
	a[0] = 1; a[1] = 1; a[2] = 2;
	dfs(35);
	while (cin >> n && n != -1) {

		cout << a[n] << endl;

	}

	return 0;
}


//
//Problem Description
//这是个古老的小游戏。
//
//假设在地上按照顺时针方向依次写下2n个数字1, 2, 3, 4...2n围成一个圆，然后用n条直线连接这2n个数字，每个数字都和一个数字相连，并且仅仅和一个数字相连。要求所有的连线都不能有交点。
//
//请计算一共有多少种不同的连线方式。
//
//比如，当n等于2时，地上一共有4个数字，有2种不同的连线方式。
//Input
//输入包含多组测试用例。
//
//每行输入数据包含一个正整数n（ & #160; 1 <= n <= 35），除了最后一行的 - 1，它表示输入数据的结束。
//Output
//对于每组输入数据的n，请计算2n个数字的不同的连线方式数目。
//
//每组数据输出一行。
//Sample Input