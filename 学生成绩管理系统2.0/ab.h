//ab.h
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//抽象类（不需要cpp文件来实现）
class ab
{
public:
	//显示信息
	virtual void display() = 0;
	//设置信息序号
	virtual void set_no(int i) = 0;
	//信息序号
	int no;
};