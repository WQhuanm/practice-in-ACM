#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>
#define ll long long
using namespace std;
// map����Ϊӳ�䣬Ҳ�ǳ�����STL����,map���Խ���һ�����͵�����һ�����͵�ӳ��
//��Ϊmap��Ҫȷ��ӳ��ǰ���ͣ���key����ӳ������ͣ�ֵvalue����������Ҫ��<>����д�������ͣ�����һ���Ǽ������ͣ��ڶ�����ֵ������

//ע�⣬����������ַ��������͵�ӳ�䣬������string������char���飬��ʱ��Ϊchar������Ϊ�����ǲ��ܱ���Ϊ��ֵ�ġ������ַ�����ӳ�䣬ֻ����string

// map������Ԫ�صķ���
// 1����Ϊ�±���Ψһ�ģ������ظ�������ͨ���±����
// 2��������������mp��first���ʼ���mp��second����ֵ

//ע�⣬map���Լ��Ĵ�С��С�����˳���Զ�����������Ϊmap�ڲ���ʹ�ú������setҲ�ǣ����ڽ���ӳ��Ĺ����л��Զ�ʵ�ִ�С�����������
int main()
{
    map<string, string> mp;
    string a, b;
    cin >> a;
    while (cin >> a && a != "END")
    {
        cin >> b;
        mp[b] = a; // a��Ӣ�ģ�b��δ֪�ַ���
    }
    cin >> a;
    char h[3100];
    getchar(); //��ȡ����
    while (1)
    {
        gets(h);
        if (strcmp(h, "END") == 0)break;//�Ƚ��ַ����Ƿ���ͬ����������==����strcmp����ͬ����0����ͬ�����������߸���
        int len = strlen(h);
        b = ""; //����û�ж�����Ϊ��
        for (int i = 0; i < len; ++i)
        {
            if (h[i] < 'a' || h[i] > 'z') //����������ĸ�ַ����Ϳ��Զ��ַ���b�ж�������и�����Ч���ַ������ʹ�ӡ��û�д�ӡb���δ֪�ַ���
            {
                if (mp[b] != "")
                    cout << mp[b]; //�ж�Ӧ������󣬴�ӡ
                else
                    cout << b;
                cout << h[i]; //��ӡb�����������ĸ�ַ���Ҫ���˴�ӡ
                b = "";       //�ǵô�ӡb�����³�ʼ��
            }
            else
                b += h[i]; //ֻҪ����ĸ����һֱ��b����
        }
        cout << '\n'; //ע�⣬gets����\n����������ǻ��\nתΪ\0������������Ҫ�Լ�����
    }

    return 0;
}