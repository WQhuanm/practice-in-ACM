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
		stack<char>s;//ģ���ջ
		s.push('#');
		cin >> a >> b;
		int p1 = 0, p2 = 0, k = 0;//p1���aλ�ã�p2���b���飬k��ʾ�ڼ����ж�
		while (a[p1] != '\0') {
			book[++k] = 1; s.push(a[p1++]);//��ջ���������൱��in�����bookΪ1
			while (b[p2] == s.top())//p2ָ��ջ��
			{
				s.pop(); p2++; book[++k] = 0;//��ȥջ���͵���out�����bookΪ0
			}

		}
		if (s.top() != '#')cout << "No.\nFINISH" << endl;  //ջ����Ϊ��ʼֵ��˵����û��ȥ��
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