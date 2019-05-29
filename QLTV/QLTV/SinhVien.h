#pragma once
#include "BanDoc.h"
class SinhVien : public BanDoc
{
	int nKhoaHoc;
public:
	SinhVien(string sMaBD = "",string sHoTen = "", string sKhoa = "", int nNgay = 0, int nThang = 0, int nNam = 0, int nKhoaHoc = 0 ):BanDoc(sMaBD, sHoTen, sKhoa, nNgay, nThang, nNam)
	{
		this->nKhoaHoc = nKhoaHoc;
	}
	void output();
	~SinhVien(void) {};
};

