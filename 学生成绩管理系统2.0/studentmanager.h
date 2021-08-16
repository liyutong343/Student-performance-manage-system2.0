//studentmanager.h
#pragma once
#include "information.h"

class StudentManager
{
public:
	//构造函数
	StudentManager();

	//展示主菜单：运算符重载
	friend ostream& operator << (ostream&, StudentManager&);

	//0 退出系统
	void Exit_System();

	//1 录入学生成绩
	void Add_Info();

	//2 查询某条成绩信息
	void Search_Info();

	//3 修改某条成绩信息
	void Modify_Info();

	//4 统计某个学生的全部成绩信息
	void Count_Stu();

	//5 统计某门课程的全部成绩信息
	void Count_Cur();

	//打印表头
	void print_title();

	//从文件中得到已有个数
	int learn_no();

	//保存文件
	void save();

	//析构函数
	~StudentManager();
	   
	//学生个数
	int Student_Num;

	//学生数组的指针
	information * Student_Array;

};