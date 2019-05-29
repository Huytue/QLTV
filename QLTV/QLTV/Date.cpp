#include "Date.h"
void Date::setNgay(int nNgay)
{
	this->nNgay = nNgay;
}
void Date::setThang(int nThang)
{
	this->nThang = nThang;
}
void Date::setNam(int nNam)
{
	this->nNam = nNam;
}
int Date::getNgay()
{
	return this->nNgay;
}
int Date::getThang()
{
	return this->nThang;
}
int Date::getNam()
{
	return this->nNam;
}
void Date::xuat()
{
	cout << this->nNgay << "/" << this->nThang << "/" << this->nNam;
}
void Date::set_NgayThangNam(int nNgay, int nThang, int nNam)
{
	this->nNgay = nNgay;
	this->nThang = nThang;
	this->nNam = nNam;
}