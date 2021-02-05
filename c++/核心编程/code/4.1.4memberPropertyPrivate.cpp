// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.1.4 将成员属性设为私有
#include<iostream>
#include<string>
using namespace std;
class Person{
public:
    void setName(string name1){
        name = name1;
    }
    string getName(){
        return name;
    }
    void setAge(int age){
        if(age >= 0 && age <= 100){
            this->age = age;
        }
        else{
            cout << "age no valid!" << endl;
        }
    }
    int getAge(){
        return age;
    }
private:
    int age;
    string name;
    string lover;
};
int main(){
    Person p1;
    p1.setName("张三");
    cout << "这个人的名字叫：" <<p1.getName() << endl;
    p1.setAge(192);
    cout << p1.getName() <<"的年龄：" <<p1.getAge() << endl;
    return 0;
}