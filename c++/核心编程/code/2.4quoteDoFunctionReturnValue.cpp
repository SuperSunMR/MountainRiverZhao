// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.4 引用做函数返回值
#include<iostream>
using namespace std;

// 1.不要返回局部变量的引用
// int& test01(){
//     int a = 10;
//     return a; 
// }

int& test02(){
    static int a = 10; // 存放在全局区，在程序结束后，系统来释放
    return a;
}

// 2.函数调用可以作为左值

int main(){
    // int &ref = test01();
    // cout << ref << endl;
    int &ref2 = test02();
    cout << ref2 << endl;
    test02() = 1000;
    cout << ref2 << endl;
    cout << ref2 << endl;
}