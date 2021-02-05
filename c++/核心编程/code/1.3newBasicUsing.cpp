// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 1.3 new 关键字使用
#include<iostream>
using namespace std;

int * func(){
    // 利用new关键字，可以将数据开辟到堆区
    // new返回的是该数据类型的指针
    int * p = new int(10);
    return p;
}

// 在堆区利用new开辟一个数组
void test02(){
    int *arr = new int[10]; // 10表示数组有10个元素

    for(int i = 0; i < 10; i++){
        arr[i] = i + 100;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    } 

    // 释放堆区数组，需要加[]才可以
    delete []arr;

}
int main(){
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    //如果想删除堆区的数据，使用delete关键字
    delete p;
    cout << *p << endl; // 内存已经被释放，再次访问就是非法操作

    test02();
    return 0;
} 