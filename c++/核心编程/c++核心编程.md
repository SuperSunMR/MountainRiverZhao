# C++ 核心编程

[TOC]

## 1.内存分区模型

- **代码区**：就是你所写代码的存放位置，存放**函数体**的二进制代码，由操作系统直接进行管理
- **全局区**：存放**全局变量**和**静态变量**以及常量
- **栈区**：
- **堆区**：

**内存四区的意义**：不同区域存放的数据，对其赋予不同的生命周期，给程序员以更灵活的编程。

### 1.1 程序运行前

在程序**编译**之后，即可得到exe可执行文件，**未执行该程序前（注意是未执行之前）**该程序的所有相关文件数据存放在两个区域：

**代码区**：

- 在程序未执行之前，代码区就已经存在了，它会存放CPU的机器指令，也就二进制0101等一些指令；
- 【特性1】代码区是**共享**的，对于频繁被执行的程序，只需要在内存中保留一份即可；
- 【特性2】代码区是**只读**的，目的是防止程序意外的修改了它的指令

**全局区**：

- 【特性】全局区的数据在程序结束后**由操作系统释放**，这部分数据的生命周期不受程序员控制；
- 【存放】全局变量、静态变量、常量；

| 不在全局区                                      | 在全局区                                                     |
| :---------------------------------------------- | :----------------------------------------------------------- |
| 1.局部变量<br />2.const修饰的局部变量(局部常量) | 1.全局变量<br />2.静态变量 static 关键字<br />3.常量<br />(1)字符串常量<br />(2)const修饰的全局变量(全局常量) |

### 1.2 程序运行后

**栈区**：

- **注意事项**：不要返回局部变量的地址！！！
- 【特性】由编译器自动分配释放，存放函数的参数值、局部变量等



**堆区**：

- 【特性1】由程序员分配和释放，若程序员不释放，在程序结束时，由操作系统统一回收
- 【特性2】在C++中主要利用new关键字开辟内存

![image-20210201185007766](.\img\image-20210201185007766.png)

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 1.2 堆区基本概念，以及使用new关键字为堆区开辟内存
#include<iostream>
using namespace std;

int * func(){
    // 利用new关键字，可以将数据开辟到堆区
    // 指针 本质上也是局部变量，放在栈上，但是指针保存的数据是放在堆区的。
    int * p = new int(10);
    return p;
}
int main(){
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    return 0;
} 
```

输出：

10

10

10

10

**解释**：因为数据存放在堆区，函数中的指针存放在栈区，函数执行完毕，栈区清空，指针所指向的地址返回给了接收的指针，通过指针解析地址即可获得堆区上所存的数据10。

### 1.3 new操作符

语法：`new 数据类型`

使用`delete`关键字

- 删除非数组：`delete 变量地址`
- 删除数组：释放堆区数组，需要加[]才可以，`delete []arr`

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 1.3 new 关键字使用
#include<iostream>
using namespace std;

int * func(){
    // 利用new关键字，可以将数据开辟到堆区
    // new返回的是该数据类型的指针
    int * p = new int(10);
    return p;
}

// 在堆区利用new开辟一个数组
void test02(){
    int *arr = new int[10]; // 10表示数组有10个元素

    for(int i = 0; i < 10; i++){
        arr[i] = i + 100;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    } 

    // 释放堆区数组，需要加[]才可以
    delete []arr;

}
int main(){
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    //如果想删除堆区的数据，使用delete关键字
    delete p;
    cout << *p << endl; // 内存已经被释放，再次访问就是非法操作

    test02();
    return 0;
} 
```

## 2.引用

### 2.1 引用的基本语法

![image-20210201195642914](.\img\image-20210201195642914.png)

**语法**：数据类型 &别名 = 原名；

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.1 引用的基本用法
#include<iostream>
using namespace std;

