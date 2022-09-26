#include "add.h"
#ifndef _Show_H
#define _Show_H
//#define _Sort_
class SystemShow : protected System
{
public:
	//本构造函数没有什么任何意义只是为了让系统回收本块内存所创立出来的，如果使用new我暂时没有想到如何进行内存释放
	SystemShow(int i = 0, int b = 0) {}

	//开始的选择目录
	void choose(System*, SystemAdd*);

	//主菜单
	void show(System*, SystemAdd*, int i);

	//开始下一步的选择
	void startDown(System*, SystemAdd*);

	//下一步的目录
	int down();

	/// @brief 进入下一步要干什么
	/// @param SystemAdd类的指针，目的是进行修改
	/// @param System类的修改同第一个参数一样
	/// @param n对用户的选择进行已有的判断
	/// @return 对用户的选择进行判断如果输入错误那么返回false,否者返回true
	bool downChoose(SystemAdd*, System*, int n);

	//显示书籍或者书刊信息
	int chooseBookAndDialNoString(SystemAdd*) const;
	//显示书籍信息
	void showBook(SystemAdd*, System*);

	//显示书刊信息
	void showDecal(SystemAdd*, System*);

	//对文件进行写入
	void readFileWirte(SystemAdd*);

#ifdef _Sort_
	//对编号进行字典序排序
	void sortNumber(SystemAdd*, std::string, int);
#endif
	//对书籍或者书刊进行查找
	bool findBookAndDial(SystemAdd*) const;

	//选择退出或者停留
	bool chooseReturn(System*, SystemAdd*);

	//清除控制台输出信息
	void Clear(System*, SystemAdd*);
};
#endif