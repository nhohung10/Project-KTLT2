#include "Sach.h"


//void Sach::input (string sMa, string sTuaDe, string sTacGia, string sNXB, int nTien, int nNamPH, int nSoTrang,int nMaPM,Date xNgayNhap(int nNgay, int nThang, int nNam) )
//{
//	this->sMaSach = sMa;
//	this->sTuaDe = sTuaDe;
//	this->sTacGia = sTacGia;
//	this->sNXB = sNXB;
//	this->nGiaTien = nTien;
//	this->nNamPhatHanh = nNamPH;
//	this->nSoTrang = nSoTrang;
//	this->xNgayNhap = xNgayNhap;
//	this->nMaPM = nMaPM;	
//}
void Sach::set_NgayNhapKho(int nN)
{
	this->xNgayNhap.set_Ngay(nN);
}
void Sach::set_ThangNhapKho(int nT)
{
	this->xNgayNhap.set_Thang(nT);
}
void Sach::set_NamNhapKho(int nN)
{
	this->xNgayNhap.set_Nam(nN);
}
string Sach::get_MaSach()
{
	return this->sMaSach;
}
string Sach::get_TuaDe()
{
	return this->sTuaDe;
}
string Sach::get_TacGia()
{
	return this->sTacGia;
}
string Sach::get_NXB()
{
	return this->sNXB;
}
int Sach::get_GiaTien()
{
	return this->nGiaTien;
}
int Sach::get_NamPH()
{
	return this->nNamPhatHanh;
}
int Sach::get_SoTrang()
{
	return this->nSoTrang;
}
int Sach::get_NgayNhapKho()
{
	return this->xNgayNhap.get_Ngay();
}
int Sach::get_ThangNhapKho()
{
	return this->xNgayNhap.get_Thang();
}
int Sach::get_NamNhapKho()
{
	return this->xNgayNhap.get_Nam();
}
int Sach::get_TinhTrang()
{
	return this->nTinhTrang;
}
void Sach::set_MaSach(string sMa)
{
	this->sMaSach = sMa;
}
void Sach::set_TuaDe(string sTuaDe)
{
	this->sTuaDe = sTuaDe;
}
void Sach::set_TacGia(string sTG)
{
	this->sTacGia = sTG;
}
void Sach::set_NXB(string sNXB)
{
	this->sNXB = sNXB;
}
void Sach::set_GiaTien(int nTien)
{
	this->nGiaTien = nTien;
}
void Sach::set_NamPH(int nNamPH)
{
	this->nNamPhatHanh = nNamPH;
}
void Sach::set_SoTrang(int nSoTrang)
{
	this->nSoTrang = nSoTrang;
}
void Sach::set_TinhTrang(int nTT)
{
	this->nTinhTrang = nTT;
}
void Sach::outputSach() 
{
	cout << "Ma sach:       " << this->sMaSach << endl;
	cout << "Tieu de:       " << this->sTuaDe << endl;
	cout << "Tac gia:       " << this->sTacGia << endl;
	cout << "NXB:           " << this->sNXB << endl;
	cout << "Tri gia:       " << this->nGiaTien << "  dong" << endl;
	cout << "Nam phat hanh: " << this->nNamPhatHanh << endl;
	cout << "So trang:      " << this->nSoTrang << endl; 
	cout << "Ngay nhap kho: ";
	this->xNgayNhap.output();
	cout << endl;
}

