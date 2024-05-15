#pragma once
#include <iostream>
#include <string>
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected :
	static void _DrawScreenHeader(string Title, string SubTitle="") {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << " \t\t\t\t\t User : " << CurrentUser.UserName;
        cout << "\n \t\t\t\t\t Date : " << clsDate::DateToString(clsDate()) <<endl <<endl;
	}
    static bool CheakAccessRight(clsUser::enPermissions permisions) {
        if (!CurrentUser.cheakAccessPermisions(permisions)) {
            cout << "\t\t\t\t\t -------------------------------------";
            cout << "\n\n\t\t\t\t\t Access Denied ! contact your Admain !";
            cout << "\n\t\t\t\t\t -------------------------------------";
            return false;
        }
        return true;
    }
};

