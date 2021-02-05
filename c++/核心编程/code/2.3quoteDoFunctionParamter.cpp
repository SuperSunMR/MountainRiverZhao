// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.3 引用做函数参数
#include<iostream>
using namespace std;

// 1. 值传递
void mySwap01(int a, int b){
    int temp = b;
    b = a;
    a = temp;
}

// 2. 地址传递
void mySwap02(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

// 3. 地址传递
void mySwap03(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

int main(){
    int a = 10;
    int b = 20;
    // mySwap01(a, b); // 值传递
    // mySwap02(&a, &b); // 地址传递
    mySwap03(a, b); // 引用传递

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}