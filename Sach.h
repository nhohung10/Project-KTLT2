#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;
class Date;
class Sach
{
private:
	string sMaSach; //k dc trung
	string sTuaDe;
	string sTacGia;
	string sNXB;
	int nGiaTien;
	int nNamPhatHanh;
	int nSoTrang;
	Date xNgayNhap;
	int nTinhTrang;
public:
	friend Date;
	string get_MaSach();
	string get_TuaDe();
	string get_TacGia();
	string get_NXB();
	int get_GiaTien();
	int get_NamPH();
	int get_SoTrang();
	int get_NgayNhapKho();
	int get_ThangNhapKho();
	int get_NamNhapKho();
	int get_TinhTrang();
	void set_MaSach(string sMa);
	void set_TuaDe(string sTuaDe);
	void set_TacGia(string sTG);
	void set_NXB(string sNXB);
	void set_GiaTien(int nTien);
	void set_NamPH(int nNamPH);
	void set_SoTrang(int nSoTrang);
	void set_TinhTrang(int nTT);
	void set_NgayNhapKho(int nN);
	void set_ThangNhapKho(int nT);
	void set_NamNhapKho(int nN);
	//void set_NgayNhapKho(int nNgay);
	//void set_ThangNhapKho(int nThang);
	//void set_NamNhapKho(int nNam);
	void outputSach();
	Sach(string sMa = "", string sTuaDe="", string sTacGia="", string sNXB="", int nTien = 0, int nNamPH = 0, int nSoTrang = 0,int nNgay = 0, int nThang = 0, int nNam = 0, int nTinhTrang = 0):xNgayNhap(nNgay,nThang,nNam)
	{
		this->sMaSach = sMa;
		this->sTuaDe = sTuaDe;
		this->sTacGia = sTacGia;
		this->sNXB = sNXB;
		this->nGiaTien = nTien;
		this->nNamPhatHanh = nNamPH;
		this->nSoTrang = nSoTrang;
		this->xNgayNhap = xNgayNhap;
		this->nTinhTrang = nTinhTrang;
	}
	~Sach(void){};
};

