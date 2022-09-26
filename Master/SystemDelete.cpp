#include "SystemDelete.h"
#include "show.h"
int SystemDelete::chooseBookOrPeriodical()const
{
	int _number=0;
	cout << "请输入想要删除书籍还是书刊" << endl
		<< "删除书籍请输入1,整体删除书刊请输入2" << endl;
	cin >> _number;
	return _number;
}
bool SystemDelete::bookDelete(System* _start, SystemAdd* _add)
{
	SystemShow _show{};
	if (_add->returnperiodicaTemp() == 0)
	{
		cout << "没有数据禁止删除" << endl;
		_show.startDown(_start, _add);
	}
	string _name;
	cout << "请输入该删除的数据" << endl;
	cin >> _name;
	for (int i = 0; i < _add->returnBookTemp(); i++)
	{
		if (_name == _add->usingBookNumber(i))
		{
			_add->DelteBookNumber(_add, i);
			break;
		}
		else if (_name == _add->usingBookKind(i))
		{
			_add->DelteBookKind(_add, i);
			break;
		}
		else if (_name == _add->usingBookName(i))
		{
			_add->DelteBookName(_add, i);
			break;
		}
		if (i == _add->returnBookTemp() - 1)
		{
			cout << "删除失败没有该数据" << endl;
			_show.choose(_start, _add);
			return false;
		}
	}
	cout << "删除成功" << endl;
	_show.startDown(_start, _add);
	return true;
}
bool SystemDelete::periodicalDelete(System* _start, SystemAdd* _add)
{
	SystemShow _show{};
	if (_add->returnperiodicaTemp() == 0)
	{
		cout << "没有数据禁止删除" << endl;
		_show.startDown(_start, _add);
	}
	string _name;;
	cout << "请输入该删除的数据" << endl;
	cin >> _name;
	for (int i = 0; i < _add->returnperiodicaTemp(); i++)
	{
		if (_name == _add->usingStorageName(i))
		{
			_add->DelteStorgeName(_add, i);
			break;
		}
		else if (_name == _add->usingStorageNumber(i))
		{
			_add->DelteStorgeName(_add, i);
			break;
		}
		if (i == _add->returnperiodicaTemp() - 1)
		{
			cout << "没有该数据删除失败" << endl;
			_show.choose(_start, _add);
			return false;
		}
	}
	cout << "删除成功" << endl;
	_show.startDown(_start, _add);
	return true;
}