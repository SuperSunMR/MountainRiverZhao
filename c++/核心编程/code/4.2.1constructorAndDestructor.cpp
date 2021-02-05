// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.1 构造函数和析构函数
#include<iostream>
#include<string>
using namespace std;
class Person{
public:
    Person(){
        cout << "构造函数调用" << endl;
    }
    ~Person(){
        cout << "~析构函数调用" << endl;
    }
};
void test01(){
    Person p;
}
int main(){
    test01();
    return 0;
}