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

//��������أ�����
istream& operator >> (istream& input, curriculum& c)
{
	string n;
	int cre;
	cout << "������γ����ƣ�" << endl;
	cin >> n;
	cout << "������ѧ�֣�" << endl;
	cin >> cre;
	c.curname = n;
	c.credit = cre;
	return input;
}

//��ʾ��Ϣ
void curriculum::display()
{
	cout << setw(20) << curname << setw(5) << credit;
}

//��ȡ�γ�����
string curriculum::get_curname()
{
	return curname;
}

//��ȡѧ��
int curriculum::get_credit()
{
	return credit;
}