#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <ctime>
using namespace std;
//Khai bao struct
struct Banker
{
	string sID;
	string sPin;
	int nSoTien;
};
//struct Card
//{
//	string sMaThe;
//	int nMenhGia;
//};
struct Node
{
	Banker xData;
	Node *pNext;
};
struct NodeCard 
{
	string sData;
	NodeCard *pNext;
};
struct LinkedList
{
	Node *pHead;
	Node *pTail;
};
struct LinkedListCard
{
	NodeCard *pHead;
	NodeCard *pTail;
};
//Khai bao nguyen mau ham
void Color(int nX);
void PassWord(char pass[]);
void initial(LinkedList &L);
void initialCard(LinkedListCard &L);
Node *getNodeUser (string sTK, string sMK, int nSoTien);
void addTailUser (LinkedList L, string sID, string sPin, int nSoTien);
void docDSTKUser(LinkedList &L, int &nSpt);
void docDSTKAdmin(LinkedList &L, int &nSpt);
void outputUser(LinkedList L);
void outputAdmin(LinkedList L);
bool kiemTraChinhTaID (string s);
bool kiemTraChinhTaPW (string s);
bool kiemTraNodeNhapVao(string s);
bool SoSanhTK (LinkedList L1, LinkedList L2, string sID,string sPin);
void nhapIDvaPin(string &sTK, string &sMK, int &nDem);
void login(LinkedList L1, LinkedList L2, string &sTK,string &sPin);
//Menu
bool kiemTraTKLogin (LinkedList L1,string s);
void taoHeader(string s);
void UserMenu (LinkedList &L1, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
void vietMenu (LinkedList &L1, LinkedList L2, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
void rutTien (LinkedList &L, string sTK,int &nTienRut);
void xuLySoTienRut (int nSoDu,int &nTienRut, int &nDem);
//Chuyen tien
void nhapTKChuyen (LinkedList L,string sTK, string &sTKChuyen, int &nDem);
void xuLySoTienChuyen (int &nTienChuyen, int nSoDu, int &nDem);
void chuyenTien (LinkedList &L,string sTK, string &sTKChuyen, int &nTienChuyen);
//Hoa don
void hoaDonRutTien (Node *pNew, int nTienRut);
void hoaDonChuyenTien (Node *q, Node *p, int nTienChuyen);
void hoaDonNapThe (Node *q, string sMenhGia);
//Xem TT
void outputNode(Node *p);
//Card
void ghiFileCard (LinkedListCard L, string sLoaiCard);
int nLengthCard(LinkedListCard L);
void docFileCard (LinkedListCard &L, int nSpt,string sMenhGia);
void outputCard (LinkedListCard L);
void napThe(LinkedList &L, string sTK,  LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5, int &nBan);
bool kiemTraMaTheTonTai (LinkedListCard L,string s);
bool kiemTraMaThe (string s);
void nhapThe(LinkedListCard L,string &sMa,int &nDem);
void xoaThe (LinkedListCard &L,string sMa);
void menuChonThe(LinkedList &L, string sTK,  LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
//Doi mat khau
void doiMatKhau (Node *&p);
//Cap nhat
void ghiDSTKUser (LinkedList L);
int nLength(LinkedList L);
void ghiFileUser(LinkedList L);
//Buoc 2: Cac ham xu ly cho Admin
//Tao menu
bool kiemTraTaiKhoanTrung (LinkedList L1, LinkedList L2, string sTK);
void taoTaiKhoan (LinkedList &L1,LinkedList L2);
void AdminMenu (LinkedList &L1,LinkedList L2, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
//Xoa tai khoan
void thaoTacXoaTaiKhoan (LinkedList &L, string sTK);
void xoaTaiKhoan (LinkedList &L1);
//Tim TK
void timTaiKhoan (LinkedList L);
//Quan Ly Tai khoan
void MenuQuanLyTaiKhoan(LinkedList &L1, LinkedList L2, string sTK);
void MenuQuanLyCard (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
//Nhap Card
void MenuQuanLyNhap (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
void QuanLyNhapCardViettel (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
void nhapCard (LinkedListCard &L);
//Xoa Card
void MenuQuanLyXoa (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
void QuanLyXoaCardViettel (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5);
void xoaCard (LinkedListCard &L);
//Quan ly Card
//Lich su gd
void taoDSLSGiaoDich (LinkedList L);
void LSGDRutTien (Node *q, int nTienRut);
void LSGDChuyenTien (Node *q, string sIDDich,int nTienChuyen);
void LSGDNapThe (Node *q, string sMenhGia);
void taoNodeLSGD (string sA);
void xoaNodeLSGD (string sA);
void main()
{
	int nUser = 0,nAdmin = 0;
	int nC1 = 0, nC2 = 0, nC5 = 0;
	LinkedList L1; //User
	initial(L1);
	LinkedList L2;
	initial(L2);
	//Tao LinkedList Card
	string sMenhGia = "100000";
	LinkedListCard LC1;
	initialCard(LC1);
	docFileCard(LC1,nC1,sMenhGia);
	sMenhGia = "200000";
	LinkedListCard LC2;
	initialCard(LC2);
	docFileCard(LC2,nC2,sMenhGia);
	sMenhGia = "500000";
	LinkedListCard LC5;
	initialCard(LC5);
	docFileCard(LC5,nC5,sMenhGia);
	//Doc file User+Admin
	docDSTKUser(L1,nUser);
	//outputUser(L1);
	docDSTKAdmin(L2,nAdmin);
	//taoDSLSGiaoDich (L1);
	string sTK,sPin; //nguoi dung nhap tu ban phim
	login(L1,L2,sTK,sPin);
	vietMenu(L1,L2,sTK,LC1,LC2,LC5);
	system("pause");
}
//Khai bao dinh nghia ham

//Admin
//Quan Ly Tai khoan
void MenuQuanLyTaiKhoan(LinkedList &L1, LinkedList L2, string sTK)
{
	//Khai bao du lieu
	string sHeader = "Quan Ly TK";
	string sTimTK = "";
	Node *q;
	int nChonCN = 0;
	do
	{
		system("cls");
		taoHeader(sHeader);Color(11);
		cout << "\n\t1. Tao tai khoan moi\n";
		cout << "\t2. Xoa tai khoan\n";
		cout << "\t3. Tim tai khoan bang ID\n";
		cout << "\t4. Xem tat ca thong tin tai khoan\n";Color(10);
		cout << "Ban chon chuc nang so: ";Color(7);
		cin >> nChonCN;
		switch(nChonCN)
		{
		case 1:
			taoTaiKhoan(L1,L2);
			break;
		case 2:
			xoaTaiKhoan(L1);
			break;
		case 3:
			timTaiKhoan(L1);
			break;
		case 4:
			outputUser(L1);
			break;
		default:
			Color(14);
			cout << "\n\t Ban chon thoat chuong trinh!!\n";Color(7);
		}
		ghiFileUser(L1); 
		system("pause");
	}while (nChonCN >= 1 && nChonCN <= 4);
}
//Quan ly Card
void MenuQuanLyCard (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	//Khai bao du lieu
	int nChon = 0;
	string sHeader = "Chuc nang";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\n\t1. Nhap Card\n";
		cout << "\t2. Xoa Card\n";
		cout << "\t3. Thoat chuong trinh\n";Color(13);
		cout << "Chon chuc nang: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			MenuQuanLyNhap(LC1,LC2,LC5);
			break;
		case 2:
			MenuQuanLyXoa (LC1,LC2,LC5);
			break;
		case 3:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);
			return;
		default:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);

		}

	}while (nChon >= 1 && nChon <= 3);	
}
//Nhap Card
void MenuQuanLyNhap (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	//Khai bao du lieu
	int nChon = 0;
	string sHeader = "Nha Mang";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\n\t1. Viettel\n";
		cout << "\t2. Mobile\n";
		cout << "\t3. Thoat chuong trinh\n";Color(13);
		cout << "Chon nha mang: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			QuanLyNhapCardViettel (LC1,LC2,LC5);
			break;
		case 2:
			Color(14);
			cout << "\n\tChuc nang nay dang phat trien!!\n";Color(7);
			break;
		case 3:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);
			return;
		default:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);

		}

	}while (nChon >= 1 && nChon <= 3);
}
void QuanLyNhapCardViettel (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	//Khai bao du lieu
	string sLoaiCard = "";
	int nChon = 0;
	string sHeader = "Loai Card";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\n\t1. Card 100.000\n";
		cout << "\t2. Card 200.000\n";
		cout << "\t3. Card 500.000\n";
		cout << "\t4. Thoat chuong trinh\n";Color(11);
		cout << "Chon nha mang: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			sLoaiCard = "100000";
			nhapCard(LC1);
			ghiFileCard(LC1,sLoaiCard);
			break;
		case 2:
			sLoaiCard = "200000";
			nhapCard(LC2);
			ghiFileCard(LC2,sLoaiCard);
			break;
		case 3:
			sLoaiCard = "500000";
			nhapCard(LC5);
			ghiFileCard(LC5,sLoaiCard);
			break;
		case 4:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);
			return;
		default:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 3);
}
void nhapCard (LinkedListCard &L)
{
	string sMaThe = "";
	int nDem = 0;
a:
	Color(11);
	cout << "\nNhap ma the: ";Color(7);
	fflush(stdin);
	getline(cin,sMaThe);
	if (kiemTraMaThe (sMaThe) == false)
	{
		nDem++;
		if (nDem == 3)
		{Color(12);
		cout << "\n\tBan da nhap qua so lan cho phep!!\n";Color(7);
		return;
		}
		Color(14);
		cout << "\n\tMa the khong hop le, yeu cau nhap lai\n";Color(7);
		goto a;
	}
	if (kiemTraMaTheTonTai (L,sMaThe) == true)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap qua so lan cho phep!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tMa the bi trung lap, yeu cau nhap lai\n";Color(7);
		goto a;
	}
	//Dua The vao LinkedList
	NodeCard *pNew = new NodeCard;
	if (pNew == NULL)
		exit(1);
	pNew->sData = sMaThe;
	pNew->pNext = NULL;
	if (L.pHead == NULL)
	{
		L.pHead = pNew;
		L.pTail = pNew;
	}
	else
	{
		L.pTail->pNext = pNew;
		L.pTail = pNew;
	}
	Color(14);
	cout << "\n\t\tNap the thanh cong!!\n";Color(7);
} 
//Xoa Card
void MenuQuanLyXoa (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	//Khai bao du lieu
	int nChon = 0;
	string sHeader = "Nha Mang";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\n\t1. Viettel\n";
		cout << "\t2. Mobile\n";
		cout << "\t3. Thoat chuong trinh\n";Color(10);
		cout << "Chon nha mang: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			QuanLyXoaCardViettel (LC1,LC2,LC5);
			break;
		case 2:
			cout << "\n\tChuc nang nay dang phat trien!!\n";
			break;
		case 3:
			cout << "\n\tBan chon thoat chuong trinh!!\n";
			return;
		default:
			cout << "\n\tBan chon thoat chuong trinh!!\n";

		}

	}while (nChon >= 1 && nChon <= 3);
}
void QuanLyXoaCardViettel (LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	//Khai bao du lieu
	string sLoaiCard = "";
	int nChon = 0;
	string sHeader = "Loai Card";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\n\t1. Card 100.000\n";
		cout << "\t2. Card 200.000\n";
		cout << "\t3. Card 500.000\n";
		cout << "\t4. Thoat chuong trinh\n";Color(10);
		cout << "Chon nha mang: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			sLoaiCard = "100000";
			xoaCard(LC1);
			ghiFileCard(LC1,sLoaiCard);
			break;
		case 2:
			sLoaiCard = "200000";
			xoaCard(LC2);
			ghiFileCard(LC2,sLoaiCard);
			break;
		case 3:
			sLoaiCard = "500000";
			xoaCard(LC5);
			ghiFileCard(LC5,sLoaiCard);
			break;
		case 4:
			cout << "\n\tBan chon thoat chuong trinh!!\n";
			return;
		default:
			cout << "\n\tBan chon thoat chuong trinh!!\n";
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 3);
}
void xoaCard (LinkedListCard &L)
{
	if (L.pHead == NULL)//DS Rong~
	{
		Color(12);
		cout << "\n\t\tThe da het!!\n";Color(7);
		return;
	}
	string sMaThe = "";
	int nDem = 0;
a:
	Color(11);
	cout << "Nhap ma the: ";Color(7);
	fflush(stdin);
	getline(cin,sMaThe);
	if (kiemTraMaThe (sMaThe) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap qua so lan cho phep!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tMa the khong hop le, yeu cau nhap lai\n";Color(7);
		goto a;
	}
	if (kiemTraMaTheTonTai (L,sMaThe) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap qua so lan cho phep!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tThe khong co tren he thong\n";Color(7);
		goto a;
	}
	//Xoa the
	xoaThe(L,sMaThe);
	Color(11);cout << "\n\tXoa thanh cong!!\n";Color(7);
} 
//1. Tao Tai khoan
bool kiemTraTaiKhoanTrung (LinkedList L1, LinkedList L2, string sTK)
{
	Node *q = L1.pHead;
	while (q != NULL)
	{
		if (q->xData.sID == sTK)
			return true;
		q=q->pNext;
	}
	//TK do k nam tren User
	q = L2.pHead;
	while (q != NULL)
	{
		if (q->xData.sID == sTK)
			return true;
		q=q->pNext;
	}
	//TK k nam tren Admin + User
	return false;
}
void taoTaiKhoan (LinkedList &L1,LinkedList L2)
{
	string sID ="", sPin ="";
	int nSoTien = 0;
	int nDem = 0;
a:
	Color(14);
	cout << "Nhap tai khoan moi: ";Color(11);
	fflush(stdin);
	getline(cin,sID);
	if (kiemTraChinhTaID (sID) == false)
	{
		nDem++;
		if(nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";
			return;
		}
		Color(12);
		cout << "\n\tBan da nhap sai cu phap, vui long nhap lai!!\n";
		goto a;
	}
	//Tai khoan hop le cu phap
	if (kiemTraTaiKhoanTrung (L1,L2, sID) == true)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";
			return;
		}
		Color(12);
		cout << "\n\tTai khoan da ton tai!!\n";
		goto a;
	}
	//Tai khoan hop le cu phap + TK k trung
	nDem = 0;
