#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int N = 100;
int a[N];

int head[N * N + 110];
int temp[N * N + 110];

                     //ĸ����
int main() {
	int n;
	while (cin >> n) {
		memset(temp, 0, sizeof(temp));
		memset(head, 0, sizeof(head));
		int sum = 0;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i]; sum += a[i];
		}
		head[0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= sum; ++j) 
			{
				int a1 = j + a[i], a2 = abs(j - a[i]);
				temp[j] += head[j];   //ֻҪ��һ���head[j]��ֵ����ô���������õ����ݶ���ֵ
				temp[a1] += head[j];            //˼�룬�洢��һ�����ݵ�ֵ����ǰ��������ʱ�������ж���ֻҪ����Դ��������һ��洢��head[j]����ô�Ϳ��Ի��ֵ����Ϊ0
				temp[a2] += head[j];

			}
			for (int j = 0; j <= sum; ++j)//ÿ��ѭ��һ������a[i]������ʱ������ֵ�洢��Ŀ���У�Ȼ�������ʱ����
			{
				head[j] = temp[j];
				temp[j] = 0;
			}
		}
		queue<int>q;
		for (int i = 1; i <= sum; ++i) {
			if (!head[i]) {
				q.push(i);
			}
		}

		if (!q.empty()) {
			cout << q.size() << endl;
			while (!q.empty()) {
				cout << q.front();
				if (q.size() == 1)cout << endl;
				else cout << " ";


				q.pop();
			}
		

		}
		else cout << 0 << endl;

	}

	


	return 0;
}


//�����֣���������ѧ�����ߣ����ڵ�ҩ��ʦ���㽭ʡ��ҽԺ��ҩ��ʦ��ͬ���������Ϊ����ҩʦ����
//
//��ҩʦÿ���������ǰﲡ�˵���ҩ���أ�ò�ƺܷ�ζ�����ǣ�ƽ�������Ӳ�������ֹ���ǿŸ߹���ġ�
//
//������ǰ��N����ƽ���룬ϲ����ѧ�ĺ�ҩʦð����һ�����⣺
//
//�����������������֮����S����ô��[1, S]�ķ�Χ�ڣ���Щ�������޷�����ƽ�Ƴ����أ�
//Input
//��������������������
//ÿ����������ĵ�һ����һ��������N(1 <= N <= 100)����ʾ��N�����롣
//������һ����N������Ai(1 <= i <= N)���ֱ��ʾN�������������1 <= Ai <= 100��
//Output
//����ÿ��������ݣ�������������ܳƳ��������ĸ��������������Ϊ0��Ȼ�������һ����������в��ܳƵ����������ݿո�������������С