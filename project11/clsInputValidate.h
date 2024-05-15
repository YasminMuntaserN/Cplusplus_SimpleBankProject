#pragma once
#include "clsDate.h"
class clsInputValidate
{
public :
	static bool IsNumberBetween(int Number, int From, int To){
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(double Number, double From, double To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(float Number, float From, float To) {
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		if ((clsDate::CompareDates(Date, From) == clsDate::After) &&
			(clsDate::CompareDates(Date, To) == clsDate::Before))
			return true;
		return false;
	}
	static int ReadIntNumber(string Message = "Invalid Number, Enter again\n") {
		int input;
		while (!(cin >> input)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << Message;
		}
		return input;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static int ReadDoubleNumber(string Message = "Invalid Number, Enter again\n") {
		double input;
		while (!(cin >> input)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}
		return input;
	}
	static int ReadFloatNumber(string Message = "Invalid Number, Enter again\n") {
		float input;
		while (!(cin >> input)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << Message;
		}
		return input;
	}
	static int ReadDoubleNumberBetween(int from, int to, string Message) {
		double input= ReadDoubleNumber();
		while (!(to > input && from < input)) {
			cin.clear();
			cout << Message ;
			input = ReadDoubleNumber();
		}
		return input;
	}
	static bool IsValideDate(clsDate date) {
		return clsDate::IsValidDate(date);
	}
	static string ReadString() {
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}
	template <typename T>T myMax(T Number1, T Number2) {
		return (Number1 > Number2) ? Number1 : Number2;
	}
};
