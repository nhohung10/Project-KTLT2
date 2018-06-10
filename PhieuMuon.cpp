#include "PhieuMuon.h"



void PhieuMuon::output()
{
	cout << "***********************************************\n";
	cout << "Ma phieu muon: " << this->nMaPM << endl;
	cout << "Ma sach: " << this->xSach.get_MaSach() << endl;
	cout << "Ma ban doc: " << this->xBanDoc.get_MaBD() << endl;
	cout << "Ngay muon: "; this->xNgayMuon.output(); cout << endl;
	cout << "Ngay tra: "; this->xNgayTra.output(); cout << endl;
	cout << "Tinh trang: " << this->nTrangThai << endl;
}
int PhieuMuon::get_TongPM()
{
	return this->nTongPM;
}
BanDoc PhieuMuon::get_BanDoc()
{
	return this->xBanDoc;
}
Sach PhieuMuon::get_Sach()
{
	return this->xSach.get_MaSach();
}
Date PhieuMuon::get_NgayMuon()
{
	return this->xNgayMuon;
}
Date PhieuMuon::get_NgayTra()
{
	return this->xNgayTra;
}
int PhieuMuon::get_MaPM()
{
	return this->nMaPM;
}
int PhieuMuon::get_TrangThai()
{
	return this->nTrangThai;
}
void PhieuMuon::set_TrangThai(int nTT)
{
	this->nTrangThai = nTT;
}
void PhieuMuon::set_Sach(Sach xS)
{
	this->xSach = xS;
}
void PhieuMuon::setBanDoc(BanDoc xBD)
{
	this->xBanDoc = xBD;
}
