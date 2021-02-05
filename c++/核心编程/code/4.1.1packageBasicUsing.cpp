// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.1.1 封装的意义
#include<iostream>
using namespace std;
const double PI = 3.1415926;
class Circle{
    //访问权限
public:
    //属性
    int m_r; // 半径
    //行为
    double getZC(){ // 获取周长
        return 2*PI*m_r;
    }
};
int main(){
    //通过圆类创建对象
    Circle c1;
    c1.m_r = 10;
    cout << "Circle ZhouChang is " << c1.getZC() << endl;

    return 0;
}