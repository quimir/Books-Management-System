#include "start.h"
#ifndef _Add_H
#define _Add_H
class SystemAdd : protected System
{
public:
	//初始化两个参数
	SystemAdd(int _bookTemp = 0, int _periodicalTemp = 0) : bookTemp(_bookTemp), periodicalTemp(_periodicalTemp) {};
	//添加图书
	void addBook(System*);
	/// @brief 对添加书籍的判断
	/// @param  传入写入的字符串
	/// @return 如果改书籍存在那么返回false，否则返回true
	bool ifBook(std::string);

	//修改书籍书刊总目录
	int alteringNoString();
	//添加期刊
	void addPeriodical(System*);

	/// @brief 对添加期刊的判断
	/// @param  传入写入的字符串
	/// @return 如果该期刊存在那么返回false，否则返回true
	bool ifPeriodical(std::string);

	/// @brief 选择强制添加或者不强制添加
	/// @param 第一个参数为传入想要修改的字符串
	/// @param 第二个为修改的字符串
	/// @return 一个数字用来判断用户的选择
	int dataChoose(std::string*, std::string);

	//修改图书
	void alteringBook(System*);

	//修改期刊
	void alteringDial(System*);

#ifdef VS_H
	inline void usingBookNumber(const int&, const std::wstring&)
#else
	/// @brief 修改书籍的编号
	/// @param  第一个参数为修改的编号
	/// @param 第二个参数为将修改的字符串传进来
	/// @return 空返回值
	inline void usingBookNumber(const int&, const std::string&);
#endif

	//查看书籍编号
	inline std::string usingBookNumber(const int& serialNumber) const
	{
		return (this->book)[serialNumber].number;
	};

	/// @brief 修改书籍的名字
	/// @param  第一个参数为修改的编号
	/// @param 第二个参数为将修改的字符串传进来
	/// @return 空返回值
	inline void usingBookName(const int&, const std::string&);

	//查看书籍名字
	inline std::string usingBookName(const int& serialNumber) const { return (this->book)[serialNumber].name; };

	/// @brief 修改书籍的座位号
	/// @param  第一个参数为修改的编号
	/// @param 第二个参数为将修改的字符串传进来
	/// @return 空返回值
	inline void usingBookKind(const int&, const std::string&);

	//查看书籍座位号
	inline std::string usingBookKind(const int& serialNumber) const { return (this->book)[serialNumber].kind; };

	/// @brief 修改书刊的编号
	/// @param  第一个参数为修改的编号
	/// @param 第二个参数为将修改的字符串传进来
	/// @return 空返回值
	inline void usingStorageNumber(const int&, const std::string&);

	//查看书刊编号
	inline std::string usingStorageNumber(const int& serialNumber) const { return (this->Storage)[serialNumber].number; };

	/// @brief 修改书刊的名字
	/// @param  第一个参数为修改的编号
	/// @param 第二个参数为将修改的字符串传进来
	/// @return 空返回值
	inline void usingStorageName(const int&, const std::string&);

	//查看书刊名字.
	inline std::string usingStorageName(const int& serialNumber) const { return (this->Storage)[serialNumber].name; }

	//使保存书的数量增加
	inline int usingBookTemp();

	//使保存书刊的数量增加
	inline int usingperiodicalTemp();

	//查看保存书的数量
	inline int returnBookTemp() const { return this->bookTemp; }

	//查看保存书刊的数量
	inline int returnperiodicaTemp() const { return this->periodicalTemp; }

	//文件的添加
	int addFileBookOrPeriodical();

	//读取图书文件的信息
	void readFileBook();

	//读取期刊的信息
	void readFilePeriodical();


	//删除书本的编号
	void DelteBookNumber(SystemAdd*, const int);
	//删除书本的座位号
	void DelteBookKind(SystemAdd*,const int);
	//删除书本的名字
	void DelteBookName(SystemAdd*, const int);
	//删除书刊的编号
	void DelteStorgeNumber(SystemAdd*, const int);
	//删除书刊的名字
	void DelteStorgeName(SystemAdd*,const  int);

protected:
	//保存书的数量
	int bookTemp;
	//保存期刊的数量
	int periodicalTemp;
	//存储书的结构体
	struct Book
	{
		//编号
		std::string number;
		//名字
		std::string name;
		//座位号
		std::string kind;
	} book[100];
	//存储期刊的结构体
	struct periodical
	{
		//编号
		std::string number;
		//名字
		std::string name;
	} Storage[100];
};
#endif

// from --QuiMir