//student.h
#pragma once
#include "ab.h"

//ѧ����
class student :virtual public ab
{
public:
	//Ĭ�Ϲ��캯��
	student();
	//���ι��캯��
	student(string n);
	//��������أ�����
	friend istream& operator >> (istream&, student&);
	//��ʾ��Ϣ
	virtual void display();
	//��ȡ����
	string get_name();

protected:
	//����
	string name;

};