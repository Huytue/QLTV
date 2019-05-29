
#include <iostream>
#include <string>
using namespace std;
class Admin
{
private:
	string sUserName;
	string sPassWord;
public:
	Admin()
	{
		this->sUserName = "";
		this->sPassWord = "";
	}
	Admin(string sUserName, string sPassWord)
	{
		this->sUserName = sUserName;
		this->sPassWord = sPassWord;
	}
	string getUserName();
	string getPassWord();
	void setUser(string sUserName);
	void setPass(string sPassWord);
	void setUserPassWord(string sUserName, string sPassWord);
	~Admin(){};
};

