#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
                                 //哈希表（hash）
const int N = 1e6;
                                  
ll zhen[N + 100];   //把表达式分为俩半，统计各自可能得到的值，因为4个一起必定超时
ll fu[N + 100];  //正数一个数组，负数一个数组

int main() {
	ll a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		
		if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))cout << 0 << endl;
		else {
			memset(zhen, 0, sizeof(zhen));
			memset(fu,0, sizeof(fu));
			for (int i = 1; i <= 100; ++i)for (int j = 1; j <= 100; ++j) {
				ll x = i * i * a + b * j * j; //获得a*x12 + b*x22的可能值，累加数组中，重复出现就会加加
				if (x >= 0)zhen[x]++;//正数放正数组
				else fu[-x]++;//负数，填个负号放负数数组
			}
			ll ans = 0;  //开始统计
			for (int i = 1; i <= 100; ++i)for (int j = 1; j <= 100; ++j) {
				ll y = i * i * c + j * j * d;//获得c*x32 + d*x42的可能值
				if (y <= 0)ans += zhen[-y];//注意，是相反数，即让x+y==0，所以y为负数，比较的是正数组，-y==x时，匹配，加一次，表示1*这个数已有情况的乘积
				else ans += fu[y];//比较负数组，y是正的，不用添负号，负号是给上一组的负数添变为正的

			}
			cout << ans * 16 << endl;//++--4个组合共有16种

		}


	}

	return 0;
}






