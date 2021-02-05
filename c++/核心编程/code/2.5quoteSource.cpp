// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.5 引用的本质
#include<iostream>
using namespace std;

/// 引用转换为 int * const ref = &a;
void func(int &ref){
    ref = 100; // ref是引用，将其转换为 *ref = 20;
}

int main(){
    int a = 10;
    
    // 自动转换为 int * const ref = &a; 指针常量指针指向不能改，指针所指的值可以改。这里也就说明了为什么引用不能被修改
    int &ref = a;
    ref = 20;
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    func(a);
    cout << "ref: " << ref << endl;

    return 0;
}