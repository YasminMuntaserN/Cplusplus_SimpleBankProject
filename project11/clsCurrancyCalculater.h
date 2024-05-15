#pragma once
#include "clsScreen.h"
#include "clsCurrancyExtchange.h"
#include "clsInputValidate.h"
class clsCurrancyCalculater :protected clsScreen
{
private :
    static float _ReadAmount()
    {
        cout << "\nEnter Amount to Extchange: ";
        float NewRate = 0;

        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }
    static void _PrintCurrency(clsCurrancyExtchange Currency)
    {
        cout << "\n_____________________________\n";
        cout << "\nCountry    : " << Currency.getCountry();
        cout << "\nCode       : " << Currency.getCode();
        cout << "\nName       : " << Currency.getName();
        cout << "\nRate(1$) = : " << Currency.getRate();
        cout << "\n_____________________________\n";
    }
    static float convertAmountToUSD(int Amount, clsCurrancyExtchange Currency1) {
       // float Currency1Rate = Currency1.getRate();
       // float USD_Rate = clsCurrancyExtchange::FindByCode("USD").getRate();
        return (float)(Amount / Currency1.getRate());
    }
    static float convertFromUSDToCurrency2Rate(float USD_Amont, clsCurrancyExtchange Currency2) {
        return USD_Amont * Currency2.getRate();
    }
public :
    static void ShowCurrancyCalculater() {
        char Choice = 'y';
        while (Choice == 'y' || Choice == 'Y') {
            system("cls");
            cout << "\n Please Enter Currancy1 code :";
            clsCurrancyExtchange  currancy1 = clsCurrancyExtchange::FindByCode(clsInputValidate::ReadString());
            cout << "\n Please Enter Currancy2 code :";
            clsCurrancyExtchange  currancy2 = clsCurrancyExtchange::FindByCode(clsInputValidate::ReadString());

            float Amount = _ReadAmount();
            float USD_Amont = convertAmountToUSD(Amount, currancy1);

            cout << "\nConvert from :";
            _PrintCurrency(currancy1);
            cout << endl << Amount << " " << currancy1.getCode() << " = " << USD_Amont << " USD ";

            cout << "\nConverting from USD TO :\n";
            _PrintCurrency(currancy2);
            cout << endl << Amount << " " << currancy1.getCode() << " = "
                << convertFromUSDToCurrency2Rate(USD_Amont, currancy2) << " " << currancy2.getCode();

            cout << "\nAre you sure you want to perform this calculation :";
            cin >> Choice;
        }

    }

};

