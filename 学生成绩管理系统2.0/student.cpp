//student.cpp
#include "student.h"

//Ĭ�Ϲ��캯��
student::student()
{

}

//���ι��캯��
student::student(string n)
{
	name = n;
}

//��������أ�����
istream& operator >> (istream& input, student& s)
{
	string n;
	cout << "������ѧ��������" << endl;
	cin >> n;
	s.name = n;
	return input;
}

//��ʾ��Ϣ
void student::display()
{
	cout << setiosflags(ios::left) << setw(10) << name;
}

//��ȡ����
string student::get_name()
{
	return name;
}