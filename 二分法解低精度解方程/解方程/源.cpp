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
				while (right - left > 1e-8) {//���ַ�ֻ���������ֵ���޷����ڣ���������ѭ��������������ֻ��Ҫ��Ҫ�󾫶ȸ�һ��Ϳ����˳�ѭ��
					
					mid = (left + right) / 2;
					if (mi(mid) > y) {
						right = mid- 1e-9;	
					}
					else if (mi(mid) < y) {
						left = mid+ 1e-9;  //��������Ϊ��������Ҫ�յ���˽�Ҫ�þã�����right�ټ���ԭ��Сһ��㣨��while�ľ���1e-8С����left�Ӷ�һ��㣬����������ѭ��
					}
					else
						break;
				}
				printf("%.4lf\n", (left + right) / 2);  //����else���ӡ���������Ǿ��ȵ���
			}
			
		
	}
	return 0;
}