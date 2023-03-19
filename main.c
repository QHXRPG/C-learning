#include <stdio.h>
#include "2_14.h"
#include "2_25.h"
#include "string.h"
#include "3_13.h"
#include "3_19.h"
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

void bubble_sort_(int *p, int len)
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
        printf("%c ",p[i]);
    }
    printf("\n");
}

int cmp_int(const void*p1, const void*p2)
{
    printf("%d - %d\n", *(int *)p1,*(int *)p2);
    return *(int *)p1 - *(int*)p2;
}
void Swap(char *buf1, char *buf2, int width)
{
    int i=0;
    for(i=0; i<width; i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}

void bubble_sort(void *base, size_t num, size_t width, int (*cmp)(const void *p1, const void *p2))
{
    size_t i=0;
    for(i=0; i<num-1; i++)
    {
        size_t j=0;
        for(j=0; j<num-1;j++)
        {
            if(cmp((char*)base+j*width, (char *)base+(j+1)*width)>0)
            {
                Swap((char*)base+j*width, (char *)base+(j+1)*width, width);
            }
        }

    }
}

void test3()
{
    int a[3][5] = {5, 4, 3, 2, 1,5,44,3,2,
                   1,5,4,3,2,1};
    int *p = (int*)(&a[1]);
    printf("%d\n",*(p+1));
}
int main()
{
    test3_19_7();
}