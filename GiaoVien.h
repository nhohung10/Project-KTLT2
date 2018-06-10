#pragma once
#include "bandoc.h"
class GiaoVien :
	public BanDoc
{
private:
	string sDiaChi;
	string sSDT;
public:
	string get_DiaChi ();
	string get_STD();
	void set_DiaChi (string sDC);
	void set_SDT (string sSDT);
	void ghiFile();
	void output();
	int get_LoaiBD();
	GiaoVien(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0, string sDiaChi = "", string sSDT = ""):BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sDiaChi = sDiaChi;
		this->sSDT = sSDT;
	}
	~GiaoVien(void){};
};

