#include "show.h"
#include "SystemDelete.h"
void SystemShow::choose(System* _start, SystemAdd* _add)
{
	int number;
	cout << "欢迎来到图书系统\n"
		<< "1.对书籍或者期刊信息的输入\n"
		<< "2.对现有的书籍或书刊进行修改\n"
		<< "3.显示已存信息\n"
		<< "4.查找书籍或者书刊信息\n"
		<< "5.清理控制台输出信息\n"
		<< "6.删除书籍或书刊信息\n"
		<< "7.退出本系统\n"
		<< "请输入想要的功能\n ";
	cin >> number;
	if (_start->readNumber())
	{
		_start->alterNumberDouble(_start->readNumber());
	}
	_start->alterNumber(number);
	this->show(_start, _add, number);
}
void SystemShow::show(System* _start, SystemAdd* _add, int i)
{
	SystemDelete Sdelete;
	string name = "";
	int number = 0;
	switch (i)
	{
	case 1:
	{
		number = _add->addFileBookOrPeriodical();
		if (number == _start->Ebook)
		{
			_add->addBook(_start);
			return;
		}
		else if (number == _start->Eperiodical)
		{
			_add->addPeriodical(_start);
			return;
		}
		else
		{
			cout << "输入错误请重新输入\n";
			this->show(_start, _add, _start->readNumber());
		}
	}
	case 2:
	{
		number = this->chooseBookAndDialNoString(_add);
#ifdef _Sort_
		this->sortNumber(_add, name, number);
#endif
		if (number == _start->Ebook)
		{
			_add->alteringBook(_start);
			return;
		}
		else if (number == _start->Eperiodical)
		{
			_add->alteringDial(_start);
			return;
		}
		else
		{
			cout << "输入错误请重新输入\n";
			this->show(_start, _add, _start->readNumber());
		}
	}
	case 3:
	{
		number = this->chooseBookAndDialNoString(_add);
#ifdef _Sort_

		this->sortNumber(_add, name, number);
#endif // _Sort_

		if (number == _start->Ebook)
		{
			this->showBook(_add, _start);
			return;
		}
		else if (number == _start->Eperiodical)
		{
			this->showDecal(_add, _start);
			return;
		}
		else
		{
			cout << "输入错误请重新输入\n";
			this->show(_start, _add, _start->readNumber());
		}
	}
	case 4:
	{
		bool Find = this->findBookAndDial(_add);
		if (Find)
		{
			this->startDown(_start, _add);
			return;
		}
		else
		{
			Find = this->chooseReturn(_start, _add);
			if (!Find)
			{
				this->chooseReturn(_start, _add);
			}
			return;
		}
	}
	break;
	case 5:
		this->Clear(_start, _add);
		break;
	case 6:
	{
		number = Sdelete.chooseBookOrPeriodical();
		if (number == Ebook)
		{
			Sdelete.bookDelete(_start, _add);
			return;
		}
		else if (number == Eperiodical)
		{
			Sdelete.periodicalDelete(_start, _add);
			return;
		}
		else
		{
			this->chooseReturn(_start, _add);
		}
	}
	case 7:
		this->readFileWirte(_add);
		cout << "退出成功\n";
		return;
	default:
		this->chooseReturn(_start, _add);
		break;
	}
}
int SystemShow::down()
{
	int _number;
	cout << "请输入接下来要干什么\n"
		<< "1.返回主菜单\n"
		<< "2.返回上一个选项\n"
		<< "3.继续现在的选项\n"
		<< "4.退出本系统\n";
	cin >> _number;
	return _number;
}
bool SystemShow::downChoose(SystemAdd* _add, System* _start, int n)
{
	switch (n)
	{
	case 1:
		this->choose(_start, _add);
		break;
	case 2:
	{
		if (!_start->readNumberDouble())
		{
			cout << "上一个选项为空没有所以即将返回主菜单\n";
			this->choose(_start, _add);
		}
		this->show(_start, _add, _start->readNumberDouble());
	}
	break;
	case 3:
		this->show(_start, _add, _start->readNumber());
		break;
	case 4:
	{
		this->show(_start, _add, 7);
	}
	break;
	default:
		cout << "输入错误请重新输入\n";
		return false;
	}
	return true;
}

