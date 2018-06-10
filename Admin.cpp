#include "Admin.h"


string Admin::get_ID ()
{
	return this->sID;
}
string Admin::get_Pass ()
{
	return this->sPass;
}
void Admin::set_ID (string sID)
{
	this->sID = sID;
}
void Admin::set_Pass (string sPass)
{
	this->sPass = sPass;
}

