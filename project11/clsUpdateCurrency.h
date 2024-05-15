#pragma once
#include "clsScreen.h"
#include "clsCurrancyExtchange.h"
#include "clsInputValidate.h"
class clsUpdateCurrency :protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrancyExtchange Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.getCountry();
        cout << "\nCode       : " << Currency.getCode();
        cout << "\nName       : " << Currency.getName();
        cout << "\nRate(1$) = : " << Currency.getRate();
        cout << "\n_____________________________\n";
    }
public :
    static void ShowUpdateCurrencyScreen() {
        _DrawScreenHeader("\t  Update Currency Screen");
        cout << "\n Please Enter Currency code : ";
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrancyExtchange::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrancyExtchange  currancy = clsCurrancyExtchange::FindByCode(CurrencyCode);
        _PrintCurrency(currancy);
        cout << "\n Are you sure you want to update rate of this currency ? y/n ?";
        char Answer;
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            cout << "\n  Update currency Rate :";
            cout << "\n ---------------------------";
            cout << "\n Enter New Rate :";

            float NewRate = clsInputValidate::ReadFloatNumber();
            currancy.UpdateRate(NewRate);

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(currancy);
        }
    }
};

