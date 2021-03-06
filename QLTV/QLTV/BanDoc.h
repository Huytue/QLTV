#ifndef Bandoc_h
#define Bandoc_h
#pragma once
#include "Date.h"
class Date;
class PhieuMuon;
class BanDoc
{
protected:
	string sMaBD;
	string sHoTen;
	string sKhoa;
	Date xNgay;
public:
	friend Date;
	friend PhieuMuon;
	BanDoc()
	{
		this->sMaBD = "";
		this->sHoTen = "";
		this->sKhoa = "";
	}
	BanDoc(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0):xNgay(nNgay, nThang, nNam)
	{
		this->sMaBD = sMaBD;
		this->sHoTen = sHoTen;
		this->sKhoa = sKhoa;
	}

	string getMaBanDoc();

	void xuat();
	virtual void output() {};
	~BanDoc(){};
};

#endif // !Bandoc_h
