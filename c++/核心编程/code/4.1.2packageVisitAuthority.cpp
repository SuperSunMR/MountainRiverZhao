// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.1.2 访问权限
#include<iostream>
using namespace std;
// public： 类内可以访问，类外也可以访问
// protected：类内可以访问，类外不可以访问，子类可以访问父类中的protected内容
// private：类内可以访问，类外不可以访问，子类不可以访问父类中的private内容
class Person{
    // public
    public:
        string m_name; //姓名
    protected:
        string m_car; //车
    private:
        string m_password; // 密码
    public:
        void func(){
            m_name = "zhangsan";
            m_car = "benchi";
            m_password = "123456";
        }
};
int main(){
    Person p1;

    p1.m_name = "lisi";
    // p1.m_car = "baoma"; // protected权限在类外访问不到
    // p1.m_password = "876543"; // private权限在类外访问不到

    return 0;
}