//information.cpp
#include"information.h"

//Ĭ�Ϲ��캯��
information::information()
{

}

//���ι��캯��
information::information(string n, string c, int cre, int sc):student(n),curriculum(c,cre)
{
	//learn_no();
	score = sc;
	scoretograde();
	gp = scoretogp();
}

//�������
void information::set_no(int i)
{
	no = i;
}

//��ʾ��Ϣ
void information::display()
{
	cout << setiosflags(ios::left) << setw(5) << no << setw(10) << name
		<< setw(20) << curname << setw(5) << credit << setw(15) << score
		<< setw(15) << grade << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << gp << resetiosflags(ios::fixed) << endl;
}



//��������أ����
ostream& operator << (ostream& output, information& s)
{
	output << setiosflags(ios::left) << setw(5) << s.no << setw(10) << s.name
		<< setw(20) << s.curname << setw(5) << s.credit << setw(15) << s.score
		<< setw(15) << s.grade << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << s.gp << resetiosflags(ios::fixed) << endl;
	return output;
}

//��������أ�����
istream& operator >> (istream& input, information& s)
{
	cout << "������ѧ��������" << endl;
	cin >> s.name;
	cout << "������γ����ƣ�" << endl;
	cin >> s.curname;
	cout << "������ѧ�֣�" << endl;
	cin >> s.credit;
	cout << "������ٷ��Ƴɼ���" << endl;
	cin >> s.score;
	s.scoretograde();
	s.gp = s.scoretogp();

	return input;
}

//��������أ��ļ����
fstream& operator << (fstream& output, information& s)
{
	output << setiosflags(ios::left) << setw(5) << s.no << setw(10) << s.name
		<< setw(20) << s.curname << setw(5) << s.credit << setw(15) << s.score
		<< setw(15) << s.grade << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << s.gp << resetiosflags(ios::fixed) << endl;
	return output;
}

//��������أ��ļ�����
ifstream& operator >> (ifstream& input, information& s)
{
	input >> s.no >> s.name >> s.curname >> s.credit >> s.score >> s.grade >> s.gp;
	return input;
}


//���ɵȼ��Ƴɼ�
string information::scoretograde()
{
	if (score > 100)
		cout << "ע�⣬�ٷ��Ƴɼ�Խ�磡" << endl;
	else if (score == 100)
		grade = "A+";
	else if (score >= 95)
		grade = "A";
	else if (score >= 90)
		grade = "A-";
	else if (score >= 85)
		grade = "B+";
	else if (score >= 80)
		grade = "B";
	else if (score >= 77)
		grade = "B-";
	else if (score >= 73)
		grade = "C+";
	else if (score >= 70)
		grade = "C";
	else if (score >= 67)
		grade = "C-";
	else if (score >= 63)
		grade = "D+";
	else if (score >= 60)
		grade = "D";
	else if (score >= 0)
		grade = "F";
	else
	{
		cout << "ע�⣬�ٷ��Ƴɼ�Խ�磡" << endl;
		grade = "N/A";
	}
	return grade;
}

//���ɼ���
float information::scoretogp()
{
	if (score > 100)
		return 0.0f;
	else if (score >= 90)
		return 4.0f;
	else if (score >= 85)
		return 3.6f;
	else if (score >= 80)
		return 3.3f;
	else if (score >= 77)
		return 3.0f;
	else if (score >= 73)
		return 2.6f;
	else if (score >= 70)
		return 2.3f;
	else if (score >= 67)
		return 2.0f;
	else if (score >= 63)
		return 1.6f;
	else if (score >= 60)
		return 1.3f;
	else
		return 0.0f;
}

//��ȡ�ٷ��Ƴɼ�
int information::get_score()
{
	return score;
}

//��ȡ�ȼ��Ƴɼ�
string information::get_grade()
{
	return grade;
}

//��ȡ����
float information::get_gp()
{
	return gp;
}
