//curriculum.cpp
#include"curriculum.h"

curriculum::curriculum()
{

}

curriculum::curriculum(string cur,int c)
{
	curname = cur;
	credit = c;
}

//运算符重载：输入
istream& operator >> (istream& input, curriculum& c)
{
	string n;
	int cre;
	cout << "请输入课程名称：" << endl;
	cin >> n;
	cout << "请输入学分：" << endl;
	cin >> cre;
	c.curname = n;
	c.credit = cre;
	return input;
}

//显示信息
void curriculum::display()
{
	cout << setw(20) << curname << setw(5) << credit;
}

//获取课程名称
string curriculum::get_curname()
{
	return curname;
}

//获取学分
int curriculum::get_credit()
{
	return credit;
}