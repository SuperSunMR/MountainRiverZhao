// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.5 深拷贝和浅拷贝
#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    Person(){
        cout << "Person的默认构造函数调用" <<endl;
    }

    Person(int age, int height){
        this->age = age;
        this->height = new int(height);
        cout << "Person的有参函数调用" <<endl;
    }

    //自己实现拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p){
        cout << "Person的拷贝构造函数调用" <<endl;
        this->age = p.age;
        // this->height = p.height; // 编译器默认实现就是这行代码
        // 深拷贝操作
        this->height = new int(*p.height);
    }
    ~Person(){
        // 将堆区开辟的数据给释放掉
        if(height != NULL){
            delete height;
        }
        height = NULL; 
        cout << "Person的析构函数调用" <<endl;
    }
    int age;
    int *height;

};

void test01(){
    Person p1(18, 180);
    cout << "p1年龄为" << p1.age << " 身高：" << *p1.height <<endl;
    Person p2(p1);
    cout << "p2年龄为" << p2.age << " 身高：" << *p2.height <<endl;
}

int main(){
    test01();
    return 0;
}