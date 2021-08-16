//information.h
#pragma once
#include"student.h"
#include"curriculum.h"

//��Ϣ��
class information :public student, public curriculum
{
public:
	//Ĭ�Ϲ��캯��
	information();
	//���ι��캯��
	information(string n, string c, int cre, int sc);
	//������Ϣ���
	virtual void set_no(int i);
	//��ʾ��Ϣ
	virtual void display();
	//��������أ����
	friend ostream& operator << (ostream&, information&);
	//��������أ�����
	friend istream& operator >> (istream&, information&);
	//��������أ��ļ����
	friend fstream& operator << (fstream&, information&);
	//��������أ��ļ�����
	friend ifstream& operator >> (ifstream&, information&);
	//���ɵȼ��Ƴɼ�
	string scoretograde();
	//���ɼ���
	float scoretogp();
	//��ȡ�ٷ��Ƴɼ�
	int get_score();
	//��ȡ�ȼ��Ƴɼ�
	string get_grade();
	//��ȡ����
	float get_gp();

private:
	//�ٷ��Ƴɼ�
	int score;
	//�ȼ��Ƴɼ�
	string grade;
	//����
	float gp;

};