int main(){
    int a = 10;
    int &b = a;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    b = 100;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    return 0;
}
```

输出：

a = 10

b = 10

a = 100

b = 100

### 2.2 引用的注意事项

- 引用必须初始化。像`int &b;`这种写法是错误的
- 引用初始化之后就不可发生改变

### 2.3 引用做函数参数

**作用**：函数传参数时，可以用引用的技术让形参修饰实参

**优点**：可以简化指针修改实参

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.3 引用做函数参数
#include<iostream>
using namespace std;

// 1. 值传递
void mySwap01(int a, int b){
    int temp = b;
    b = a;
    a = temp;
}

// 2. 地址传递
void mySwap02(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

// 3. 地址传递
void mySwap03(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

int main(){
    int a = 10;
    int b = 20;
    // mySwap01(a, b); // 值传递
    // mySwap02(&a, &b); // 地址传递
    mySwap03(a, b); // 引用传递

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}
```

### 2.4 引用做函数的返回值

- 不要返回局部变量的引用
- 函数调用可以作为左值

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.4 引用做函数返回值
#include<iostream>
using namespace std;

// 1.不要返回局部变量的引用
// int& test01(){
//     int a = 10;
//     return a; 
// }

int& test02(){
    static int a = 10; // 存放在全局区，在程序结束后，系统来释放
    return a;
}

// 2.函数调用可以作为左值

int main(){
    // int &ref = test01();
    // cout << ref << endl;
    int &ref2 = test02();
    cout << ref2 << endl;
    test02() = 1000; // 作为左值
    cout << ref2 << endl;
    cout << ref2 << endl;
}
```

输出：

10

1000

1000

### 2.5 引用的本质

**本质**：引用的本质在C++内部就是一个**指针常量**

> 引用转换为 int \* const ref = &a;

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.5 引用的本质
#include<iostream>
using namespace std;

/// 引用转换为 int * const ref = &a;
void func(int &ref){
    ref = 100; // ref是引用，将其转换为 *ref = 20;
}

int main(){
    int a = 10;
    
    // 自动转换为 int * const ref = &a; 指针常量指针指向不能改，指针所指的值可以改。这里也就说明了为什么引用不能被修改
    int &ref = a;
    ref = 20;
    cout << "a: " << a << endl;
    cout << "ref: " << ref << endl;

    func(a);
    cout << "ref: " << ref << endl;

    return 0;
}
```

### 2.6 常量引用

**作用**：主要用来修饰形参，防止误操作。

在函数形参列表中，增加`const`操作符修饰形参，可以防止形参改变实参。

**注意**：`int &ref = 10;`这种写法是不合法的，因为引用必须引一块合法的内存空间。

但是，`const int &ref = 10;` 是合法的，因为在加上const之后，编译器将代码修改 `int temp = 10; const int &ref = temp;`，所以我们在操纵这块内存空间用的是别名。

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 2.6 常量引用
#include<iostream>
using namespace std;

//打印输出
void showVal(const int &val){
    cout << "val: " << val << endl;
}

int main(){
    int a = 1000;
    showVal(a);

    return 0;
}
```

## 3.函数提高

### 3.1 函数的默认参数

函数的形参列表中的形参是可以有默认值的。

**语法**：`返回值类型 函数名(参数=默认值){}`

**注意事项**：

- 如果某个位置已经有了默认参数，那么从这个位置往后，从左至右都必须有默认值
- 如果函数声明有默认参数，函数实现就不能有默认参数。因为会出现二义性。

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 3.1 函数默认参数
#include<iostream>
using namespace std;

//函数默认参数
// 1.如果某个位置已经有了默认参数，那么从这个位置往后，从左至右都必须有默认值
// int func(int a, int b=20, int c=30, int d){
//    return a + b + c;
// }

// int func2(int a = 10, int b = 10);
int func2(int a = 10, int b = 10){
    return a + b;
}
int main(){
    cout << func2(10, 30) << endl;

    return 0;
}
```

### 3.2 函数的占位参数

