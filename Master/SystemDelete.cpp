#include "SystemDelete.h"
#include "show.h"
int SystemDelete::chooseBookOrPeriodical()const
{
	int _number=0;
	cout << "��������Ҫɾ���鼮�����鿯" << endl
		<< "ɾ���鼮������1,����ɾ���鿯������2" << endl;
	cin >> _number;
	return _number;
}
bool SystemDelete::bookDelete(System* _start, SystemAdd* _add)
{
	SystemShow _show{};
	if (_add->returnperiodicaTemp() == 0)
	{
		cout << "û�����ݽ�ֹɾ��" << endl;
		_show.startDown(_start, _add);
	}
	string _name;
	cout << "�������ɾ��������" << endl;
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
			cout << "ɾ��ʧ��û�и�����" << endl;
			_show.choose(_start, _add);
			return false;
		}
	}
	cout << "ɾ���ɹ�" << endl;
	_show.startDown(_start, _add);
	return true;
}
bool SystemDelete::periodicalDelete(System* _start, SystemAdd* _add)
{
	SystemShow _show{};
	if (_add->returnperiodicaTemp() == 0)
	{
		cout << "û�����ݽ�ֹɾ��" << endl;
		_show.startDown(_start, _add);
	}
	string _name;;
	cout << "�������ɾ��������" << endl;
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
			cout << "û�и�����ɾ��ʧ��" << endl;
			_show.choose(_start, _add);
			return false;
		}
	}
	cout << "ɾ���ɹ�" << endl;
	_show.startDown(_start, _add);
	return true;
}