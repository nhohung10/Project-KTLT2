#include "GiaoVien.h"

int GiaoVien::get_LoaiBD()
{
	return 1;
}
void GiaoVien::ghiFile()
{
	ofstream file;
	file.open("BanDoc.txt",ios::app);
	file << 1 << ","
		<< this->sMaBD << ","
		<< this->sHoTen << ","
		<< this->sKhoa << ","
		<< this->get_Ngay() << ","
		<< this->geT_Thang() << ","
		<< this->get_Nam() << ","
		<< this->sDiaChi << ","
		<< this->sSDT << endl;
	file.close();
}
string GiaoVien::get_DiaChi ()
{
	return this->sDiaChi;
}
string GiaoVien::get_STD()
{
	return this->sSDT;
}
void GiaoVien::set_DiaChi (string sDC)
{
	this->sDiaChi = sDC;
}
void GiaoVien::set_SDT (string sSDT)
{
	this->sSDT = sSDT;
}
void GiaoVien::output()
{
	BanDoc::xuatBD();
	cout << "Dia chi: " << this->sDiaChi << endl;
	cout << "SDT: " << this->sSDT << endl;
}
