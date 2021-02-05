// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.4.3 成员函数做友元函数
#include<iostream>
#include<string>
using namespace std;

class Building;
class GoodGay{
public:
    GoodGay();
public:
    void visit(); // 让visit函数可以访问Building中的私有属性
    void visit2(); // visit2函数不可以访问Building中的私有属性
    Building *building;
};

//Building 类
class Building{
    friend void GoodGay::visit(); // 告诉编译器GoodGay类下的visit成员函数是本类的好朋友，可以访问本类的私有属性；
public:
    Building();
public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};

//类外写成员函数
Building::Building(){
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

// 类外实现成员函数
GoodGay::GoodGay(){
    building = new Building(); 
}
void GoodGay::visit(){
    cout << "好基友成员函数visit() 正在访问" << building->m_SittingRoom << endl;
    cout << "好基友成员函数visit() 正在访问" << building->m_BedRoom << endl;
} 
void GoodGay::visit2(){
    cout << "好基友成员函数visit2() 正在访问" << building->m_SittingRoom << endl;
    // cout << "好基友成员函数 正在访问" << building->m_BedRoom << endl;
}

// 测试函数
void test01(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main(){
    test01();
    
    return 0;
}