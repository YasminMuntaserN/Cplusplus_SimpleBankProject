#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>

using namespace std;

class clsBankClient : public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode =1 , AddNewMode =2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDeleted = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#"){
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


	static  vector <clsBankClient> _LoadClientsDataFromFile(){
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return vClients;
	}

	static void _SaveCleintsDataToFile(vector <clsBankClient> vClients) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDeleted == false) {
					DataLine = _ConverClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& c : _vClients) {
			if (c.AccountNumber() == AccountNumber()) {
				c = *this;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open()){
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew() {
		_AddDataLineToFile(_ConverClientObjectToLine(*this));
	}
	 string _PrepareTransferLogin(string Seperator
		, clsBankClient DestinationClient, float Amount ,string UserName)
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += AccountNumber() + Seperator;
		LoginRecord += DestinationClient.AccountNumber() + Seperator;
		LoginRecord += to_string(Amount) + Seperator;
		LoginRecord += to_string(AccountBalance) + Seperator;
		LoginRecord += to_string(DestinationClient.AccountBalance) + Seperator;
		LoginRecord += UserName;

		return LoginRecord;
	}

	 void _TransferLogininFile( clsBankClient DestinationClient, float Amount , string UserName ) {
		string stDataLine = _PrepareTransferLogin("#///#",DestinationClient, Amount , UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;

			MyFile.close();
		}
	}
	 struct  stTransferLogRecord;
	 static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
	 {
		 stTransferLogRecord TrnsferLogRecord;

		 vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
		 TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
		 TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
		 TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
		 TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
		 TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
		 TrnsferLogRecord.DesBalanceAfter = stod(vTrnsferLogRecordLine[5]);
		 TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

		 return TrnsferLogRecord;

	 }

public:
	struct stTransferLogRecord {
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float DesBalanceAfter;
		string UserName;
	};
	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDeleted() {
		return _MarkedForDeleted;
	}
	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string GetPinCode() {
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance){
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance(){
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;
	/*
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAccount Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";

	}
	*/
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open()){
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode){
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient client1 = clsBankClient::Find(AccountNumber);
		return (!client1.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save() {
		switch (_Mode) {
		case enMode::EmptyMode:
			if(IsEmpty())
			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
			break;

		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountNumberExists;
			}else{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", "", "", 0);
	}

	bool Delete() {
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& c : _vClients) {
			if (c.AccountNumber() == _AccountNumber) {
				c._MarkedForDeleted = true;
				break;
			}
		}
		_SaveCleintsDataToFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList() {
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances() {
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		double TotalBalances = 0;
		for (clsBankClient Client : vClients) {
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount) {
		if (Amount > _AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();
		}
	}
	bool Transfer(float Amount, clsBankClient& DestinationClient , string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_TransferLogininFile( DestinationClient, Amount , UserName);
		return true;
	}
	static vector <stTransferLogRecord> GetTransferLogList() {
		vector < stTransferLogRecord> vTransferLogRecord;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stTransferLogRecord Client = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecord.push_back(Client);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}


};
