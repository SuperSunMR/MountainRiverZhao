// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.4 构造函数的调用规则
#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    // Person(){
    //     cout << "Person的默认构造函数"<<endl;
    // }
    ~Person(){
        cout << "Person的析构函数"<<endl;
    }
    Person(int age){
        this->age = age;
        cout << "Person的有参构造函数"<<endl;
    }
    Person(const Person &p){
        this->age = p.age;
        cout << "Person的拷贝构造函数"<<endl;
    }

    int age;
};

// void test01(){
//     Person p1;
//     Person p2(10);
//     Person p3(p2);
// }

void test02(){
    // Person p1;
    Person p2(10);
    Person p3(p2);
}

int main(){
    test02();
    return 0;
}