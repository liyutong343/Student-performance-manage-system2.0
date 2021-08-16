//studentmanager.cpp
#include "studentmanager.h"
#include "information.h"

//���캯��
StudentManager::StudentManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open("student.dat", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		//��ʼ��ѧ������
		Student_Num = 0;
		//��ʼ��ѧ������
		Student_Array = NULL;
		ifs.close();
		return;
	}

	//�ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;//����һ���ַ�
	if (ifs.eof())//������β
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		//��ʼ��ѧ������
		Student_Num = 0;
		//��ʼ��ѧ������
		Student_Array = NULL;
		ifs.close();
		return;
	}
	//�ļ����ڣ����Ѿ�������
	else
	{
		Student_Num = learn_no();
		Student_Array = new information[Student_Num+1];
		ifs.seekg(0, ios::beg);
		for (int i = 0;i < Student_Num;i++)
		{
			ifs.seekg(i*77, ios::beg);
			ifs >> Student_Array[i];
			Student_Array[i].no = i + 1;
		}
		ifs.close();
	}
	
}

//��ʾ���˵������������
ostream& operator << (ostream& output, StudentManager& sm)
{
	cout << endl << "�� * �� * �� * �� * �� * �� * �� * �� * �� * �� * �� " << endl;
	cout << endl << "* * * * * * * * * ѧ���ɼ�����ϵͳ * * * * * * * * *" << endl;
	cout << endl << "�� * �� * �� * �� * �� * �� * �� * �� * �� * �� * �� " << endl;
	cout << "                  _                          _ " << endl;
	cout << "    __      _____| | ___ ___  _ __ ___   ___| |" << endl;
	cout << "    \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ |" << endl;
	cout << "     \\ V  V /  __/ | (_| (_) | | | | | |  __/_|" << endl;
	cout << "      \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___(_)" << endl;
	cout << endl << "��ӭʹ��ѧ���ɼ�����ϵͳ��" << endl;
	cout << "��ѡ����Ҫʹ�õĹ��ܣ�" << endl;
	cout << "1 ¼��ѧ���ɼ�" << endl;
	cout << "2 ��ѯĳ���ɼ���Ϣ" << endl;
	cout << "3 �޸�ĳ���ɼ���Ϣ" << endl;
	cout << "4 ͳ��ĳ��ѧ����ȫ���ɼ���Ϣ" << endl;
	cout << "5 ͳ��ĳ�ſγ̵�ȫ���ɼ���Ϣ" << endl;
	cout << "0 �˳�" << endl;
	return output;
}

//0 �˳�ϵͳ
void StudentManager::Exit_System()
{
	cout << endl << "��лʹ��ѧ���ɼ�����ϵͳ����ӭ�´�ʹ�ã�" << endl;
	cout << endl << "      ____               _                _ " << endl;
	cout << "     | __ ) _   _  ___  | |__  _   _  ___| |" << endl;
	cout << "     |  _ \\| | | |/ _ \\ | '_ \\| | | |/ _ \\ |" << endl;
	cout << "     | |_) | |_| |  __/ | |_) | |_| |  __/_|" << endl;
	cout << "     |____/ \\__, |\\___| |_.__/ \\__, |\\___(_)" << endl;
	cout << "            |___/              |___/        " << endl;
	cout << endl << "�� * �� * �� * �� * �� * �� * �� * �� * �� * �� * �� " << endl;
	cout << endl << "* * * * * * * * * ѧ���ɼ�����ϵͳ * * * * * * * * *" << endl;
	cout << endl << "�� * �� * �� * �� * �� * �� * �� * �� * �� * �� * �� " << endl;
	exit(0);
}

//1 ¼��ѧ���ɼ�
void StudentManager::Add_Info()
{

	//¼������
	Student_Num++;

	//�����¿ռ�
	information * newspace = new information[Student_Num];

	//��ԭ�ռ����ݿ������¿ռ�
	if (Student_Array != NULL)
	{
		for (int i = 0;i < Student_Num - 1;i++)
		{
			newspace[i] = Student_Array[i];
		}
	}

	//¼������
	cin >> newspace[Student_Num - 1];
	newspace[Student_Num - 1].set_no(Student_Num);

	//�ͷ�ԭ�пռ�
	delete[]Student_Array;

	//����ָ��
	Student_Array = newspace;

	//¼��ɹ���ʾ
	cout << "¼��ɹ���" << endl;
	print_title();
	cout << Student_Array[Student_Num-1];
	
	//���浽�ļ�
	save();
}

//2 ��ѯĳ���ɼ���Ϣ
void StudentManager::Search_Info()
{
	int goal;
	cout << "��������Ҫ��ѯ����Ϣ��Ŀ����ţ�" << endl;
	cin >> goal;
	if (goal<0 || goal>Student_Num)
		cout << endl << "��Ϣ��Ŀ�����ڣ�" << endl;
	else
	{
		cout << endl << "��ѯ�����" << endl;
		print_title();
		cout << Student_Array[goal - 1];
	}
	
}

