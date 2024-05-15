#pragma once
#include"clsScreen.h"
#include <iomanip>
#include"clsInputValidate.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"


class clsTransactionsScreen : protected clsScreen
{
private :
	enum enTransactionsMenueOptions {
		eDepsoit = 1 , eWithdraw = 2 , eShowTotalBalance = 3
		 , eTransfer =4,eTransferLog =5,eShowMainMenue =6
	};
	static short _ReadTransactionsMenueOption() {
		cout << setw(37) << left << " " << "choossse what do you want to do ? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}
    static void _GoBackToTransactionsMenue(){}

    static void _ShowDepositScreen() {
        clsDepositScreen::showDepositeScreen();
    }
    static void _ShowWithdrawScreen() {
        clsWithdrawScreen::ShowWidthdrawScreen();
    }
    static void _ShowTotalBalancesScreen() {
        clsTotalBalanceScreen::ShowTotalBalances;
    }
    static void _ShowTransferScreen() {
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen() {
        clsTransferLogScreen::ShowTransferLogScreen();
    }
    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption) {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDepsoit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;
        }
        case enTransactionsMenueOptions::eTransferLog:
        {
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }
    }

public:
    static void ShowTransactionsMenue()
    {
        if (!CheakAccessRight(clsUser::enPermissions::pTranactions)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
    }
};

