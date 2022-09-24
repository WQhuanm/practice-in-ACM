#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
const int w = 1000000000;

                      //假设k=1,n=5.即从5个物品中拿出1对。
//那么shifts[1][5] = shifts[1][4]和(a[5] - a[4]) ^ 2中最小的一个。即前四个{ 1,2,3,4 }中最小的一对或者最后一对。
//假设k = 2, n = 5.即从5个物品中拿出2对。
//那么shifts[2][5] = shifts[2][4]和shifts[1][3] + (a[4] - a[3]) ^ 2中最小的一个。即前四个{ 1,2,3,4 }中最小的两对或者前三个中最小的一对加最后一对。
//……假设k = j, n = i.即从i个物品中拿出j对。
//那么shifts[j][i] = shifts[j][i - 1]和shifts[j - 1][i - 2] + (a[i] - a[i - 1]) ^ 2中最小的一个。
//即前i - 1个{ 1,2,…,i - 1 }中最小的j对或者前i - 2个中最小的j - 1对加最后一对。
// 则状态转移方程为：
//shifts[j][i] = min(shifts[j][i - 1], shifts[j - 1][i - 2] + (a[i] - a[i - 1]) ^ 2);

bool cmp(int x, int y) {
    return x < y;
}
int dp[2010][1010] = { 0 };
int wet[2010] = { 0 };
int main() {
    int n, k;
  
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 1; i <= n; ++i)scanf("%d", &wet[i]);  //输入
        sort(wet + 1, wet + 1 + n, cmp);      //从小到大排序重量
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {                  //j==0的不用初始化，为0，因为没搬无消耗，其余全部极大值
                dp[i][j] = w;   //都初始化为极大值，保证开始min一定有用

            }
        }
        for (int i = 2; i <= n; ++i) {   //i从2开始，因为每俩为一组
            for (int j = 1; j * 2 <= i; ++j)   //为了组队，j必须小于等于i/2
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (wet[i] - wet[i - 1])* (wet[i] - wet[i - 1]));// 保证每次都是最小的最优解
            }
        }
        printf("%d\n", dp[n][k]);

    }
    return 0;
}







