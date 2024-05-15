#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
class clsLoginRegister : protected clsScreen
{
private :
	string _DateAndTime;
	string _UserName;
	string _Password;
	string _Permissions;


	static clsLoginRegister _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vLoginRegisterData;
		vLoginRegisterData = clsString::Split(Line, Seperator);

		return clsLoginRegister(vLoginRegisterData[0], vLoginRegisterData[1], clsUtil::DecryptText(vLoginRegisterData[2]),
			vLoginRegisterData[3]);
	}

	static  vector <clsLoginRegister> _LoadClientsDataFromFile() {
		vector <clsLoginRegister> vClients;
		fstream MyFile;
		MyFile.open("Login.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsLoginRegister User = _ConvertLinetoUserObject(Line);
				vClients.push_back(User);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void printClientRecordLine(clsLoginRegister Record) {
		cout << "| " << setw(15) << left << Record._DateAndTime;
		cout << "| " << setw(20) << left << Record._UserName;
		cout << "| " << setw(12) << left << Record._Password;
		cout << "| " << setw(20) << left << Record._Permissions;
	}

public :
	clsLoginRegister(string DateAndTime, string UserName, string Password, string Permissions) {
		_DateAndTime = DateAndTime;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	static void ShowLoginRegisterScreen() {
		if (!CheakAccessRight(clsUser::enPermissions::pLoginRegister)) {
			return;
		}
		vector <clsLoginRegister>vUsers = _LoadClientsDataFromFile();

		string Title = "\t Login Regisster Screen ";
		string subTitle = "\t    (" + to_string(vUsers.size()) + " ) Record(s).";

		_DrawScreenHeader(Title, subTitle);

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "| " << left << setw(15) << "Date / Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vUsers.size() == 0) {
			cout << "\t\t\t\t No clients Available in the system !";
		}
		else {
			for (clsLoginRegister client : vUsers) {
				printClientRecordLine(client);
				cout << endl;
			}
		}
	}
	
};

