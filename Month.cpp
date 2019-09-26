#include <iostream>
#include <string>

#include "Month.h"

using namespace std;

Month::Month(string name) {
    this->name = name;
}
string Month::GetName() const {
    return this->name;
}
void Month::AddTransaction(Transaction* userPtr) {
    this->transList.push_back(userPtr);
}
