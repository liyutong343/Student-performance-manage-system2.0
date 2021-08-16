//学生成绩管理系统2.0.cpp
#include "studentmanager.h"
#include <ctime>
using namespace std;

int main()
{
	//实例化
	StudentManager sm;
	int OPTION = 0, option = 0;
	while (true)
	{
		system("cls");
		cout << sm;//显示主菜单
		cin >> OPTION;//得到用户的选项
		switch (OPTION)
		{
		case 0://0 退出系统
			sm.Exit_System();
			break;
		case 1://1 录入学生成绩
			while (true)
			{
				option = 0;

				sm.Add_Info();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续录入？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}

			break;
		case 2://2 查询某条成绩信息
			while (true)
			{
				option = 0;

				sm.Search_Info();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续查询？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
			break;
		case 3://3 修改某条成绩信息
			while (true)
			{
				option = 0;

				sm.Modify_Info();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续修改？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
			break;
		case 4://4 统计某个学生的全部成绩信息
			while (true)
			{
				option = 0;

				sm.Count_Stu();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续统计？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
			break;
		case 5://5 统计某门课程的全部成绩信息
			while (true)
			{
				option = 0;

				sm.Count_Cur();

				while (option != 1 && option != 2)
				{
					cout << endl << "是否继续统计？" << endl << "1 继续" << endl << "2 返回主菜单" << endl;
					cin >> option;
					if (option != 1 && option != 2)
						cout << "输入不正确！请输入1或2！" << endl;
				}
				if (option == 1)
					continue;
				if (option == 2)
					break;
			}
			break;
		default:
		{
			cout << "请输入0~6之间的整数！5秒后返回主菜单！" << endl;
			double pretime = clock();
			while (true)
			{
				if (clock() - pretime > 5000)
					break;
			}
			break;
		}

		}
	}

	return 0;
}
