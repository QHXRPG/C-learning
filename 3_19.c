//
// Created by 邱浩轩 on 2023/3/19.
//

#include "3_19.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "errno.h"
#include "stddef.h"

//定义一个学生结构体
struct Student
{
    //成员变量
    char name[20];
    int age;
    double weight;
}s4,s5,s6;  //全局变量

//匿名结构体
struct
{
    //成员变量
    char name[20];
    int age;
    float weight;
}s7;  //全局变量

void test3_19_1()
{
    struct Student s1; //局部变量
}


//结构自引用/链表
struct Node
{
    int data;
    struct Node *next;
};
void test3_19_2()
{
    struct Node n1;
    struct Node n2;
    n1.next = &n2;  //在n1中存放n2的地址
    struct Student s8= {"asd",12,60.4f};
    printf("%s,%d,%f",s8.name,s8.age,s8.weight);
}

//起名
typedef struct
{
    //成员变量
    char name[20];
    int age;
    float weight;
}S;  //全局变量

void test3_19_3()
{
    struct Student s8= {"asd",12,60.4f};
    printf("%d",sizeof(s8));
}
/*
 * 存放规则： 结构体的第一个成员永远放在0偏移处
 * 第二个成员开始，以后每个成员都要对齐到某个对齐数的整数倍处，这个对齐数是：成员自身大小和默认对齐数的较小值
 * 当成员全部存放，结构体的总大小是所有成员1对齐数中最大对齐数的整数倍，如果不够，就浪费空间对齐
 */


//设置默认对齐数 2^n
#pragma pack(1)
struct Student2
{
    char c1[10];
    int i;
    char c2[10];
};
#pragma pack(0)
void test3_19_4()
{
    printf("%d\n",sizeof(struct Student2));  //6
}


void print1(struct Student2 s)
{
    printf("%d\n",s.i);
}
//结构体地址传参
void print2(struct Student2 *s)
{
    printf("%d\n",s->i);
}
void test3_19_5()
{
    struct Student2 s = {"aqw",1,"dqwe"};
    print1(s);
    print2(&s);  //尽量去传结构体的地址
}


//位段  -  二进制位 -  不跨平台
struct A
{
    int _a:2;  //2个二进制位
    int _b:5; //5个二进制位 5个bit
    int _c:10;
    int _d:30;
};
//分配原则 ：4个字节4个字节地分配(32个bit)
void test3_19_6()
{
    struct A sa = {0,1,2,3};
    printf("%d\n",sizeof(sa));
}


//枚举 - 增加代码可读性和可维护性 - 便于调试  -  类型检查，更加严谨
enum Sex
{
    //枚举可能的取值,默认值：0，1，2，。。。。
    //枚举常量
    man=2,
    woman,
};
void test3_19_7()
{
    enum Sex s = man;  //只能在可能取值中去赋值
    printf("%d\n",s);
}