// project11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "clsMainScreen.h"
#include "clsLoginScreen.h"
#include "clsCurrancyExtchange.h"

using namespace std;

//static void _PrintCurrency(clsCurrancyExtchange Currency)
//{
//    cout << "\nCurrency Card:\n";
//    cout << "_____________________________\n";
//    cout << "\nCountry    : " << Currency.getCountry();
//    cout << "\nCode       : " << Currency.getCode();
//    cout << "\nName       : " << Currency.getName();
//    cout << "\nRate(1$) = : " << Currency.getRate();
//
//    cout << "\n_____________________________\n";
//
//}
//
//int main()
//
//{
//    clsCurrancyExtchange Currency1 = Currency1.FindByCode("jod");
//
//    if (Currency1.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency1);
//    }
//
//    clsCurrancyExtchange Currency2 = Currency2.FindByCountry("Egypt");
//
//    if (Currency2.IsEmpty())
//    {
//        cout << "\nCurrency Is Not Found!\n";
//    }
//    else
//    {
//        _PrintCurrency(Currency2);
//    }
//
//    cout << "Currency1 after updating Rate:\n";
//    Currency1.UpdateRate(0.71);
//    _PrintCurrency(Currency1);
//    return 0;
//}
int main()
{
    clsLoginScreen::ShowLoginScreen();
    //while (true) {
    //    if (!clsLoginScreen::ShowLoginScreen()) {
    //        break;
    //    }
    //}
    system("pause>0");

    return 0;
}
