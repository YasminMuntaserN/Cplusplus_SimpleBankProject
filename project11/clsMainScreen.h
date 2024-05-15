#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include <iomanip>
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "Global.h"
#include "clsLoginRegister.h"
#include "CurrancyMenu.h"


using namespace std;

class clsMainScreen : protected clsScreen
{
private :
    enum enMainMenueOptions {
        eListClient = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, LoginRegister = 8 ,eCurrencyExtchange=9 , eExit = 10
    };
     
     static short _ReadMainMenueOption() {
         cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 10]? ";
         short Choice = clsInputValidate::ReadIntNumberBetween(1, 10, "Enter Number between 1 to 10? ");
         return Choice;
     }
	static void _GoBackToMainMenue(){}

    static void _ShowAllClientsScreen(){
        clsClientListScreen::ShowClientList();
    }

    static void _ShowAddNewClientsScreen() {
        clsAddNewClientScreen::showAddNewClientScreen();
    }

    static void _ShowUpdateClientsScreen() {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowDeleteClientsScreen() {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowFindClientsScreen() {
        clsFindClientScreen::ShowFindClientScreen();
    }
    static void _ShowTransactionsMenue() {
        clsTransactionsScreen::ShowTransactionsMenue();
    }
    static void _ShowManageUsersMenue() {
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    static void _ShowLoginRegisterRecords() {
        clsLoginRegister::ShowLoginRegisterScreen();
    }
    static void _ShowCurrancyExtchangeScreen() {
        CurrancyMenu::ShowCurrancyExtchangeScreen();
    }
    static void _Logout() {
        CurrentUser = clsUser::Find("", "");
       // clsLoginScreen::ShowLoginScreen();
    }
    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption) {
        switch (MainMenueOption) {
        case enMainMenueOptions::eListClient:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            break;

        case enMainMenueOptions::LoginRegister:
            system("cls");
            _ShowLoginRegisterRecords();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eCurrencyExtchange:
            system("cls");
            _ShowCurrancyExtchangeScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }
    }
public:
	static void ShowMainMenue(){
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] CurrancyExtchange.\n";
        cout << setw(37) << left << "" << "\t[10]Logout.\n";

        cout << setw(37) << left << "" << "===========================================\n";
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());

	}
};

