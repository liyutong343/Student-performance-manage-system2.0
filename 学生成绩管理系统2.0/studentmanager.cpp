//studentmanager.cpp
#include "studentmanager.h"
#include "information.h"

//构造函数
StudentManager::StudentManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open("student.dat", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		//初始化学生个数
		Student_Num = 0;
		//初始化学生数组
		Student_Array = NULL;
		ifs.close();
		return;
	}

	//文件存在，数据为空
	char ch;
	ifs >> ch;//读走一个字符
	if (ifs.eof())//若到结尾
	{
		cout << "文件为空！" << endl;
		//初始化学生个数
		Student_Num = 0;
		//初始化学生数组
		Student_Array = NULL;
		ifs.close();
		return;
	}
	//文件存在，且已经有数据
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

//显示主菜单：运算符重载
ostream& operator << (ostream& output, StudentManager& sm)
{
	cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
	cout << endl << "* * * * * * * * * 学生成绩管理系统 * * * * * * * * *" << endl;
	cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
	cout << "                  _                          _ " << endl;
	cout << "    __      _____| | ___ ___  _ __ ___   ___| |" << endl;
	cout << "    \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ |" << endl;
	cout << "     \\ V  V /  __/ | (_| (_) | | | | | |  __/_|" << endl;
	cout << "      \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___(_)" << endl;
	cout << endl << "欢迎使用学生成绩管理系统！" << endl;
	cout << "请选择想要使用的功能：" << endl;
	cout << "1 录入学生成绩" << endl;
	cout << "2 查询某条成绩信息" << endl;
	cout << "3 修改某条成绩信息" << endl;
	cout << "4 统计某个学生的全部成绩信息" << endl;
	cout << "5 统计某门课程的全部成绩信息" << endl;
	cout << "0 退出" << endl;
	return output;
}

//0 退出系统
void StudentManager::Exit_System()
{
	cout << endl << "感谢使用学生成绩管理系统！欢迎下次使用！" << endl;
	cout << endl << "      ____               _                _ " << endl;
	cout << "     | __ ) _   _  ___  | |__  _   _  ___| |" << endl;
	cout << "     |  _ \\| | | |/ _ \\ | '_ \\| | | |/ _ \\ |" << endl;
	cout << "     | |_) | |_| |  __/ | |_) | |_| |  __/_|" << endl;
	cout << "     |____/ \\__, |\\___| |_.__/ \\__, |\\___(_)" << endl;
	cout << "            |___/              |___/        " << endl;
	cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
	cout << endl << "* * * * * * * * * 学生成绩管理系统 * * * * * * * * *" << endl;
	cout << endl << "☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ * ☆ " << endl;
	exit(0);
}

//1 录入学生成绩
void StudentManager::Add_Info()
{

	//录入数据
	Student_Num++;

	//开辟新空间
	information * newspace = new information[Student_Num];

	//将原空间数据拷贝到新空间
	if (Student_Array != NULL)
	{
		for (int i = 0;i < Student_Num - 1;i++)
		{
			newspace[i] = Student_Array[i];
		}
	}

	//录入数据
	cin >> newspace[Student_Num - 1];
	newspace[Student_Num - 1].set_no(Student_Num);

	//释放原有空间
	delete[]Student_Array;

	//更新指向
	Student_Array = newspace;

	//录入成功提示
	cout << "录入成功！" << endl;
	print_title();
	cout << Student_Array[Student_Num-1];
	
	//保存到文件
	save();
}

//2 查询某条成绩信息
void StudentManager::Search_Info()
{
	int goal;
	cout << "请输入想要查询的信息条目的序号：" << endl;
	cin >> goal;
	if (goal<0 || goal>Student_Num)
		cout << endl << "信息条目不存在！" << endl;
	else
	{
		cout << endl << "查询结果：" << endl;
		print_title();
		cout << Student_Array[goal - 1];
	}
	
}

