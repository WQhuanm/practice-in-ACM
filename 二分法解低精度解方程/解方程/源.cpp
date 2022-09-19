#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<math.h>
double mi(double x) {
	return  8 *pow(x,4.0)+ 7*pow(x,3.0) + 2*pow(x,2.0) + 3 * x + 6;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		double y;
		scanf("%lf", &y);
			if (y<mi(0)||y>mi(100))
			{
				printf("No solution!\n");
			}
			else {
				double left = 0, right = 100;
				double mid = (left + right) / 2;
				while (right - left > 1e-8) {//二分法只能求出近似值，无法等于（这样会死循环），所以我们只需要比要求精度高一点就可以退出循环
					
					mid = (left + right) / 2;
					if (mi(mid) > y) {
						right = mid- 1e-9;	
					}
					else if (mi(mid) < y) {
						left = mid+ 1e-9;  //这里是因为单纯二分要凑到如此近要好久，所以right再减比原来小一点点（比while的精度1e-8小），left加多一点点，这样避免死循环
					}
					else
						break;
				}
				printf("%.4lf\n", (left + right) / 2);  //跳出else后打印，这样才是精度到了
			}
			
		
	}
	return 0;
}