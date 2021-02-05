// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.1.3 struct和class的区别
#include<iostream>
using namespace std;
class C1{
    int m_A; //默认权限是私有
};
struct S1{
    int m_A; // 默认权限是公有
};
int main(){
    // struct和class的区别
    C1 c1;
    // c1.m_A = 10; // 不可以访问
    S1 s1;
    s1.m_A = 10;

    return 0;
}