#include "Date.h"


int Date::get_Ngay()
{
	return this->nNgay;
}
int Date::get_Thang()
{
	return this->nThang;
}
int Date::get_Nam()
{
	return this->nNam;
}
void Date::set_Ngay (int nN)
{
	this->nNgay = nN;
}
void Date::set_Thang (int nT)
{
	this->nThang = nT;
}
void Date::set_Nam (int nNam)
{
	this->nNam = nNam;
}
void Date::input (int nNgay, int nThang, int nNam)
{
	this->nNgay = nNgay;
	this->nThang = nThang;
	this->nNam = nNam;
}
void Date::output()
{
	cout << "Ngay: " << this->nNgay << "/" << this->nThang << "/" << this->nNam << endl;
}
