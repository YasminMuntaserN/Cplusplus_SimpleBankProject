#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

using namespace std;
class clsClientListScreen : protected clsScreen
{
private :
	static void printClientRecordLine(clsBankClient Client) {
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.Phone;
		cout << "| " << setw(20) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
public :
	static void ShowClientList() {
		if (!CheakAccessRight(clsUser::enPermissions::pListClients)) {
			return ;
		}
		vector <clsBankClient>vClients = clsBankClient::GetClientsList();

		string Title = "\t client List Screen ";
		string subTitle = "\t    (" +to_string(vClients.size()) + " ) Client(s).";

		_DrawScreenHeader(Title , subTitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) <<left<< "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0) {
			cout << "\t\t\t\t No clients Available in the system !";
		}
		else {
			for (clsBankClient client : vClients) {
				printClientRecordLine(client);
				cout << endl;
			}
		}
	}
};