b:
	Color(14);
	cout << "\nNhap ma pin: ";Color(11);
	fflush(stdin);
	getline(cin,sPin);
	if (kiemTraChinhTaPW (sPin) == false)
	{
		nDem++;
		if(nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";
			return;
		}
		Color(12);
		cout << "\n\tBan da nhap sai cu phap, vui long nhap lai!!\n";
		goto b;
	}
	//Ma pin da hop le
	nDem = 0;
	//nSoTien luon luon mac dinh = 0
	//3 dieu kien da hop le!!
	addTailUser(L1,sID,sPin,nSoTien);
	Color(11);
	cout << "\n\t\tTao Tai khoan thanh cong!!\n";
	taoNodeLSGD(sID); //Tao ra 1 file "sID.txt" 
	ghiDSTKUser (L1); //Cap nhat lai DSTK User tren file "DSTKUser.txt"
}
//2. Xoa tai khoan
void thaoTacXoaTaiKhoan (LinkedList &L, string sTK)
{
	if (L.pHead == NULL)
	{
		Color(12);
		cout << "Khong xoa dc!!\n";Color(7);
		return;
	}
	if (L.pHead->pNext == NULL)
	{
		Node *p = L.pHead;
		L.pHead = NULL;
		L.pTail = NULL;
		delete p;
		return;
	}
	Node *q = L.pHead;
	while (q != NULL && q->pNext != NULL)
	{
		if (q->pNext->xData.sID == sTK) //Node ke tiep trung voi tai khoan can tim
		{
			Node *p = q->pNext;
			q->pNext = p->pNext;
			if (q->pNext == NULL)
			{
				L.pTail = q;
			}
			delete p;
			Color(14);cout << "\n\t\t Xoa thanh cong!!\n";Color(7);
			ghiDSTKUser (L);
			return;
		}
		q=q->pNext;
	}
	Color(12);
	cout << "\n\tKhong xoa duoc!!\n";Color(7);
}
void xoaTaiKhoan (LinkedList &L1)
{
	int nDem = 0;
	string sTK = "";
a:
	Color(11);
	cout << "Nhap ten tai khoan can xoa: ";Color(7);
	fflush(stdin);
	getline(cin,sTK);
	if (kiemTraChinhTaID (sTK) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tSai cu phap, yeu cau nhap lai\n";Color(7);
		goto a;
	}
	nDem = 0;
	if (kiemTraTKLogin (L1,sTK) == false) //Khong tim thay User trong List
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tTai khoan can xoa khong ton tai\n";Color(7);
		goto a;		
	}
	thaoTacXoaTaiKhoan(L1,sTK);
}
//3. TimTK
void timTaiKhoan (LinkedList L)
{
	string sTKTim = "";
	int nDem = 0;
a:
	Color(11);
	cout << "\nNhap tai khoan can tim: ";Color(7);
	fflush(stdin);
	getline(cin,sTKTim);
	if (kiemTraChinhTaID (sTKTim) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan cho phep!!\n";Color(7);
			return;
			//Quay lai menu
		}
		Color(14);
		cout << "\n\tSai cu phap, vui long nhap lai!!\n";Color(7);
		goto a;
	}
	//Tai khoan nhap can tim da hop le!!
	if (kiemTraTKLogin (L,sTKTim) == false)//Kt tk co ton tai tren he thong hay k
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan cho phep!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tTai khoan khong ton tai!!!!\n";Color(7);
		goto a;
	}
	//TK da ton tai tren L1
	Node *q = L.pHead;
	while (q != NULL)
	{
		if (q->xData.sID == sTKTim)
		{
			Color(14);cout << "\n\t\tXuat Thong tin cua User!!\n"; 
			Color(11);
			outputNode(q);Color(7);
		}
		break;
		q=q->pNext;
	}
}
//Lich su giao dich
void xoaNodeLSGD (string sA)
{
	/*DeleteFile("C:/Users/Admin/Downloads/TrenhQuyHung-CNTT/CauTrucDuLieu-GiaiThuat/Project-Last/Project-Last/LichSuGD/"+sA+".txt");*/
}
void taoNodeLSGD (string sA)
{
	string sHeader = "Lich Su Giao Dich";
	ofstream file;
	file.open("D:/Project-Last/Project-Last/LichSuGD/"+sA+".txt");
	file << "\t\t\t\t\t\t\t\t\t\t\t***************************************\n";
	file << "\t\t\t\t\t\t\t\t\t\t\t*******     ";file << sHeader;file << "    *****\n";
	file << "\t\t\t\t\t\t\t\t\t\t\t***************************************\n";
	file << endl;
	file << setw(10) << "Time"
		<< setw(15) << "Day"
		<< setw(20) << "So ID"
		<< setw(20) << "Loai GD"
		<< setw(20) << "So Tien Rut"
		<< setw(20) << "So ID Dich"
		<< setw(20) << "So Tien Chuyen"
		<< setw(20) << "Loai Card"
		<< setw(20) << "Menh Gia"
		<< setw(20) << "So Du" << endl;
	file.close();
}
void taoDSLSGiaoDich (LinkedList L)
{
	Node *q = L.pHead;
	string sHeader = "Lich Su Giao Dich";
	time_t baygio;
	tm *ltm;
	while (q != NULL)
	{
		ofstream file;
		file.open("D:/Project-Last/Project-Last/LichSuGD/"+q->xData.sID+".txt");
		baygio = time(0);
		ltm = localtime(&baygio);
		file << "\t\t\t\t\t\t\t\t\t\t\t***************************************\n";
		file << "\t\t\t\t\t\t\t\t\t\t\t*******     ";file << sHeader;file << "    *****\n";
		file << "\t\t\t\t\t\t\t\t\t\t\t***************************************\n";
		file << endl;
		file << setw(10) << "Time"
			<< setw(15) << "Day"
			<< setw(20) << "So ID"
			<< setw(20) << "Loai GD"
			<< setw(20) << "So Tien Rut"
			<< setw(20) << "So ID Dich"
			<< setw(20) << "So Tien Chuyen"
			<< setw(20) << "Loai Card"
			<< setw(20) << "Menh Gia"
			<< setw(20) << "So Du" << endl;
		file.close();
		q=q->pNext;
	}
}
void LSGDRutTien (Node *q, int nTienRut)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ofstream file;
	file.open("D:/Project-Last/Project-Last/LichSuGD/"+q->xData.sID+".txt",ios::app);
	file << setw(4) << ltm->tm_hour
		<< setw(1) << ":" 
		<< setw(2) << ltm->tm_min
		<< setw(1) << ":" 
		<< setw(2) << 1+ltm->tm_sec
		<< setw(7) << ltm->tm_mday
		<< setw(1) << "/" 
		<< setw(2) << 1+ltm->tm_mon
		<< setw(1) << "/" 
		<< setw(4) << 1900+ltm->tm_year
		<< setw(20) << q->xData.sID
		<< setw(20) << "Rut Tien"
		<< setw(20) << nTienRut
		<< setw(20) << "Not Application"
		<< setw(20) << "Not Application"
		<< setw(20) << "Not Application"
		<< setw(20) << "Not Application"
		<< setw(20) << q->xData.nSoTien << endl;
	file.close();
}
void LSGDChuyenTien (Node *q, string sIDDich,int nTienChuyen)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ofstream file;
	file.open("D:/Project-Last/Project-Last/LichSuGD/"+q->xData.sID+".txt",ios::app);
	file << setw(4) << ltm->tm_hour
		<< setw(1) << ":" 
		<< setw(2) << ltm->tm_min
		<< setw(1) << ":" 
		<< setw(2) << 1+ltm->tm_sec
		<< setw(7) << ltm->tm_mday
		<< setw(1) << "/" 
		<< setw(2) << 1+ltm->tm_mon
		<< setw(1) << "/" 
		<< setw(4) << 1900+ltm->tm_year
		<< setw(20) << q->xData.sID
		<< setw(20) << "Chuyen Tien"
		<< setw(20) << "Not Application"
		<< setw(20) << sIDDich
		<< setw(20) << nTienChuyen
		<< setw(20) << "Not Application"
		<< setw(20) << "Not Application"
		<< setw(20) << q->xData.nSoTien << endl;
	file.close();
}
void LSGDNapThe (Node *q, string sMenhGia)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ofstream file;
	file.open("D:/Project-Last/Project-Last/LichSuGD/"+q->xData.sID+".txt",ios::app);
	file << setw(4) << ltm->tm_hour
		<< setw(1) << ":" 
		<< setw(2) << ltm->tm_min
		<< setw(1) << ":" 
		<< setw(2) << 1+ltm->tm_sec
		<< setw(7) << ltm->tm_mday
		<< setw(1) << "/" 
		<< setw(2) << 1+ltm->tm_mon
		<< setw(1) << "/" 
		<< setw(4) << 1900+ltm->tm_year
		<< setw(20) << q->xData.sID
		<< setw(20) << "Nap Card"
		<< setw(20) << "Not Application"
		<< setw(20) << "Not Application"
		<< setw(20) << "Not Application"
		<< setw(20) << "Viettel"
		<< setw(20) << sMenhGia
		<< setw(20) << q->xData.nSoTien << endl;
	file.close();
}
//Nap the
int nLengthCard(LinkedListCard L)
{
	int nLength = 0;
	NodeCard *q = L.pHead;
	while (q != NULL)
	{
		nLength++;
		q=q->pNext;
	}
	return nLength;
}
void xoaThe (LinkedListCard &L,string sMa)
{
	if (L.pHead == NULL)
		return;
	if (L.pHead->pNext == NULL)
	{
		NodeCard *p = L.pHead;
		L.pHead = NULL;
		L.pTail = NULL;
		delete p;
		return;
	}
	if (L.pHead->sData == sMa) //The nam o vi tri dau
	{
		NodeCard *p= L.pHead;
		L.pHead=L.pHead->pNext;
		//Neu ds rong sau khi xoa
		if(L.pHead == NULL)
		{
			L.pTail = NULL;
		}
		delete p;
	}
	NodeCard *q = L.pHead;
	while (q != NULL && q->pNext != NULL)
	{
		if (q->pNext->sData == sMa)
		{
			NodeCard *p = q->pNext; //p la the can xoa
			q->pNext = p->pNext;
			if (q->pNext == NULL)
			{
				L.pHead = q;
			}
			delete p;
			break;
		}

		q=q->pNext;
	}
}
void nhapThe(LinkedListCard L,string &sMa,int &nDem)
{
	if (L.pHead == NULL) //Het card!!
	{
		Color(12);
		cout << "\n\t\t Het Card!!\n";Color(7);
		return;
	}
a:
	Color(13);
	cout << "Nhap ma the: ";
	Color(11);
	fflush(stdin);
	getline(cin,sMa);
	if (kiemTraMaThe (sMa) == false || kiemTraMaTheTonTai (L,sMa) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\tThe da su dung hoac khong ton tai\n";Color(7);
		goto a;
	}
}
bool kiemTraMaTheTonTai (LinkedListCard L,string s)
{
	NodeCard *q = L.pHead;
	while (q != NULL)
	{
		if (q->sData == s)
			return true;
		q=q->pNext;
	}
	return false;

}
bool kiemTraMaThe (string s)
{
	if (s.length() != 12)
	{return false;}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{return false;}
	}
	return true;
}
void napThe(LinkedList &L, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5, int &nBan)
{
	string sHD = "";
	Node *q;
	string sLoaiCard = "";
	int nChon = 0;
	int nDem = 0;
	string sHeader = "Menh Gia";
	string sMa = "";
	do
	{
		system("cls");
		taoHeader(sHeader);
		cout << endl;
		Color(10);
		cout << "\t1. Card 100.000\n";
		cout << "\t2. Card 200.000\n";
		cout << "\t3. Card 500.000\n";
		cout << "\t4. Thoat chuong trinh\n";Color(11);
		cout << "Ban chon loai card: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			nhapThe(LC1,sMa,nDem);
			if (nDem == 0)
				return;
			if (nDem == 3)
			{
				nBan = 1;
				return;
			}
			q = L.pHead;
			while (q != NULL)
			{
				if (q->xData.sID == sTK)
				{
					Color(11);
					cout << "\n\t\tHe thong dang xu ly";Sleep(600);cout << ".";Sleep(600);cout << ".";Sleep(600);cout << ".";
					Color(14);
					cout << "\n\t\tSo du Tai khoan: " << q->xData.nSoTien << endl;
					cout << "\n\t\tSo card nap: 100.000 VND" << endl;
					q->xData.nSoTien += 100000;
					cout << "\n\t\tSo du TK da nap: " << q->xData.nSoTien << endl;Color(7);
					xoaThe(LC1,sMa);
					//Viet hoa don && LSGD
					sLoaiCard = "100000";
					LSGDNapThe (q,sLoaiCard);
					Color(10);
					cout << "\n\t Ban co muon in hoa don khong? (y/n)";
					getline(cin,sHD);
					if (sHD == "y")
					{
						Color(14);
						hoaDonNapThe(q,sLoaiCard);
						cout << "\n\n\t Cam on quy khach da su dung dich vu!!\n";
					}
					else
					{
						cout << "\n\n\t Cam on quy khach da su dung dich vu!!\n";
						Color(14);
					}
					Color(7);
					break;
				}
				q=q->pNext;
			}
			ghiFileCard(LC1,sLoaiCard);
			break;
		case 2:
			nhapThe(LC2,sMa,nDem);
			if (nDem == 3)
			{
				nBan = 1;
				return;
			}
			q = L.pHead;
			while (q != NULL)
			{
				if (q->xData.sID == sTK)
				{
					Color(11);
					cout << "\n\t\tHe thong dang xu ly";Sleep(600);cout << ".";Sleep(600);cout << ".";Sleep(600);cout << ".";
					Color(14);
					cout << "\n\t\tSo du Tai khoan: " << q->xData.nSoTien << endl;
					cout << "\n\t\tSo card nap: 200.000 VND" << endl;
					q->xData.nSoTien += 200000;
					cout << "\n\t\tSo du TK da nap: " << q->xData.nSoTien << endl;Color(7);
					xoaThe(LC2,sMa);
					//Viet hoa don && LSGD
					sLoaiCard = "200000";
					LSGDNapThe (q,sLoaiCard);
					Color(10);
					cout << "\n\t Ban co muon in hoa don khong? (y/n)";
					getline(cin,sHD);
					if (sHD == "y")
					{
						Color(14);
						hoaDonNapThe(q,sLoaiCard);
						cout << "\n\n\t Cam on quy khach da su dung dich vu!!\n";Color(7);
					}
					else
					{
						Color(14);
						cout << "\n\n\t Cam on quy khach da su dung dich vu!!\n";Color(7);
						
					}
					Color(7);
					break;
				}
				q=q->pNext;
			}
			ghiFileCard(LC2,sLoaiCard);
			break;
		case 3:
			nhapThe(LC5,sMa,nDem);
			if (nDem == 3)
			{
				nBan = 1;
				return;
			}
			q = L.pHead;
			while (q != NULL)
			{
				if (q->xData.sID == sTK)
				{
					Color(11);
					cout << "\n\t\tHe thong dang xu ly";Sleep(600);cout << ".";Sleep(600);cout << ".";Sleep(600);cout << ".";
					Color(14);
					cout << "\n\t\tSo du Tai khoan: " << q->xData.nSoTien << endl;
					cout << "\n\t\tSo card nap: 500.000 VND" << endl;
					q->xData.nSoTien += 500000;
					cout << "\n\t\tSo du TK da nap: " << q->xData.nSoTien << endl;Color(7);
					xoaThe(LC5,sMa);
					//Viet hoa don && LSGD
					sLoaiCard = "500000";
					LSGDNapThe (q,sLoaiCard);
					Color(10);
					cout << "\n\t Ban co muon in hoa don khong? (y/n)";
					getline(cin,sHD);
					if (sHD == "y")
					{
						Color(14);
						hoaDonNapThe(q,sLoaiCard);
						cout << "\n\n\t Cam on quy khach da su dung dich vu!!\n";
					}
					else
					{
						Color(14);
						cout << "\n\n\t Cam on quy khach da su dung dich vu!!\n";
						
					}
					Color(7);
					break;
				}
				q=q->pNext;
			}
			ghiFileCard(LC5,sLoaiCard);
			break;
		case 4:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);
			return;
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 4);
}
void menuChonThe(LinkedList &L, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	int nChon = 0;
	int nBan = 0;
	string sHeader = "Nha Mang";
	do
	{
		system("cls");
		taoHeader(sHeader);
		cout << endl;
		Color(10);
		cout << "\t1. Viettel\n";
		cout << "\t2. Mobile\n";
		cout << "\t3. Thoat\n";Color(11);
		cout << "Ban chon loai the: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			if (nBan == 1)
			{
				Color(12);
				cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Color(7);
				break;
			}
			napThe(L,sTK,LC1,LC2,LC5, nBan);
			break;
		case 2:
			if (nBan == 1)
			{
				Color(12);
				cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Color(7);
				break;
			}
			Color(14);
			cout << "Tinh nang nay dang phat trien!!\n";Color(7);
			break;
		case 3:
			Color(14);
			cout << "\n\tBan chon thoat chuong trinh!!\n";Color(7);
			return;
		}
		system("pause");
	}while (nChon >= 1 && nChon <= 3);
}
void outputCard (LinkedListCard L)
{
	Color(14);
	cout << "Xuat thong tin Card!!\n";
	NodeCard *q = L.pHead;
	while (q != NULL)
	{
		Color(11);
		cout << "Ma card: " << q->sData<< endl;Color(7);
		q=q->pNext;
	}
}
void ghiFileCard (LinkedListCard L, string sLoaiCard)
{
	ofstream file;
	file.open("Card" + sLoaiCard+".txt");
	file << nLengthCard(L) << endl;
	NodeCard *q = L.pHead;
	while (q != NULL)
	{
		file << q->sData << endl;
		q=q->pNext;
	}
}
void docFileCard (LinkedListCard &L, int nSpt, string sMenhGia)
{
	ifstream file;
	file.open("Card"+ sMenhGia + ".txt");
	file >> nSpt;
	file.ignore(1,'\n');
	NodeCard *pNew;
	for (int i = 1; i <= nSpt; i++)
	{
		pNew = new NodeCard;
		if (pNew == NULL)
			exit(1);
		fflush(stdin);
		getline(file,pNew->sData,'\n');
		pNew->pNext = NULL;
		if (L.pHead == NULL)
		{
			L.pHead = pNew;
			L.pTail = pNew;
		}
		else
		{

			L.pTail->pNext = pNew;
			L.pTail = pNew;
		}

	}
}
//Cap nhat du lieu
void ghiFileUser(LinkedList L)
{
	ofstream file;
	file.open("inputUser.txt");
	file << nLength(L) << endl;
	Node *q = L.pHead;
	while (q != NULL)
	{
		file << q->xData.sID << "#" << q->xData.sPin << "#" << q->xData.nSoTien << endl;
		q=q->pNext;
	}
}
int nLength(LinkedList L)
{
	int nLength = 0;
	Node *q = L.pHead;
	while (q != NULL)
	{
		nLength++;
		q=q->pNext;
	}
	return nLength;
}
void outputNode(Node *p)
{
	cout << "\n\tID: " << p->xData.sID << endl;
	cout << "\tPin Code: " << p->xData.sPin << endl;
	cout << "\tSo du: " << p->xData.nSoTien << endl;
}
void ghiDSTKUser (LinkedList L)
{
	ofstream file;
	file.open("DSTKUser.txt");
	Node *q  = L.pHead;
	while (q != NULL)
	{
		file << q->xData.sID << "#" << q->xData.sPin << endl;
		q=q->pNext;
	}
	file.close();
}
//Hoa don
void hoaDonNapThe (Node *q, string sMenhGia)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ofstream file;
	file.open("HoaDon.txt");
	file << "\t\t\t***************************************\n";
	file << "\t\t\t*******      ";file << "ATM Banking";file << "    ***********\n";
	file << "\t\t\t***************************************\n";
	file << endl;
	file  << "Ngay"
		<< setw(30) << "     Gio" << endl;
	file << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1990+ltm->tm_year
		<< setw(30) << ltm->tm_hour << ":" << ltm->tm_min << ":" << 1+ltm->tm_sec << endl;
	file << "ID: " << q->xData.sID << endl;
	file << "\n****************Nap The***************\n";file << endl;
	file << setw(15) << "ID Nap The: " << setw(20) << q->xData.sID << endl;
	file << setw(15) << "Loai Card: " << setw(20) << "Viettel\n";
	file << setw(15) << "Menh Gia: " << setw(20) << sMenhGia << endl;
	file << setw(15) << "So du: " << setw(20) << q->xData.nSoTien << endl;
	file << "\n\n\t\t Cam on da su dung dich vu!!\n";
}
void hoaDonChuyenTien (Node *q, Node *p, int nTienChuyen)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ofstream file;
	file.open("HoaDon.txt");
	file << "\t\t\t***************************************\n";
	file << "\t\t\t*******      ";file << "ATM Banking";file << "    ***********\n";
	file << "\t\t\t***************************************\n";
	file << endl;
	file  << "Ngay"
		<< setw(30) << "     Gio" << endl;
	file << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1990+ltm->tm_year
		<< setw(30) << 1+ltm->tm_hour << ":" << 1+ltm->tm_min << ":" << 1+ltm->tm_sec << endl;
	file << "ID: " << q->xData.sID << endl;
	file << "\n****************Chuyen Tien***************\n";file << endl;
	file << setw(15) << "ID Nguon: " << setw(20) << q->xData.sID << endl;
	file << setw(15) << "ID Dich: " << setw(20) << p->xData.sID << endl;
	file << setw(15) << "Tien chuyen: " << setw(20) << nTienChuyen << endl;
	file << setw(15) << "So du: " << setw(20) << q->xData.nSoTien << endl;
	file << "\n\n\t\t Cam on da su dung dich vu!!\n";
}
void hoaDonRutTien (Node *pNew, int nTienRut)
{
	time_t baygio = time(0);
	tm *ltm = localtime(&baygio);
	ofstream file;
	file.open("HoaDon.txt");
	file << "\t\t\t***************************************\n";
	file << "\t\t\t*******      ";file << "ATM Banking";file << "    ***********\n";
	file << "\t\t\t***************************************\n";
	file << endl;
	file  << "Ngay"
		<< setw(30) << "     Gio" << endl;
	file << ltm->tm_mday << "/" << 1+ltm->tm_mon << "/" << 1990+ltm->tm_year
		<< setw(30) << 1+ltm->tm_hour << ":" << 1+ltm->tm_min << ":" << 1+ltm->tm_sec << endl;
	file << "ID: " <<  pNew->xData.sID << endl;
	file <<  "\n****************Rut Tien***************\n";file << endl;
	file << setw(20) <<  "ID: " << setw(20) << "So tien rut" << endl;
	file  << setw(20) << pNew->xData.sID << setw(20) << nTienRut << endl;
	file << "So du: " << pNew->xData.nSoTien << endl;
	file << "\n\n\t\t Cam on da su dung dich vu!!\n";

}
//Doi mat khau
void doiMatKhau (Node *&p)
{
	char c[12],c2[12];string s,s2; int nFlag = 0; int nDem =0;
a:
	Color(11);
	cout << "\nNhap PIN cu: ";Color(7);
	PassWord(c); s = c; cout << endl;
	while (nDem != 3)
	{
		if (s != p->xData.sPin)
		{
			nDem++;
			if (nDem == 3)
			{
				Color(12);
				cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Color(7);
				nFlag = 1;
				return;
			}
			Color(14);
			cout << "\n\tBan da nhap sai, vui long nhap lai!!\n";Color(7);
			goto a;
		}
		else
			break;
	}
	//Mat khau cu da nhap dung!!
	if (nFlag == 0)
	{
b:
		Color(11);
		cout << "\nNhap ma pin moi: ";Color(7);
		PassWord(c); s = c; cout << endl;
		if (kiemTraChinhTaPW (s) == false)
		{
			Color(14);
			cout << "\n\tBan nhap sai cu phap, vui long nhap lai!!\n";Color(7);
			goto b;
		}
		//Ma pin moi lan 1 da nhap dung!!
		Color(11);
		cout << "\nNhap lai ma pin: ";Color(7);
		PassWord(c2); s2 = c2; cout << endl;
		if (s2 != s)
		{
			Color(14);
			cout << "\n\tMa pin nhap lai khong chinh xac!!\n";Color(7);
			goto b;
		}
		//Ma pin moi lan 2 da duoc nhap dung!!
		p->xData.sPin = s; //or s2
		Color(10);
		cout << "\n\tMat khau da duoc thay doi thanh cong!!\n";Color(7);

	}

}
//Chuyen tien
void chuyenTien (LinkedList &L,string sTK, string &sTKChuyen, int &nTienChuyen)
{
	int nDem = 0;
	Node *q = L.pHead;
	Node *p;
	while (q != NULL)
	{
		if (q->xData.sID == sTK)
		{
			Color(13);
			cout << "So du trong TK: ";Color(11); cout <<  q->xData.nSoTien << endl;
			if (q->xData.nSoTien < 50000)
			{
				Color(12);
				cout << "\n\t\t Ban phai co so du 50.000 tro len moi thuc hien duoc giao dich\n";Color(7);
				return;
			}
			nhapTKChuyen (L,sTK,sTKChuyen, nDem);
			if (nDem == 3)
				return;
			nDem = 0;
			xuLySoTienChuyen (nTienChuyen, q->xData.nSoTien, nDem);
			if (nDem == 3)
				return;
			p = L.pHead;
			while (p->xData.sID != sTKChuyen)
				p=p->pNext;
			q->xData.nSoTien = q->xData.nSoTien - nTienChuyen;
			p->xData.nSoTien = p->xData.nSoTien + nTienChuyen;
			Color(11);
			cout << "\n\t\tHe thong dang xu ly";Sleep(600);cout << ".";Sleep(600);cout << ".";Sleep(600);cout << ".";
			Color(10);
			cout << "\n\t\tGiao dich thanh cong!!\n";Sleep(1000);
			//Lich su GD + Hoa Don
			LSGDChuyenTien (q,p->xData.sID,nTienChuyen);
			string s = "";
			Color(10);
			cout << "\n\t\tBan co muon in hoa don khong (y/n): ";
			fflush(stdin);
			getline(cin,s);
			if (s == "y")
			{
				hoaDonChuyenTien (q,p,nTienChuyen);
				Color(14);
				cout << "\n\t\tCam on quy khach da su dung dich vu!!\n";
			}
			else
			{Color(14);
			cout << "\n\t\tCam on quy khach da su dung dich vu!!\n";}
			Color(7);
			break;
		}
		q=q->pNext;
	}
}
void xuLySoTienChuyen (int &nTienChuyen, int nSoDu, int &nDem)
{
a:
	if (nSoDu < 50000)
	{
		Color(12);
		cout << "\n\Can phai co so du > 50.000 de tiep tuc chuong trinh!!\n";Color(7);
		nDem = 3;
		return;
	}
	Color(13);
	cout << "Nhap so tien ban muon chuyen: ";
	Color(11);
	cin >> nTienChuyen;
	if (nTienChuyen > nSoDu || nTienChuyen < 50000 || nTienChuyen % 1000 != 0)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan!!\n";Sleep(2000);Color(7);
			return;
		}
		Color(14);
		cout << "\n\tSo tien chuyen khong hop le!!\n";Color(7);
		goto a;
	}
	if (nSoDu - nTienChuyen < 50000)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\tBan da nhap sai qua so lan!!\n";Sleep(2000);Color(7);
			return;
		}
		Color(14);
		cout << "\n\tSo du tai khoan sau khi rut phai tren 50000!!\n";Color(7);
		goto a;
	}
}
void nhapTKChuyen (LinkedList L, string sTK, string &sTKChuyen, int &nDem)
{
a:
	Color(13);
	cout << "\nNhap tai khoan can chuyen: ";
	Color(11);
	fflush(stdin);
	getline(cin,sTKChuyen);Color(7);
	if (sTKChuyen == sTK)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\t\tBan da nhap sai qua so lan\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\t\tTai khoan trung voi account!!\n";Color(7);
		goto a;
	}
	if (kiemTraChinhTaID (sTKChuyen) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\t\tBan da nhap sai qua so lan!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "\n\t\tNhap sai cu phap, vui long nhap lai!!\n";Color(7);
		goto a;
	}
	if (kiemTraTKLogin(L,sTKChuyen) == false)
	{
		nDem++;
		if (nDem == 3)
		{
			Color(12);
			cout << "\n\t\tBan da nhap sai qua so lan!!\n";Color(7);
			return;
		}
		Color(14);
		cout << "Tai khoan can chuyen khong ton tai!!\n";Color(7);
		goto a;
	}
	return;
}
//Rut Tien
void xuLySoTienRut (int nSoDu,int &nTienRut,int &nDem)
{
	nDem = 0;
	nTienRut = 0.0;
	if(nSoDu < 50000)
	{
		Color(12);
		cout << "Ban phai co so du TK tren 50000 de tiep tuc chuong trinh!!\n";Sleep(2000);Color(7);
		nDem = 3;
		return;
	}
	while (nDem != 3)
	{
a:
		Color(13);
		cout << "\nNhap so tien ban muon rut: ";
		Color(11);
		cin >> nTienRut;
		if (nTienRut > nSoDu || nTienRut < 50000 || nTienRut % 1000 != 0)
		{
			nDem++;
			if (nDem == 3)
			{
				Color(12);
				cout << "Ban da nhap sai qua so lan!!\n";Sleep(2000);Color(7);
				return;
			}
			Color(14);
			cout << "\n\tSo tien rut khong hop le!!\n";Color(7);
			goto a;
		}
		if (nSoDu - nTienRut < 50000)
		{
			nDem++;
			if (nDem == 3)
			{
				Color(12);
				cout << "Ban da nhap sai qua so lan!!\n";Sleep(2000);Color(7);
				return;
			}
			Color(14);
			cout << "So du tai khoan sau khi rut phai tren 50000!!\n";Color(7);
			goto a;
		}
		//So tien rut da hop le!!
		return;
	}

}
void rutTien (LinkedList &L, string sTK,int &nTienRut)
{
	int nDem = 0;
	Node *q = L.pHead;
	while (q != NULL)
	{
		if (q->xData.sID == sTK)
		{
			Color(11);
			cout << "So du hien tai: " << q->xData.nSoTien << endl;Color(7);
			xuLySoTienRut(q->xData.nSoTien,nTienRut,nDem);
			//nDem && nTienRut da duoc cap nhat
			//So tien can rut da hop le or da sai qua so lan!!
			if (nDem == 3)
				return;
			//So tien rut da hop le
			Color(11);
			cout << "\n\t He thong dang xu ly";Sleep(700);cout << ".";Sleep(700);cout << ".";Sleep(700);cout << ".\n";
			q->xData.nSoTien = q->xData.nSoTien - nTienRut;
			//Luc nay So du da dc cap nhat
			Color(10);cout << "\t\tBan da rut " << nTienRut << endl;Sleep(1000);
			cout << "\t\tSo du con lai trong tai khoan cua ban la: " << q->xData.nSoTien << endl;Sleep(1000);
			//Lich su giao dich && Hoa don
			LSGDRutTien (q, nTienRut);
			string s = "";
			Color(11);
			cout << "Ban co muon in hoa don khong (y/n): ";Color(7);
			fflush(stdin);
			getline(cin,s);
			if (s == "y")
			{
				hoaDonRutTien (q, nTienRut);
				Color(11);
				cout << "\n\t\tCam on quy khach da su dung dich vu!!\n";Color(7);
			}
			else
				{Color(11);
			cout << "\n\t\tCam on quy khach da su dung dich vu!!\n";Color(7);}
			break;
		}
		q=q->pNext;
	}
}
//Ham Main
void vietMenu (LinkedList &L1, LinkedList L2, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	if (kiemTraTKLogin (L1,sTK) == true) //Day la tai khoan cua User
	{
		UserMenu(L1,sTK,LC1,LC2,LC5);
	}
	else //Admin
	{
		AdminMenu (L1,L2,sTK,LC1,LC2,LC5);
	}
}
void AdminMenu (LinkedList &L1,LinkedList L2, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	//Khai bao cac bien o day
	int nChonCN = 0;
	Node *q;
	string sHeader = "Admin Login";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\t1. Quan ly Tai Khoan\n";
		cout << "\t2. Quan ly Card\n";
		cout << "\t3. Thoat chuong trinh\n";Color(11);
		cout << "Ban chon chuc nang so: ";Color(7);
		cin >> nChonCN;
		switch(nChonCN)
		{
		case 1:
			MenuQuanLyTaiKhoan(L1,L2,sTK);
			break;
		case 2:
			MenuQuanLyCard (LC1,LC2,LC5);
			break;
		case 3:
			Color(14);
			cout << "\n\tCam on da su dung dich vu cua chung toi!!\n";Color(7);
			ghiFileUser(L1); 
			ghiDSTKUser (L1);
			return;
		default:
			Color(10);
			cout << "\n\t\tBan chon thoat chuong trinh!!\n";Color(7);
		}
		ghiFileUser(L1); 
		ghiDSTKUser (L1);
		system("pause");
	}while (nChonCN >= 1 && nChonCN <= 3);

}
void UserMenu (LinkedList &L1, string sTK, LinkedListCard &LC1,LinkedListCard &LC2,LinkedListCard &LC5)
{
	int nChon = 0;
	int nTienRut = 0, nTienChuyen = 0;
	string sTKChuyen = "";
	Node *q;
	string sHeader = "ATM Banking";
	do
	{
		system("cls");
		taoHeader(sHeader);
		Color(11);
		cout << "\t1. Rut tien.\n";
		cout << "\t2. Chuyen tien.\n";
		cout << "\t3. Xem So du tai khoan\n";
		cout << "\t4. Nap tien online\n";
		cout << "\t5. Doi ma Pin\n";
		cout << "\t6. Thoat chuong trinh\n";Color(13);
		cout << "\n\t Moi ban chon chuc nang so: ";Color(7);
		cin >> nChon;
		switch(nChon)
		{
		case 1:
			rutTien(L1,sTK,nTienRut);
			break;
		case 2:
			chuyenTien (L1,sTK,sTKChuyen,nTienChuyen);
			break;
		case 3:
			q = L1.pHead;
			while (q != NULL)
			{
				if (q->xData.sID == sTK)
				{
					Color(14);
					cout << "Thong tin cua Khach hang!!\n";
					cout << endl;
					Color(11);
					outputNode(q);Color(7);
					break;
				}
				q=q->pNext;
			}
			break;
		case 4:
			menuChonThe(L1, sTK,LC1,LC2,LC5);
			break;
		case 5:
			q = L1.pHead;
			while (q != NULL)
			{
				if (q->xData.sID == sTK)
				{
					doiMatKhau(q);
					ghiDSTKUser (L1);
					break;
					//Node q da duoc thay doi!!
				}
				q=q->pNext;
			}
			break;
		case 6:
			Color(11);
			cout << "\n\tHen gap quy khach lan sau!!\n";
			ghiFileUser(L1); 
			ghiDSTKUser (L1);
			return;
		default:
			Color(11);
			cout << "\n\tHen gap quy khach lan sau!!\n";
		}
		ghiFileUser(L1); 
		ghiDSTKUser (L1);
		system("pause");//Du lieu se duoc cap nhat ngay khi ket thuc 1 case
	}while(nChon >= 1 && nChon <= 5);
}
void taoHeader(string s)
{
	Color(11);
	cout << "\t\t\t************************************\n";
	cout << "\t\t\t*******      ";Color(12);cout << s;Color(11);cout << "    ********\n";
	cout << "\t\t\t************************************\n";Color(7);
	cout << endl;
}
bool kiemTraTKLogin (LinkedList L1,string s)
{
	Node *q = L1.pHead;
	while (q != NULL)
	{
		//Neu tai khoan nam trong LinkedList cua User thi return true
		if (q->xData.sID == s)
			return true;
		q=q->pNext;
	}
	//Nguoc lai
	return false;
}
//So cap
void login(LinkedList L1, LinkedList L2, string &sTK,string &sPin)
{
	int nDem = 0;
	string sHeader = "ATM Banking";
	taoHeader(sHeader);
	Color(10);
	cout << "\nMoi ban dang nhap de tiep tuc chuong trinh.\n";Color(7);
a:
	nhapIDvaPin(sTK,sPin,nDem);
	//nDem da duoc thay doi
	while (nDem != 3)
	{
		if (SoSanhTK(L1,L2,sTK,sPin) == true)
		{
			Color(11);
			cout << "\n\tDang dang nhap";Sleep(700);cout << ".";Sleep(700);cout << ".";Sleep(700);cout << ".";Sleep(700);Color(7);
			break;
		}
		else
		{
			nDem++;
			if (nDem == 3)
			{
				Color(11);
				cout << "\n\tBan da nhap sai qua so lan quy dinh!!\n";Sleep(1000);Color(7);
				exit(1);
			}
			Color(13);cout << "\n\t\tID khong ton tai!! Vui long nhap lai\n";Color(7);
			cout << endl;
			goto a;
		}
	}
}
void nhapIDvaPin(string &sTK, string &sMK, int &nDem)
{
	char c[10];
	while (nDem != 3)
	{
a:
		Color(11);cout << setw(15) <<  "\tNhap ID: ";Color(7);
		fflush(stdin);
		getline(cin,sTK);Color(11);
		cout << setw(15) << "\tNhap Ma Pin: "; Color(7);
		PassWord(c);sMK = c; cout << endl;

		if ( kiemTraChinhTaID (sTK) == false || kiemTraChinhTaPW(sMK) == false)
		{
			nDem++;
			if (nDem == 3)
			{
				Color(11);
				cout << "\n\t\tBan da nhap sai qua 3 lan!! He thong se thoat\n";Sleep(1000);Color(7);
				exit(1);
			}
			Color(11);
			cout << "\n\t\tBan da nhap sai cu phap, vui long nhap lai\n";Color(7);
			cout << endl;
			goto a;
		}
		return;
	}
}
void outputAdmin(LinkedList L)
{
	cout << "Xuat thong tin Admin!!\n";
	Node *q = L.pHead;
	while (q != NULL)
	{
		cout << "Tai khoan: " << q->xData.sID << endl;
		cout << "Mat khau: " << q->xData.sPin << endl;
		cout << endl;
		q=q->pNext;
	}
}
void outputUser(LinkedList L)
{
	Color(10);
	cout << "\n\tXuat thong tin tat ca User!!\n";Color(7);
	Node *q = L.pHead;
	int i = 0;
	while (q != NULL)
	{
		Color(14);
		i++;
		cout << "\nXuat thong tin User thu " << i << ": \n";
		Color(11);cout << "\tTai khoan: " << q->xData.sID << endl;
		cout << "\tMat khau: " << q->xData.sPin << endl;
		cout << "\tSo tien: " << q->xData.nSoTien << endl;
		q=q->pNext;
	}
	Color(7);
}
void docDSTKAdmin(LinkedList &L, int &nSpt)
{
	ifstream file;
	file.open("inputAdmin.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	Node *pNew;
	for (int i = 1; i <= nSpt; i++)
	{
		pNew = new Node;
		if (pNew == NULL)
			exit(1);
		fflush(stdin);
		getline(file,pNew->xData.sID,'#');
		fflush(stdin);
		getline(file,pNew->xData.sPin,'\n');
		pNew->pNext = NULL;
		if (L.pHead == NULL)
		{
			L.pHead = pNew;
			L.pTail = pNew;
		}
		else
		{

			L.pTail->pNext = pNew;
			L.pTail = pNew;
		}

	}
}
void docDSTKUser(LinkedList &L, int &nSpt)
{
	ifstream file;
	file.open("inputUser.txt");
	file >> nSpt;
	file.ignore(1,'\n');
	Node *pNew;
	for (int i = 1; i <= nSpt; i++)
	{
		pNew = new Node;
		if (pNew == NULL)
			exit(1);
		fflush(stdin);
		getline(file,pNew->xData.sID,'#');
		fflush(stdin);
		getline(file,pNew->xData.sPin,'#');
		file >> pNew->xData.nSoTien;
		file.ignore(1,'\n');
		pNew->pNext = NULL;
		if (L.pHead == NULL)
		{
			L.pHead = pNew;
			L.pTail = pNew;
		}
		else
		{

			L.pTail->pNext = pNew;
			L.pTail = pNew;
		}

	}
}
Node *getNodeUser (string sTK, string sMK, int nSoTien)
{
	Node *pNew = new Node;
	if (pNew == NULL)
		exit(1);
	pNew->xData.sID = sTK;
	pNew->xData.sPin = sMK;
	pNew->xData.nSoTien = nSoTien;
	pNew->pNext = NULL;
	return pNew;
}
void addTailUser (LinkedList L, string sID, string sPin, int nSoTien)
{
	Node *pNew = getNodeUser (sID,sPin,nSoTien);
	//Da tao ra 1 Node pNew chua xData cua 3 du lieu dc dua vao va pNext = NULL;
	if (L.pHead == NULL)
	{
		L.pHead = pNew;
		L.pTail = pNew;
	}
	else
	{
		L.pTail->pNext = pNew;
		L.pTail = pNew;
	}
}
void initial(LinkedList &L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}
void initialCard (LinkedListCard &L)
{
	L.pHead = NULL;
	L.pTail = NULL;
}
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
//Ham xu ly chuoi
bool SoSanhTK (LinkedList L1, LinkedList L2, string sID,string sPin)
{
	Node *q = L1.pHead;
	while (q != NULL)
	{
		if (q->xData.sID == sID && q->xData.sPin == sPin)
			return true;
		q=q->pNext;
	}
	q = L2.pHead;
	while (q != NULL)
	{
		if (q->xData.sID == sID && q->xData.sPin == sPin)
			return true;
		q=q->pNext;
	}
	return false;
}
bool kiemTraChinhTaPW (string s)
{
	if (s.length() != 6)
	{return false;}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{return false;}
	}
	return true;
}
bool kiemTraChinhTaID (string s)
{
	if (s.length() != 14)
	{return false;}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{return false;}
	}
	return true;
}