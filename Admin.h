#pragma once
#include <iostream>
#include <string>
using namespace std;
class Admin
{
private:
	string sID;
	string sPass;
public:
	string get_ID ();
	string get_Pass ();
	void set_ID (string sID);
	void set_Pass (string sPass);
	Admin(string sID = "", string sPass = "")
	{
		this->sID = sID;
		this->sPass = sPass;
	}
	~Admin(void){};
};