也就是占着坑不拉……

函数的形参列表中可以有占位参数，用来做占位，调用函数时必须填补该位置

**语法**：`返回值类型 函数名(数据类型){}`

**示例**：

```c++
int func(int a = 10, int){
    cout << "this is a function" << endl;
}
int main(){
    func(10);

    return 0;
}
```

后面会详细介绍……

### 3.3 函数重载

#### 3.3.1 函数重载基本概述

**作用**：函数名可以相同，提高复用性

**函数重载的满足条件**：

- 同一个作用域下
- 函数名称相同
- 函数的参数**类型不同** 或 **个数不同** 或 **顺序不同**

**注意**：函数的返回值不可以作为函数重载的条件

#### 3.3.2 函数重载注意事项

- 引用作为重载条件
- 函数重载碰到默认参数

**示例**：

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 3.3 函数重载的注意事项
#include<iostream>
using namespace std;


// 1.引用作为函数重载的条件
void func(int &a){
    cout << "func(int &a)调用" << endl;
}
void func(const int &a){
    cout << "func(const int &a)调用" << endl;
}

//2.函数重载碰到默认参数
void func2(int a){
    cout << "func2(int a)调用" << endl;
}

void func2(int a, int b = 10){
    cout << "func2(int a, int b)调用" << endl;
}
int main(){
    int a = 10;
    // func(a); //走 func(int &a)调用
    // func(10); //走 func(const int &a)调用
    func2(10); // 当函数重载碰见默认参数会出现二义性，在写代码的时候尽量避免这种情况

    return 0;
}
```



## 4. 类和对象

C++面向对象的三大特性：封装、继承、多态

C++认为万物皆可为对象，对象上有其属性和行为

具有相同性质的**对象**，我们可以抽象为**类**，人属于人类，车属于车类。

### 4.1 封装

#### 4.1.1 封装的意义

封装的意义：

- 一、将属性和行为作为一个整体，表现生活中的事物
- 二、将属性和行为加以权限控制

**意义一**：

在设计类的时候，将属性和行为写在一起，表现事物

**语法**：`class 类名{ 访问权限：属性/行为 };`

**示例1**：设计一个圆类，求圆的周长

```c++
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
```

#### 4.1.2 访问权限

访问权限有三种：

- public：公共权限
- private：私有权限
- protect：保护权限

```c++
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
```

#### 4.1.3 struct和class的区别

在c++中，struct和class的唯一区别在于默认的访问权限不一样

区别：

- struct默认访问权限为公有
- class  默认访问权限为私有

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.1.3 struct和class的区别
#include<iostream>
using namespace std;
class C1{
    int m_A; //默认权限是私有
};
struct S1{
    int m_A; // 默认权限是公有
};
int main(){
    // struct和class的区别
    C1 c1;
    // c1.m_A = 10; // 不可以访问
    S1 s1;
    s1.m_A = 10;

    return 0;
}
```

#### 4.1.4 成员属性设为私有

**优点1**：将所有成员属性设置为私有，可以自己控制读写权限

**优点2**：对于写权限，我们可以检测数据的有效性

```c++
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
```

### 4.2 对象的初始化和清理

#### 4.2.1 构造函数和析构函数

**构造函数语法**：`类名(){}`

- 构造函数没有返回值，也不写void
- 构造函数名与类名相同
- 构造函数可以有参数，因此可以发生重载
- 程序在创建对象的时候会自动调用构造函数，无需手动调用，而且只需要调用一次

**析构函数语法**：`~类名(){}`

