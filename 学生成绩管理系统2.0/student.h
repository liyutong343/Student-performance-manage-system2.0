//student.h
#pragma once
#include "ab.h"

//学生类
class student :virtual public ab
{
public:
	//默认构造函数
	student();
	//含参构造函数
	student(string n);
	//运算符重载：输入
	friend istream& operator >> (istream&, student&);
	//显示信息
	virtual void display();
	//获取姓名
	string get_name();

protected:
	//姓名
	string name;

};