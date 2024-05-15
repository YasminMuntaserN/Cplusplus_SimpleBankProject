#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen : protected clsScreen
{
private:
	static bool _Login() {
		bool LofInFaild = true;
		string Username, password;
		int count = 3;
		while ((count > 0) && (LofInFaild == true)) {
            cout << "Enter UserName ?";
            cin >> Username;
            cout << "Enter password ?";
            cin >> password;
		CurrentUser = clsUser::Find(Username, password);
	    LofInFaild = CurrentUser.IsEmpty();
		count--;
			if (LofInFaild == true) {
				cout << "\n Invalid Username/password";
				cout << "\n You have " << count << " trials to login ." <<endl << endl;
			}
			else {
				clsMainScreen::ShowMainMenue();
				CurrentUser.RegisterLoginInFile();
			}
			if (count == 0) {
				cout << "\nYou are loceted after 3 trials Faild .";
				return false;
			}
            	}
		return true;

            }

public :
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t LoginScreen");
		return _Login();
	}
};

