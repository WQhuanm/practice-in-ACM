#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 20;
int n;
int book[N];
int arr[N];   //表示第几位上的数字
void dfs(int x) {
	if (x == n+1) {   //把n位全部存完，那我就一位一位打印
		for (int i = 1; i <= n; ++i)	
			printf("%d ", arr[i]);    //使用搜索，一定不要用cout或者cin，极可能超时
		printf("\n");
		return;
	}
	else {
		for (int i = 1; i <= n; ++i) {   //按照字典序，那么这样顺序保证最小
			if (!book[i]) {    //采用递归，只要前面没用过，我就拿，一直贪心最小
				book[i] = 1;
				arr[x] = i;
				dfs(x + 1);
				book[i] = 0;
			}
		}
	}

}


int main() {
	
	while (~scanf("%d",&n)) {
		dfs(1);
	}
	return 0;
}