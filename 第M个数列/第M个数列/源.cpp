#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
                           //next_permutation(a,a+n)ȫ���к���
        //next_permutation��start,end������prev_permutation��start,end��������������������һ���ģ����������ǰ������ǵ�ǰ���е���һ�����У���һ������ǵ�ǰ���е���һ�����С�
             //����ǰ���в�������һ������ʱ����������false�����򷵻�true
       //next_permutation(num,num+n)�����Ƕ�����num�е�ǰn��Ԫ�ؽ���ȫ���У�ͬʱ���ı�num�����ֵ��
          //���⣬next_permutation��node,node+n,cmp�����ԶԽṹ��num�����Զ��������ʽcmp��������

const int N = 1100;
int a[N];
int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)a[i] = i;
        for (int i = 1; i <= m - 1; ++i) {//��Ϊһ��ʼ�����о��ǵ�һ��������ֻ��Ҫ��next_permutationm-1����������m������
            next_permutation(a + 1, a + 1 + n);
        }
        for (int i = 1; i <= n; ++i) {
            cout << a[i];
            if (i != n)cout << " ";
            else cout << "\n";
        }
    }

    return 0;
}


//����1��N�����У����Ƕ���1, 2, 3 ...N - 1, N����1��N��ɵ����������е���С���У�ÿ������ֻ��ʹ��һ�Σ���������׿������ڶ�����С��������1, 2, 3 ... N, N - 1��
//���ڣ�������������N��M�������������1��N��ɵĵ�M����С��������ʲô��
//Input
//�����������������ݣ��봦���ļ�������
//ÿ��������ݰ�����������N��M(1 <= N <= 1000, 1 <= M <= 10000)��
//���ݱ�֤һ��������Ҫ������С�
//Output
//���������Ҫ������С����е�������֮����1���ո�������������һ��������û�пո�
//ÿ���������һ�С