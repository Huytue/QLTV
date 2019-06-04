/*
-------THANH VIEN NHOM-------
Nguyen Huy Tue
Nguyen Vinh Hien
Tran Thi Thuc Trinh
Mai Xuan Tri
Tran Cong Hoa
	
*/
// Khai bao thu vien:
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <iomanip>
#include "Admin.h"
#include "GiaoVien.h"
#include "SinhVien.h"
#include "PhieuMuon.h"
#include "Sach.h"
using namespace std;
int PhieuMuon::nTongPhieuMuon = 0;
//Admin
void doc_Admin(list <Admin> &L);
void dangNhap(list <Admin> L, list <Sach> LSach, list <BanDoc*> LBanDoc, list <PhieuMuon> LPhieuMuon);
void Color(int xcolor);
string maHoaPassword(unsigned maxLength);
//DS ban doc
void docDsBanDoc(list <BanDoc*> &LBanDoc);
void xuatDsBanDoc(list <BanDoc*> LBanDoc);
void timKiemBanDoc(list <BanDoc*> LBanDoc);
bool kiemTraBD(list <BanDoc*> LBanDoc, string sMaBD);
void themBanDoc(list <BanDoc*> &LBanDoc);
int soLuongBanDocGiaoVien(list <BanDoc*> LBanDoc);
int soLuongBanDocSinhVien(list <BanDoc*> LBanDoc);
//DS sach
bool kiemTraSachMuon(list <Sach> LSach, string sMS);
void docDsSach(list <Sach> &LSach);
void xuatDsSach(list <Sach> LSach);
void ghiDsSach(list <Sach> LSach);
int demSachHienCo(list <Sach> LSach);
void themSach(list <Sach> &LSach);
void xoaSach(list <Sach> &LSach);
void timKiem(list <Sach> LSach);
int nDemSachChuaMuon(list <Sach> LSach);
int nDemSachDaMuon(list <Sach> LSach);
//Phieu muon
void docDsPhieuMuon(list <PhieuMuon> &LPhieuMuon);
void themPhieuMuon(list <PhieuMuon> &LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> &LSach);
void xuatDsPhieuMuon(list <PhieuMuon> LPhieuMuon);
void ghiDsPhieuMuon(list <PhieuMuon> LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> LSach);
int demTongPhieuMuon(list <PhieuMuon> LPhieuMuon);
void traSach(list <PhieuMuon> &LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> &LSach);
void lietKeSachBanDocMuon(list <PhieuMuon> LPhieuMuon, list <Sach> LSach);
// MENU
void menu_Main();
void menu_TimThongTin();
void menu_DangNhap();
void menu_Admin();
void menu_QLPhieuMuon();
void menu_QuanLySach();
void menu_thongKe();
void menu_QuanLyBanDoc();
void menu_ThemBanDoc();
// thong bao
void thongBao();
void thongBaoNhapSai();
void login(list <Admin> L, list <PhieuMuon> LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> LSach);
//Chuong trinh chinh
void main()
{
	list <Admin> L1;
	list <BanDoc*> LBanDoc;
	list <Sach> LSach;
	list <PhieuMuon> LPhieuMuon;
	doc_Admin(L1);
	docDsBanDoc(LBanDoc);
	docDsSach(LSach);
	docDsPhieuMuon(LPhieuMuon);
	login(L1, LPhieuMuon, LBanDoc, LSach);
	system("pause");
}
// Menu Thong Dao Dau
void menu_Main()
{
	system("cls");
	Color(14);
	cout << "\n\t\t===============================================\n";
	cout << "\t\t===========>";
	Color(11);
	cout << " MENU QUAN LY THU VIEN ";
	Color(14);
	cout << "<===========\n";
	cout << "\t\t===============================================\n";
	Color(10);
	cout << "\t\t-----------------------------------------------\n";
	Color(12);
	cout << "\t\t\t 1. Hien Thi Thong Tin Sach.\n";
	cout << "\t\t\t 2. Hien Thi Thong Tin Ban Doc.\n";
	cout << "\t\t\t 3. Tim Kiem Thong Tin.\n";
	cout << "\t\t\t 4. Quan Ly.\n";
	cout << "\t\t\t 5. Thoat Chuong Trinh!\n";
	Color(10);
	cout << "\t\t-----------------------------------------------\n";
	Color(13);
	cout << "\t\t\t   Chon Chuc Nang: "; Color(7);

}
void menu_TimThongTin()
{
	system("cls"); 
	Color(12);
	cout << "\t\t\t   Tim Kiem Thong Tin\n";
	Color(6);
	cout << "\t\t-------------------------------------------\n"; Color(10);
	cout << "\t\t      1. Tim sach theo ma sach.\n";
	cout << "\t\t      2. Tim ban doc theo ma ban doc.\n";
	cout << "\t\t      3. Tro Ve Menu Chinh.\n"; Color(6);
	cout << "\t\t-------------------------------------------\n"; Color(9);
	cout << "\t\t\t   Nhap Lua Chon: "; Color(7);
}
void menu_DangNhap()
{
	system("cls");
	Color(10);
	cout << "\t\t------------------------------------\n";
	cout << "\t\t|             "; 
	Color(14);
	cout << "DANG NHAP";
	Color(10);
	cout <<"            | \n";
	cout << "\t\t------------------------------------\n";
	Color(12);
	cout << "\t\t\t Nhap \"ESC\" de thoat!\n";
}
void menu_Admin()
{
	system("cls");
	Color(12);
	cout << "\t\t\t HE THONG QUAN LY THU VIEN\n";
	Color(6);
	cout << "\t\t-------------------------------------------\n"; Color(10);
	cout << "\t\t\t  1. Quan ly phieu muon.\n";
	cout << "\t\t\t  2. Quan ly sach.\n";
	cout << "\t\t\t  3. Quan ly ban doc.\n";
	cout << "\t\t\t  4. Thong ke.\n";
	cout << "\t\t\t  0. Thoat!\n"; Color(6);
	cout << "\t\t-------------------------------------------\n"; Color(9);
	cout << "\t\t\t  Chon Chuc Nang: "; Color(7);
}
void menu_QLPhieuMuon()
{
	system("cls");
	Color(12);
	cout << "\t\t\t   QUAN LY PHIEU MUON\n";
	Color(6);
	cout << "\t\t------------------------------------------\n"; Color(10);
	cout << "\t\t\t  1. Them phieu muon.\n";
	cout << "\t\t\t  2. Tra Sach.\n";
	cout << "\t\t\t  3. Xuat danh dach phieu muon\n";
	cout << "\t\t\t  4. Tro Ve Quan Ly!\n"; Color(6);
	cout << "\t\t------------------------------------------\n"; Color(9);
	cout << "\t\t\t  Chon Chuc Nang: "; Color(7);
}
void menu_QuanLySach()
{
	system("cls");
	Color(12);
	cout << "\t\t\t\t QUAN LY PHIEU MUON\n";
	Color(6);
	cout << "\t\t\t-------------------------------------\n"; Color(10);
	cout << "\t\t\t\t 1. Them sach moi.\n";
	cout << "\t\t\t\t 2. Xoa Sach.\n";
	cout << "\t\t\t\t 3. Tro Ve Quan Ly!\n"; Color(6);
	cout << "\t\t\t-------------------------------------\n"; Color(9);
	cout << "\t\t  Luu y: Nhap ";
	Color(12);
	cout << "ESC ";
	Color(9);
	cout << "de huy chuc nang dang thuc hien!\n";
	Color(6);
	cout << "\t\t\t-------------------------------------\n"; Color(13);
	cout << "\t\t\t\t   Chon Chuc Nang: "; Color(7);
}
void menu_thongKe()
{
	system("cls");
	Color(12);
	cout << "\t\t\t\t QUAN LY THONG KE\n";
	Color(6);
	cout << "\t----------------------------------------------------------\n"; Color(10);
	cout << "\t  1. Tong so sach con lai trong thua vien chua duoc muon. \n";
	cout << "\t  2. Tong so sach da muon.\n";
	cout << "\t  3. Liet ke sach ma 1 ban doc dang muon bang ma ban doc. \n";
	cout << "\t  4. Tong so ban doc la giao vien.\n";
	cout << "\t  5. Tong so ban doc la sinh vien.\n";
	cout << "\t  6. Tro Ve Quan Ly!\n"; Color(6);
	cout << "\t----------------------------------------------------------\n"; Color(9);
	cout << "\t\t\t   Chon Chuc Nang: "; Color(7);
}
void menu_QuanLyBanDoc()
{
	system("cls");
	Color(12);
	cout << "\t\t\t\t QUAN LY BAN DOC\n";
	Color(6);
	cout << "\t\t-------------------------------\n"; Color(10);
	cout << "\t\t\t  1. Them Ban Doc\n";
	cout << "\t\t\t  2. Tro Ve Quan Ly!\n"; Color(6);
	cout << "\t\t-------------------------------\n"; Color(9);
	cout << "\t\t\t   Chon Chuc Nang: "; Color(7);
}
void menu_ThemBanDoc()
{
	system("cls");
	Color(12);
	cout << "\t\t\t THEM BAN DOC\n";
	Color(6);
	cout << "\t\t-------------------------------------\n";
	cout << "\t\t\t  1. Them ban doc Giao Vien.\n";
	cout << "\t\t\t  2. Them ban doc Sinh Vien.\n";
	cout << "\t\t\t  3. Tro Ve Quan Ly!\n";
	cout << "\t\t-------------------------------------\n";
	cout << "\t\t\t  Chon Chuc Nang: "; Color(7);
}
// Menu Thong Bao Cuoi
void thongBao()
{
	Color(4);
	cout << "\t\t\tKhong duoc de trong !\n";
	Color(7);
}
void thongBaoNhapSai()
{
	Color(4);
	cout << "\t\tNhap sai! Vui long nhap lai.\n";
	Color(7);
}
// Nhap Vao Cac Chuc nang
void login(list <Admin> L, list <PhieuMuon> LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> LSach)
{
	int nChucNang = 0;
	do
	{
	nhapLaiMenu:
		menu_Main();
		cin >> nChucNang;
		switch (nChucNang)
		{
		case 1:
			system("cls");
			Color(14);
			cout << "\t\t===========>";
			Color(11);
			cout << " THONG TIN SACH ";
			Color(14);
			cout << "<===========\n";
			xuatDsSach(LSach);
			system("pause");
			goto nhapLaiMenu;
		case 2:
			system("cls");
			Color(5);
			cout << "\t\t===========>";
			Color(11);
			cout << " THONG TIN BAN DOC ";
			Color(5);
			cout << "<===========\n";
			Color(6);
			if (LBanDoc.empty() == true)
			{
				cout << "Danh Sach Rong\n";
			}
			else
			{
				cout << endl;
			}
			xuatDsBanDoc(LBanDoc);
			system("pause");
			goto nhapLaiMenu;
		case 3:
			timThongTin:
			menu_TimThongTin();
			cin >> nChucNang;
			do
			{
				switch (nChucNang)
				{
				case 1:
					Color(14);
					cout << "\n\t\t----------Tim sach theo ma sach-----------\n\n";
					timKiem(LSach);
					cout << "\t\t";
					system("pause");
					goto timThongTin;
				case 2:
					Color(14);
					cout << "\n\t\t--------Tim ban doc theo ma ban doc--------\n\n";
					timKiemBanDoc(LBanDoc);
					cout << "\t\t";
					system("pause");
					goto timThongTin;
				case 3:
					goto nhapLaiMenu;
				default:
					thongBaoNhapSai();
					cout << "\t\t";
					system("pause");
					goto timThongTin;
				}
			} while (nChucNang < 0 || nChucNang > 3);

		case 4:
			dangNhap(L, LSach, LBanDoc, LPhieuMuon);
			system("pause");
			goto nhapLaiMenu;
		case 5:
			exit(1);
			break;
		default:
			break;
		}
	} while (nChucNang < 1 && nChucNang > 5);
}
//Phieu muon
void lietKeSachBanDocMuon(list <PhieuMuon> LPhieuMuon, list <Sach> LSach)
{
	int flag = 0;
	string sMBD = "";
nhapLaiMaBanDoc:
	Color(4);
	cout << "\n\t\t\t   Nhap N de thoat!\n\n";
	Color(13);
	cout << "\t\t\tNhap ma ban doc: ";
	rewind(stdin);
	getline(cin, sMBD);
	if (sMBD == "N"|| sMBD == "n")
	{
		Color(10);
		cout << "\t\tBan da con thoat!\n";
		Color(7);
		return;
	}
	list <PhieuMuon>::iterator p = LPhieuMuon.begin();
	Color(1);
	cout << "\n\t-------------Danh Sach Sach Ban Doc Dang Muon--------------\n\n";
	Color(10);
	while (p != LPhieuMuon.end())
	{
		if (sMBD == p->getBanDoc().getMaBanDoc() && p->getTrangThai() != 0)
		{

			list <Sach>::iterator q = LSach.begin();
			while (q != LSach.end())
			{
				if (q->getMS() == p->getSach().getMS())
				{
					flag = 1;
					q->outputSach();
				}
				q++;
			}
		}
		p++;
	}
	if (flag == 0)
	{
		Color(4);
		cout << "\t   Ma ban doc nay chua muon sach.Vui long nhap lai!\n ";
		Color(7);
		goto nhapLaiMaBanDoc;
	}

}
void traSach(list <PhieuMuon> &LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> &LSach)
{ dd:
	int flag = 0;
	int nMPM = 0;
	while (true)
	{
		
		system("cls");
		Color(10);
		cout << "\n\t   -----------------Them Phieu Muon---------------\n\n";
		Color(13);
		cout << "\t\tNhap ma phieu muon can tra sach: "; cin >> nMPM;
		if (nMPM == 0 )
		{
			return;
		}
		list <PhieuMuon> ::iterator p = LPhieuMuon.begin();
		while (p != LPhieuMuon.end())
		{
			if (nMPM == p->getMaPhieuMuon())
			{
				if (p->getTrangThai() != 0)
				{
					flag = 1;
					p->setTrangThai(0); // gan tinh trang 0 cho phieu muon muon tra sach
					string sMaSach = p->getSach().getMS();
					for (list <Sach> ::iterator q = LSach.begin(); q != LSach.end(); q++)
					{
						if (q->getMS() == sMaSach)
						{
							q->setTinhTrang(0); // gan trai thang 0 cho sach da duoc tra
							break;
						}
					}
					ghiDsSach(LSach);
					ghiDsPhieuMuon(LPhieuMuon, LBanDoc, LSach);
					Color(10);
					cout << "\t\tTra sach thanh cong!\n";
					Color(7);
					break;
				}
				else
				{
					flag = 2;
					Color(4);
					cout << "\n\t\tMa phieu muon da duoc tra!\n\t\t";
					Color(7);
					system("pause");
				}
			}
			p++;
		}
		if (flag == 0)
		{
			Color(4);
			cout << "\n\t\tMa phieu muon khong ton tai!\n\n\t\t";
			Color(7);
			system("pause");
		}
		else if (flag == 1)
		{
			break;
		} if (flag == 2)
		{
			goto dd;
		}
	}
}
int demTongPhieuMuon(list <PhieuMuon> LPhieuMuon)
{
	int nDem = 0;
	list <PhieuMuon> ::iterator p = LPhieuMuon.begin();
	while (p != LPhieuMuon.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
void themPhieuMuon(list <PhieuMuon> &LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> &LSach)
{
	string sMBD = "";
	while (true)
	{
		system("cls");
		Color(10);
		cout << "\n\t   -----------------Them Phieu Muon---------------\n";
		Color(4);
		cout << "\n\t\t\t  Nhap ESC de thoat!\n";
		Color(14);
		cout << "\n\t\tNhap ma ban doc can muon sach: ";
		rewind(stdin);
		getline(cin, sMBD);
		if (sMBD == "")
		{
			Color(4);
			cout << "\n\t\tKhong duoc de trong ! \n\n\t\t";
			Color(7);
			system("pause");
		}
		else if (sMBD == "ESC"|| sMBD == "esc")
		{
			Color(10);
			cout << "\t\tBan chon thoat!\n";
			Color(7);
			return;
		}
		else if (kiemTraBD(LBanDoc, sMBD) != true)
		{
			Color(4);
			cout << "\n\t\tMa ban doc khong ton tai!\n\n\t\t";
			Color(7);
			system("pause");
		}
		else
		{
			break;
		}
	}
	string sMS = "";
	while (true)
	{
		Color(14);
		cout << "\t\tNhap ma sach: ";
		rewind(stdin);
		getline(cin, sMS);
		if (sMS == "")
		{
			Color(4);
			cout << "\n\t\tKhong duoc de trong ! \n\n\t\t";
			Color(7);
			system("pause");
		}
		else if (kiemTraSachMuon(LSach, sMS) == true)
		{
			break;
		}
		else if (sMS == "ESC" || sMS == "esc")
		{
			Color(10);
			cout << "\t\tBan chon thoat!\n";
			Color(7);
			return;
		}
		else
		{
			Color(4);
			cout << "\t\tMa sach khong ton tai! hoac dang co ban doc muon.\n";
			Color(7);
			system("pause");
		}
	}
	PhieuMuon pm(sMBD, sMS);
	LPhieuMuon.push_back(pm);
	Color(10);
	cout << "\t\tTao phieu muon thanh cong!\n";
	Color(7);
	ofstream fout;
	fout.open("PhieuMuon.txt", ios::app);
	fout << "\n" << LPhieuMuon.rbegin()->getMaPhieuMuon() << "," << LPhieuMuon.rbegin()->getBanDoc().getMaBanDoc() << "," << LPhieuMuon.rbegin()->getSach().getMS() << "," << LPhieuMuon.rbegin()->getNgayMuon().getNgay() << "," << LPhieuMuon.rbegin()->getNgayMuon().getThang() << "," << LPhieuMuon.rbegin()->getNgayMuon().getNam() << "," << LPhieuMuon.rbegin()->getNgayTra().getNgay() << "," << LPhieuMuon.rbegin()->getNgayTra().getThang() << "," << LPhieuMuon.rbegin()->getNgayTra().getNam() << "," << LPhieuMuon.rbegin()->getTrangThai();
	fout.close();
	int nTinhTrang = LPhieuMuon.rbegin()->getMaPhieuMuon(); // trang thai
	list <Sach> ::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		if (p->getMS() == sMS)
		{
			p->setTinhTrang(nTinhTrang);// tinh trang
			break;
		}
		p++;
	}
	ghiDsSach(LSach);

}
void ghiDsPhieuMuon(list <PhieuMuon> LPhieuMuon, list <BanDoc*> LBanDoc, list <Sach> LSach)
{
	int nTongPM = demTongPhieuMuon(LPhieuMuon);
	int nDem = 1;
	ofstream fout;
	fout.open("PhieuMuon.txt");
	list <PhieuMuon> ::iterator p = LPhieuMuon.begin();
	while (p != LPhieuMuon.end())
	{
		fout << p->getMaPhieuMuon() << "," << p->getBanDoc().getMaBanDoc() << "," << p->getSach().getMS() << "," << p->getNgayMuon().getNgay() << "," <<
			p->getNgayMuon().getThang() << "," << p->getNgayMuon().getNam() << "," << p->getNgayTra().getNgay() << "," << p->getNgayTra().getThang() << "," << 
			p->getNgayTra().getNam() << "," << p->getTrangThai();
		if (nDem < nTongPM)
		{
			fout << endl;
			nDem++;
		}
		p++;
	}
	fout.close();
}
void xuatDsPhieuMuon(list <PhieuMuon> LPhieuMuon)
{
	list <PhieuMuon> ::iterator p = LPhieuMuon.begin();
	while (p != LPhieuMuon.end())
	{
		p->xuat();
		p++;
	}
}
void docDsPhieuMuon(list <PhieuMuon> &LPhieuMuon)
{
	int nSPM = 0;
	string sMBD = "";
	string sMS = "";
	int nNgayMuon = 0;
	int nThangMuon = 0;
	int nNamMuon = 0;
	int nNgayTra = 0;
	int nThangTra = 0;
	int nNamTra = 0;
	int nTrangThai = 0;
	ifstream fin;
	fin.open("PhieuMuon.txt");
	while (!fin.eof())
	{
		fin >> nSPM;
		fin.ignore(1, ',');
		getline(fin, sMBD, ',');
		getline(fin, sMS, ',');
		fin >> nNgayMuon;
		fin.ignore(1, ',');
		fin >> nThangMuon;
		fin.ignore(1, ',');
		fin >> nNamMuon;
		fin.ignore(1, ',');
		fin >> nNgayTra;
		fin.ignore(1, ',');
		fin >> nThangTra;
		fin.ignore(1, ',');
		fin >> nNamTra;
		fin.ignore(1, ',');
		fin >> nTrangThai;
		fin.ignore(1, '\n');
		PhieuMuon pm(nSPM, sMBD, sMS, nNgayMuon, nThangMuon, nNamMuon, nNgayTra, nThangTra, nNamTra, nTrangThai);
		LPhieuMuon.push_back(pm);
	}
	fin.close();
}
//DS Ban Doc
int soLuongBanDocSinhVien(list <BanDoc*> LBanDoc)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	ifstream fin;
	fin.open("BanDoc.txt");
	while (!fin.eof())
	{
		fin >> nLoai;
		fin.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(fin, sMaBD, '\n');
		}
		else if (nLoai == 2)
		{
			nDem++;
			getline(fin, sMaBD, '\n');
		}
	}
	fin.close();
	return nDem;
}
int soLuongBanDocGiaoVien(list <BanDoc*> LBanDoc)
{
	int nDem = 0;
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream fin;
	fin.open("BanDoc.txt");
	while (!fin.eof())
	{
		fin >> nLoai;
		fin.ignore(1, ',');
		if (nLoai == 1)
		{
			nDem++;
			getline(fin, sMaBD, ',');
			getline(fin, sHoTen, ',');
			getline(fin, sKhoa, ',');
			fin >> nNgay;
			fin.ignore(1, ',');
			fin >> nThang;
			fin.ignore(1, ',');
			fin >> nNam;
			fin.ignore(1, ',');
			getline(fin, sDC, ',');
			getline(fin, sSDT, '\n');
		}
		else if (nLoai == 2)
		{
			getline(fin, sMaBD, ',');
			getline(fin, sHoTen, ',');
			getline(fin, sKhoa, ',');
			fin >> nNgay;
			fin.ignore(1, ',');
			fin >> nThang;
			fin.ignore(1, ',');
			fin >> nNam;
			fin.ignore(1, ',');
			fin >> nKhoaHoc;
			fin.ignore(1, '\n');
		}
	}
	fin.close();
	return nDem;
}
void themBanDoc(list <BanDoc*> &LBanDoc)
{
	time_t t = time(0);
	struct tm *Now = localtime(&t);
	int nLoaiBD = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = Now->tm_mday;         
	int nThang = Now->tm_mon + 1;    // ngay lam the duoc lay thu dong:
	int nNam = Now->tm_year + 1900;  
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	
	while (true)
	{
		menu_ThemBanDoc();
		cin >> nLoaiBD;
		if (nLoaiBD == 1)
		{
			nLoaiBD = 1;
			int nTongSL = soLuongBanDocGiaoVien(LBanDoc);
		dd:	Color(11);
			cout << "\t\tNhap ma ban doc:"; rewind(stdin); getline(cin, sMaBD);
			for (list <BanDoc*> ::iterator p = LBanDoc.begin(); p != LBanDoc.end(); p++)
			{
				if (sMaBD == (*p)->getMaBanDoc())
				{
					Color(4);
					cout << "\t\tMa ban doc da ton tai. Vui long nhap lai!\n";
					goto dd;
				}
			}
			cout << "\t\tNhap ho va ten: "; rewind(stdin); getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; rewind(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap dia chi: "; rewind(stdin); getline(cin, sDC);
			cout << "\t\tNhap so dien thoai: "; rewind(stdin); getline(cin, sSDT);
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			LBanDoc.push_back(gv);
			ofstream fout;
			fout.open("BanDoc.txt", ios::app);
			fout << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << sDC << "," << sSDT;
			fout.close();
			Color(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			system("pause");
			break;
		}
		else if (nLoaiBD == 2)
		{
		cc:	nLoaiBD = 2;
			int nTongSL = soLuongBanDocSinhVien(LBanDoc);
			Color(11);
			cout << "\t\tNhap ma ban doc:"; rewind(stdin); getline(cin, sMaBD);
			for (list <BanDoc*> ::iterator p = LBanDoc.begin(); p != LBanDoc.end(); p++)
			{
				if (sMaBD == (*p)->getMaBanDoc())
				{
					Color(4);
					cout << "\t\tMa ban doc da ton tai. Vui long nhap lai!\n";
					goto cc;
				}
			}
			cout << "\t\tNhap ho va ten: "; rewind(stdin); getline(cin, sHoTen);
			cout << "\t\tNhap Khoa: "; rewind(stdin); getline(cin, sKhoa);
			cout << "\t\tNhap Khoa Hoc: "; cin >> nKhoaHoc;
			BanDoc *  sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			LBanDoc.push_back(sv);
			ofstream fout;
			fout.open("BanDoc.txt", ios::app);
			fout << "\n" << nLoaiBD << "," << sMaBD << "," << sHoTen << "," << sKhoa << "," << nNgay << "," << nThang << "," << nNam << "," << nKhoaHoc;
			fout.close();
			Color(10);
			cout << "\t\tThem ban doc thanh cong!\n ";
			system("pause");
			break;
		}
		else if (nLoaiBD == 0)
		{
			break;
		}
		else
		{
			thongBaoNhapSai();
		}
	}
}
void timKiemBanDoc(list <BanDoc*> LBanDoc)
{
	string sMBD = "";
	Color(4);
	cout << "\t\t\t   Nhap N de thoat!\n\n";
	Color(7);
dd:
	list <BanDoc*>::iterator p = LBanDoc.begin();
	Color(10);
	cout << "\t\tNhap ma ban doc can tim thong tin: ";
	cin >> sMBD;
	if (sMBD == "N")
	{
		Color(10);
		cout << "\t\t\tBan da chon thoat!\n";
		Color(7);
		return;
	}
	while (p != LBanDoc.end())
	{
		if (sMBD == (*p)->getMaBanDoc())
		{
			Color(13);
			cout << "\n\t\t--------------THONG BAN DOC---------------\n\n";
			Color(1);
			(*p)->output();
			return;
		}
		p++;
	}
	Color(4);
	cout << "\n\t\tMa ban doc khong ton tai. Vui long nhap lai!\n\n";
	Color(7);
	goto dd;
}
bool kiemTraBD(list <BanDoc*> LBanDoc, string sMaBD)
{
	list <BanDoc*>::iterator p = LBanDoc.begin();
	while (p != LBanDoc.end())
	{
		if (sMaBD == (*p)->getMaBanDoc())
		{
			return true;
		}
		p++;
	}
	return false;
}
void xuatDsBanDoc(list <BanDoc*> LBanDoc)
{
	list <BanDoc*> ::iterator p = LBanDoc.begin();
	while (p != LBanDoc.end())
	{
		Color(4);
		cout << "\n\t\t<========================================>\n\n";
		Color(10);
		(*p)->output();
		p++;
		Sleep(300);
	}
}
void docDsBanDoc(list <BanDoc*> &LBanDoc)
{
	int nLoai = 0;
	string sMaBD = "";
	string sHoTen = "";
	string sKhoa = "";
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	string sDC = "";
	string sSDT = "";
	int nKhoaHoc = 0;
	ifstream fin;
	fin.open("BanDoc.txt");
	while (!fin.eof())
	{
		fin >> nLoai;
		fin.ignore(1, ',');
		if (nLoai == 1)
		{
			getline(fin, sMaBD, ',');
			getline(fin, sHoTen, ',');
			getline(fin, sKhoa, ',');
			fin >> nNgay;
			fin.ignore(1, ',');
			fin >> nThang;
			fin.ignore(1, ',');
			fin >> nNam;
			fin.ignore(1, ',');
			getline(fin, sDC, ',');
			getline(fin, sSDT, '\n');
			BanDoc * gv = new GiaoVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, sDC, sSDT);
			LBanDoc.push_back(gv);
		}
		else if (nLoai == 2)
		{
			getline(fin, sMaBD, ',');
			getline(fin, sHoTen, ',');
			getline(fin, sKhoa, ',');
			fin >> nNgay;
			fin.ignore(1, ',');
			fin >> nThang;
			fin.ignore(1, ',');
			fin >> nNam;
			fin.ignore(1, ',');
			fin >> nKhoaHoc;
			fin.ignore(1, '\n');
			BanDoc * sv = new SinhVien(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam, nKhoaHoc);
			LBanDoc.push_back(sv);
		}
	}
	fin.close();
}
void xoaBanDoc(list <BanDoc>& LBanDoc)
{
	Color(4);
	cout << "\t\t\t\t   Nhap N de thoat! \n";
	string sBanDocCanXoa = "";
nhapLaiMaSach:
	Color(13);
	rewind(stdin);
	cout << "\t\tNhap ma ban doc can xoa: ";
	getline(cin, sBanDocCanXoa);
	if (sBanDocCanXoa == "N" || sBanDocCanXoa == "n")
	{
		Color(10);
		cout << "\t\tBan da chon thoat! \n";
		Color(7);
	}
	else
	{
		int flag = 0;
		list <BanDoc>::iterator p = LBanDoc.begin();
		while (p != LBanDoc.end())
		{
			if (sBanDocCanXoa == p->getMaBanDoc())
			{
				flag = 0;
				Color(10);
				cout << "\n\t\t\t\t  Xoa sach thanh cong!\n";
				Color(7);
				LBanDoc.erase(p);
				break;
			}
			else
			{
				LBanDoc.push_back(*(p));
				ofstream fout;
				fout.open("BanDoc.txt", ios::app);
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			Color(4);
			cout << "\n\t\tMa so sach khong ton tai, hoac sach dang duoc muon!\n\n";
			Color(7);
			goto nhapLaiMaSach;
		}
	}

}
//DS Sach
int nDemSachDaMuon(list <Sach> LSach)
{
	int nDem = 0;
	list <Sach>::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		if (p->getTinhTrang() != 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
int nDemSachChuaMuon(list <Sach> LSach)
{
	int nDem = 0;
	list <Sach>::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		if (p->getTinhTrang() == 0)
		{
			nDem++;
		}
		p++;
	}
	return nDem;
}
void timKiem(list <Sach> LSach)
{
	int flag = 0;
	Color(4);
	cout << "\t\t\t   Nhap 0 de thoat!\n\n";
	Color(7);
	string sTimKiem = "";
nhapLaiMasachcanTim:
	Color(9);
	cout << "\t\tNhap ma sach can tim: ";
	rewind(stdin);
	getline(cin, sTimKiem);
	if (sTimKiem == "0")
	{
		Color(10);
		cout << "\t\tBan da chon thoat! \n";
		Color(7);
	}
	else
	{
		list <Sach>::iterator p = LSach.begin();
		while (p != LSach.end())
		{
			if (sTimKiem == p->getMS())
			{
				flag = 0;
				Color(13);
				cout << "\n\t\t--------------THONG TIN SACH---------------\n\n";
				Color(10);
				p->outputSach();
				Color(13);
				cout << "\t\t___________________________________________\n";
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			Color(4);
			cout << "\t\tMa sach khong ton tai. Vui long nhap lai !\n";
			Color(7);
			goto nhapLaiMasachcanTim;
		}
	}

}
void xoaSach(list <Sach> &LSach)
{
	Color(4);
	cout << "\t\t\t\t   Nhap N de thoat! \n";
	string sSachCanXoa = "";
nhapLaiMaSach:
	Color(13);
	rewind(stdin);
	cout << "\t\tNhap ma so sach can xoa: ";
	getline(cin, sSachCanXoa);
	if (sSachCanXoa == "N"|| sSachCanXoa == "n")
	{
		Color(10);
		cout << "\t\tBan da chon thoat! \n";
		Color(7);
	}
	else
	{
		int flag = 0;
		list <Sach>::iterator p = LSach.begin();
		while (p != LSach.end())
		{
			if (sSachCanXoa == p->getMS() && p->getTinhTrang() == 0)
			{
				flag = 0;
				Color(10);
				cout << "\n\t\t\t\t  Xoa sach thanh cong!\n";
				Color(7);
				LSach.erase(p);
				ghiDsSach(LSach);
				break;
			}
			else
			{
				flag = 1;
			}
			p++;
		}
		if (flag == 1)
		{
			Color(4);
			cout << "\n\t\tMa so sach khong ton tai, hoac sach dang duoc muon!\n\n";
			Color(7);
			goto nhapLaiMaSach;
		}
	}

}
void themSach(list <Sach> &LSach)
{
	string sMS = "", sTuaDe = "", sTacGia = "", sNXB = "";
	float fTriGia = NULL;
	int nNamPhatHanh = 0, nSoTrang = 0, nNgay = 0, nThang = 0, nNam = 0, nTinhTrang = 0;
nhapLaiMaSach:
	Color(13);
	cout << "\t\tNhap ma so sach: "; rewind(stdin); getline(cin, sMS);
	list <Sach>::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		if (sMS == p->getMS() || sMS == "")
		{
			Color(4);
			cout << "\t\t\tMa so sach da ton tai. Vui long nhap lai!!!\n";
			Color(7);
			goto nhapLaiMaSach;
		}
		else if(sMS == "ESC" || sMS == "esc")
		{
			return;
		}
		p++;
	}
nhapLaiTuaDe:
	cout << "\t\tNhap tua de sach: ";
	rewind(stdin);
	getline(cin, sTuaDe);
	if (sTuaDe == "")
	{
		thongBao();
		goto nhapLaiTuaDe;
	}
	else if (sTuaDe == "ESC" || sTuaDe == "esc")
	{
		return;
	}
nhapLaiTenTacGia:
	cout << "\t\tNhap ten tac gia: ";
	rewind(stdin);
	getline(cin, sTacGia);
	if (sTacGia == "")
	{
		thongBao();
		goto nhapLaiTenTacGia;
	}
	else if (sTacGia == "ESC" || sTacGia == "esc")
	{
		return;
	}
nhapLaiNhaXuatBan:
	cout << "\t\tNhap nha xuat ban: ";
	rewind(stdin);
	getline(cin, sNXB);
	if (sNXB == "")
	{
		thongBao();
		goto nhapLaiNhaXuatBan;
	}
	else if (sNXB == "ESC" || sNXB == "esc")
	{
		return;
	}
	cout << "\t\tNhap gia cuon sach: ";
	cin >> fTriGia;
	cout << "\t\tNhap nam phat hanh: ";
	cin >> nNamPhatHanh;
	cout << "\t\tNhap so trang: ";
	cin >> nSoTrang;
	cout << "\t\tNgay nhap kho gom:  ";
	cout << "\n\t\tNhap ngay: ";
	cin >> nNgay;
	cout << "\t\tNhap thang: ";
	cin >> nThang;
	cout << "\t\tNhap nam: ";
	cin >> nNam;
	nTinhTrang = 0;
	Sach s(sMS, sTuaDe, sTacGia, sNXB, fTriGia, nNamPhatHanh, nSoTrang, nNgay, nThang, nNam, nTinhTrang);
	LSach.push_back(s);
	Color(10);
	cout << "\t\t\t\t  Them sach thanh cong !\n";
	Color(7);
}
void ghiDsSach(list <Sach> LSach)
{
	ofstream fout;
	fout.open("Sach.txt");
	int nDem = 1;
	int nTongSoSach = demSachHienCo(LSach);
	list <Sach>::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		fout << p->getMS() << "," << p->getTD() << "," << p->getTG() << "," << p->getNXB() << "," << p->getGia() << "," << p->getNPH() << "," << p->getST() << "," << p->getNgayNK() << "," << p->getThangNK() << "," << p->getNamNK() << "," << p->getTinhTrang();
		if (nDem < nTongSoSach)
		{
			fout << endl;
			nDem++;
		}
		p++;
	}
	fout.close();
}
void xuatDsSach(list <Sach> LSach)
{
	list <Sach>::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		Color(4);
		cout << "\n\t\t<========================================>\n\n";
		Color(10);
		p->outputSach();
		p++;
		Sleep(300);
		
	}
}
void docDsSach(list <Sach> &LSach)
{
	string sMS = "";
	string sTuaDe = "";
	string sTacGia = "";
	string sNXB = "";
	float fTriGia = 0.0;
	int nNamPhatHanh = 0;
	int nSoTrang = 0;
	int nNgay = 0;
	int nThang = 0;
	int nNam = 0;
	int nTinhTrang = 0;
	ifstream fin;
	fin.open("Sach.txt");
	while (!fin.eof())
	{
		getline(fin, sMS, ',');
		getline(fin, sTuaDe, ',');
		getline(fin, sTacGia, ',');
		getline(fin, sNXB, ',');
		fin >> fTriGia;
		fin.ignore(1, ',');
		fin >> nNamPhatHanh;
		fin.ignore(1, ',');
		fin >> nSoTrang;
		fin.ignore(1, ',');
		fin >> nNgay;
		fin.ignore(1, ',');
		fin >> nThang;
		fin.ignore(1, ',');
		fin >> nNam;
		fin.ignore(1, ',');
		fin >> nTinhTrang;
		fin.ignore(1, '\n');
		Sach s(sMS, sTuaDe, sTacGia, sNXB, fTriGia, nNamPhatHanh, nSoTrang, nNgay, nThang, nNam, nTinhTrang);
		LSach.push_back(s);
	}
	fin.close();
}
int demSachHienCo(list <Sach> LSach)
{
	int nDem = 0;
	list <Sach>::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		nDem++;
		p++;
	}
	return nDem;
}
bool kiemTraSachMuon(list <Sach> LSach, string sMS)
{
	list <Sach> ::iterator p = LSach.begin();
	while (p != LSach.end())
	{
		if (sMS == p->getMS() && p->getTinhTrang() == 0)
		{
			return true;
		}
		p++;
	}
	return false;
}
//Admin
string maHoaPassword(unsigned maxLength)
{
	string sPassWord = "";
	for (char c; (c = getch()); )
	{
		if (c == '\n' || c == '\r') {
			cout << "\n";
			break;
		}
		else if (c == '\b') { //phím backspace
			cout << "\b \b";
			if (!sPassWord.empty()) sPassWord.erase(sPassWord.size() - 1);
		}
		else if (c == -32) { //phím mũi tên
			_getch(); //bỏ qua kí tự tiếp theo (hướng mũi tên)
		}
		else if (isprint(c) && sPassWord.size() < maxLength) { //isprint tức là chỉ nhận những ký tự in ra được (có tính khoảng trắng)
			cout << '*';
			sPassWord += c;
		}
	}
	return sPassWord;
}
void dangNhap(list <Admin> L, list <Sach> LSach, list <BanDoc*> LBanDoc, list <PhieuMuon> LPhieuMuon)
{
	int nChucNangMenu = 0;
	string sUser = "";
	string sPassWord = "";
	int flag = 0;
	while (true)
	{
		menu_DangNhap();
		Color(11);
		cout << "\n\t\tNhap Username: ";
		Color(15);
		rewind(stdin);
		getline(cin, sUser);
		if (sUser == "ESC" || sUser == "esc")
		{
			flag = 1;
			break;
		}
		Color(11);
		cout << "\n\t\tNhap Password: ";
		Color(15);
		rewind(stdin);
		sPassWord = maHoaPassword(6);
		list <Admin>::iterator p = L.begin();
		while (p != L.end())
		{
			if (sUser == p->getUserName() && sPassWord == p->getPassWord())
			{
				flag = 1;
				cout << "Dang Nhap thanh cong !\n";
				while (true)
				{
					menu_Admin();
					cin >> nChucNangMenu;
					if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 4&& nChucNangMenu != 0)
					{
						thongBaoNhapSai();
						system("pause");
					}
					else if (nChucNangMenu == 1)
					{
						cout << "\t\t*Quan ly phieu muon*\n";
						while (true)
						{
							menu_QLPhieuMuon();
							cin >> nChucNangMenu;
							if (nChucNangMenu == 1)
							{
								themPhieuMuon(LPhieuMuon, LBanDoc, LSach);
								system("pause");
							}
							else if (nChucNangMenu == 2)
							{
								traSach(LPhieuMuon, LBanDoc, LSach);
								system("pause");
							}
							else if (nChucNangMenu == 3)
							{
								Color(14);
								xuatDsPhieuMuon(LPhieuMuon);
								system("pause");
							}
							else if (nChucNangMenu == 4)
							{
								break;
							}
							else
							{
								thongBaoNhapSai();
								system("pause");
							}
						}
					}
					else if (nChucNangMenu == 2)
					{
						cout << "2. Quan ly sach.\n";
						while (true)
						{
							menu_QuanLySach();
							cin >> nChucNangMenu;
							if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3)
							{
								thongBaoNhapSai();
								system("pause");
							}
							else if (nChucNangMenu == 1)
							{
								themSach(LSach);
								ghiDsSach(LSach);
								system("pause");
							}
							else if (nChucNangMenu == 2)
							{
								xoaSach(LSach);
								system("pause");
							}
							else if (nChucNangMenu == 3)
							{
								break;
							}
						}

						system("pause");
					}
					else if (nChucNangMenu == 3)
					{
						cout << "\t\t  *Quan ly ban doc*\n";
						while (true)
						{
							menu_QuanLyBanDoc();
							cin >> nChucNangMenu;
							if (nChucNangMenu == 1)
							{
								themBanDoc(LBanDoc);
							}
							else if (nChucNangMenu == 2)
							{
								break;
							}
							else
							{
								thongBaoNhapSai();
								system("pause");
							}
						}
						system("pause");
					}
					else if (nChucNangMenu == 4)
					{
						while (true)
						{
							menu_thongKe();
							cin >> nChucNangMenu;
							if (nChucNangMenu != 1 && nChucNangMenu != 2 && nChucNangMenu != 3 && nChucNangMenu != 0 && nChucNangMenu != 4 && nChucNangMenu != 5 && nChucNangMenu != 6)
							{
								thongBaoNhapSai();
								system("pause");
							}
							else if (nChucNangMenu == 1)
							{
								Color(10);
								cout << "\n\tTong so sach con lai trong thu vien chua duoc muon la: " << nDemSachChuaMuon(LSach) << endl;
								Color(7);
								system("pause");
							}
							else if (nChucNangMenu == 2)
							{
								Color(10);
								cout << "\n\tTong so sach da duoc muon la: " << nDemSachDaMuon(LSach) << endl;
								Color(7);
								system("pause");
							}
							else if (nChucNangMenu == 3)
							{
								lietKeSachBanDocMuon(LPhieuMuon, LSach);
								system("pause");
							}
							else if (nChucNangMenu == 4)
							{
								Color(10);
								cout << "\n\tTong so ban doc la giao vien: " << soLuongBanDocGiaoVien(LBanDoc) << endl;
								Color(7);
								system("pause");
							}
							else if (nChucNangMenu == 5)
							{
								Color(10);
								cout << "\n\tTong so ban doc la sinh vien: " << soLuongBanDocSinhVien(LBanDoc) << endl;
								Color(7);
								system("pause");
							}
							else if (nChucNangMenu == 6)
							{
								break;
							}
						}
					}
					else if (nChucNangMenu == 0)
					{
						break;
					}
				}
				system("pause");
			}
			p++;
		}
		if (flag == 0)
		{
			thongBaoNhapSai();
			system("pause");
		}
	}

}
void doc_Admin(list <Admin> &L)
{
	Admin xAdmin;
	string sUser = "";
	string sPassWord = "";
	ifstream fin;
	fin.open("Admin.txt", ios::in);
	while (!fin.eof())
	{
		getline(fin, sUser, ',');
		xAdmin.setUser(sUser);
		getline(fin, sPassWord);
		xAdmin.setPass(sPassWord);
		L.push_back(xAdmin);
		fin.ignore(0, '\n');
	}
	fin.close();
}
void Color(int nX)
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hc,nX);
}