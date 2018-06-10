#pragma once
#include <iostream>
#include "Date.h"
#include "BanDoc.h"
#include "Sach.h"
#include <time.h>
class BanDoc;
class Sach;
class Date;
class PhieuMuon
{
private:
	BanDoc xBanDoc;
	Sach xSach;
	Date xNgayMuon, xNgayTra;
	static int nTongPM;
	int nMaPM;
	int nTrangThai;
public:
	int get_TongPM();
	BanDoc get_BanDoc();
	Sach get_Sach();
	Date get_NgayMuon(); 
	Date get_NgayTra();
	int get_MaPM();
	int get_TrangThai();
	void set_TrangThai(int nTT);
	void set_Sach(Sach xS);
	void setBanDoc(BanDoc xBD);
	//
	void output();
	PhieuMuon(int nMaPM = 0, string sMaBD = "", string sMaSach = "",int nA = 0, int nB = 0, int nC = 0, int nD = 0, int nE = 0,int nF = 0,int nTrangThai = 0) : xBanDoc(sMaBD), xSach(sMaSach), xNgayMuon(nA,nB,nC), xNgayTra(nD,nE,nF)
	{
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = nTrangThai;
	}
	PhieuMuon(string sMaBD = "",string sMaSach = ""): xBanDoc(sMaBD), xSach(sMaSach)
	{
		time_t t = time(0); 
		struct tm *Info =localtime(&t);
		xNgayMuon.set_Ngay(Info->tm_mday);
		xNgayMuon.set_Thang(Info->tm_mon + 1);
		xNgayMuon.set_Nam(Info->tm_year + 1900);

		xNgayTra.set_Ngay(Info->tm_mday + 7);
		xNgayTra.set_Thang(Info->tm_mon + 1);
		xNgayTra.set_Nam(Info->tm_year + 1900);
		
		this->nTongPM++;
		this->nMaPM = nTongPM;
		this->nTrangThai = 1;
	}
	friend BanDoc;
	friend Sach;
	friend Date;
	~PhieuMuon(void){};
};

