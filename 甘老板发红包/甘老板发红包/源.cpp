#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;

const int N = 10010;

int n, m;
int indegree[N];   //不知道最大值是多少，但是知道最小值，所以我们统计以最小为头的入度，最小值入度为0，当indegree[x]为0，说明没有比他小的值，入度为0
vector<int>v[N];//建立一个一维是长度为N，二维是动态变换的容器，减少不必要空间浪费
int ans[N];//记录每个数应多少钱
void tuopu() {
	int x, y;
	for (int i = 1; i <= m; ++i) {
		cin >> x >> y;//x是大值，y是小值
		v[y].push_back(x);//存入比y大的x
		indegree[x]++;//表示比x小的值
	}
	int sum = 0;//标记有多少个入度为0，如果能有结果，那么最终肯定所有都会入度为0，不会证明不成立
	for (int i = 1; i <= n; ++i) {  //最多遍历n个
		int t = 0;//暂时储存小值
		for (int j = 1; j <= n; ++j) {
			if (!indegree[j]) {
				sum++;
				t = j;
				indegree[j] = -1;//防止重复统计到他
				break;
			}
		}
		for (int j = 0; j < v[t].size(); ++j)//v[t].size()表示t这一行有多少元素，但是下标从0开始，所有j=0开始，然后是<就好
		{
			int temp = v[t].at(j);//用temp暂时储存数组中已经存的比t大的值
			indegree[temp]--;//减去了t这个比temp小的
			ans[temp] = max(ans[temp], ans[t] + 1);//temp的钱至少比t的钱大一元
		}
	}
	if (sum == n) {
		int h = 0;//把各个数的值总和
		for (int i = 1; i <= n; ++i) {
			h += ans[i];
		}
		cout << h + n * 888 << endl;

	}
	else cout << -1 << endl;
}


int main() {
	while (cin >> n >> m) {
		memset(indegree, 0, sizeof(indegree));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i <= n; ++i)v[i].clear();   //清空容器，只能一行一行清
		tuopu();
	}

	return 0;
}

//甘晨煜是一家软件公司的创始人，人称“甘老板”。
//
//经过几年的努力，公司已经准备在纳斯达克上市，甘老板自然也是心情大好。随着中秋节的临近，甘老板决定为员工们每人发个红包。
//
//现在的问题是，每人发多少红包呢？要知道，很多员工提出了自己的要求，比如，胡承轩就提出他的红包应该比麻致远的大！
//
//为了图吉利，甘老板决定为每名员工至少发888的红包，同时，他还希望能满足员工们提出的所有的要求，当然，最后是希望发出红包的总金额最少。
//Input
//输入包含多组测试数据。
//每组数据第一行首先是两个整数n和m，分别表示员工的人数是n，员工们一共提出了m条要求。
//接着的m行，每行包含2个整数a和b，表示一条要求：a的红包应该比b的大。
//
//n <= 10000
//m <= 20000
//员工编号a和b不等，且都在区间[1, n]内