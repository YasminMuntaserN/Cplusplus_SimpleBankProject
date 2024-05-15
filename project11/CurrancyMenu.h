#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesList.h"
#include "clsFindCurrency.h"
#include "clsUpdateCurrency.h"
#include "clsCurrancyCalculater.h"

class CurrancyMenu : protected clsScreen 
{
private :
	enum enCurrancyMenuOption {
		eListCurrancy = 1, eFindCurrancy = 2, eUpdateCurrancy = 3,
		eCurrancyCalculater = 4, eMainMenu = 5
	};
	static short _ReadCurrancyMenueOption() {
		cout << setw(37) << left << " " << "choossse what do you want to do ? [1 ,5 ]?";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;
	}
	static void ShowListCurrencis() {
		cout << "\nCurreinses code will be here !";
	}

	static void ShowCurrencisList() {
		clsCurrenciesList::ShowCurancyList();
	}

	static void FindCurrencyScreen() {
		clsFindCurrency::FindCurrency();
	}

	static void UpdateRateCurrencyScreen() {
		clsUpdateCurrency::ShowUpdateCurrencyScreen();
	}
	static void CurrencyCalculaterScreen() {
		clsCurrancyCalculater::ShowCurrancyCalculater();
	}


	static void PerformCurrancyExtchangeScreen(enCurrancyMenuOption choice) {
		switch (choice)
		{
		case enCurrancyMenuOption::eListCurrancy:
			system("cls");
			ShowCurrencisList();
			break;

		case enCurrancyMenuOption::eFindCurrancy:
			system("cls");
			FindCurrencyScreen();
			break;

		case enCurrancyMenuOption::eUpdateCurrancy:
			system("cls");
			UpdateRateCurrencyScreen();
			break;

		case enCurrancyMenuOption::eCurrancyCalculater:
			CurrencyCalculaterScreen();
			break;

		case enCurrancyMenuOption::eMainMenu:
			ShowListCurrencis();
			break;
		}
	}
public:
	static void ShowCurrancyExtchangeScreen() {
		_DrawScreenHeader("\tCurrancy Extchange Main Screen ");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\Currancy Extchange  Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencis.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currancy.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currancy.\n";
		cout << setw(37) << left << "" << "\t[4] Currancy Calculater.\n";
		cout << setw(37) << left << "" << "\t[5] Main menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		PerformCurrancyExtchangeScreen((enCurrancyMenuOption)(_ReadCurrancyMenueOption()));
	}
};

