#include "GiaoVien.h"

void GiaoVien::output()
{
	BanDoc::xuat();
	cout << "\t\tDia chi: " << this->sDiaChi << endl;
	cout << "\t\tSo Dien Thoai: " << this->sSDT << endl;
}