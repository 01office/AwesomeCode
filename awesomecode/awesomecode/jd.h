//
//  jd.h
//  awesomecode
//
//  Created by heyong on 2016/12/19.
//  Copyright © 2016年 heyong. All rights reserved.
//

#ifndef jd_h
#define jd_h

#include <iostream>

class A
{
public:
    A(){std::cout << "construct A" << std::endl;}
    ~A(){std::cout << "destruct A" << std::endl;}
    virtual void fun1() = 0;
    virtual void fun2(){std::cout << "A fun2" << std::endl; this->fun3();}
    void fun3(){std::cout << "A fun3" << std::endl;}
};

class B: public A
{
public:
    B(){std::cout << "construct B" << std::endl;}
    ~B(){std::cout << "destruct B" << std::endl;}
    virtual void fun1(){std::cout << "B fun1" << std::endl; this->fun2();}
    void fun2(){std::cout << "B fun2" << std::endl;}
    void fun3(){std::cout << "B fun3" << std::endl;}
    void doSth(){std::cout << "B do sth" << std::endl; fun1();}
};

#endif /* jd_h */
