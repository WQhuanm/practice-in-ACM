#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
                                 //��ϣ��hash��
const int N = 1e6;
                                  
ll zhen[N + 100];   //�ѱ��ʽ��Ϊ���룬ͳ�Ƹ��Կ��ܵõ���ֵ����Ϊ4��һ��ض���ʱ
ll fu[N + 100];  //����һ�����飬����һ������

int main() {
	ll a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		
		if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))cout << 0 << endl;
		else {
			memset(zhen, 0, sizeof(zhen));
			memset(fu,0, sizeof(fu));
			for (int i = 1; i <= 100; ++i)for (int j = 1; j <= 100; ++j) {
				ll x = i * i * a + b * j * j; //���a*x12 + b*x22�Ŀ���ֵ���ۼ������У��ظ����־ͻ�Ӽ�
				if (x >= 0)zhen[x]++;//������������
				else fu[-x]++;//������������ŷŸ�������
			}
			ll ans = 0;  //��ʼͳ��
			for (int i = 1; i <= 100; ++i)for (int j = 1; j <= 100; ++j) {
				ll y = i * i * c + j * j * d;//���c*x32 + d*x42�Ŀ���ֵ
				if (y <= 0)ans += zhen[-y];//ע�⣬���෴��������x+y==0������yΪ�������Ƚϵ��������飬-y==xʱ��ƥ�䣬��һ�Σ���ʾ1*�������������ĳ˻�
				else ans += fu[y];//�Ƚϸ����飬y�����ģ��������ţ������Ǹ���һ��ĸ������Ϊ����

			}
			cout << ans * 16 << endl;//++--4����Ϲ���16��

		}


	}

	return 0;
}






