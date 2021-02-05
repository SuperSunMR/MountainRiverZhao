// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.6 常量引用
#include<iostream>
using namespace std;

//打印输出
void showVal(const int &val){
    cout << "val: " << val << endl;
}

int main(){
    int a = 1000;
    showVal(a);

    return 0;
}