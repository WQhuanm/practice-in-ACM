#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#define ll long long
using namespace std;
// map翻译为映射，也是常见的STL容器,map可以建立一个类型到另外一个类型的映射
//因为map需要确定映射前类型（键key）和映射后类型（值value），所以需要在<>内填写两个类型，其中一个是键的类型，第二个是值的类型

//注意，但是如果是字符串到整型的映射，必须是string而不是char数组，这时因为char数组作为数组是不能被作为键值的。所以字符串作映射，只能用string

// map容器内元素的访问
// 1，因为下标是唯一的，不能重复，可以通过下标访问
// 2，迭代器，如用mp。first访问键，mp。second访问值

//注意，map会以键的大小从小到大的顺序自动排序，这是因为map内部是使用红黑树（set也是），在建立映射的过程中会自动实现从小到大的排序功能
int main()
{
    map<string, string> mp;
    string a, b;
    cin >> a;
    while (cin >> a && a != "END")
    {
        cin >> b;
        mp[b] = a; // a是英文，b是未知字符串
    }
    cin >> a;
    char h[3100];
    getchar(); //读取换行
    while (1)
    {
        gets(h);
        if (strcmp(h, "END") == 0)break;//比较字符串是否相同，不可以用==，用strcmp，相同返回0，不同返回正数或者负数
        int len = strlen(h);
        b = ""; //里面没有东西，为空
        for (int i = 0; i < len; ++i)
        {
            if (h[i] < 'a' || h[i] > 'z') //当读到非字母字符，就可以对字符串b判定，如果有跟他等效的字符串，就打印，没有打印b这个未知字符串
            {
                if (mp[b] != "")
                    cout << mp[b]; //有对应翻译对象，打印
                else
                    cout << b;
                cout << h[i]; //打印b后，你这个非字母字符不要忘了打印
                b = "";       //记得打印b后重新初始化
            }
            else
                b += h[i]; //只要是字母，就一直堆b身上
        }
        cout << '\n'; //注意，gets读入\n后结束，但是会把\n转为\0，所以我们需要自己打换行
    }

    return 0;
}