//curriculum.h
#pragma once
#include "ab.h"

//�γ���
class curriculum :virtual public ab
{
public:
	//Ĭ�Ϲ��캯��
	curriculum();
	//���ι��캯��
	curriculum(string cur,int c);
	//��������أ�����
	friend istream& operator >> (istream&, curriculum&);
	//��ʾ��Ϣ
	virtual void display();
	//��ȡ�γ�����
	string get_curname();
	//��ȡѧ��
	int get_credit();

protected:
	//�γ�����
	string curname;
	//ѧ��
	int credit;
};
