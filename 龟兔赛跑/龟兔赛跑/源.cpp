#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>

const int w = 2e9;
using namespace std;
//
//����Ŀ����������ԣ��봦���ļ�������ÿ�����԰������У�
//��һ����һ������L�����ܵ����ܳ���
//�ڶ��а�����������N��C��T���ֱ��ʾ���վ�ĸ������綯���������Ժ�����ʻ�ľ����Լ�ÿ�γ������Ҫ��ʱ��
//������Ҳ����������VR��VT1��VT2���ֱ��ʾ�����ܲ����ٶȣ��ڹ꿪�綯�����ٶȣ��ڹ�ŵŵ綯�����ٶ�
//�����а�����N(N <= 100)������p1, p2...pn, �ֱ��ʾ�������վ���ܵ����ľ��룬����0 < p1 < p2 < ... < pn < L
//	����ÿ��������32λ���ͷ�Χ֮�ڡ�



double dp[110];   //���浽ÿ��վ����Сʱ��
double arr[110];   //����ÿ��վ�㵽������

int main() {
	double L, C, T, vr, vt1, vt2;
	int N;
	while (scanf("%lf %d %lf %lf %lf %lf %lf", &L, &N, &C, &T, &vr, &vt1, &vt2) == 7) {
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		arr[0] = 0; arr[N + 1] = L;   //һ����㣬һ���յ�ľ���
		double tmin = 0;
		for (int i = 1; i <= N; ++i)scanf("%lf", &arr[i]);
		for (int i = 1; i <= N + 1; ++i) {
			double mymin = w;     //һ��Ҫ��ÿ�ν���jѭ��ʱ���ã�����ᱣ����һ��ѭ������Сֵ��myminֻ��������ÿ��jѭ������Сֵ����������iѭ��
			for (int j = 0; j < i; ++j) {      //��ʾ��jվ����iվ�����ʱ��  ������i��1��ʼ���ʹ�0��ʼ
				if (C >= arr[i] - arr[j])
					tmin = (arr[i] - arr[j]) / vt1;
				else {
					tmin = C / vt1 + ((arr[i] - arr[j])-C) / vt2;   //(arr[i] - arr[j])�����������ȥC
				}
				if (j)tmin += T;   //ֻҪj����0����������㣩���ͼӳ��ʱ�䣬���ùܾ�����û�б�Ҫ����Ϊdpʱ���Զ�ɸѡ�����j��i���һ�ξͺã�������Сʱ����dp[j]+tmin
				                        //����������м�ÿ�ζ���磬ʱ��϶����ˣ��ᱻmin����
				mymin = min(mymin, dp[j] + tmin);
			}
			dp[i] = mymin;  //�ڶ���ѭ�����󵽵�i��վ���tmin�����Ա���ѭ�����ʱ���ٸ�����У�����ʱ�����
		}
		double tr = L / vr;//����ʱ��
		if (tr > dp[N + 1])printf("What a pity rabbit!\n");
		if (tr < dp[N + 1])printf("Good job,rabbit!\n");
	}
	return 0;
}