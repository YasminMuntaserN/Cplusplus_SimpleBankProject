#pragma once
#include <iostream>
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private :
	 static void  _ReadClientInfo(clsBankClient& Client) {
		 cout << "\nEnter FirstName : ";
		 Client.FirstName = clsInputValidate::ReadString();
		 cout << "\nEnter LasttName : ";
		 Client.LastName = clsInputValidate::ReadString();
		 cout << "\nEnter Email : ";
		 Client.Email = clsInputValidate::ReadString();
		 cout << "\nEnter Phone : ";
		 Client.Phone = clsInputValidate::ReadString();
		 cout << "\nEnter PinCode : ";
		 Client.PinCode = clsInputValidate::ReadString();
		 cout << "\nEnter AccountBalance : ";
		 Client.SetAccountBalance(clsInputValidate::ReadFloatNumber());
	 }
	 static void _PrintClient(clsBankClient Client)
	 {
		 cout << "\nClient Card:";
		 cout << "\n___________________";
		 cout << "\nFirstName   : " << Client.FirstName;
		 cout << "\nLastName    : " << Client.LastName;
		 cout << "\nFull Name   : " << Client.FullName();
		 cout << "\nEmail       : " << Client.Email;
		 cout << "\nPhone       : " << Client.Phone;
		 cout << "\nAcc. Number : " << Client.AccountNumber();
		 cout << "\nPassword    : " << Client.PinCode;
		 cout << "\nBalance     : " << Client.AccountBalance;
		 cout << "\n___________________\n";
	 }
public :
	static void showAddNewClientScreen() {
		_DrawScreenHeader("\t Add New client Screen");
		string AccountNumber = "";
		cout << "Please Enter Account Number :";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\n Account Number Is Already Used , choose Another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult) {
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\n Account Addeded Successfuly :) ";
			_PrintClient(NewClient);
			break;
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\n Error Account was not saved because ites Empty :) ";
			break;
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
	}
};

