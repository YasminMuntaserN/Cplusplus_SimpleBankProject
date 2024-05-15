#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"


class clsUpdateClientScreen :protected clsScreen
{
private:
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
public :
	static void ShowUpdateClientScreen() {
		if (!CheakAccessRight(clsUser::enPermissions::pUpdateeClients)) {
			return;
		}
		_DrawScreenHeader("\t Update Client Screen");
		cout << "Please Enter Client Account Number : ";
		string AccountNum = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNum)) {
			cout << "\nAccount Number is Not Found , choose another one : ";
			AccountNum = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNum);
		_PrintClient(Client1);
		cout << "Are You sure you want to update this client y/n ? ";
		char Answer;
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			cout << "\n\nUpdeat client Info :";
			cout << "\n___________________\n";

			_ReadClientInfo(Client1);
			clsBankClient::enSaveResults SaveResult;
			SaveResult = Client1.Save();
			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\n Account Updated Successfully :)\n";
				_PrintClient(Client1);
				break;
			case clsBankClient::enSaveResults::svFaildEmptyObject:
				cout << "\nError account was not saved because its Empty";
				break;
			}
		}
	}
	
};

