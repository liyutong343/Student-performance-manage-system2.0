//information.h
#pragma once
#include"student.h"
#include"curriculum.h"

//信息类
class information :public student, public curriculum
{
public:
	//默认构造函数
	information();
	//含参构造函数
	information(string n, string c, int cre, int sc);
	//设置信息序号
	virtual void set_no(int i);
	//显示信息
	virtual void display();
	//运算符重载：输出
	friend ostream& operator << (ostream&, information&);
	//运算符重载：输入
	friend istream& operator >> (istream&, information&);
	//运算符重载：文件输出
	friend fstream& operator << (fstream&, information&);
	//运算符重载：文件输入
	friend ifstream& operator >> (ifstream&, information&);
	//生成等级制成绩
	string scoretograde();
	//生成绩点
	float scoretogp();
	//获取百分制成绩
	int get_score();
	//获取等级制成绩
	string get_grade();
	//获取绩点
	float get_gp();

private:
	//百分制成绩
	int score;
	//等级制成绩
	string grade;
	//绩点
	float gp;

};