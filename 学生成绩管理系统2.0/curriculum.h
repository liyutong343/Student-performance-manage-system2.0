//curriculum.h
#pragma once
#include "ab.h"

//课程类
class curriculum :virtual public ab
{
public:
	//默认构造函数
	curriculum();
	//含参构造函数
	curriculum(string cur,int c);
	//运算符重载：输入
	friend istream& operator >> (istream&, curriculum&);
	//显示信息
	virtual void display();
	//获取课程名称
	string get_curname();
	//获取学分
	int get_credit();

protected:
	//课程名称
	string curname;
	//学分
	int credit;
};
