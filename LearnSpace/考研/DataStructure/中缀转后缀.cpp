#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define MAX 1000
char *change(char data[]);
bool compare(char a, char b);
int priority(char a);
// (40  括号在算术上优先级最高，但是在 栈的优先级是最低的，为了其他符号正常入栈 优先级最低
//  /* 优先级最高 , +- 优先级最低
 
// true 的情况 只有a 是*/ b是+-的情况
int priority(char a)
{
    if (a == '(')
    {
        return 0;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
// 比较优先级 ,a 的优先级比b 高，就返回true
bool compare(char a, char b)
{
    return priority(a) > priority(b);
}
 
void show(char data[],int length)
{
    printf("输出状态\t");
    for (int i=0; i<length; i++)
    {
        printf("%c",data[i]);
    }
}
 
// 中缀表达式--> 后缀表达式(逆波兰表达式)
// 返回字符串数组
char *change(char data[])
{
    int length = strlen(data);
    char *hou = (char *)malloc(length * sizeof(char));
    stack<char> s;
    int index = 0; // 后缀表达式的长度
 
    // 1. 判断类型
    for (int i = 0; i < length; i++)
    {
        // 如果是运算数，直接输出，
        if (data[i] >= '0' && data[i] <= '9')
        {
            hou[index] = data[i];
            index++;
        }
        else if (data[i] == ')')
        {
            // 不断的弹出栈元素并输出直到遇到左括号结束
            while (!s.empty() && s.top() != '(')
            {
                hou[index] = s.top();//栈s中的栈顶元素
                index++;
                s.pop();//c++中输出栈s的栈顶函数
            }
            s.pop(); //退出左括号
        }
        else if(data[i]=='(')
        {
            s.push(data[i]);
        }
        else
        {
            // 表示 运算符优先级小于等于 栈顶元素,就退出栈顶元素，并输出
            // 包含情况data[i]='(',compare 返回false
 
            while (!s.empty() && !compare(data[i], s.top()))//s.empty()用于判断栈s是否为空
            {
                printf("进行比较%c %c %d\n",data[i],s.top(),compare(data[i], s.top()));
                hou[index] = s.top();
                index++;
                s.pop();
            }
            s.push(data[i]);
        }
        show(hou,index);
        printf("\t 参加运算的符号 is %c  \t  栈的元素个数 is %d \n", data[i], s.size());
    }
 
    // 输出栈内所有元素
    while (!s.empty())
    {
        hou[index] = s.top();
        index++;
        s.pop();
    }
    // 打印最后的结果
    show(hou,index);
    return hou;
}
char Switch(char a[])//将字符串中数字部分转换为十进制存储
{
    int lenth=strlen(a);
    int i;
    for(i=0; i<lenth; i++)
        if(a[i]>=48&&a[i]<=57)//数字在字符串中存储的数值不同
            a[i]=a[i]-48;
}
char Count(char a[])//利用后缀表达式计算混合运算
{
    int lenth=strlen(a);
    int num;
    int i,j,k;
    for(i=0; i<lenth; i++)//遍历后缀表达式的字符串
    {
        if(a[i]=='/')
        {
            a[i-2]=a[i-2]/a[i-1];
            for(j=i-1,k=i+1; j<lenth; j++,k++)//进行计算后要将字符串前移
                a[j]=a[k];
            i=-1;//让循环从头进行
            lenth--;//计算后长度缩减
            continue;
        }
        else if(a[i]=='*')
        {
            a[i-2]=(a[i-2])*(a[i-1]);
            for(j=i-1,k=i+1; j<lenth; j++,k++)
                a[j]=a[k];
            i=-1;
            lenth--;
            continue;
        }
        else if(a[i]=='+')
        {
            a[i-2]=(a[i-2])+(a[i-1]);
            for(j=i-1,k=i+1; j<lenth; j++,k++)
                a[j]=a[k];
            i=-1;
            lenth--;
            continue;
        }
        else if(a[i]=='-')
        {
            a[i-2]=(a[i-2])-(a[i-1]);
            for(j=i-1,k=i+1; j<lenth; j++,k++)
            {
                a[j]=a[k];
            }
            i=-1;
            lenth--;
            continue;
        }
        else//遇到数字部分跳过
            continue;
    }
    return a[0];
}
 
// 后缀表达式的计算
int main(int argc, char const *argv[])
{
    // 样例 2*(9+6/3-5)+4
    // 结果 2963/+5-*4+
    ///char s[MAX] = "2*(9+6/3-5)+4";
    char s[MAX];
    printf("请输入正确的表达式(英文状态):");
    scanf("%s",s);
    char *result;
    result = change(s);
    Switch(result);
    printf("\n%s=",s);
    printf("%d\n",Count(result));
    return 0;
}