// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.4.2 类做友元
#include<iostream>
#include<string>
using namespace std;
//家 类
class Building{
    friend class GoodGay; // GoodGay这个类是本类的好朋友，可以访问本类的私有属性
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

class GoodGay{
public:
    GoodGay();
public:
    void visit(); //参观函数，访问Building中的属性
    Building *building;
};

// 类外实现成员函数
GoodGay::GoodGay(){
    building = new Building(); 
}
void GoodGay::visit(){
    cout << "好基友类 正在访问" << building->m_SittingRoom << endl;
    cout << "好基友类 正在访问" << building->m_BedRoom << endl;

}
void test01(){
    GoodGay gg;
    gg.visit();
}

int main(){
    test01();
    
    return 0;
}