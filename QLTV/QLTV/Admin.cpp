#include "Admin.h"


string Admin::getUserName()
{
	return this->sUserName;
}
string Admin::getPassWord()
{
	return this->sPassWord;
}
void Admin::setUser(string sUsername)
{
	this->sUserName = sUsername;
}
void Admin::setPass(string sPassWord)
{
	this->sPassWord = sPassWord;
}
void Admin::setUserPassWord(string sUserName, string sPassWord)
{
	this->sUserName = sUserName;
	this->sPassWord = sPassWord;
}