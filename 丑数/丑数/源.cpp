#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long dp[6000] = { 0 };

           //��������1��ʼ����������֮�䶼��2��3��5��7�ı�����ϵ������ÿ��������ʵ����ǰ��ĳһ������2��3��5��7�����������n��������
            //��ô��Ҫ��֤���ظ��������ǰ�������洢�ġ�
int main() {
         int n2 = 1, n3 = 1, n5 = 1, n7 = 1,x=1;
        dp[1] = 1; int a = 0;
        while (x < 6000) {
            a = min(dp[n2] * 2, min(dp[n3] * 3, min(dp[n5] * 5, dp[n7] * 7)));
            if (a == dp[n2] * 2)n2++;  //n2��3��5��7���Էֿ���ʹ���Ƕ��Ǵӵ�һ��������ʼ�������ӣ�ÿʹ�ù�һ�Σ��Լ���nx�ͼ�һ�£���ʾ�´λ�����һ������ȡ�˻�
            if (a == dp[n3] * 3)n3++;
            if (a == dp[n5] * 5)n5++;
            if (a == dp[n7] * 7)n7++;
            x++;   //��ʱx������һ���ģ�Ҫ�ȼ����ٸ�ֵ
            dp[x] = a;   //n��ŵ�n������
            
        }
        int n;
        while (scanf("%d", &n) == 1 && n) {
            printf("%lld\n", dp[n]);
        }
    
    return 0;
}










//                //����dp[x]Ϊǰ������֣�yΪ2��3��5��ĳһ�����˵Ľ��Ϊdp[i]=dp[x]*y����ô������dp[i]��Ҫ�������dp[i-1]ͬʱ������С
//           //���Ӷ�ΪO��n*n���ᳬʱ
//
//long long dp[6000] = { 0 };
//int main() {
//	int n;
//	while (scanf("%d", &n) == 1 && n) {
//		memset(dp, 0, sizeof(dp));
//		dp[1] = 1;
//		for (int i = 2; i <= n; ++i) {   //i��ʾ��i������
//			for (int j = i - 1; j >= 1; --j) {   //j��i-1��ʼ������i����������һ���������ݼ�������ʹ��i������������С
//				if (dp[j] * 2 > dp[i - 1])dp[i] = dp[j] * 2;    //*2��������С�ĳ˷��������ʼ��dii����˵��ͨ���������Ų���j��С����ȡ��С�ĵ�i������
//				if (dp[j] * 3 > dp[i - 1])dp[i] = min(dp[i], dp[j] * 3);
//				if (dp[j] *5 > dp[i - 1])dp[i] = min(dp[i], dp[j] * 5);
//				if (dp[j] * 7 > dp[i - 1])dp[i] = min(dp[i], dp[j] * 7);
//				else
//					break;   //���Ѿ���Сʱ����û�б�Ҫ�����������õ�ѭ����
//			}
//		}
//		printf("%lld\n", dp[n]);
//	}
//
//
//	return 0;
//}