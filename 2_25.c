//
// Created by 邱浩轩 on 2023/2/23.
//
#include "stdio.h"
#include "stdlib.h"

struct Stu
{
    char name[20];
    int age;
};


int cmp_stu_by_name(const void *p1, const void *p2)
{
    return ((struct Stu*)p1)->age - ((struct Stu*)p2)->age;
}



void test_2_25_0()
{
    struct Stu s[] = {{"zhangsan",20},{"lis",

            15},{"wangwu",30}};
    printf("%d\n",s[1].age);
    int len = sizeof(s)/sizeof(s[0]);
    qsort(s,len,sizeof(s[0]),cmp_stu_by_name);
}

