#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int w = 1e7;

struct po {
	char name[20];
	int age;
	double sco;



}arr[w];

bool cmp1(po x, po y) {
	if(x.sco!=y.sco)
	return x.sco > y.sco;
	else
	{
		if (x.age != y.age)
			return x.age < y.age;
		else
			for (int k = 0; k < 11; ++k) {
				if (x.name[k] != y.name[k])return x.name[k] < y.name[k];
			}


	}
}
//
//bool cmp2(po x, po y) {
//	return x.age <= y.age;
//}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 1; i <= n; ++i) {
			scanf("%s %d %lf", arr[i].name, &arr[i].age, &arr[i].sco);
		}

		sort(arr + 1, arr + 1 + n, cmp1);

		for (int i = 1; i <= n; ++i) {
			printf("%s %d %.2f\n", arr[i].name, arr[i].age, arr[i].sco);
		}


	}

	return 0;
}