// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.4.1 全局函数做友元函数
#include<iostream>
#include<string>
using namespace std;

class Building{
    friend void goodGay(Building *building); // goodGay函数是Building类的好朋友，可以访问Building中的私有成员
public:
    Building(){
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
public:
    string m_SittingRoom; //客厅

private:
    string m_BedRoom; //卧室
};

//全局函数
void goodGay(Building *building){
    cout << "好基友全局函数 正在访问" << building ->m_SittingRoom << endl;
    cout << "好基友全局函数 正在访问" << building ->m_BedRoom << endl;
}

//测试函数
void test01(){
    Building building;
    goodGay(&building);
}

int main(){
    test01();
    
    return 0;
}