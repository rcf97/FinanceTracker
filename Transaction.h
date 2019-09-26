#pragma once
#include <iostream>
#include <string>
using namespace std;

class Transaction {
    double amount;
    string date;
    string category;
    string description;
    string vendor;
public: 
    Transaction(double amount, string userMonth, string day, string year, string vendor, string category = "General Purchase", string description = " ");
    string ToString() const;
    string ToSave() const;
};