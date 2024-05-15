#pragma once
#include "clsScreen.h"
#include "clsCurrancyExtchange.h"
#include "clsInputValidate.h"
class clsFindCurrency : protected clsScreen
{
private :
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
public:
    static void FindCurrency() {
        _DrawScreenHeader("\t  Find Currency Screen");
        cout << "\nFind By : [1] Code or [2] Country ?";
        int choice = clsInputValidate::ReadIntNumber();
        if (choice == 1) {
            cout << "\n Please Enter currancy Code :";
            string code = clsInputValidate::ReadString();
            clsCurrancyExtchange  currancy = clsCurrancyExtchange::FindByCode(code);
            _PrintCurrency(currancy);

        }
        else if (choice == 2) {
            cout << "\n Please Enter countray Nmae :";
            string country = clsInputValidate::ReadString();
            clsCurrancyExtchange currancy = clsCurrancyExtchange::FindByCountry(country);
            _PrintCurrency(currancy);

        }
    }
};

