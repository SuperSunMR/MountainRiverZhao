// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.7 类对象做类成员
#include<iostream>
#include<string>
using namespace std;

class Phone{
public:
    Phone(){
        cout << "Phone默认构造函数" << endl;
    }
    Phone(string name){
        this->name;
        cout << "Phone有参构造函数" << endl;
    }
    string name; //手机名称
};

class Person{
public:
    Person(int pAge, string pName):age(pAge), phone(pName){
        // this->age = age;
        // this->phone = pName; //隐式转换法
        cout << "Person有参构造函数" << endl;
    }
    // Person(int pAge, string pName){
    //     this->age = age;
    //     this->phone = pName; //隐式转换法
    //     cout << "Person有参构造函数" << endl;
    // }
    int age;
    Phone phone;
};

void test01(){
    Person p1(30, "apple");
}

int main(){
    test01();
    return 0;
}