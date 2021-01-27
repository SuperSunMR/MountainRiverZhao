// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 01 多态的基本用法

#include<iostream>
using namespace std;

// 父类：动物类
class Animal
{
public:
    virtual void speak(){ // 虚函数
        cout << "动物在说话" << endl;
    }
};

// 子类：猫类
class Cat : public Animal
{
public:
    void speak(){
        cout << "小猫在说话" << endl;
    }
};

// 子类：狗类
class Dog : public Animal
{

public:
    void speak(){
        cout << "小狗在说话" << endl;
    }
};


// 执行说话的函数
// 地址早绑定：在编译阶段，就确定函数地址
// 若想执行猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，也就是地址晚绑定，即使用虚函数
/*
   动态多态需要满足的条件：
   1.有继承关系
   2.子类要重写父类的虚函数，即Cat类需要重写Animal的虚函数speak，注意不是重载，函数名和参数列表应该完全相同！

   动态多态使用：
   父类的指针或引用指向子类的对象，就可以实现动态的多态。
*/
void doSpeak(Animal &animal){ // Animal & animal = cat; 在c++中父类指针可以指向子类对象
    animal.speak();
}

// 测试函数
void test01(){
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

int main(){
    test01();
    return 0;
}