// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 3.3 函数重载的注意事项
#include<iostream>
using namespace std;


// 1.引用作为函数重载的条件
void func(int &a){
    cout << "func(int &a)调用" << endl;
}
void func(const int &a){
    cout << "func(const int &a)调用" << endl;
}

//2.函数重载碰到默认参数
void func2(int a){
    cout << "func2(int a)调用" << endl;
}

void func2(int a, int b = 10){
    cout << "func2(int a, int b)调用" << endl;
}
int main(){
    int a = 10;
    // func(a); //走 func(int &a)调用
    // func(10); //走 func(const int &a)调用
    // func2(10); // 当函数重载碰见默认参数会出现二义性，在写代码的时候尽量避免这种情况

    return 0;
}