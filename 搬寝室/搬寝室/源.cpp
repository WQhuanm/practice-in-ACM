#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm> 
using namespace std;
const int w = 1000000000;

                      //����k=1,n=5.����5����Ʒ���ó�1�ԡ�
//��ôshifts[1][5] = shifts[1][4]��(a[5] - a[4]) ^ 2����С��һ������ǰ�ĸ�{ 1,2,3,4 }����С��һ�Ի������һ�ԡ�
//����k = 2, n = 5.����5����Ʒ���ó�2�ԡ�
//��ôshifts[2][5] = shifts[2][4]��shifts[1][3] + (a[4] - a[3]) ^ 2����С��һ������ǰ�ĸ�{ 1,2,3,4 }����С�����Ի���ǰ��������С��һ�Լ����һ�ԡ�
//��������k = j, n = i.����i����Ʒ���ó�j�ԡ�
//��ôshifts[j][i] = shifts[j][i - 1]��shifts[j - 1][i - 2] + (a[i] - a[i - 1]) ^ 2����С��һ����
//��ǰi - 1��{ 1,2,��,i - 1 }����С��j�Ի���ǰi - 2������С��j - 1�Լ����һ�ԡ�
// ��״̬ת�Ʒ���Ϊ��
//shifts[j][i] = min(shifts[j][i - 1], shifts[j - 1][i - 2] + (a[i] - a[i - 1]) ^ 2);

bool cmp(int x, int y) {
    return x < y;
}
int dp[2010][1010] = { 0 };
int wet[2010] = { 0 };
int main() {
    int n, k;
  
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 1; i <= n; ++i)scanf("%d", &wet[i]);  //����
        sort(wet + 1, wet + 1 + n, cmp);      //��С������������
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {                  //j==0�Ĳ��ó�ʼ����Ϊ0����Ϊû�������ģ�����ȫ������ֵ
                dp[i][j] = w;   //����ʼ��Ϊ����ֵ����֤��ʼminһ������

            }
        }
        for (int i = 2; i <= n; ++i) {   //i��2��ʼ����Ϊÿ��Ϊһ��
            for (int j = 1; j * 2 <= i; ++j)   //Ϊ����ӣ�j����С�ڵ���i/2
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + (wet[i] - wet[i - 1])* (wet[i] - wet[i - 1]));// ��֤ÿ�ζ�����С�����Ž�
            }
        }
        printf("%d\n", dp[n][k]);

    }
    return 0;
}







