//
// Created by 邱浩轩 on 2023/2/14.
//
#include <stdio.h>
#include "string.h"

void print_arr_2(int *p,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%c ",p[i]);
    }
    printf("\n");
}
int asd()
{
    printf("asd");
    return 0;
}

void my_swap(int *p1,int*p2,int len)
{
    int temp = 0;
    for(int i=0;i<len;i++)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        *p1++;
        *p2++;
    }
}

void test_1()
{
    char a[1000];
    int i;
    for(i=0;i<100;i++)
    {
        a[i] = -1 - i;
    }
    int len = sizeof(a);
    print_arr_2(a,len);
}

void test_2()
{
    int n=9;
    float *pFloat = (float*)&n;
    printf("n: %d\n",n);
    printf("*pFloat:&f\n", *pFloat);
    *pFloat = 9.0;
    printf("n: %d\n",n);
    printf("*pFloat: %f\n", *pFloat);
}

//最小公倍数
int least_common_multiple(int a, int b)
{
    int x=1,y=1;
    while(a*x != b*y)
    {
        if (a*x<b*y)
        {
            x++;
        }
        else
        {
            y++;
        }
    }
    return a*x;
}

//二维数组打印
void print_arr_2_(int(*arr)[5], int r,int c)
{
    int i=0;
    for(i=0;i<3;i++)
    {
        int j=0;
        for(j=0;j<5;j++)
        {
            printf("%d",*(*(arr+i)+j));
        }
        printf("\n");
    }
}

//字符串左旋
void string_leftshift(char *p,int num)
{
    char q[100] = "";
    int sz = strlen(p);
    for(int i=0;i<num;i++)
    {
        q[i]=p[i];
    }
    printf("%d\n",sz-num);
    for(int j=0;j<sz-num;j++)
    {
        p[j] = p[num+j];
    }
    for(int j=0;j<num;j++)
    {
        p[j+sz-num] = q[j];
    }
    printf("%s",p);
}

//判断一个字符串是否为另外一个字符串旋转之后的字符串
int is_string_leftshift(char *p1,char *p2)
{
    char p3[100] ="";
    int len1 = strlen(p1);
    int z=1;
    for(int i=0;i<len1;i++)
    {
        p1[len1+i]=p1[i];    //AABCDAABCD
    }
    for(int i=0;i< len1;i++)
    {
        z=1;
        for(int j=0;j< len1;j++)
        {
            p3[j]=p1[j+i];
        }
        for(int k=0;k<len1;k++)
        {
            if(p2[k]!=p3[k]){z=0;break;}
        }
        if(z==1){return 1;}
    }
    return 0;
}

void test_3()
{
    int a[]={1,2,3,4,5};
    int (*p)[]=&a;     //数组指针
    printf("%d\n",(*p)[3]);
}
int add(int x,int y)
{
    return x+y;
}
int mul(int x,int y)
{
    return x*y;
}
int sub(int x,int y)
{
    return x-y;
}
int div(int x,int y)
{
    return x/y;
}
void test_4()
{
    void (*fp[])() ={test_1,test_2,test_3,test_4}; //函数指针数组
    int (*fp2[])(int, int) ={add,sub,mul,div};
}