- 析构函数没有返回值，也不写void
- 函数名与类名相同，并在前面加上~
- 析构函数**不可以**有参数，因此不可以发生重载
- 程序在对象销毁的时候会自动调用析构函数，无需手动调用，而且只需要调用一次

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.1 构造函数和析构函数
#include<iostream>
#include<string>
using namespace std;
class Person{
public:
    Person(){
        cout << "构造函数调用" << endl;
    }
    ~Person(){
        cout << "~析构函数调用" << endl;
    }
};
void test01(){
    Person p; //在栈上的数据，函数调用完毕对象会被销毁，自动调用析构函数
}
int main(){
    test01();
    return 0;
}
```

#### 4.2.2 函数的分类和调用

两种分类方式：

- 按参数分为：有参构造和无参构造
- 按类型分为：普通构造和拷贝构造

```c++
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
```

#### 4.2.3 拷贝构造函数调用时机

拷贝构造函数的调用时机一般分为三种情况

- 使用一个已经创建完毕的对象来创建另一个对象
- 值传递的方式给函数传值
- 以值方式返回给局部对象

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.3 拷贝构造函数的调用时机
#include<iostream>
#include<string>
using namespace std;
class Person{
public:
    Person(){
        cout << "默认构造函数调用" << endl;
    }
    Person(int age){
        this->age = age;
        cout << "有参构造函数调用" << endl;
    }
    Person(const Person &p){
        this->age = p.age;
        cout << "拷贝构造函数调用" << endl;
    }
    ~Person(){
        cout << "~析构函数调用" << endl;
    }
    int age;
};
 // 1.使用一个已经创建完毕的对象来创建另一个对象
void test01(){
    Person p1(12);
    Person p2(p1);
    cout << "p2的年龄：" << p2.age << endl;
}
// 2. 值传递的方式给函数传值
// 实参传给形参的时候，调用了拷贝构造函数
void doWork(Person p){

}
void test02(){
    Person p;
    doWork(p);
}

// 3. 以值方式返回给局部对象
// 【？】待解决：这种跑出来的结果没有调用拷贝构造函数
Person doWork2(){
    Person p1;
    cout << (int*)&p1 << endl;
    return p1;
}
void test03(){
    Person p = doWork2();
     cout << (int*)&p << endl;
}
int main(){
    test03();
    return 0;
}
```

#### 4.2.4 构造函数调用规则

默认情况下，c++编译器至少会给一个类添加3个函数

- 默认构造函数（无参，函数体为空）
- 默认析构函数（无参，函数体为空）
- 默认拷贝构造函数，对属性进行值拷贝



拷贝构造函数的调用规则如下：

- 如果用户定义有参构造函数，C++则不再提供无参构造函数，但是会提供默认拷贝构造函数
- 如果用户定义拷贝构造函数，C++则不再定义其他构造函数，但是你可以自己定义有参或者无参构造函数

**示例**：

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 4.2.4 构造函数的调用规则
#include<iostream>
#include<string>
using namespace std;

class Person{
public:
    // Person(){
    //     cout << "Person的默认构造函数"<<endl;
    // }
    ~Person(){
        cout << "Person的析构函数"<<endl;
    }
    Person(int age){
        this->age = age;
        cout << "Person的有参构造函数"<<endl;
    }
    // Person(const Person &p){
    //     this->age = p.age;
    //     cout << "Person的拷贝构造函数"<<endl;
    // }

    int age;
};

// void test01(){
//     Person p1;
//     Person p2(10);
//     Person p3(p2);
// }

void test02(){
    // Person p1;
    Person p2(10);
    Person p3(p2);
}

