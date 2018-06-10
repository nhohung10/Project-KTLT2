#include <time.h>
#include "GiaoVien.h"
#include "SinhVien.h"
#include "Date.h"
#include "PhieuMuon.h"
#include "Sach.h"
#include "Admin.h"
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;
//Bien toan cuc
#define MAX 100
int PhieuMuon::nTongPM = 0;
//Khai bao nguyen mau ham
void Color(int nX); //Nguon: https://zfull.net/thu-thuat-it/doi-mau-chu-va-mau-nen-don-gian-trong-c/
void PassWord(char pass[]); //Nguon: http://diendan.congdongcviet.com/threads/t1944::lap-trinh-cpp-tao-password-trong-cpp.cpp
//Admin
void docFileAdmin (Admin *pa[], int &Spt);
void xuatAdmin (Admin *pa[], int nSpt);
//Sach
void docFileSach (Sach *pa[], int &nSpt);
void xuatSach (Sach *pa[], int nSpt);
//Ban doc
int nDemGV (BanDoc *pa[], int nSpt);
int nDemSV (BanDoc *pa[], int nSpt);
void docFileBanDoc (BanDoc *pa[], int &nSpt);
void xuatBanDoc (BanDoc *pa[], int nSpt);
//Phieu muon
void docFilePhieuMuon (PhieuMuon *pa[], int &nSpt);
void xuatPhieuMuon (PhieuMuon *pa[], int &nSpt);
void taoPhieuMuonMoi (PhieuMuon *pd[], int &nTongSoPM,BanDoc *pc[], int nSoBanDoc, Sach *pb[], int &nSoSach);
void traSach (PhieuMuon *pd[], int &nTongSoPM,BanDoc *pc[], int nSoBanDoc,Sach *pb[], int nSoSach);
//Kiem tra
bool kiemTraBanDoc (BanDoc *pc[] ,int nSoBanDoc,string sMaBD);
bool kiemTraSachDeMuon (Sach *pb[], int nSach,string sMaSach);
bool kiemTraTaiKhoanDangNhap (Admin *pa[], int nSpt,string sID, string sPass);
bool kiemTraSachTrung (Sach *pa[], int nSpt, string sMaSach);
bool kiemTraTKTrung (BanDoc *pa[], int nSpt, string sMaBD);
//Dang nhap
void login (Admin *pa[], int nSpt, string &sID, string &sPass,int &nLanSai);
string timKiemTuanTu (Sach *pa[], int nSpt,string sX);
void timKiemThongTin (Sach *pa[], int nSoSach, BanDoc *pb[], int nSoBD);
void chucNangQuanLy (Admin *pa[], int nAd, Sach *pb[], int &nSach, BanDoc *pc[], int &nSoBanDoc, PhieuMuon *pd[], int &nTongSoPM);
//Cap nhat
void ghiFilePhieuMuon (PhieuMuon *pa[], int nSpt);
void ghiFileSach (Sach *pa[], int nSpt);
void xoaSach (Sach *pa[], int &nSpt);
void themSach (Sach *pa[], int &nSpt);
void ghiFileBanDoc (BanDoc *pa[], int nSpt);
void themBanDoc (BanDoc *pa[], int &nSpt);
int nSoSachMuon (Sach *pa[], int nSpt);
int nSoSachConLai (Sach *pa[], int nSpt);
//Chuong trinh chinh
void main()
{
	//Admin
	Admin *pa[MAX];
	int nAd = 0;
	docFileAdmin (pa,nAd);
	//xuatAdmin (pa,nAd);
	//Sach
	Sach *pb[MAX];
	int nSach = 0;
	docFileSach (pb,nSach);


	//Ban doc
	BanDoc *pc[MAX];
	int nSoBanDoc = 0;
	docFileBanDoc (pc,nSoBanDoc);

	//Phieu muon
	PhieuMuon *pd[MAX];
	int nTongSoPM = 0;
	docFilePhieuMuon (pd,nTongSoPM);
	//xuatPhieuMuon(pd,nTongSoPM);
	string sID = "", sPass = "";
	int nLanSai = 0 ;//Dem so lan sai!!
	int nChon = 0;
	do
	{
		system("cls");
		Color(14);
		cout << "\t\t\t**********************************************\n";
		cout << "\t\t\t*                ";Color(12);cout << "Quan Ly Thu Vien";Color(14);cout <<"            *\n"; //16
		cout << "\t\t\t**********************************************\n";Color(11);
		cout << "\n\t  1. Hien thi thong tin sach\n";
		cout << "\t  2. Hien thi thong tin ban doc\n";
		cout << "\t  3. Tim kiem thong tin\n";
		cout << "\t  4. Quan ly\n";
		cout << "\t  5. Thoat!\n";Color(10);
		cout << "Chon chuc nang: ";Color(11);
		cin >> nChon;Color(7);
		switch(nChon)
		{
		case 1:
			xuatSach (pb,nSach);
			break;
		case 2:
			xuatBanDoc (pc,nSoBanDoc);
			break;
		case 3:
			timKiemThongTin (pb,nSach,pc,nSoBanDoc);
			break;
		case 4:
			login (pa, nAd,sID,sPass,nLanSai);
			if (nLanSai == 3)
				return;
			chucNangQuanLy(pa,nAd,pb, nSach, pc,nSoBanDoc,pd,nTongSoPM);
			break;
		case 5:
			cout << "Ban chon thoat chuong trinh!!\n";
			return;
		default:
			cout << "Ban chon thoat chuong trinh!!\n";
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 5);

}
//Khai bao dinh nghia ham
//Dang nnhap
void login (Admin *pa[], int nSpt, string &sID, string &sPass,int &nLanSai)
{
	system("cls");
		Color(14);
		cout << "\t\t\t***********************************\n";
		cout << "\t\t\t*                ";Color(12);cout << "Login";Color(14);cout <<"            *\n"; //16
		cout << "\t\t\t***********************************\n";Color(11);
		cout << endl << endl;
	char c[20];
a:
	Color(11);
	cout << "Nhap ID: ";Color(7);
	fflush(stdin);
	getline(cin,sID);
	Color(11);
	cout << "Nhap Pass: ";Color(7);
	fflush(stdin);
	PassWord(c);sPass = c;cout << endl;
	if (kiemTraTaiKhoanDangNhap (pa,nSpt,sID,sPass)== false)
	{
		nLanSai++;
		if (nLanSai == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tID or Pass khong dung!!\n";Color(7);
		goto a;
	}
	Color(10);
	cout << "\n\t\tDang dap nhap";Sleep(600);cout << ".";Sleep(600);cout << ".";Sleep(600);cout << ".";
	cout << endl;

}
void chucNangQuanLy (Admin *pa[], int nAd, Sach *pb[], int &nSach, BanDoc *pc[], int &nSoBanDoc, PhieuMuon *pd[], int &nTongSoPM)
{
	int nChon = 0;
	int nChonCase1 = 0;
	int nChonCase2 = 0;
	do
	{
		system("cls");
		Color(14);
		cout << "\t\t\t**********************************************\n";
		cout << "\t\t\t*                ";Color(12);cout << "Quan Ly Thu Vien";Color(14);cout <<"            *\n"; //16
		cout << "\t\t\t**********************************************\n";Color(11);
		cout << "\n\t  1. Quan Ly Phieu Muon\n";
		cout << "\t  2. Quan Ly Sach\n";
		cout << "\t  3. Quan ly ban doc\n";
		cout << "\t  4. Thong Ke\n";
		cout << "\t  5. Thoat!\n";Color(10);
		cout << "Chon chuc nang: ";Color(11);
		cin >> nChon;
		Color(7);
		switch(nChon)
		{
		case 1:
			do
			{
				system("cls");
				Color(14);
				cout << "\t\t\t************************************************\n";
				cout << "\t\t\t*                ";Color(12);cout << "Quan Ly Phieu Muon";Color(14);cout <<"            *\n"; //16
				cout << "\t\t\t************************************************\n";Color(11);
				cout << "\n\t  1. Tao Phieu Muon Moi\n";
				cout << "\t  2. Tra Sach\n";
				cout << "\t  3. Xuat Danh sach phieu muon\n";
				cout << "\t  4. Thoat!\n";Color(10);
				cout << "Chon chuc nang: ";Color(11);
				cin >> nChonCase1;
				Color(7);
				switch(nChonCase1)
				{
				case 1:
					taoPhieuMuonMoi(pd,nTongSoPM,pc,nSoBanDoc,pb,nSach);
					ghiFilePhieuMuon (pd,nTongSoPM);
					ghiFileSach (pb,nSach);
					break;
				case 2:
					traSach (pd, nTongSoPM,pc, nSoBanDoc,pb,nSach);
					break;
				case 3:
					xuatPhieuMuon(pd,nTongSoPM);
					break;
				case 4:
					return;
				default:
					Color(14);
					cout << "Ban chon thoat chuong trinh!!\n";Color(7);
				}
				system("pause");
			}while(nChonCase1 >= 1 && nChonCase1 <= 4);
			break;
		case 2:
			do
			{
				system("cls");
				Color(14);
				cout << "\t\t\t********************************************\n";
				cout << "\t\t\t*                ";Color(12);cout << "Quan Ly Sach";Color(14);cout <<"            *\n"; //16
				cout << "\t\t\t********************************************\n";Color(11);
				cout << "\n\t  1. Them Sach\n";
				cout << "\t  2. Xoa Sach\n";
				cout << "\t  3. Thoat!\n";Color(10);
				cout << "Chon chuc nang: ";Color(11);
				cin >> nChonCase2;Color(7);
				switch(nChonCase2)
				{
				case 1:
					themSach (pb,nSach);
					break;
				case 2:
					xoaSach (pb,nSach);
					break;
				case 3:
					return;
				default:
					Color(14);
					cout << "Ban chon thoat chuong trinh!!\n";Color(7);
				}
				system("pause");
			}while(nChonCase1 >= 1 && nChonCase1 <= 3);

			break;
		case 3:
			do
			{
				system("cls");
				Color(14);
				cout << "\t\t\t*******************************************\n";
				cout << "\t\t\t*                ";Color(12);cout << "Quan Ly Ban Doc";Color(14);cout <<"            *\n"; //16
				cout << "\t\t\t*******************************************\n";Color(11);
				cout << "\n\t  1. Them Ban doc\n";
				cout << "\t  2. Thoat!\n";Color(10);
				cout << "Chon chuc nang: ";Color(11);
				cin >> nChonCase2;Color(7);
				switch(nChonCase2)
				{
				case 1:
					//Them ban
					themBanDoc(pc,nSoBanDoc);
					break;
				case 2:
					return;
				default:
					Color(4);
					cout << "Ban chon thoat chuong trinh!!\n";Color(7);
				}
				system("pause");
			}while(nChonCase1 >= 1 && nChonCase1 <= 2);
			break;
		case 4:
			do
			{
								system("cls");
				Color(14);
				cout << "\t\t\t***********************************\n";
				cout << "\t\t\t*                ";Color(12);cout << "Thong Ke";Color(14);cout <<"            *\n"; //16
				cout << "\t\t\t***********************************\n";Color(11);
				cout << "\n\t1. Liet ke so sach da duoc muon\n";
				cout << "\t2. Liet ke so sach con lai trong thu vien\n";
				cout << "\t3. Liet ke so ban doc la Giao vien\n";
				cout << "\t4. Liet ke so ban doc la Sinh vien\n";
				cout << "\t5. Thoat!\n";Color(10);
				cout << "Chon chuc nang: ";Color(11);
				cin >> nChon;Color(7);
				switch(nChon)
				{
				case 1:
					Color(14);
					cout << "\n\tSo sach da duoc muon la: " << nSoSachMuon(pb,nSach) << endl;Color(7);
					break;
				case 2:
					Color(14);
					cout << "\n\tSo sach con lai trong thu vien la: "<< nSoSachConLai (pb,nSach) << endl;Color(7);
					break;
				case 3:
					Color(14);
					cout << "\n\tSo ban doc la Giao vien la: " << nDemGV (pc,nSoBanDoc) << endl;Color(7);
					break;
				case 4:
					Color(14);
					cout << "\n\tSo ban doc la Sinh vien la: " << nDemSV (pc,nSoBanDoc) << endl;Color(7);
					break;
				case 5:
					return;
				}
				system("pause");
			}while (nChon >= 1 && nChon <= 5);
			break;
		case 5:
			return;
		default:
			cout << "Ban chon thoat chuong trinh!!\n";
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 5);
}
int nSoSachConLai (Sach *pa[], int nSpt)
{
	int nDem = 0;
	for (int i = 0; i < nSpt; i++)
	{
		if (pa[i]->get_TinhTrang() == 0)
			nDem++;
	}
	if (nDem != 0)
		return nDem;
	else
		return -1;
}
int nSoSachMuon (Sach *pa[], int nSpt)
{
	int nDem = 0;
	for (int i = 0; i < nSpt; i++)
	{
		if (pa[i]->get_TinhTrang() != 0)
			nDem++;
	}
	if (nDem != 0)
		return nDem;
	else
		return -1;
}
void timKiemThongTin (Sach *pa[], int nSoSach, BanDoc *pb[], int nSoBD)
{
	string sTuaDe = "", sMaBD = "";
	int nFlag = 0;
	int nChon = 0;
	int i;
	do
	{
		system("cls");
		Color(14);
		cout << "\t\t\t*************************************************\n";
		cout << "\t\t\t*                ";Color(12);cout << "Tim Kiem Thong Tin";Color(14);cout <<"            *\n";
		cout << "\t\t\t*************************************************\n";Color(11);
		cout << "\n\t  1. Tim kiem thong tin sach qua Tua de sach\n";
		cout << "\t  2. Tim kiem thong tin ban doc qua Ma ban doc\n";
		cout << "\t  3. Thoat!\n";Color(10);
		cout << "Chon chuc nang: ";Color(11);
		cin >> nChon;Color(7);
		switch(nChon)
		{
		case 1:
			do
			{
				cout << "Nhap tua de sach: ";
				fflush(stdin);
				getline(cin,sTuaDe);
			}while (sTuaDe.length() == 0); //Khong duoc de trong!!
			for (i = 0; i < nSoSach; i++)
			{
				if (pa[i]->get_TuaDe() == sTuaDe) //Vi tri can tim trong mang
				{
					Color(14);
					cout << "\n\tThong tin sach: \n";Color(11);
					pa[i]->outputSach();Color(7);
					nFlag = 1;
					break;
				}
				
			}
			if (nFlag == 0)
			{
				Color(14);
				cout << "\n\tKhong tim thay!!\n";Color(7);
			}
			break;
		case 2:
			do
			{
				cout << "Nhap Ma ban doc: ";
				fflush(stdin);
				getline(cin,sMaBD);
			}while (sMaBD.length() == 0); //Khong duoc de trong!!
			for (i = 0; i < nSoBD; i++)
			{
				if (pb[i]->get_MaBD()== sMaBD) //Vi tri can tim trong mang
				{
					nFlag = 1;
					Color(14);
					cout << "\tThong tin Ban doc!!\n";Color(11);
					pb[i]->output();Color(7);
					break;
				}
				
			}
			if (nFlag == 0)
			{
				Color(14);
				cout << "\nKhong tim thay!!\n";Color(7);
			}
			break;
		case 3:
			Color(12);
			cout << "Ban chon thoat chuong trinh!!\n";Color(7);
			return;
		default:
			Color(12);
			cout << "Ban chon thoat chuong trinh!!\n";Color(7);
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 3);
}
//Viet Menu
void docFilePhieuMuon (PhieuMuon *pa[], int &nSpt)
{
	int nSPM = 0;
	string sMaBD = "";
	string sMaSach = "";
	int nNgayMuon = 0;
	int nThangMuon = 0;
	int nNamMuon = 0;
	int nNgayTra = 0;
	int nThangTra = 0;
	int nNamTra = 0;
	int nTrangThai = 0;
	ifstream file;
	file.open("PhieuMuon.txt");
		file >> nSpt;
	file.ignore(1,'\n');
	for (int i = 0; i < nSpt; i++)
	{
		file >> nSPM;
		file.ignore(1,',');
		fflush(stdin);
		getline(file,sMaBD,',');
		fflush(stdin);
		getline(file,sMaSach,',');
		file >> nNgayMuon;
		file.ignore(1,',');
		file >> nThangMuon;
		file.ignore(1,',');
		file >> nNamMuon;
		file.ignore(1,',');
		file >> nNgayTra;
		file.ignore(1,',');
		file >> nThangTra;
		file.ignore(1,',');
		file >> nNamTra;
		file.ignore(1,',');
		file >> nTrangThai;
		file.ignore(1,'\n');
		pa[i] = new PhieuMuon (nSPM, sMaBD,sMaSach,nNgayMuon,nThangMuon,nNamMuon,nNgayTra,nThangTra,nNamTra,nTrangThai);
	}
}
void ghiFilePhieuMuon (PhieuMuon *pa[], int nSpt)
{
	ofstream file;
	file.open("PhieuMuon.txt");
	file << nSpt << endl;
	for (int i = 0; i < nSpt; i++)
	{
		file<< pa[i]->get_MaPM() << ","
			<< pa[i]->get_BanDoc().get_MaBD() << ","
			<< pa[i]->get_Sach().get_MaSach() << ","
			<< pa[i]->get_NgayMuon().get_Ngay() << ","
			<< pa[i]->get_NgayMuon().get_Thang() << ","
			<< pa[i]->get_NgayMuon().get_Nam() << ","
			<< pa[i]->get_NgayTra().get_Ngay() << ","
			<< pa[i]->get_NgayTra().get_Thang() << ","
			<< pa[i]->get_NgayTra().get_Nam() << ","
			<< pa[i]->get_TrangThai() << endl;
	}
	file.close();
}
void xuatPhieuMuon (PhieuMuon *pa[], int &nSpt)
{
	for (int i = 0; i < nSpt; i++)
	{
		Color(14);
		cout << "\n\tThong tin phieu muon!!\n";Color(11);
		pa[i]->output();Color(7);
	}
}
//Phieu muon
void traSach (PhieuMuon *pd[], int &nTongSoPM,BanDoc *pc[], int nSoBanDoc,Sach *pb[], int nSoSach)
{
	int nMaPM = 0;
	int nFlag = 0;
	Color(11);
	cout << "Nhap ma PM: ";
	cin >> nMaPM;
	Color(7);
	for (int i = 0 ; i< nTongSoPM; i++)
	{
		//cout << "Ma PM: " << pd[i]->get_MaPM() << endl;
		if (pd[i]->get_MaPM() == nMaPM)//Tim thay
		{
			nFlag = 1;
			if (pd[i]->get_TrangThai() != 0) //Neu trang thai Ma phieu # 0 thi lam
			{
				pd[i]->set_TrangThai(0); //Chinh trang thai ve bang 0
				string sMaSach = pd[i]->get_Sach().get_MaSach(); //Tim ma sach cua ma phieu muon
				for (int j = 0; j < nSoSach; j++)
				{
					if (pb[j]->get_MaSach() == sMaSach)
					{
						pb[j]->set_TinhTrang(0);
						break;
					}
					
				}
				Color(14);
				cout << "\n\tTra thanh cong!!\n";Color(7);
				//Cap nhat lai o day!! gom cap nhat lai DS Sach va DS Phieu Muon
				ghiFileSach (pb,nSoSach);
				ghiFilePhieuMuon (pd,nTongSoPM);
			}
			
		}

	}
	if (nFlag == 0)
	{
		Color(14);
		cout << "Khong tim thay!!\n";Color(7);
		return;
	}
	
}
void taoPhieuMuonMoi (PhieuMuon *pd[], int &nTongSoPM,BanDoc *pc[], int nSoBanDoc, Sach *pb[], int &nSoSach)
{
	string sMaBD ="";
	string sMaSach ="";
a:
	Color(11);
	cout << "\nNhap ma ban doc: ";
	fflush(stdin);
	getline (cin,sMaBD);
	Color(7);
	if (kiemTraBanDoc (pc,nSoBanDoc,sMaBD) == false)
	{
		Color(12);
		cout << "Ma ban doc khong ton tai!!\n";Color(7);
		goto a;
	}
b:
	Color(11);
	cout << "\nNhap ma sach: ";
	fflush(stdin);
	getline(cin,sMaSach);
	Color(7);
	if (kiemTraSachDeMuon (pb,nSoSach,sMaSach) == false)
	{
		Color(12);
		cout << "Sach khong ton tai hoac da co nguoi muon!!\n";Color(7);
		goto b;
	}
	PhieuMuon *p = new PhieuMuon(sMaBD,sMaSach);// Da tao duoc 1 phieu muon
	int nViTri = nTongSoPM;
	for (int i = nTongSoPM; i > nViTri; i--)
	{	pd[i] = pd[i-1];}
	pd[nViTri] = p;
	nTongSoPM++;
	//Tao 1 phieu muon nam o cuoi phan tu
	Color(14);
	
	int nTrangThai = p->get_MaPM();
	for (int j = 0; j < nSoSach; j++)
	{
		if (pb[j]->get_MaSach() == sMaSach)
		{
			pb[j]->set_TinhTrang(nTrangThai);
			break;
		}
		
	}
	
	cout << "\n\tTao phieu muon thanh cong!!\n";Color(7);
	//Cap nhap Lai Sach va Phieu Muon;

}

//
void themBanDoc (BanDoc *pa[], int &nSpt)
{
	int nLoai;
	string sMaBD,sTen, sKhoa;
	int nNgay,nThang,nNam;
	string sDiaChi,sSDT;
	string sNienKhoa;
	int nViTri;
	int nChon = 0;
	int i = 0;
	BanDoc *p;
	Color(14);
	system("cls");
	cout << "\t\t\t***********************************\n";
	cout << "\t\t\t*                ";Color(12);cout << "Login";Color(14);cout <<"            *\n"; //16
	cout << "\t\t\t***********************************\n";Color(11);
	cout << endl;
	cout << "\t1. Giao vien: \n";
	cout << "\t2. Sinh vien: \n";
	cout << "\t3. Thoat!!\n";Color(10);
	cout << "Chon loai Ban doc: ";Color(11);
	cin >> nChon;Color(7);
	switch(nChon)
	{
	case 1:
		nLoai = 1;
		do
		{
			Color(11);
			cout << "\nNhap ma ban doc: ";
			fflush (stdin);
			getline(cin,sMaBD);Color(7);
		}while (kiemTraTKTrung (pa,nSpt,sMaBD) == true);
		Color(11);
		cout << "\nNhap ten: ";
		fflush (stdin);
		getline(cin,sTen);
		cout << "\nNhap khoa: ";
			fflush (stdin);
		getline(cin,sKhoa);
		cout << "\nNgay lam the: ";
		cin >> nNgay;
		cout << "\nThang lam the: ";
		cin >> nThang;
		cout << "\nNam lam the: ";
		cin >> nNam;
		cout << "\nNhap dia chi: ";
				fflush (stdin);
		getline(cin,sDiaChi);
		cout << "\nNhap SDT: ";
				fflush (stdin);
		getline(cin,sSDT);Color(7);
		//Them vao mang:
		p = new GiaoVien (sMaBD,sTen,sKhoa,nNgay,nThang,nNam,sDiaChi,sSDT);
	//Dua vao mang
		nViTri = nSpt;
		for ( i = nSpt; i > nViTri; i--)
		{	pa[i] = pa[i-1];}
		pa[nViTri] = p;
		nSpt+=1;
	//Tao 1 phieu muon nam o cuoi phan tu
	Color(14);
	cout << "\n\tTao Ban doc thanh cong!!\n";Color(7);
	ghiFileBanDoc(pa,nSpt);
		break;
	case 2:
		nLoai = 2;
		Color(11);
		do
		{
			cout << "\nNhap ma ban doc: ";
			fflush (stdin);
			getline(cin,sMaBD);
		}while (kiemTraTKTrung (pa,nSpt,sMaBD) == true);
		cout << "\nNhap ten: ";
		fflush (stdin);
		getline(cin,sTen);
		cout << "\nNhap khoa: ";
				fflush (stdin);
		getline(cin,sKhoa);
		cout << "\nNgay lam the: ";
		cin >> nNgay;
		cout << "\nThang lam the: ";
		cin >> nThang;
		cout << "\nNam lam the: ";
		cin >> nNam;
		cout << "\nNhap khoa hoc: ";
		fflush(stdin);
		getline(cin,sNienKhoa);
		p = new SinhVien (sMaBD,sTen,sKhoa,nNgay,nThang,nNam,sNienKhoa);
		
				nViTri = nSpt;
		for ( i = nSpt; i > nViTri; i--)
		{	pa[i] = pa[i-1];}
		pa[nViTri] = p;
		nSpt+=1;
	//Tao 1 phieu muon nam o cuoi phan tu
	Color(14);
	cout << "Tao Ban doc thanh cong!!\n";Color(7);
	ghiFileBanDoc(pa,nSpt);
	break;
	case 3:
		return;
	}
}
bool kiemTraTKTrung (BanDoc *pa[], int nSpt, string sMaBD)
{
	for (int i = 0; i < nSpt; i++)
	{
		if (pa[i]->get_MaBD() == sMaBD)
			return true;
	}
	return false;

}

int nDemSV (BanDoc *pa[], int nSpt)
{
	int nDem = 0;
	for (int i = 0; i < nSpt; i++)
	{
		if (pa[i]->get_LoaiBD() == 2)
			nDem++;
	}
	if (nDem != 0)
		return nDem;
	else
		return -1;
}
int nDemGV (BanDoc *pa[], int nSpt)
{
	int nDem = 0;
	for (int i = 0; i < nSpt; i++)
	{
		if (pa[i]->get_LoaiBD() == 1)
			nDem++;
	}
	if (nDem != 0)
		return nDem;
	else
		return -1;
}
void xuatBanDoc (BanDoc *pa[], int nSpt)
{
	for (int i = 0; i < nSpt; i++)
	{
		Color(14);
		cout << "Xuat thong tin ban doc: \n";Color(11);
		pa[i]->output();Color(7);
		cout << "********************************\n";
	}
}
void docFileBanDoc (BanDoc *pa[], int &nSpt)
{
	int nLoai = 0;
	string sMa = "", sTen = "", sKhoa = "";
	int nNgay = 0, nThang = 0, nNam = 0;
	int nKhoaHoc = 0;
	string sNienKhoa = "";
	string sDiaChi = "", sSDT = "";
	ifstream file;
	file.open("BanDoc.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	for (int i =0; i < nSpt; i++)
	{
		file >> nLoai;
		file.ignore(1,',');
		if (nLoai == 1) //GV
		{
			fflush(stdin);
			getline(file,sMa,',');
			fflush(stdin);
			getline(file,sTen,',');
			fflush(stdin);
			getline(file,sKhoa,',');
			file >> nNgay;
			file.ignore(1,',');
			file >> nThang;
			file.ignore(1,',');
			file >> nNam;
			file.ignore(1,',');
			fflush(stdin);
			getline(file,sDiaChi,',');
			fflush(stdin);
			getline(file,sSDT,'\n');
			pa[i] = new GiaoVien (sMa,sTen,sKhoa,nNgay,nThang,nNam,sDiaChi,sSDT);
		}
		else //SV
		{
			fflush(stdin);
			getline(file,sMa,',');
			fflush(stdin);
			getline(file,sTen,',');
			fflush(stdin);
			getline(file,sKhoa,',');
			file >> nNgay;
			file.ignore(1,',');
			file >> nThang;
			file.ignore(1,',');
			file >> nNam;
			file.ignore(1,',');
			getline(file,sNienKhoa,'\n');
			pa[i] = new SinhVien (sMa, sTen, sKhoa, nNgay, nThang, nNam,sNienKhoa);
		}
	}
	file.close();
}
void ghiFileBanDoc (BanDoc *pa[], int nSpt)
{
	ofstream file;
	file.open("BanDoc.txt");
	file << nSpt << endl;
	file.close();
	for (int i = 0; i < nSpt; i++)
	{
		pa[i]->ghiFile();
	}
	file.close();
}
//Ban doc

void xoaSach (Sach *pa[], int &nSpt)
{
	int nViTri = 0;
	int nFlag = 0;
	string sMaSach;
	do
	{
			cout << "Nhap ma sach: ";
			fflush(stdin);
	getline(cin,sMaSach);
	}while (kiemTraSachTrung (pa,nSpt,sMaSach) == false); // Kiem tra su ton tai
	for (int i = 0; i < nSpt; i++)
	{
		if (sMaSach == pa[i]->get_MaSach() && pa[i]->get_TinhTrang() == 0) //Sach ton tai && khong duoc muon
		{
			nFlag = 1;
			for (int j = i; j < nSpt-1 ; j++)
			pa[j] = pa[j+1];
			nSpt--;
			cout << "Xoa Sach thanh cong!!\n";
			ghiFileSach (pa,nSpt);
			break;
		}
	}
	if (nFlag == 0)
		cout << "Sach khong ton tai hoac dang duoc muon!!\n";

	//Cap nhap Lai Sach va Phieu Muon;
}
void themSach (Sach *pa[], int &nSpt)
{
	string sMaSach,sTuaDe,sTacGia,sNXB;
	int nGiaTien,nNamPH,nSoTrang,nNgayNhap,nThangNhap,nNamNhap;int nTinhTrang = 0;
	do
	{
		Color(11);
			cout << "\nNhap ma sach: ";
			fflush(stdin);
	getline(cin,sMaSach);
	}while (kiemTraSachTrung (pa,nSpt,sMaSach) == true); //Trung thi bat nhap lai
	Color(11);
	cout << "\nNhap tua de: ";
	fflush(stdin);
	getline (cin,sTuaDe);
	cout << "\nNhap tac gia: ";
	fflush(stdin);
	getline (cin,sTacGia);
	cout << "\nNhap NXB: ";
	fflush(stdin);
	getline (cin,sNXB);
	cout << "\nNhap gia tien: ";
	cin >> nGiaTien;
	cout << "\nNhap nam phat hanh: ";
	cin >> nNamPH;
	cout << "\nNhap so trang: ";
	cin >> nSoTrang;
	do
	{
			cout << "\nNhap ngay vao kho: ";
		cin >> nNgayNhap;
		cout << "\nNhap thang vao kho: ";
		cin >> nThangNhap;
		cout << "\nNhap Nam vao kho: ";
		cin >> nNamNhap;
	}while (nNamNhap < nNamPH);
	Sach *p = new Sach (sMaSach,sTuaDe,sTacGia,sNXB,nGiaTien,nNamPH,nSoTrang,nNgayNhap,nThangNhap,nNamNhap,nTinhTrang);
	//Dua vao mang
	int nViTri = nSpt;
	for (int i = nSpt; i > nViTri; i--)
	{	pa[i] = pa[i-1];}
	pa[nViTri] = p;
	nSpt++;
	//Tao 1 phieu muon nam o cuoi phan tu
	Color(14);
	cout << "Tao Sach thanh cong!!\n";Color(7);
	ghiFileSach (pa,nSpt);
	//Cap nhap Lai Sach va Phieu Muon;


}
bool kiemTraSachTrung (Sach *pa[], int nSpt, string sMaSach)
{
	for (int i = 0;i < nSpt; i++)
	{
		if (pa[i]->get_MaSach() == sMaSach)
			return true;
	}
	return false;
}
void xuatSach (Sach *pa[], int nSpt)
{
	for (int i = 0; i < nSpt; i++ )
	{
		Color(14);cout << "Thong tin sach thu " << i+1 << ": \n";Color(11);
		pa[i]->outputSach();Color(7);
		cout << "*********************************************\n";
	}
}
void docFileSach (Sach *pa[], int &nSpt)
{
	string sMaSach = "", sTuaDe = "",sTacGia = "",
		sNXB = "";
	int nTien = 0, nNamPH = 0,nSoTrang = 0, nNgay = 0, nThang = 0, nNam = 0, nTT = 0;
	Date xNgayNhap;
	ifstream file;
	file.open("Sach.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	for (int i = 0; i < nSpt; i++)
	{
		fflush(stdin);
		getline(file,sMaSach,',');
		fflush(stdin);
		getline(file,sTuaDe,',');
		fflush(stdin);
		getline(file,sTacGia,',');
		fflush(stdin);
		getline(file,sNXB,',');
		file >> nTien;
		file.ignore(1,',');
		file >> nNamPH;
		file.ignore(1,',');
		file >> nSoTrang;
		file.ignore(1,',');
		file >> nNgay;
		file.ignore(1,',');
		file >> nThang;
		file.ignore(1,',');
		file >> nNam;
		file.ignore(1,',');
		file >> nTT;
		file.ignore(1,'\n');
		pa[i] = new Sach (sMaSach, sTuaDe, sTacGia, sNXB, nTien, nNamPH, nSoTrang, nNgay, nThang, nNam, nTT);
	}
}
void ghiFileSach (Sach *pa[], int nSpt)
{
	ofstream file;
	file.open("Sach.txt");
	file << nSpt << endl;
	for (int i = 0; i < nSpt; i++)
	{
		file << pa[i]->get_MaSach() << ","
			<< pa[i]->get_TuaDe() << ","
			<< pa[i]->get_TacGia() << ","
			<< pa[i]->get_NXB() << ","
			<< pa[i]->get_GiaTien() << ","
			<< pa[i]->get_NamPH() << ","
			<< pa[i]->get_SoTrang() << ","
			<< pa[i]->get_NgayNhapKho() << ","
			<< pa[i]->get_ThangNhapKho() << ","
			<< pa[i]->get_NamNhapKho() << ","
			<< pa[i]->get_TinhTrang() << endl;
	}
}
//Sach
void xuatAdmin (Admin *pa[], int nSpt)
{
	for (int i = 0; i < nSpt; i++ )
	{
		cout << "Tai khoan: " << pa[i]->get_ID() << endl;
		cout << "Mat khau: " << pa[i]->get_Pass() << endl;
	}
}
void docFileAdmin (Admin *pa[], int &Spt)
{
	string sID = "", sPass ="";
	ifstream file;
	file.open("Admin.txt");
	file >> Spt;
	file.ignore(1,'\n');
	for (int i = 0; i < Spt; i++)
	{

		fflush(stdin);
		getline(file,sID,'#');
		fflush(stdin);
		getline(file,sPass,'\n');
		pa[i] = new Admin (sID,sPass);
	}
}

//Ham kiem tra
bool kiemTraTaiKhoanDangNhap (Admin *pa[], int nSpt,string sID, string sPass)
{
	for (int i = 0; i < nSpt; i++)
	{
		if (pa[i]->get_ID() == sID && pa[i]->get_Pass() == sPass)
			return true;
	}
	return false;
}
bool kiemTraBanDoc (BanDoc *pc[] ,int nSoBanDoc,string sMaBD)
{
	for (int i = 0; i < nSoBanDoc; i++)
	{
		if (pc[i]->get_MaBD() == sMaBD)
			return true;
	}
	return false;
}
bool kiemTraSachDeMuon (Sach *pb[], int nSach,string sMaSach)
{
	for (int i = 0; i < nSach;i++)
	{
		if (pb[i]->get_MaSach() == sMaSach && pb[i]->get_TinhTrang() == 0)
			return true;
	}
	return false;
}
//Admin
void PassWord(char pass[])
{
	char ch;
	int dem=0;
	//char pass[10];
	while((ch=getch())!=13){
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9') /*(ch>=32&&ch<=127) bao gom ca ky tu dac biet*/){
			printf("*");
			pass[dem++]=ch;

		}else
			if(ch==8)
				if(dem>0){
					//printf("\b \b");
					cout << "\b \b";
					dem--;
				}

	}
	pass[dem]=0;
	//printf("\n%s la pass vua nhap",pass);
}
void Color(int nX)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, nX);
}