#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

                //Ҫʹ��������󻯣�ÿ��ֻҪ i ����˾ j ̨�����������
             //�� i ����˾ j ̨�����������Ҳ����Ҫ i - 1 ����˾�� z ̨����������� + �� i ����˾�� j - z ̨��������������������Ƶ�һ��Ϳ��ԡ�






int dp[110][110];
int arr[110][110];
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		for (int i = 1; i <= n; ++i) {    //��i�ҹ�˾
			for (int j = 1; j <= m; ++j) {    //������i��������j��1��ʼ�����ٸ���һ��
				for (int z = 0; z <= j; ++z) {    //��ʾǰi-1����˾��������z��������z�Ǵ�0��ʼ�ģ���Ϊǰi-1����˾�ǿ��Բ������
					dp[i][j ] = max(dp[i][j], dp[i - 1][z]+arr[i][j-z]);   //ɸ������dp[i][j]			}
			}
		}
		printf("%d\n", dp[n][m]);
	}
	return 0;
}