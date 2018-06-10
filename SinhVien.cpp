#include "SinhVien.h"

int SinhVien::get_LoaiBD()
{
	return 2;
}
string SinhVien::get_NienKhoa()
{
	return this->sNienKhoa;
}
void SinhVien::set_KhoaHoc(string sK)
{
	this->sNienKhoa = sK;
}
void SinhVien::ghiFile()
{
	ofstream file;
	file.open("BanDoc.txt",ios::app);
	file << 2 << ","
		<< this->sMaBD << ","
		<< this->sHoTen << ","
		<< this->sKhoa << ","
		<< this->get_Ngay() << ","
		<< this->geT_Thang() << ","
		<< this->get_Nam() << ","
		<< this->sNienKhoa << endl;
	file.close();
}
void SinhVien::output()
{
	BanDoc::xuatBD();
	cout << "Khoa hoc: " << this->sNienKhoa << endl;
}


