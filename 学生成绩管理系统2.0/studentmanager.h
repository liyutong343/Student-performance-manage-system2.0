//studentmanager.h
#pragma once
#include "information.h"

class StudentManager
{
public:
	//���캯��
	StudentManager();

	//չʾ���˵������������
	friend ostream& operator << (ostream&, StudentManager&);

	//0 �˳�ϵͳ
	void Exit_System();

	//1 ¼��ѧ���ɼ�
	void Add_Info();

	//2 ��ѯĳ���ɼ���Ϣ
	void Search_Info();

	//3 �޸�ĳ���ɼ���Ϣ
	void Modify_Info();

	//4 ͳ��ĳ��ѧ����ȫ���ɼ���Ϣ
	void Count_Stu();

	//5 ͳ��ĳ�ſγ̵�ȫ���ɼ���Ϣ
	void Count_Cur();

	//��ӡ��ͷ
	void print_title();

	//���ļ��еõ����и���
	int learn_no();

	//�����ļ�
	void save();

	//��������
	~StudentManager();
	   
	//ѧ������
	int Student_Num;

	//ѧ�������ָ��
	information * Student_Array;

};