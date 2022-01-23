//
// Created by Rubus on 2022/1/23.
//
#include "iostream"

using namespace std;

#define Day 7

/**
 * 3. const对象默认为文件局部变量
 * 非const变量默认为extern。要使const变量能够在其他文件中访问，必须在文件中显式地指定它为extern。
 */

int main() {

    /**
     * 4.定义常量
     */

    // 不同文件const常量访问
    extern const int ext;
    cout << ext << endl;

    const int month = 12;
    cout << "one week has " << Day << " day" << endl;
    cout << "one year has " << month << " month" << endl;

    const int b = 10;
    cout << b << endl;
    //error: assignment of read-only variable 'b'
    //b = 0;

    const string s = "HelloWorld";
    cout << s << endl;
    //error: uninitialized 'const i'
    //const int i, j = 0;

    /**
     * 5.指针与const
     *
     * const char * a; //指向const对象的指针或者说指向常量的指针。
     * char const * ab; //同上
     * char * const abc; //指向类型对象的const指针。或者说常指针、const指针。
     * const char * const abcd; //指向const对象的const指针。
     */

    //1. 指向常量的指针
    const int *ptr;
    /**
     * ptr是一个指向int类型const对象的指针，const定义的是int类型，也就是ptr所指向的对象类型，
     * 而不是ptr本身，所以ptr可以不用赋初始值。但是不能通过ptr去修改所指对象的值。
     */
    //error: assignment of read-only location '* ptr'
    //*ptr = 10;
    cout << ptr << endl;

    const int p = 10;
    //void 指针表示未知类型的指针
    const void * vp = &p;
    cout << "vp is " << vp << endl;

    //2. 常指针
    int num=0;
    int * const ptr1=&num; //const指针必须初始化！且const指针的值不能修改
    int * t = &num;
    *t = 1;
    cout<<*ptr1<<endl;

    //3. 指向常量的常指针
    const int p1 = 3;
    const int * const ptr2 = &p1;



    return 0;
}
