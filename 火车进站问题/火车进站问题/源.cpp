#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#define ll long long
using namespace std;

const int N = 100;
char a[N];
char b[N];
int book[N];
int main() {
	int n;
	while (cin >> n) {
		stack<char>s;//模拟堆栈
		s.push('#');
		cin >> a >> b;
		int p1 = 0, p2 = 0, k = 0;//p1标记a位置，p2标记b数组，k表示第几个判定
		while (a[p1] != '\0') {
			book[++k] = 1; s.push(a[p1++]);//放栈顶，放入相当于in，标记book为1
			while (b[p2] == s.top())//p2指向栈顶
			{
				s.pop(); p2++; book[++k] = 0;//撤去栈顶就等于out，标记book为0
			}

		}
		if (s.top() != '#')cout << "No.\nFINISH" << endl;  //栈顶不为初始值就说明有没出去的
		else {
			cout << "Yes." << endl;
			for (int i = 1; i <= k; ++i) {
				if (book[i])cout << "in" << endl;
				else cout << "out" << endl;
			}
			cout << "FINISH" << endl;
		}
	}
	return 0;
}