#pragma once
#include "clsScreen.h"
#include "clsString.h"
#include <iomanip>
class clsCurrancyExtchange : protected clsScreen
{
private:
    enum enMode {EmptyMode =0 ,UpdateMode = 1};
    enMode _Mode;
    string _Country;
    string _Code;
    string _Name;
    float _Rate;

    static clsCurrancyExtchange _ConvertLineToObject(string Line, string Seperator = "#//#") {
        vector<string> vCurrancyData;
        vCurrancyData = clsString::Split(Line, Seperator);

        return clsCurrancyExtchange(UpdateMode, vCurrancyData[0]
            , vCurrancyData[1], vCurrancyData[2], stod(vCurrancyData[3]));
    }

    static string _ConvertCurrancyObjecrToLine(clsCurrancyExtchange currency, string Seperator = "#//#") {
        string line = "";
        line += currency.getCountry() + Seperator;
        line += currency.getCode() + Seperator;
        line += currency.getName() + Seperator;
        line += to_string(currency.getRate()) + Seperator;
        return line;
    } 

    static vector< clsCurrancyExtchange> _LodDataFromFile() {
        vector< clsCurrancyExtchange> vCurrancyData;
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open()){
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrancyExtchange Currancy = _ConvertLineToObject(Line);
                vCurrancyData.push_back(Currancy);
            }
            MyFile.close();
        }
        return vCurrancyData;
    }

    static void _SaveCurrencyDateToFile(vector <clsCurrancyExtchange> vCurrency) {
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::out);//overwrite
        string DataLine;
        if (MyFile.is_open())
        {
            for (clsCurrancyExtchange U : vCurrency)
            {
               DataLine = _ConvertCurrancyObjecrToLine(U);
               MyFile << DataLine << endl;
                }
            }
            MyFile.close();
        }

    void _Update() {
        vector <clsCurrancyExtchange> vCurrency = _LodDataFromFile();
        for (clsCurrancyExtchange& c : vCurrency) {
            if (c.getCode() == getCode()) {
                c = *this;
                break;
            }
        }
        _SaveCurrencyDateToFile(vCurrency);
    }

public :
    clsCurrancyExtchange(enMode Mode, string Country, string Code, string Name, float Rate) {
        _Mode = Mode;
        _Country = Country;
        _Code = Code;
        _Name = Name;
        _Rate = Rate;
    }

    bool IsEmpty() {
        return (_Mode == enMode::EmptyMode);
    }

    string getCountry() {
        return _Country;
    }

    string getCode() {
        return _Code;
    }

    string getName() {
        return _Name;
    }

    void UpdateRate(float NewRate) {
        _Rate = NewRate;
        _Update();
    }

    float getRate() {
        return _Rate;
    }

    __declspec(property(get = getRate, put = SetRate)) float Rate;

    static clsCurrancyExtchange FindByCode(string CurrencyCode) {
        CurrencyCode = clsString::UpperAllString(CurrencyCode);

        vector <clsCurrancyExtchange> vCurrency = _LodDataFromFile();
        for (clsCurrancyExtchange& c : vCurrency) {
            if (c.getCode() == CurrencyCode) {
                return c;
                break;
            }
        }
    }

    static clsCurrancyExtchange FindByCountry(string country) {
        country = clsString::UpperAllString(country);
        fstream MyFile;
        MyFile.open("Currencies.txt", ios::in);//read Mode

        if (MyFile.is_open()) {
            string Line;
            while (getline(MyFile, Line))
            {
                clsCurrancyExtchange Currancy = _ConvertLineToObject(Line);
                if (clsString::UpperAllString(Currancy.getCountry()) == country) {
                    MyFile.close();
                    return Currancy;
                }
            }
        }
    }

    static bool IsCurrencyExist(string CurrencyCode) {
        clsCurrancyExtchange c = clsCurrancyExtchange::FindByCode(CurrencyCode);
        return (!c.IsEmpty());
    }

    static vector <clsCurrancyExtchange> GetCurrenciesList()
    {
        return _LodDataFromFile();
    }


};

