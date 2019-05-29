#pragma once
#include <iostream>
#include <string>
using namespace std;
class BanDoc;
class Sach;
class PhieuMuon;
class Date
{
protected:
	int nNgay;
	int nThang;
	int nNam;
public:
	
	friend BanDoc;
	friend Sach;
	friend PhieuMuon;
	Date()
	{
		this->nNgay = 0;
		this->nThang = 0;
		this->nNam = 0;
	}
	Date(int nNgay, int nThang, int nNam)
	{
		this->nNgay = nNgay;
		this->nThang = nThang;
		this->nNam = nNam;
	}
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int nNgay);
	void setThang(int nThang);
	void setNam(int nNam);
	void set_NgayThangNam(int nNgay, int nThang, int nNam);
	void xuat();
	~Date(){};
};