#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
const int w = 100010;
int arr[w][20];
int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {

		int x, t; int b = -1;
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &x, &t);
			arr[t][x]++; b = max(b, t);
		}
		for (int i = b - 1; i >=1; --i) {    //��    //n��ʾ���������������b��ʾ����������ʱ�䣬����n��һ������b���ҿ��Ծ���һ�������������10000�������£������Ա���һb��Ϊѭ������
			for (int j = 0; j <= 10; ++j) {   //λ�� 
		if(j==0)
			arr[i][j] = max( arr[i + 1][j], arr[i + 1][j + 1]) + arr[i][j];
		if (j >= 1)
			arr[i][j] = max(max(arr[i + 1][j - 1], arr[i + 1][j]), arr[i + 1][j + 1]) + arr[i][j];

			}
		}
		printf("%d\n", max(max(arr[1][4], arr[1][5]), arr[1][6]));



	}
}