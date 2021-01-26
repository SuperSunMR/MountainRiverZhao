#include<iostream>
using namespace std;


//实现两个整型交换
void swapInt(int &a, int &b){
    int temp = a;
    a = b; 
    b = temp;
}

//实现两个浮点型交换
void swapDouble(double &a, double &b){
    double temp = a;
    a = b; 
    b = temp;
}

void test01(){
    int a = 10;
    int b = 20;

    swapInt(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
int main(){

    test01();
    system("pause");
    return 0;
}