//3 �޸�ĳ���ɼ���Ϣ
void StudentManager::Modify_Info()
{
	int goal,choice=0;
	cout << "��������Ҫ�޸ĵ���Ϣ��Ŀ����ţ�" << endl;
	cin >> goal;
	if (goal<0 || goal>Student_Num)
		cout << endl << "��Ϣ��Ŀ�����ڣ�" << endl;
	else
	{
		cout << endl << "��ѯ�����" << endl;
		print_title();
		cout << Student_Array[goal - 1];

		while (choice != 1 && choice != 2)
		{
			cout << endl << "�Ƿ��޸ģ�" << endl << "1 ��" << endl << "2 ��" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cin >> Student_Array[goal - 1];
				cout << endl << "�޸ĳɹ����޸Ľ����" << endl;
				print_title();
				cout << Student_Array[goal - 1];
				save();
			}
			else if (choice != 2)
			{
				cout << "���벻��ȷ��������1��2��" << endl;
			}
		}
	}

}

//4 ͳ��ĳ��ѧ����ȫ���ɼ���Ϣ
void StudentManager::Count_Stu()
{
	int creditsum = 0;
	float gpsum = 0;
	float gpa;
	string goal;
	int i, nameflag = 1;

	cout << endl << "��������Ҫͳ����ɼ���ѧ������:" << endl;
	cin >> goal;

	for (i = 0;i <Student_Num;i++)
	{
		if (Student_Array[i].get_name()==goal)
		{
			if (nameflag)
			{
				nameflag = 0;
				cout << endl << "��ѯ�ɹ�����Ϣ���£�" << endl;
				print_title();
			}
			creditsum = creditsum + Student_Array[i].get_credit();
			gpsum = gpsum + Student_Array[i].get_gp()*Student_Array[i].get_credit();
			cout << Student_Array[i];
		}
	}
	if (nameflag)
	{
		cout << "û���ҵ���ѧ������Ϣ��" << endl;
	}
	else
	{
		gpa = gpsum / (float)creditsum;
		cout << goal << "��gpaΪ" << setiosflags(ios::fixed) << setprecision(2) << gpa << endl;
	}

}

//5 ͳ��ĳ�ſγ̵�ȫ���ɼ���Ϣ
void StudentManager::Count_Cur()
{
	int sum = 0;
	int scoresum = 0;
	float ave;
	string goal;
	int i, nameflag = 1;

	cout << endl << "��������Ҫͳ����ɼ��Ŀγ�����:" << endl;
	cin >> goal;

	for (i = 0;i < Student_Num;i++)
	{
		if (Student_Array[i].get_curname() == goal)
		{
			if (nameflag)
			{
				nameflag = 0;
				cout << endl << "��ѯ�ɹ�����Ϣ���£�" << endl;
				print_title();
			}
			sum++;
			scoresum = scoresum + Student_Array[i].get_score();
			cout << Student_Array[i];
		}
	}
	if (nameflag)
	{
		cout << "û���ҵ��ÿγ̵���Ϣ��" << endl;
	}
	else
	{
		ave = (float)scoresum / (float)sum;
		cout << goal << "��ƽ���ٷ��Ƴɼ�Ϊ" << setiosflags(ios::fixed) << setprecision(2) << ave << endl;
	}
}

//��ӡ��ͷ
void StudentManager::print_title()
{
	cout << setiosflags(ios::left) << setw(5) << "���" << setw(10) << "����"
		<< setw(20) << "�γ�����" << setw(5) << "ѧ��" << setw(15) << "�ٷ��Ƴɼ�"
		<< setw(15) << "�ȼ��Ƴɼ�" << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << "����" << resetiosflags(ios::fixed) << endl;
}

//���ļ��еõ����и���
int StudentManager::learn_no()
{
	int num;
	ifstream infile1("student.dat", ios::in);			//��ȡ��Ϣ��Ŀ�����
	if (!infile1)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	char ch;
	infile1 >> ch;//����һ���ַ�
	if (infile1.eof())//������β
		num = 0;
	else
	{
		infile1.seekg(-77, ios::end);
		infile1 >> num;
	}
	infile1.close();

	return num;
}

//�����ļ�
void StudentManager::save()
{
	ofstream outfile;

	//���ļ�
	outfile.open("student.dat", ios::out);
	//�ж��ļ��Ƿ�򿪳ɹ�
	if (!outfile)
	{
		cerr << "open error!??" << endl;
		exit(1);
	}

	//������д���ļ���
	for (int i=0;i < Student_Num;i++)
	{
		outfile << Student_Array[i];
	}

	//�ر��ļ�
	outfile.close();
}

StudentManager::~StudentManager()
{
	//�ֶ��ͷŶ�������
	if (Student_Array != NULL)
	{
		delete[]Student_Array;
		Student_Array = NULL;
	}

}