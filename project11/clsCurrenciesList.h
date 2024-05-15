#pragma once
#include "clsScreen.h"
#include "clsCurrancyExtchange.h"
class clsCurrenciesList : protected clsScreen
{
private:
	static void printCurancyRecordLine(clsCurrancyExtchange Currancy) {
		cout << "| " << setw(30) << left << Currancy.getCountry();
		cout << "| " << setw(8) << left << Currancy.getCode();
		cout << "| " << setw(45) << left << Currancy.getName();
		cout << "| " << setw(10) << left << Currancy.getRate();
	}
public:
	static void ShowCurancyList() {
		if (!CheakAccessRight(clsUser::enPermissions::pListClients)) {
			return;
		}
		vector <clsCurrancyExtchange>vCurrancy = clsCurrancyExtchange::GetCurrenciesList();

		string Title = "\t Currancies List Screen ";
		string subTitle = "\t    (" + to_string(vCurrancy.size()) + " ) Curancy(s).";

		_DrawScreenHeader(Title, subTitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate (1$)";
		cout << setw(8) << left << "" << "\n\t" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vCurrancy.size() == 0) {
			cout << "\t\t\t\tNo Currencies Available In the System!";
		}
		else {
			for (clsCurrancyExtchange curancy : vCurrancy) {
				printCurancyRecordLine(curancy);
				cout << endl;
			}
		}
	}
};

