#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
const int N = 20;
int n;
int book[N];
int arr[N];   //��ʾ�ڼ�λ�ϵ�����
void dfs(int x) {
	if (x == n+1) {   //��nλȫ�����꣬���Ҿ�һλһλ��ӡ
		for (int i = 1; i <= n; ++i)	
			printf("%d ", arr[i]);    //ʹ��������һ����Ҫ��cout����cin�������ܳ�ʱ
		printf("\n");
		return;
	}
	else {
		for (int i = 1; i <= n; ++i) {   //�����ֵ�����ô����˳��֤��С
			if (!book[i]) {    //���õݹ飬ֻҪǰ��û�ù����Ҿ��ã�һֱ̰����С
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