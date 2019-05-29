#include "BanDoc.h"

void BanDoc::xuat()
{
	cout << "\t\tMa doc gia: " << this->sMaBD << endl;
	cout << "\t\tNgay dang ky the: ";
	xNgay.xuat(); cout << endl;
	cout << "\t\tHo va Ten: " << this->sHoTen << endl;
	cout << "\t\tKhoa: " << this->sKhoa << endl;
}

string BanDoc::getMaBanDoc()
{
	return this->sMaBD;
}