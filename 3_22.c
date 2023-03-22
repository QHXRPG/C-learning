//
// Created by 邱浩轩 on 2023/3/22.
//

#include "3_22.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "errno.h"

//动态内存管理 malloc free calloc realloc

//malloc
void test3_22_1()
{
    int *p = (int*)malloc(20);  //向内存申请二十个字节的内存， 无初始化
    if(p==NULL)
    {
        printf("%s\n", strerror(errno));
    }
    //使用
    for(int i=0;i<5;i++)
    {
        *(p+i) = i+1;
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",*(p+i));
    }

    //释放
    free(p); //释放一次之后不能再释放
    p = NULL;
}

//calloc
void test3_22_2()
{
    int *p = (int*) calloc(10, sizeof(int)); //开辟10个大小为sizeof(int)的元素的空间，初始化为0
    if(p==NULL)
    {
        printf("%s\n", strerror(errno));
    }
    //使用
    for(int i=0;i<5;i++)
    {
        *(p+i) = i+1;
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",*(p+i));
    }
    //释放
    free(p);
    p = NULL;
}

//realloc  对动态内存进行动态调整
void test3_22_3()
{
    int *p = (int*)malloc(20);
    if(p==NULL)
    {
        printf("%s\n", strerror(errno));
    }
    //使用
    for(int i=0;i<5;i++)
    {
        *(p+i) = i+1;
    }
    int *pn = (int*)realloc(p,40);  //调整为40大小
    if(pn != NULL)
    {
        p = pn;
        for(int i=5;i<10;i++)
        {
            *(p+i) = i+1;
        }
        for(int i=0;i<10;i++)
        {
            printf("%d ",*(p+i));
        }
    }  //扩充成功了才可以给p，不然p的内存会丢失
    //释放
    free(p);  //如果不释放，程序结束后，也会由操作系统回收； 如果不释放程序不结束，内存泄漏
    p = NULL;
}


void testtest3_22_4()
{
    char *str = (char*) malloc(100);
    strcpy(str, "hello");
    free(str);
    str = NULL;  //free之后要置空
    if(str != NULL)
    {
        strcpy(str, "world");  //野指针，非法访问
        printf(str);
    }
}

