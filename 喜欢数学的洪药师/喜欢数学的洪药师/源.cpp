#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int N = 100;
int a[N];

int head[N * N + 110];
int temp[N * N + 110];

                     //母函数
int main() {
	int n;
	while (cin >> n) {
		memset(temp, 0, sizeof(temp));
		memset(head, 0, sizeof(head));
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i]; sum += a[i];
		}
		head[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= sum; ++j) 
			{
				int a1 = j + a[i], a2 = abs(j - a[i]);
				temp[j] += head[j];   //只要上一组的head[j]有值，那么对其操作获得的数据都有值
				temp[a1] += head[j];            //思想，存储上一组数据的值，当前数据用临时变量来判定，只要他的源来自我上一组存储的head[j]，那么就可以获得值而不为0
				temp[a2] += head[j];

			}
			for (int j = 0; j <= sum; ++j)//每次循环一个数据a[i]，就临时变量的值存储到目标中，然后清空临时变量
			{
				head[j] = temp[j];
				temp[j] = 0;
			}
		}
		queue<int>q;
		for (int i = 1; i <= sum; ++i) {
			if (!head[i]) {
				q.push(i);
			}
		}

		if (!q.empty()) {
			cout << q.size() << endl;
			while (!q.empty()) {
				cout << q.front();
				if (q.size() == 1)cout << endl;
				else cout << " ";


				q.pop();
			}
		

		}
		else cout << 0 << endl;

	}

	


	return 0;
}


//洪熹林，曾经的数学爱好者，现在的药剂师，浙江省中医院的药剂师，同事们尊称其为“洪药师”。
//
//洪药师每天的任务就是帮病人的中药称重，貌似很乏味。但是，平凡的日子并不能阻止他那颗高贵的心。
//
//看着眼前的N个天平砝码，喜爱数学的洪药师冒出来一个问题：
//
//假设所有砝码的重量之和是S，那么在[1, S]的范围内，哪些重量是无法用天平称出来呢？
//Input
//输入包含多组测试用例。
//每组测试用例的第一行是一个正整数N(1 <= N <= 100)，表示有N个砝码。
//接下来一行是N个整数Ai(1 <= i <= N)，分别表示N个砝码的重量，1 <= Ai <= 100。
//Output
//对于每组测试数据，请首先输出不能称出的重量的个数，如果个数不为0，然后接下来一行请输出所有不能称的重量，数据空格隔开，升序排列。