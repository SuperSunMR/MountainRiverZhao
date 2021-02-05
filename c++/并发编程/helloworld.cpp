// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 01 C++ 编程的入门编程，简单的用法
#include<iostream>
#include<string>
#include<thread>
using namespace std;

void proc(int &a)
{
    cout << "我是子线程,传入参数为" << a << endl;
    cout << "子线程中显示子线程id为" << std::this_thread::get_id()<< endl;
}
int main()
{
    cout << "我是主线程" << endl;
    int a = 9;
    std::thread th2(proc,a);//第一个参数为函数名，第二个参数为该函数的第一个参数，如果该函数接收多个参数就依次写在后面。此时线程开始执行。
    cout << "主线程中显示子线程id为" << th2.get_id() << endl;
    th2.join(); //此时主线程被阻塞直至子线程执行结束。

    return 0;
}
