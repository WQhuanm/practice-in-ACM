#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <algorithm>
#include<string.h>
using namespace std;
const int W = 1e5;

struct rice
{
    int p;//pΪ���������׵ĵ��ۣ�h���������׵�������
   int h;
}arr[W];
bool cmp(rice x, rice y) {
    return (x.p) < (y.p);
}
int main()
{
    int C;
    scanf("%d", &C);
    while (C--)
    {
        int n, m;//nΪ���ʽ�mΪ��������
        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &arr[i].p, &arr[i].h);
        }
        sort(arr, arr + m, cmp);//���۸�����С����ǰ
        double sum = 0;
        for (int i = 0; i <= m; ++i) {  //����
            if (n >= (arr[i].p) * (arr[i].h))
            {
                sum += arr[i].h; n -= (arr[i].p) * (arr[i].h);
            }
            else
            {
                sum += (n * 1.0 / (arr[i].p)) ;
                break;
            }
        }
        printf("%.2lf\n", sum);

    }


    return 0;
}




