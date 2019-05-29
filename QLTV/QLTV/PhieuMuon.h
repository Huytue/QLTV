#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include "BanDoc.h"
#include "Date.h"
#include "Sach.h"
class BanDoc;
class Date;
class Sach;
class PhieuMuon
{
	BanDoc xBanDoc;
	Sach xSach;
	Date xNgayMuon, xNgayTra;
	static int nTongPhieuMuon;
	int nMaPhieuMuon;
	int nTrangThai;
public:
	friend Date;
	friend BanDoc;
	friend Sach;
	PhieuMuon(int nMaPhieuMuon = 0, string sMaBD = "", string sMaSach = "", int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0, int nTrangThai = 0) : xBanDoc(sMaBD), xSach(sMaSach), xNgayMuon(a, b, c), xNgayTra(d, e, f)
	{
		this->nTongPhieuMuon++;
		this->nMaPhieuMuon = nTongPhieuMuon;
		this->nTrangThai = nTrangThai;
	}
	PhieuMuon(string sMaBD = "", string sMaSach = "") : xBanDoc(sMaBD), xSach(sMaSach)
	{
		time_t t = time(0);
		struct tm *Now = localtime(&t);
		xNgayMuon.setNgay(Now->tm_mday);
		xNgayMuon.setThang(Now->tm_mon + 1);
		xNgayMuon.setNam(Now->tm_year + 1900);
		xNgayTra.setNgay(nNgayPlus(7));
		xNgayTra.setThang(nThangPlus(7));
		xNgayTra.setNam(nNamPlus(7));
		this->nTongPhieuMuon++;
		this->nMaPhieuMuon = nTongPhieuMuon;
		this->nTrangThai = 1;
	}
	BanDoc getBanDoc();
	Sach getSach();
	Date getNgayMuon();
	Date getNgayTra();
	int getMaPhieuMuon();
	int getTrangThai();
	int getTongPhieuMuon();
	void setTrangThai(int a);
	void setSach(Sach s);
	void setBanDoc(BanDoc xBD);
	// Xu Ly Ngay:
	int nNgayPlus(int nN);
	int nThangPlus(int nN);
	int nNamPlus(int nN);
	bool ktrNamNhuan();
	void xuat();
	~PhieuMuon(void) {};
};