//3 修改某条成绩信息
void StudentManager::Modify_Info()
{
	int goal,choice=0;
	cout << "请输入想要修改的信息条目的序号：" << endl;
	cin >> goal;
	if (goal<0 || goal>Student_Num)
		cout << endl << "信息条目不存在！" << endl;
	else
	{
		cout << endl << "查询结果：" << endl;
		print_title();
		cout << Student_Array[goal - 1];

		while (choice != 1 && choice != 2)
		{
			cout << endl << "是否修改？" << endl << "1 是" << endl << "2 否" << endl;
			cin >> choice;
			if (choice == 1)
			{
				cin >> Student_Array[goal - 1];
				cout << endl << "修改成功！修改结果：" << endl;
				print_title();
				cout << Student_Array[goal - 1];
				save();
			}
			else if (choice != 2)
			{
				cout << "输入不正确！请输入1或2！" << endl;
			}
		}
	}

}

//4 统计某个学生的全部成绩信息
void StudentManager::Count_Stu()
{
	int creditsum = 0;
	float gpsum = 0;
	float gpa;
	string goal;
	int i, nameflag = 1;

	cout << endl << "请输入想要统计其成绩的学生姓名:" << endl;
	cin >> goal;

	for (i = 0;i <Student_Num;i++)
	{
		if (Student_Array[i].get_name()==goal)
		{
			if (nameflag)
			{
				nameflag = 0;
				cout << endl << "查询成功！信息如下：" << endl;
				print_title();
			}
			creditsum = creditsum + Student_Array[i].get_credit();
			gpsum = gpsum + Student_Array[i].get_gp()*Student_Array[i].get_credit();
			cout << Student_Array[i];
		}
	}
	if (nameflag)
	{
		cout << "没有找到该学生的信息！" << endl;
	}
	else
	{
		gpa = gpsum / (float)creditsum;
		cout << goal << "的gpa为" << setiosflags(ios::fixed) << setprecision(2) << gpa << endl;
	}

}

//5 统计某门课程的全部成绩信息
void StudentManager::Count_Cur()
{
	int sum = 0;
	int scoresum = 0;
	float ave;
	string goal;
	int i, nameflag = 1;

	cout << endl << "请输入想要统计其成绩的课程名称:" << endl;
	cin >> goal;

	for (i = 0;i < Student_Num;i++)
	{
		if (Student_Array[i].get_curname() == goal)
		{
			if (nameflag)
			{
				nameflag = 0;
				cout << endl << "查询成功！信息如下：" << endl;
				print_title();
			}
			sum++;
			scoresum = scoresum + Student_Array[i].get_score();
			cout << Student_Array[i];
		}
	}
	if (nameflag)
	{
		cout << "没有找到该课程的信息！" << endl;
	}
	else
	{
		ave = (float)scoresum / (float)sum;
		cout << goal << "的平均百分制成绩为" << setiosflags(ios::fixed) << setprecision(2) << ave << endl;
	}
}

//打印表头
void StudentManager::print_title()
{
	cout << setiosflags(ios::left) << setw(5) << "序号" << setw(10) << "姓名"
		<< setw(20) << "课程名称" << setw(5) << "学分" << setw(15) << "百分制成绩"
		<< setw(15) << "等级制成绩" << setw(5) << setiosflags(ios::fixed)
		<< setprecision(1) << "绩点" << resetiosflags(ios::fixed) << endl;
}

//从文件中得到已有个数
int StudentManager::learn_no()
{
	int num;
	ifstream infile1("student.dat", ios::in);			//读取信息条目的序号
	if (!infile1)
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	char ch;
	infile1 >> ch;//读走一个字符
	if (infile1.eof())//若到结尾
		num = 0;
	else
	{
		infile1.seekg(-77, ios::end);
		infile1 >> num;
	}
	infile1.close();

	return num;
}

//保存文件
void StudentManager::save()
{
	ofstream outfile;

	//打开文件
	outfile.open("student.dat", ios::out);
	//判断文件是否打开成功
	if (!outfile)
	{
		cerr << "open error!??" << endl;
		exit(1);
	}

	//将数据写入文件中
	for (int i=0;i < Student_Num;i++)
	{
		outfile << Student_Array[i];
	}

	//关闭文件
	outfile.close();
}

StudentManager::~StudentManager()
{
	//手动释放堆区数据
	if (Student_Array != NULL)
	{
		delete[]Student_Array;
		Student_Array = NULL;
	}

}