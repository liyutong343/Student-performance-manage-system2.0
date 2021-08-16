//student.cpp
#include "student.h"

//默认构造函数
student::student()
{

}

//含参构造函数
student::student(string n)
{
	name = n;
}

//运算符重载：输入
istream& operator >> (istream& input, student& s)
{
	string n;
	cout << "请输入学生姓名：" << endl;
	cin >> n;
	s.name = n;
	return input;
}

//显示信息
void student::display()
{
	cout << setiosflags(ios::left) << setw(10) << name;
}

//获取姓名
string student::get_name()
{
	return name;
}