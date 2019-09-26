#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Transaction.h"

using namespace std;

 
Transaction::Transaction(double amount, string userMonth, string day, string year, string vendor, string category, string description) {
    this->amount = amount;
    this->date = userMonth + " " + day + " " + year;
    this->category = category;
    this->vendor = vendor;
    this->description = description;
}
string Transaction::ToString() const {
    stringstream ss;
    ss << date << "\t" << vendor << "\t\t" << fixed << setprecision(2) << amount << "\t" << category << "\t\t" << description;
    return ss.str();
}
string Transaction::ToSave() const {
    stringstream ss;
    stringstream parse(this->date);
    string month,day,year;
    parse >> month >> day >> year;
    ss << month << "\n";
    ss << day << "\n";
    ss << year << "\n";
    ss << this->vendor << "\n";
    ss << this->amount << "\n";
    ss << this->category << "\n";
    if (this->description == " ") {
        ss << "n" << "\n";
    }
    else {
        ss << this->description << "\n";
    }
    return ss.str();
}
