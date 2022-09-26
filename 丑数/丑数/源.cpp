#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
long long dp[6000] = { 0 };

           //丑数，从1开始，各个丑数之间都是2、3、5、7的倍数关系，所以每个丑数其实都是前面某一个丑数2或3或5或7倍，我们求第n个丑数，
            //那么就要保证不重复，并且是按照升序存储的。
int main() {
         int n2 = 1, n3 = 1, n5 = 1, n7 = 1,x=1;
        dp[1] = 1; int a = 0;
        while (x < 6000) {
            a = min(dp[n2] * 2, min(dp[n3] * 3, min(dp[n5] * 5, dp[n7] * 7)));
            if (a == dp[n2] * 2)n2++;  //n2，3，5，7各自分开，使他们都是从第一个丑数开始迭代增加，每使用过一次，自己的nx就加一下，表示下次会用下一个丑数取乘积
            if (a == dp[n3] * 3)n3++;
            if (a == dp[n5] * 5)n5++;
            if (a == dp[n7] * 7)n7++;
            x++;   //此时x还是上一个的，要先加了再赋值
            dp[x] = a;   //n存放第n个丑数
            
        }
        int n;
        while (scanf("%d", &n) == 1 && n) {
            printf("%lld\n", dp[n]);
        }
    
    return 0;
}










//                //假设dp[x]为前面的数字，y为2、3、5中某一个，乘的结果为dp[i]=dp[x]*y，那么这个结果dp[i]需要满足大于dp[i-1]同时尽可能小
//           //复杂度为O（n*n）会超时
//
//long long dp[6000] = { 0 };
//int main() {
//	int n;
//	while (scanf("%d", &n) == 1 && n) {
//		memset(dp, 0, sizeof(dp));
//		dp[1] = 1;
//		for (int i = 2; i <= n; ++i) {   //i表示第i个丑数
//			for (int j = i - 1; j >= 1; --j) {   //j从i-1开始，即第i个丑数的上一个，这样递减，不断使第i个丑数无限缩小
//				if (dp[j] * 2 > dp[i - 1])dp[i] = dp[j] * 2;    //*2决定是最小的乘法，对于最开始的dii个来说，通过他，接着不断j变小，获取更小的第i个丑数
//				if (dp[j] * 3 > dp[i - 1])dp[i] = min(dp[i], dp[j] * 3);
//				if (dp[j] *5 > dp[i - 1])dp[i] = min(dp[i], dp[j] * 5);
//				if (dp[j] * 7 > dp[i - 1])dp[i] = min(dp[i], dp[j] * 7);
//				else
//					break;   //当已经最小时，就没有必要继续进行无用的循环了
//			}
//		}
//		printf("%lld\n", dp[n]);
//	}
//
//
//	return 0;
//}