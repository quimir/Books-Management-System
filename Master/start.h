#ifndef _Start_H
#define _Start_H
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
//如果想启用中文的输入请解除此屏蔽
//失败未能解决类型不匹配的问题
// #define VS_H
#define tab "\t"
class System
{
public:
    /// @brief 对这一次的选择值进行查看，本函数是不能更改的
    /// @return 返回这一次的返回值
    int readNumber() const;

    /// @brief 对上一次的返回值进行查看，本函数是不能更改的
    /// @return 返回上一次的选择值
    int readNumberDouble() const;

    /// @brief 对这一次的选择进行更改
    /// @param number 这一次选择的值
    void alterNumber(int);

    /// @brief 对上一次的返回值进行更改
    /// @param number 上一次的选择值
    void alterNumberDouble(int);



private:
    //记录这一次选择的值
    int _number;
    //记录上一次的选择值
    int _numberDouble;

public:
    // 用枚举的手段实现中文可能输入失败的问题
    enum SystemBook
    {
        Ebook = 1,
        Eperiodical
    };
};
#endif