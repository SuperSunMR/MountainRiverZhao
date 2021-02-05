// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 3.1 函数默认参数
#include<iostream>
using namespace std;

//函数默认参数
// 1.如果某个位置已经有了默认参数，那么从这个位置往后，从左至右都必须有默认值
// int func(int a, int b=20, int c=30, int d){
//    return a + b + c;
// }

// int func2(int a = 10, int b = 10);
int func2(int a = 10, int b = 10){
    return a + b;
}
int main(){
    cout << func2(10, 30) << endl;

    return 0;
}