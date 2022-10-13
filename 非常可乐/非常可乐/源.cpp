#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>    //ʹ�ö���queue���ɱ䳤�ȣ���ͷ�ļ�
using namespace std;

const int N = 110;

int v[4];  //��ʾ�ڼ�������
struct bei {
	int v[4];//��ʾ��ǰ�ڼ������ӵ�״̬
	int step;//��ʾ���˶��ٲ�
};

bei head, temp;  //��������������ȡ�봢��

int book[N][N][N];//���ĳ��״̬�Ƿ��Ѿ����Թ�



void pour(int a,int b) {//a��b��ˮ
	int sum = temp.v[a] + temp.v[b];//��ʾ��ǰa��b����ˮ���ܺͣ����sum����v[b]��b���ӵ�������֤��a�е�ˮ���Ե���b����
	if (sum >= v[b]) {
		temp.v[b] = v[b];//a����ʣ��sum��ȥ��b���ӵģ�ʣ�¾���a��
	}//b���ӵ������
	else {
		temp.v[b] = sum;//û���ܵ����ٵ�����
	}
	temp.v[a] = sum - temp.v[b];  //��Ϊˮ����һ����������������ն�����a���ӵ������ܼ�ȥ����b���ӵ���
}

void bfs() {
	queue<bei>q;
	head.v[1] = v[1]; head.v[2] = head.v[3] = head.step = 0;
	memset(book, 0, sizeof(book));
	book[v[1]][0][0] = 1;//�ʼ���ֱ�ӱ��
	q.push(head);
	while (!q.empty()) {  //������û������ʱ������1������Ϊ0������ֻҪ���������ݣ���һֱ������ֱ��Ŀ��
		head = q.front();//ȡ���е�һ������Ȼ���ж�
		q.pop();//ȡ���ɾ���Ѿ��浽head����
		if (head.v[1] == head.v[2] && head.v[3] == 0) { cout << head.step << endl; return; }//�Ѿ���֤��������v[1]>v[2]>=v[3],��ô���ֻ�迴���if�ͺã��ɹ���֦
		for (int i = 1; i <= 3; ++i)for (int j = 1; j <= 3; ++j) {
			if (i != j) {  //���ܸ��Լ���ˮ
				temp = head;//ע�⣬ÿһ��i*j��ѭ��������ȡ��ǰ�洢���ͬһ��head������head���и��ֿ��ܲ��貢�Ϸ��ʹ���
				pour(i, j);
				if (!book[temp.v[1]][temp.v[2]][temp.v[3]]) {
					book[temp.v[1]][temp.v[2]][temp.v[3]] = 1;
					temp.step++;
					q.push(temp);
				}
			}

	}

	}
	cout << "NO" << endl;//ֻ�ж��п��˻�û�з��ʽ����˵�������ϣ��Ż�����while��������

}

int main() {
	
	while (~scanf("%d%d%d", &v[1], &v[2], &v[3]) && (v[1] || v[2] || v[3])) {
		if (v[1] % 2 != 0)cout << "NO" << endl;
		else {
			if (v[2] < v[3])swap(v[2], v[3]);
			bfs();
		}
	}


	return 0;
}