#include "PhieuMuon.h"

BanDoc PhieuMuon::getBanDoc()
{
	return this->xBanDoc.getMaBanDoc();
}
Sach PhieuMuon::getSach()
{
	return this->xSach.getMS();
}
Date PhieuMuon::getNgayMuon()
{
	return this->xNgayMuon;
}
Date PhieuMuon::getNgayTra()
{
	return this->xNgayTra;
}
int PhieuMuon::getMaPhieuMuon()
{
	return this->nMaPhieuMuon;
}
int PhieuMuon::getTrangThai()
{
	return this->nTrangThai;
}
int PhieuMuon::getTongPhieuMuon()
{
	return this->nTongPhieuMuon;
}
void PhieuMuon::setTrangThai(int a)
{
	this->nTrangThai = a;
}
void PhieuMuon::setSach(Sach s)
{
	this->xSach = s;
}
void PhieuMuon::setBanDoc(BanDoc xBD)
{
	this->xBanDoc = xBD;
}
int PhieuMuon::nNgayPlus(int nN)
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_mon = ta->tm_mon + 1;
	ta->tm_year = ta->tm_year + 1900;
	if (ta->tm_mon == 1 || ta->tm_mon == 3 || ta->tm_mon == 5 || ta->tm_mon == 7 || ta->tm_mon == 8 || ta->tm_mon == 10)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if(nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mday;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon += 1;
			return ta->tm_mday;
		}
	}
	else if (ta->tm_mon == 4 || ta->tm_mon == 6 || ta->tm_mon == 9 || ta->tm_mon == 11)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 30)
		{
			ta->tm_mday += nN;
			return ta->tm_mday;
		}
		else
		{
			ta->tm_mday = nTongNgay - 30;
			ta->tm_mon += 1;
			return ta->tm_mday;
		}
	}
	else if (ta->tm_mon == 12)
	{
		int nTongNgay = 0;
		int nTongThang = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mday;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon = 1;
			ta->tm_year += 1;
			return ta->tm_mday;
		}
	}
	if (ktrNamNhuan() == true )
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 29)
			{
				ta->tm_mday += nN;
				return ta->tm_mday;
			}
			else
			{
				ta->tm_mday = nTongNgay - 29;
				ta->tm_mon += 1;
				return ta->tm_mday;
			}
		}
	}
	else
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 28)
			{
				ta->tm_mday += nN;
				return ta->tm_mday;
			}
			else
			{
				ta->tm_mday = nTongNgay - 28;
				ta->tm_mon += 1;
				return ta->tm_mday;
			}
		}
	}
	return 0;
}
int PhieuMuon::nThangPlus(int nN)
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_mon = ta->tm_mon + 1;
	ta->tm_year = ta->tm_year + 1900;
	if (ta->tm_mon == 1 || ta->tm_mon == 3 || ta->tm_mon == 5 || ta->tm_mon == 7 || ta->tm_mon == 8 || ta->tm_mon == 10)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if(nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mon;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon += 1;
			return ta->tm_mon;
		}
	}
	else if (ta->tm_mon == 4 || ta->tm_mon == 6 || ta->tm_mon == 9 || ta->tm_mon == 11)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 30)
		{
			ta->tm_mday += nN;
			return ta->tm_mon;
		}
		else
		{
			ta->tm_mday = nTongNgay - 30;
			ta->tm_mon += 1;
			return ta->tm_mon;
		}
	}
	else if (ta->tm_mon == 12)
	{
		int nTongNgay = 0;
		int nTongThang = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay <= 31)
		{
			ta->tm_mday += nN;
			return ta->tm_mon;
		}
		else
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon = 1;
			ta->tm_year += 1;
			return ta->tm_mon;
		}
	}
	if (ktrNamNhuan() == true )
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 29)
			{
				ta->tm_mday += nN;
				return ta->tm_mon;
			}
			else
			{
				ta->tm_mday = nTongNgay - 29;
				ta->tm_mon += 1;
				return ta->tm_mon;
			}
		}
	}
	else
	{
		if (ta->tm_mon == 2)
		{
			int nTongNgay = 0;
			nTongNgay = ta->tm_mday + nN;
			if (nTongNgay <= 28)
			{
				ta->tm_mday += nN;
				return ta->tm_mon;
			}
			else
			{
				ta->tm_mday = nTongNgay - 28;
				ta->tm_mon += 1;
				return ta->tm_mon;
			}
		}
	}
	return 0;
}
int PhieuMuon::nNamPlus(int nN)
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_mon = ta->tm_mon + 1;
	ta->tm_year = ta->tm_year + 1900;
	if (ta->tm_mon == 12)
	{
		int nTongNgay = 0;
		nTongNgay = ta->tm_mday + nN;
		if (nTongNgay > 31)
		{
			ta->tm_mday = nTongNgay - 31;
			ta->tm_mon = 1;
			ta->tm_year += 1;
			return ta->tm_year;
		}
	}
	return ta->tm_year;
}
bool PhieuMuon::ktrNamNhuan()
{
	time_t t = time(0); 
	struct tm *ta = localtime(&t);
	ta->tm_year = ta->tm_year + 1900;
	if(ta->tm_year % 400 == 0 || ta->tm_year  % 4 == 0 && ta->tm_year % 100 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void PhieuMuon::xuat()
{
	cout << "\t\t------------------------------------------\n";
	cout << "\t\t<So phieu muon>    :" << this->nMaPhieuMuon << endl;
	cout << "\t\t<Ma sach>          :" << this->xSach.getMS() << endl;
	cout << "\t\t<Ma ban doc>       :" << this->xBanDoc.getMaBanDoc() << endl;
	cout << "\t\t<Ngay muon>        :"; this->xNgayMuon.xuat();
	cout << endl;
	cout << "\t\t<Ngay phai tra>    :"; this->xNgayTra.xuat();
	cout << endl;
	cout << "\t\t<Tinh trang>       :" << this->nTrangThai << endl;
}