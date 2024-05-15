#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


class clsDepositScreen : protected clsScreen
{
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
	static string _ReadAccountNymber(){
		string AccountNumber = "";
		cout << "\nPlease enter AccountNumber? ";
		cin >> AccountNumber;
		return AccountNumber;
	}
public :
	static void showDepositeScreen() {
		_DrawScreenHeader("\t Deposit Screen");
		string AccountNumber = _ReadAccountNymber();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\n Client with [" << AccountNumber << "] does not Found";
		}
		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(client1);
		double Amount = 0;
		cout << "\n Please Enter deposit amount ? ";
		Amount = clsInputValidate::ReadDoubleNumber();
		cout << "\nAre you sure you want to perform this Transaction ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << client1.AccountBalance;
		}
		else{
			cout << "\nOperation was cancelled.\n";
		}
	}

};

