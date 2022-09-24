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
		for (int i = b - 1; i >=1; --i) {    //秒    //n表示掉落饼的总数量，b表示最晚掉落饼的时间，但是n不一定大于b（我可以就落一个饼，且这个饼10000秒后才落下），所以必须一b作为循环限制
			for (int j = 0; j <= 10; ++j) {   //位置 
		if(j==0)  //0的时候左边没有数，需要特判
			arr[i][j] = max( arr[i + 1][j], arr[i + 1][j + 1]) + arr[i][j];
		if (j >= 1)   //n不用特判，因为他右边有也是0，我们要的是较大值
			arr[i][j] = max(max(arr[i + 1][j - 1], arr[i + 1][j]), arr[i + 1][j + 1]) + arr[i][j];

			}
		}
		printf("%d\n", max(max(arr[1][4], arr[1][5]), arr[1][6]));



	}
}
