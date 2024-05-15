#pragma once
#include <iostream>
using namespace std;
class clsPerson
{
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
    clsPerson(string FirstName, string LastName, string Email, string Phone)
    {

        _FirstName = FirstName;
        _LastName = LastName;
        _Email = Email;
        _Phone = Phone;
    }
    void SetFirstName(string FirstName) {
        _FirstName = FirstName;
    }
    string getFirstName() {
        return _FirstName;
    }
    __declspec(property(get = getFirstName, put = SetFirstName)) string FirstName;

    void SetLastName(string lastName) {
        _LastName = lastName;
    }
    string getLastName() {
        return _LastName;
    }

    __declspec(property(get = getLastName, put = SetLastName)) string LastName;

    void SetEmail(string Email) {
        _Email = Email;
    }
    string getEmail() {
        return _Email;
    }

    __declspec(property(get = getEmail, put = SetEmail)) string Email;
    
    void SetPhone(string phone) {
        _Phone = phone;
    }
    string getPhone() {
        return _Phone;
    }

    __declspec(property(get = getPhone, put = SetPhone)) string Phone;

    string FullName() {
        return FirstName + LastName;
    }

};

