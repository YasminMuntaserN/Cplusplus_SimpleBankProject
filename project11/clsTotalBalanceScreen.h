#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
class clsTotalBalanceScreen :protected clsScreen
{
private:
	static void printClientRecordBalanceLine(clsBankClient& Client) {
		cout << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}
public :
	static void ShowTotalBalances() {
		vector <clsBankClient>vClients = clsBankClient::GetClientsList();
		cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		double TotalBalances = clsBankClient::GetTotalBalances();
		if (vClients.size() == 0) {
			cout << "\t\t\t\t No clients Available in the system !";
		}
		else {
			for (clsBankClient& client : vClients) {
				printClientRecordBalanceLine(client);
				cout << endl;
			}
		}
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\t\t   Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
	}
};

