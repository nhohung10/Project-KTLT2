#include "BanDoc.h"


string BanDoc::get_MaBD()
{
	return this->sMaBD;
}
string BanDoc::get_Ten()
{
	return this->sHoTen;
}
string BanDoc::get_Khoa()
{
	return this->sKhoa;
}
int BanDoc::get_Ngay()
{
	return xNgayDK.get_Ngay();
}
int BanDoc::geT_Thang()
{
	return xNgayDK.get_Thang();
}
int BanDoc::get_Nam()
{
	return xNgayDK.get_Nam();
}
void BanDoc::xuatBD()
{
	cout << "************************************\n";
	cout << "Ma ban doc: " << this->sMaBD << endl;
	cout << "Ngay dang ky the: ";
	xNgayDK.output();
	cout << "Ho va Ten: " << this->sHoTen << endl;
	cout << "Khoa: " << this->sKhoa << endl;
}
void BanDoc::set_MaBD (string sMa)
{
	this->sMaBD = sMa;
}
void BanDoc::set_Ten (string sTen)
{
	this->sHoTen = sTen;
}
void BanDoc::set_Khoa (string sKhoa)
{
	this->sKhoa = sKhoa;
}
void BanDoc::set_Ngay(int nN)
{
	this->xNgayDK.set_Ngay(nN);
}
void BanDoc::set_Thang(int nT)
{
	this->xNgayDK.set_Thang(nT);
}
void BanDoc::set_Nam (int nN)
{
	this->xNgayDK.set_Nam(nN);
}