int main(){
    test02();
    return 0;
}
```



#### 4.2.5 深拷贝和浅拷贝

深拷贝和浅拷贝是面试经常会问到的问题，也是常见的一个坑。

浅拷贝：简单的赋值拷贝操作；编译器里面提供的默认拷贝操作

深拷贝：在堆区重新申请空间，进行拷贝操作



浅拷贝带来的问题就是堆区带来的重复释放。

![image-20210202202444328](.\img\image-20210202202444328.png)

通过深拷贝，解决浅拷贝带来的问题。

![image-20210202202649717](.\img\image-20210202202649717.png)

```c++
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
```

> 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题。



#### 4.2.6 构造函数初始化列表

**作用**：c++提供了初始化列表的语法，用来初始化属性

**语法**：`构造函数():属性1(值1),属性2(值2)...{}`

![image-20210202204531239](.\img\image-20210202204531239.png)

#### 4.2.7类对象做类成员

c++类中的成员可以是另一个类的对象，我们称该成员为 **对象成员**

示例：

```c++
class A{};
class B{
    A a;
}
```

问题：当创建B对象时，A与B的构造和析构哪个先哪个后？



### 4.4 友元

生活中的家有客厅、卧室等，一般对于客厅是public(允许所有客人访问)的，但是对于卧室而言，应该是private(这个访问权限可能只提供给自己)的。

但是呢，你的卧室也可以允许你信赖的人(比如朋友)进去。这就是友元的形象概念。



在程序中，有些私有属性，也想让类外一些特殊的函数或者类进行访问，就需要用到友元的技术。

友元的目的就是一个函数或者类访问另一个类的私有变量。



友元的关键字为：**friend**

友元的三种实现：

- 全局函数做友元
- 类做友元
- 类中成员函数做友元

#### 4.4.1 全局函数做友元

用法：

将全局函数的声明前面加一个friend关键字，写到类函数中即可，如下代码块中：

```c++
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
```

输出：

好基友全局函数 正在访问客厅

好基友全局函数 正在访问卧室

#### 4.4.2 类做友元函数

```c++
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
```

输出：

好基友类 正在访问客厅

好基友类 正在访问卧室

#### 4.4.3 成员函数做友元

```c++
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
    cout << "好基友成员函数 正在访问" << building->m_SittingRoom << endl;
    cout << "好基友成员函数 正在访问" << building->m_BedRoom << endl;
} 
void GoodGay::visit2(){
    cout << "好基友成员函数 正在访问" << building->m_SittingRoom << endl;
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
```

输出：

好基友成员函数visit() 正在访问客厅

好基友成员函数visit() 正在访问卧室

好基友成员函数visit2() 正在访问客厅

**注意：**这里的类定义和声明的顺序，如果顺序乱了，后面的**building->m_BedRoom**也会报错！！！！！

### 4.6 继承

继承，是面向对象的第二大特征。

#### 4.6.1 基本语法







### 4.7 多态

#### 4.7.1 多态基本语法

**多态是C++面向对象三大特性之一**

多态分为两类：

- 静态多态：函数重载和运算符重载属于静态多态，复用函数名，以多种形态表现
- 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态的区别：

- 静态多态的函数地址**早绑定**：编译阶段确定函数地址
- 动态多态的函数地址**晚绑定**：运行阶段确定函数地址

**案例：**

```c++
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

//输出
小猫在说话
小狗在说话
```

**总结：**

   动态多态需要满足的条件：

1. 有继承关系
2. 子类要重写父类的虚函数，即Cat类需要重写Animal的虚函数speak，**注意不是重载，函数名和参数列表应该完全相同**！

   动态多态使用：
   父类的指针或引用**指向**子类的对象，就可以实现动态的多态。

   **重写：**函数返回值类型 函数名 参数列表 完全一致称为重写

#### 4.7.2 多态的原理剖析

探究一下加了`virtual`关键字之后发生了什么：

```c++
// Copyright (c) 2021 Qihoo
// License(BSD/GPL/...)
// Author: blackzero
// 02 多态原理剖析

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

// 查看类大小
void test02(){
    cout << "size of Animal = " << sizeof(Animal) << endl;
}
int main(){
    test02();
    return 0;
}
```

- 不加`virtual`字段的输出为：size of Animal = 1
- 加上`virtual`字段的输出为：size of Animal = 8

**解释：**这里size of Animal变化的原因是：增加了一个指针，在64为操作系统下，指针大小占8个字节；在32位操作系统下，指针大小占4个字节。



#### 4.7.3 案例 实现计算器类

