#pragma once
#include "bandoc.h"
class SinhVien :
	public BanDoc
{
private:
	string sNienKhoa;
public:
	string get_NienKhoa();
	void set_KhoaHoc(string sK);
	void output();
	void ghiFile();
	int get_LoaiBD();
	SinhVien(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0, string sNienKhoa =""):BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->sNienKhoa = sNienKhoa;
	}
	~SinhVien(void){};
};

