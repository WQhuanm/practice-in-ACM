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
	if (a[x])return a[x];         //���ƣ��Ѵ�ͼ��һ���߸�����Сͼ��Сͼ�δ�Сǰ���Ѿ�����
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
//���Ǹ����ϵ�С��Ϸ��
//
//�����ڵ��ϰ���˳ʱ�뷽������д��2n������1, 2, 3, 4...2nΧ��һ��Բ��Ȼ����n��ֱ��������2n�����֣�ÿ�����ֶ���һ���������������ҽ�����һ������������Ҫ�����е����߶������н��㡣
//
//�����һ���ж����ֲ�ͬ�����߷�ʽ��
//
//���磬��n����2ʱ������һ����4�����֣���2�ֲ�ͬ�����߷�ʽ��
//Input
//��������������������
//
//ÿ���������ݰ���һ��������n�� & #160; 1 <= n <= 35�����������һ�е� - 1������ʾ�������ݵĽ�����
//Output
//����ÿ���������ݵ�n�������2n�����ֵĲ�ͬ�����߷�ʽ��Ŀ��
//
//ÿ���������һ�С�
//Sample Input