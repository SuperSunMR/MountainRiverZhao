// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 1.2 堆区基本概念，以及使用new关键字为堆区开辟内存
#include<iostream>
using namespace std;

int * func(){
    // 利用new关键字，可以将数据开辟到堆区
    // 指针 本质上也是局部变量，放在栈上，但是指针保存的数据是放在堆区的。
    int * p = new int(10);
    return p;
}
int main(){
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    return 0;
} 