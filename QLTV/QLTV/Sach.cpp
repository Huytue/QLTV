#include "Sach.h"

string Sach::getMS()
{
	return this->sMaSach;
}
string Sach::getTD()
{
	return this->sTuaDe;
}
string Sach::getTG()
{
	return this->sTacGia;
}
string Sach::getNXB()
{
	return this->sNXB;
}
float Sach::getGia()
{
	return this->fTriGia;
}
int Sach::getNPH()
{
	return this->nNamPhatHanh;
}
int Sach::getST()
{
	return this->nSoTrang;
}
int Sach::getNgayNK()
{
	return this->xNgayNhapKho.getNgay();
}
int Sach::getThangNK()
{
	return this->xNgayNhapKho.getThang();
}
int Sach::getNamNK()
{
	return this->xNgayNhapKho.getNam();
}
int Sach::getTinhTrang()
{
	return this->nTinhTrang;
}
void Sach::setTinhTrang(int a)
{
	this->nTinhTrang = a;
}
void Sach::outputSach()
{
	
	cout << "\t\tMa sach       : " << this->sMaSach << endl;
	cout << "\t\tTieu de       : " << this->sTuaDe << endl;
	cout << "\t\tTac gia       : " << this->sTacGia << endl;
	cout << "\t\tNha Xuat Ban  : " << this->sNXB << endl;
	cout << "\t\tTri gia       : " << this->fTriGia << " VND" << endl;
	cout << "\t\tNam phat hanh : " << this->nNamPhatHanh << endl;
	cout << "\t\tNgay nhap kho : ";
	this->xNgayNhapKho.xuat();
	cout << endl;
}