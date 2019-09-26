#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Transaction.h"

using namespace std;

class Month {
public:
    string name;
    vector<Transaction*> transList;
    Month(string name);
    string GetName() const;
    void AddTransaction(Transaction* userPtr);
};