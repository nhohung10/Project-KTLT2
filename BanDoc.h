#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
class Date;
class PhieuMuon;
class BanDoc
{
protected:
	string sMaBD;
	string sHoTen;
	string sKhoa;
	Date xNgayDK;
public:
	friend Date;
	friend PhieuMuon;
	virtual int get_LoaiBD(){return 0;};
	virtual void output(){};
	virtual void ghiFile(){};
	void xuatBD();
	string get_MaBD();
	string get_Ten();
	string get_Khoa();
	int get_Ngay();
	int geT_Thang();
	int get_Nam();
	void set_MaBD (string sMa);
	void set_Ten (string sTen);
	void set_Khoa (string sKhoa);
	void set_Ngay(int nN);
	void set_Thang(int nT);
	void set_Nam (int nN);
	BanDoc(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0):xNgayDK(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
		this->xNgayDK = xNgayDK;
	}
	~BanDoc(void){};
};

