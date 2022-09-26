#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char x[1100]; char y[1100];
int dp[1100][1100];

int main() {
	while (scanf("%s %s", x, y) == 2) {
		memset(dp, 0, sizeof(dp));
		int len1 = strlen(x); int len2 = strlen(y);
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {                  //����ǰn-1������ģ�����n�������������һ��Xn==Ym�������ͳ��ȼ�һ��Ҫô���ȣ���ôfn������ǰһ��һ����
				if (x[i - 1] == y[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;   //��ôҪô��ΪXn-1Ym������У�Ҫô��XnYm-1��
				else    //��Ϊx[]��y[]���Ǵ��±�0��ʼ����i��1��ʼ�����Լ�һ������ͳ�Ƴ���dp��1��ʼ�����Բ���
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		printf("%d\n", dp[len1][len2]);

}



	return 0;
}