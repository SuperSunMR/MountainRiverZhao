// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.2 构造函数分类和调用
#include<iostream>
#include<string>
using namespace std;
// 1.有参构造和无参构造
// 2.普通构造和拷贝构造
class Person{
public:
    // 无参构造函数调用或默认构造函数调用
    Person(){
        cout << "无参构造函数调用或默认构造函数调用" << endl;
    }
    // 有参构造函数调用
    Person(int age){
        this->age = age;
        cout << "有参构造函数调用" << endl;
    }
    //拷贝构造函数调用 写法要按照const 类型 &对象名
    Person(const Person &p){
        age = p.age;
        cout << "拷贝构造函数调用" << endl;
    }
    ~Person(){
        cout << "~析构函数调用" << endl;
    }
    
    int age;
};

//调用
void test01(){
    //1.括号法
    Person p1; // 默认构造函数调用
    Person p2(10); // 有参构造函数调用
    Person p3(p2); // 拷贝构造函数调用
    // 【注意事项(1)】
    // 在调用默认构造函数的时候，不要加小括号()
    //【解释】因为编译器会认为是一个函数声明，例如 Person p1(); void func(); 不会认为是在创建对象！！！
    cout << "p2的年龄:" << p2.age << endl;
    cout << "p3的年龄:" << p3.age << endl;

    //2.显示法
    Person p2 = Person(28); //有参构造
    Person p3 = Person(p2); //拷贝构造

    Person(10); // 单独拿出来叫做 匿名对象，当前执行完毕之后，系统会立刻释放该匿名对象
    // 【注意事项(2)】
    // 不要利用拷贝构造函数初始化一个匿名对象
    // 编译器会认为Person(p3) 等价于 Person p3，将其理解为一个对象声明，因此会和上面的p3重定义！！！
    // Person(p3); 

    // 3.隐式转换法
    Person p4 = 10; // 相当于写了 Person p4 = Person(10);   有参构造
    Person p5 = p4; // 拷贝构造
}
int main(){
    test01();
    return 0;
}