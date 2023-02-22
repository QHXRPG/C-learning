#include <stdio.h>
#include "2_14.h"
#include "string.h"
#include "/Users/qiuhaoxuan/miniforge3/include/python3.10/Python.h"

void test1()
{
    char ch1[10]={'a','b','c'};
    char ch2[]="asd";
    int ch3[10]={1,2,3,4,5,6,7,8,9,10};
    int *p = &ch3[0];
    printf("%d\n",sizeof(ch3));
    printf("%d\n",sizeof(ch3[0]));
    for(int i=0;i<sizeof(ch3)/sizeof(ch3[0]);i++)
    {
        printf("%d ",*(p+i));
    }
    printf("\n");
    int a = sizeof(ch1);
    printf("%d\n",a);  //10
    printf("%c\n",ch1[2]); //c
    printf("%c\n",ch1[4]); //NULL
    printf("%s\n",ch2); //asd
    printf("%s\n",ch1); //abc
    printf("%p\n",&ch3);
    printf("%p\n",ch3);
}

void test2()
{
    int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%2d ",arr[i][j]); //-2d是左对齐
        }
        printf("\n");
    }
}

void bubble_sort(int *p, int len)
{
    int tmp;
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(p[i]>p[j])
            {
                tmp = p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }
}

//一位数组print
void print_arr_1(int *p,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
}



int main()
{
    int a[]={1,2,3,4,5};
    int (*p)[]=&a;
}