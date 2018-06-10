#pragma once
#include <iostream>
using namespace std;
class Date
{
private:
	int nNgay;
	int nThang;
	int nNam;
public:
	void input (int nNgay, int nThang, int nNam);
	void Date::output();
	int get_Ngay();
	int get_Thang();
	int get_Nam();
	void set_Ngay (int nN);
	void set_Thang (int nT);
	void set_Nam (int nNam);
	Date(void)
	{
		nNgay = 0;
		nThang = 0;
		nNam = 0;
	}
	Date (int nNgay, int nThang, int nNam)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	~Date(void){};
};

