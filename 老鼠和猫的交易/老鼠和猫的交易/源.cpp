#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>


               //FatMouse׼����M����è����׼���������ֿ��è���ף�����װ������ϲ����ʳ��JavaBean��
//�ֿ���N�����䡣i - th ������� J[i] ��צ�۶��� ��Ҫһ��è����FatMouse�����÷��������е�צ�۶���������
//�෴�����������F[i]1 % ����è���������ܻ�õ�J[i]1 % ����צ�۶���������һ����ʵ�����֡����ڣ������ڸ�����������ҵ���������ܵõ������������צ�۶���

#include<algorithm>  //ʹ��sort������ͷ�ļ�
using namespace std; //���ⷢ��������ͻ������ʹ�ÿ⺯��������sort�ſ�����
const int W = 1e4 + 5; //���鿪�󣬱�֤�ܴ���ȫ������
int M, N;   //MΪè������NΪ������
double tot; //��ȡ������
struct room     //�ýṹ�����һ�����壬������ȡ��ת��
{
    double catfood;
    double cheese;

}arr[W];    //�൱��room���͵����飨��room arr[max])����һ�����飩

bool emp(room x, room y)    //����sort�Ӵ�С����ĺ���   //bool�Ƿ�������߼ٵ����ͣ�����ͨ��return��������ʾ��٣���x��y�Ƚ�ʱ��x��ֵ�����������������档sort���ý������ǣ��෴�����ؼ٣�sort����ʹ��Ϊ��
{
    return (x.cheese) / (x.catfood) > (y.cheese) / (y.catfood);   //����/è����ֵԽ��Խ����    //x.cheese��ʾroom x����ṹ�������е�cheese��һ����.�������������
}

int main()
{
    while (scanf("%d %d", &M, &N) == 2 &&M!=-1&&N!=-1)   //M,N��Ϊ-1����������������жϻغ�
    {
        for (int i = 1; i <= N; ++i)  //i��ʾ��i�䷿��,i��1��ʼ����Ϊ����û�е�0��
        {
            scanf("%lf %lf", &arr[i].cheese, &arr[i].catfood);     //����ÿ�䷿���������è��
        }
        sort(arr + 1, arr + 1 + N, emp);  //ʹ�����򣬽��Լ۱ȸߵķ�������ǰ�棬������˳����㣬sortȡ���ǵ�ַ��arr+1��ʾarr[1]�ĵ�ַ��������д��arr,arr+N)�����Ǵ�arr[0]��ʼ�������ǵķ����arr[1]��ʼ
        for (int i = 1; i <= N; ++i)
        {
            if (M - arr[i].catfood >= 0)
            {
                tot += arr[i].cheese * 1.0;   //����������tot���ӣ�è������
                M -= arr[i].catfood;
            }
            else //��è��������ȡȫ�������ˣ��Ͱ�������
            {
                double bi = M / arr[i].catfood;
                    tot += bi * arr[i].cheese * 1.0;
                    break;  //��ʱè�����ˣ�����ѭ��
            }
           
        }
        printf("%.3lf\n", tot);
        tot = 0;//����tot����ֹ����һ�����ݵ���
    }


    return 0;
}