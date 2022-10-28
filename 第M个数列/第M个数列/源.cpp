#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
                           //next_permutation(a,a+n)全排列函数
        //next_permutation（start,end），和prev_permutation（start,end）。这两个函数作用是一样的，区别就在于前者求的是当前排列的下一个排列，后一个求的是当前排列的上一个排列。
             //当当前序列不存在下一个排列时，函数返回false，否则返回true
       //next_permutation(num,num+n)函数是对数组num中的前n个元素进行全排列，同时并改变num数组的值。
          //此外，next_permutation（node,node+n,cmp）可以对结构体num按照自定义的排序方式cmp进行排序。

const int N = 1100;
int a[N];
int main() {
    int n, m;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)a[i] = i;
        for (int i = 1; i <= m - 1; ++i) {//因为一开始的排列就是第一个，所以只需要用next_permutationm-1次求可以求第m个排列
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


//给定1到N的序列，我们定义1, 2, 3 ...N - 1, N是由1到N组成的所有序列中的最小序列（每个数字只能使用一次）。则很容易看出，第二个最小的序列是1, 2, 3 ... N, N - 1。
//现在，给定两个数字N和M，请告诉由数字1到N组成的第M个最小的序列是什么。
//Input
//输入包含多组测试数据，请处理到文件结束。
//每组测试数据包含两个整数N和M(1 <= N <= 1000, 1 <= M <= 10000)。
//数据保证一定有满足要求的数列。
//Output
//请输出满足要求的数列。数列的两个数之间用1个空格隔开，并且最后一个数后面没有空格。
//每组数据输出一行。