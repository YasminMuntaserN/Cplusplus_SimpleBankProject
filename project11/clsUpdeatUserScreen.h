#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsUpdeatUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User) {
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();
	}

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateeClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pMangeUsers;
        }

        return Permissions;

    }

public:

    static void ShowUpdateUserScreen() {
        _DrawScreenHeader("\t Update User Screen");
        string UserName = "";

        cout << "\n Please Enter User UserName : ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName)) {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate User Info : ";
            cout << "\n-------------------------------\n";

            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult) {
            case clsUser::enSaveResults::svSucceeded:
                cout << "\n User Updated Succssfuly ";
                _PrintUser(User1);
                break;
            case clsUser::enSaveResults::svFaildEmptyObject:
                cout << "\nError User was not saved because it's Empty";
                break;
            }
        }
    }
        
};

