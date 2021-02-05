// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.3 拷贝构造函数的调用时机
#include<iostream>
#include<string>
using namespace std;
class Person{
public:
    Person(){
        cout << "默认构造函数调用" << endl;
    }
    Person(int age){
        this->age = age;
        cout << "有参构造函数调用" << endl;
    }
    Person(const Person &p){
        this->age = p.age;
        cout << "拷贝构造函数调用" << endl;
    }
    ~Person(){
        cout << "~析构函数调用" << endl;
    }
    int age;
};
 // 1.使用一个已经创建完毕的对象来创建另一个对象
void test01(){
    Person p1(12);
    Person p2(p1);
    cout << "p2的年龄：" << p2.age << endl;
}
// 2. 值传递的方式给函数传值
// 实参传给形参的时候，调用了拷贝构造函数
void doWork(Person p){

}
void test02(){
    Person p;
    doWork(p);
}

// 3. 以值方式返回给局部对象
// 【？】待解决：这种跑出来的结果没有调用拷贝构造函数
Person doWork2(){
    Person p1;
    cout << (int*)&p1 << endl;
    return p1;
}
void test03(){
    Person p = doWork2();
     cout << (int*)&p << endl;
}
int main(){
    test03();
    return 0;
}