void SystemShow::showBook(SystemAdd* _add, System* _start)
{
	if (_add->returnBookTemp() == 0)
	{
		cout << "没有存入书刊信息即将回到主菜单\n";
		this->choose(_start, _add);
	}
	cout << "总共有" << _add->returnBookTemp() << "本书其书籍信息如下" << endl;
	for (int i = 0; i < _add->returnBookTemp(); i++)
	{
		cout << "座位号:" << _add->usingBookKind(i) << tab << "编号:" << _add->usingBookNumber(i) << tab "名字:" << _add->usingBookName(i) << tab << endl;
	}
	this->startDown(_start, _add);
}
void SystemShow::showDecal(SystemAdd* _add, System* _start)
{
	if (_add->returnperiodicaTemp() == 0)
	{
		cout << "没有存入书刊信息即将回到主菜单\n";
		this->choose(_start, _add);
	}
	cout << "总共有" << _add->returnperiodicaTemp() << "书刊其书刊信息如下" << endl;
	for (int i = 0; i < _add->returnperiodicaTemp(); i++)
	{
		cout << "编号:" << _add->usingStorageNumber(i) << tab << "名字:" << _add->usingStorageName(i) << tab << endl;
	}
	this->startDown(_start, _add);
}
bool SystemShow::findBookAndDial(SystemAdd* _add) const
{
	string name;
	bool _if = false;
	cout << "请输入想要查询的内容\n";
	cin >> name;
	for (int i = 0; i < _add->returnBookTemp(); i++)
	{
		if (name == _add->usingBookKind(i))
		{
			cout << "查到到的是" << _add->usingBookKind(i) << "该内容是书本的座位号是第" << i + 1 << "本书" << endl;
			_if = true;
		}
		else if (name == _add->usingBookName(i))
		{
			cout << "查到到的是" << _add->usingBookName(i) << "该内容是书本的名字是第" << i + 1 << "本书" << endl;
			_if = true;
		}
		else if (name == _add->usingBookNumber(i))
		{
			cout << "查到到的是" << _add->usingBookNumber(i) << "该内容是书本的编号是第" << i + 1 << "本书" << endl;
			_if = true;
		}
	}
	for (int j = 0; j < _add->returnperiodicaTemp(); j++)
	{
		if (name == _add->usingStorageName(j))
		{
			cout << "查到到的是" << _add->usingStorageName(j) << "该内容是书刊的名字是第" << j + 1 << "本书刊" << endl;
			_if = true;
		}
		else if (name == _add->usingStorageNumber(j))
		{
			cout << "查到到的是" << _add->usingStorageNumber(j) << "该内容是书刊的编号是第" << j + 1 << "本书刊" << endl;
			_if = true;
		}
	}
	return _if;
}
bool SystemShow::chooseReturn(System* _start, SystemAdd* _add)
{
	int number;
	cout << "出错了请选择是重新输入还是退出本系统,重新输入按1否则按0\n";
	cin >> number;
	if (number)
	{
		this->show(_start, _add, _start->readNumber());
		return true;
	}
	else if (!number)
	{
		this->show(_start, _add, 7);
		return true;
	}
	cout << "输入错误请重新输入\n";
	return false;
}
void SystemShow::startDown(System* _start, SystemAdd* _add)
{
	int number;
	bool choose;
	number = this->down();
	choose = this->downChoose(_add, _start, number);
	if (!choose)
	{
		this->startDown(_start, _add);
	}
}
int SystemShow::chooseBookAndDialNoString(SystemAdd*) const
{
	int number;
	cout << "请输入想要查看全部的是书籍还是书刊信息\n如果是书籍信息请按1如果是书刊请按2\n";
	cin >> number;
	return number;
}
#ifdef _Sort_
void SystemShow::sortNumber(SystemAdd* e, string name, int number)
{
	if (name == "书籍" || number == this->书籍)
	{
		std::sort(e->book, e->book + e->returnBookTemp(), [=](SystemAdd::Book a, SystemAdd::Book b) -> bool
			{ return a.number < b.number; });
	}
	else if (name == "书刊" || number == this->书刊)
	{
		std::sort(e->Storage, e->Storage + e->returnperiodicaTemp(), [=](SystemAdd::periodical a, SystemAdd::periodical b) -> bool
			{ return a.number < b.number; });
	}
}
#endif
void SystemShow::Clear(System* _start, SystemAdd* _add)
{
#if defined _WIN32
	system("cls");
#elif defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined(__APPLE__)
	system("clear");
#endif
	cout << "清除成功\n";
	this->startDown(_start, _add);
}
void SystemShow::readFileWirte(SystemAdd* _add)
{
	ofstream outfile, outfileStorge;
	outfile.open("Book.txt");
	outfileStorge.open("Periodical.txt");
	for (int i = 0; i < _add->returnBookTemp(); i++)
	{
		outfile << _add->usingBookKind(i) << endl;
		outfile << _add->usingBookNumber(i) << endl;
		outfile << _add->usingBookName(i) << endl;
	}
	for (int j = 0; j < _add->returnperiodicaTemp(); j++)
	{
		outfileStorge << _add->usingStorageNumber(j) << endl;
		outfileStorge << _add->usingStorageName(j) << endl;
	}
	outfile.close();
	outfileStorge.close();
	return;
}