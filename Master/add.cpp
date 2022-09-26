#include "add.h"
#include "show.h"
int SystemAdd::addFileBookOrPeriodical()
{
	int number;
	cout << "请输入想要添加的是书籍还是书刊\n如果是书籍请输入1书刊请输入2\n";
	cin >> number;
	return number;
}
void SystemAdd::readFileBook()
{
	ifstream infile;
	infile.open("Book.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	string buf, debuf, exbuf,detection, bufDetection;
	while (!infile.eof())
	{
		getline(infile, buf), getline(infile, debuf), getline(infile, exbuf);
		if (!(buf == ""))
		{
			this->usingBookKind(this->returnBookTemp(), buf);
			if (!(detection == debuf))
			{
				this->usingBookNumber(this->returnBookTemp(), debuf);
			}
			if (!(bufDetection == exbuf))
			{
				this->usingBookName(this->returnBookTemp(), exbuf);
			}
			this->usingBookTemp();
			detection = debuf, bufDetection = exbuf;
		}
	}
	infile.close();
}
void SystemAdd::readFilePeriodical()
{
	ifstream infile;
	infile.open("Periodical.txt", ios::in);
	if (!infile.is_open())
	{
		cout << "读取文件失败" << endl;
		return;
	}
	string buf, debuf, detection;
	while (!infile.eof())
	{
		getline(infile, buf), getline(infile, debuf);
		if (!(buf == ""))
		{
			this->usingStorageNumber(this->returnperiodicaTemp(), buf);
			if (!(detection == debuf))
			{
				this->usingStorageName(this->returnperiodicaTemp(), debuf);
			}
			this->usingperiodicalTemp();
			detection = debuf;
		}
	}
	infile.close();
}
void SystemAdd::addPeriodical(System* _start)
{
	SystemShow _show{};
	string name;
	cin.ignore();
	bool _if;
	int _number;
	while (true)
	{
		cout << "请输入编号\n";
		getline(cin, name);
		if (_if = this->ifPeriodical(name))
		{
			this->usingStorageNumber(this->returnperiodicaTemp(), name);
			name.clear();
			break;
		}
		else
		{
			_number = this->dataChoose(&this->Storage[this->returnperiodicaTemp()].number, name);
			cin.ignore();
			if (_number)
			{
				name.clear();
				break;
			}
		}
	}
	while (true)
	{
		cout << "请输入名字\n";
		getline(cin, name);
		if (_if = this->ifPeriodical(name))
		{
			this->usingStorageName(this->returnperiodicaTemp(), name);
			name.clear();
			break;
		}
		else
		{
			_number = this->dataChoose(&this->Storage[this->returnperiodicaTemp()].name, name);
			cin.ignore();
			if (_number)
			{
				name.clear();
				break;
			}
		}
	}
	this->usingperiodicalTemp();
	_show.startDown(_start, this);
}
void SystemAdd::addBook(System* _start)
{
	SystemShow _show{};
	cin.ignore();
	string name;
	bool _if;
	int _number;
	while (true)
	{
		cout << "请输入其的教室号\n";
		getline(cin, name);
		if (_if = this->ifBook(name))
		{
			this->usingBookKind(this->returnBookTemp(), name);
			name.clear();
			break;
		}
		else
		{
			_number = this->dataChoose(&this->book[this->returnBookTemp()].kind, name);
			cin.ignore();
			if (_number)
			{
				name.clear();
				break;
			}
		}
	}
	while (true)
	{
		cout << "请输入编号\n";
		getline(cin, name);
		if (_if = this->ifBook(name))
		{
			this->usingBookNumber(this->returnBookTemp(), name);
			name.clear();
			break;
		}
		else
		{
			_number = this->dataChoose(&this->book[this->returnBookTemp()].number, name);
			cin.ignore();
			if (_number)
			{
				name.clear();
				break;
			}
		}
	}
	while (true)
	{
		cout << "请输入名字\n";
		getline(std::cin, name);
		if (_if = this->ifBook(name))
		{
			this->usingBookName(this->returnBookTemp(), name);
			name.clear();
			break;
		}
		else
		{
			_number = this->dataChoose(&this->book[this->returnBookTemp()].name, name);
			cin.ignore();
			if (_number)
			{
				name.clear();
				break;
			}
		}
	}
	this->usingBookTemp();
	_show.startDown(_start, this);
}
int SystemAdd::alteringNoString()
{
	int number;
	cout << "请输入想要修改的是期刊还是书籍\n修改书籍输入1,修改书刊输入2\n";
	cin >> number;
	return number;
}
void SystemAdd::alteringBook(System* _start)
{
	SystemShow _show{};
	if (this->returnBookTemp() == 0)
	{
		cout << "没有书籍信息禁止修改\n";
		_show.startDown(_start, this);
	}
	string name;
	cout << "请输入修改书籍的名字或者编号或者座位号\n";
	cin.ignore();
	getline(cin, name);
	for (int i = 0; i < this->returnBookTemp(); i++)
	{
		if (name == this->usingBookKind(i))
		{
			cout << "找到了其的座位号,现在的座位号是:" << this->usingBookKind(i) << endl;
			cout << "请输入想要修改的座位号内容:\n";
			getline(cin, name);
			this->usingBookKind(i, name);
			cout << "修改成功!\n";
			_show.startDown(_start, this);
		}
		else if (name == this->usingBookName(i))
		{
			cout << "找到了其的名字,现在的名字是:" << this->usingBookName(i) << endl;
			cout << "请输入想要修改的名字内容:\n";
			getline(cin, name);
			this->usingBookName(i, name);
			cout << "修改成功!\n";
			_show.startDown(_start, this);
		}
		else if (name == this->usingBookNumber(i))
		{
			cout << "找到了其的编号,现在的编号是:" << this->usingBookNumber(i) << endl;
			cout << "请输入想要修改的编号内容:\n";
			getline(cin, name);
			this->usingBookNumber(i, name);
			cout << "修改成功!\n";
			_show.startDown(_start, this);
		}
		if (i == this->returnBookTemp() - 1)
		{
			cout << "没有找该书籍请再次查看是否有该书籍\n"
				<< "本菜单回到主菜单\n";
			_show.choose(_start, this);
		}
	}
}
void SystemAdd::alteringDial(System* _start)
{
	SystemShow _show;
	if (this->returnperiodicaTemp() == 0)
	{
		cout << "没有书刊信息禁止修改\n";
		_show.startDown(_start, this);
	}
	string name;
	cin.ignore();
	cout << "请输入修改期刊的名字或者编号\n";
	getline(cin, name);
	for (int i = 0; i < this->returnperiodicaTemp(); i++)
	{
		if (name == this->usingStorageNumber(i))
		{
			cout << "找到了其的编号,现在的编号是:" << this->usingStorageNumber(i) << endl;
			cout << "请输入想要修改的编号内容:\n";
			getline(cin, name);
			this->usingStorageNumber(i, name);
			cout << "修改成功!\n";
			_show.startDown(_start, this);
		}
		else if (name == this->usingStorageName(i))
		{
			cout << "找到了其的名字,现在的名字是:" << this->usingStorageName(i) << endl;
			cout << "请输入想要修改的名字内容:\n";
			getline(cin, name);
			this->usingStorageName(i, name);
			cout << "修改成功!\n";
			_show.startDown(_start, this);
		}
		if (i == this->returnperiodicaTemp() - 1)
		{
			cout << "没有找到该书刊再次检查是否有该书刊\n"
				<< "将返回主菜单\n";
			_show.choose(_start, this);
		}
	}
}
bool SystemAdd::ifBook(string name)
{
	for (int i = 0; i <= this->returnBookTemp(); i++)
	{
		if (this->usingBookKind(i).find(name) != this->usingBookKind(i).npos || this->usingBookName(i).find(name) != this->usingBookName(i).npos || this->usingBookNumber(i).find(name) != this->usingBookNumber(i).npos)
			return false;
	}
	return true;
}
bool SystemAdd::ifPeriodical(string name)
{
	for (int i = 0; i <= this->returnperiodicaTemp(); i++)
	{
		if (this->usingStorageName(i).find(name) != this->usingStorageName(i).npos || this->usingStorageNumber(i).find(name) != this->usingStorageNumber(i).npos)
			return false;
	}
	return true;
}
int SystemAdd::dataChoose(string* x, string m)
{
	int number;
	cout << "该内容已经在本库中存在请输入是否想要强制添加该数据,0为取消重新输入,1为强制添加\n";
	cin >> number;
	switch (number)
	{
	case 0:
		return 0;
	case 1:
		*x = m;
		break;
	default:
		cout << "错误请重新输入\n";
		this->dataChoose(x, m);
	}
	return 1;
}
int SystemAdd::usingBookTemp()
{
	return this->bookTemp++;
}
int SystemAdd::usingperiodicalTemp()
{
	return this->periodicalTemp++;
}
void SystemAdd::usingBookNumber(const int& _number, const string& CSTR)
{
	(this->book)[_number].number = CSTR;
}
void SystemAdd::usingBookName(const int& _number, const string& CSTR)
{
	(this->book)[_number].name = CSTR;
}
void SystemAdd::usingBookKind(const int& _number, const string& CSTR)
{
	(this->book)[_number].kind = CSTR;
}
void SystemAdd::usingStorageName(const int& _number, const string& CSTR)
{
	(this->Storage)[_number].name = CSTR;
}
void SystemAdd::usingStorageNumber(const int& _number, const string& CSTR)
{
	(this->Storage)[_number].number = CSTR;
}
void SystemAdd::DelteBookNumber(SystemAdd* _add, const int i)
{
	(_add->book)[i].number.erase();
}
void SystemAdd::DelteBookKind(SystemAdd* _add, const int i)
{
	(_add->book)[i].number.erase();
}
void SystemAdd::DelteBookName(SystemAdd* _add, const int i)
{
	(_add->book)[i].name.erase();
}
void SystemAdd::DelteStorgeName(SystemAdd* _add, const int i)
{
	(_add->Storage)[i].name.erase();
}
void SystemAdd::DelteStorgeNumber(SystemAdd* _add, const int i)
{
	(_add->Storage)[i].number.erase();
}