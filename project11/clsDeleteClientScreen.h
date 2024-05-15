#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"


class clsDeleteClientScreen : protected clsScreen {
private :
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
	static void ShowDeleteClientScreen(){
		if (!CheakAccessRight(clsUser::enPermissions::pDeleteClient) ){
			return;
		}
		_DrawScreenHeader("\t Delete Client");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is not Found , choose Another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(client1);
		cout << "\n Are you sure you want to delete this client y/n ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (client1.Delete()) {
				cout << "\n client Deleted successfully :)";
				_PrintClient(client1);
			}
			else {
				cout << "\n Error client Was not Deleted";
			}
		}
	}
};

