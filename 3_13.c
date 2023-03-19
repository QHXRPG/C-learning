//
// Created by 邱浩轩 on 2023/3/13.
//

#include "3_13.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"

//分隔符
void test3_1()
{
    char str[] = "1342998199@qq.com";
    const char  *p = "@.";  //定义分隔符
    char*strn = NULL;
    for(strn = strtok(str,p); strn!=NULL; strn= strtok(NULL,p))
    {
        printf("%s\n",strn);
    }
}

void test3_2()
{
    FILE *pf = fopen("./test.txt","r");
    fclose(pf);
}

void test3_3()
{
    perror("这是一个手动报错测试");
}

//拷贝内存块
void test3_4()
{
    int arr[] = {1,2,3,4,5,6,7};
    int arr2[8] = {0};
    memcpy(arr2,arr,4*5);   //将arr前五个数据拷贝到arr2中, float也是4个字节一个数据
}

void my_memcpy(void *dest, const void *src, size_t num)
{
    void *ret = dest;
    while(num--)
    {
        *(char*)dest = *(char*)src;
        dest = (char*)dest +1;
        src = (char *)src +1;
    }
}