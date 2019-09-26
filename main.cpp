#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Month.h"
#include "Transaction.h"

using namespace std;

void SaveAll(vector<Month*> monthList);
bool Initialize();

int main() {
    vector<Month*> monthList;
    
    if (Initialize() == false) {
        cout << "Corrupt memory files.  Could not read files." << endl << endl;
    }
    
    string userInput;
    while (userInput != "q") {
        
        //ADD A TRANSACTION
        if (userInput == "a") {
            double amount;
            string vendor;
            string category;
            string description;
            string userMonth;
            string day;
            string year;
            
            //add new transaction
            cout << "Who was the vendor?" << endl;
            cin.ignore();
            getline(cin, vendor);
            cout << endl;
            cout << "What date was this transaction effected? (Please enter in form January 01, 2000)" << endl;
            //cin.ignore();
            cin >> userMonth;
            cin >> day;
            cin >> year;
            cout << endl;
            cout << "What was the amount of this transaction? (Note that only positive (debit) values are accepted.  Do not include commas)" << endl;
            cin >> amount;
            cout << endl;
            cout << "Under what category is this transaction classified? (For list of possible categories, please enter \"c\")" << endl;
            getline(cin, category);
            if (category == "") {
                getline(cin, category);
            }
            if (category == "c") {
                cout << endl << "Groceries/Living" << endl;
                cout << "School" << endl;
                cout << "Rent" << endl;
                cout << "Tithing/Church" << endl;
                cout << "Restaurants" << endl;
                cout << "Recreation" << endl;
                cout << "Utilities" << endl;
                cout << "Auto Maintenance" << endl;
                cout << "Healthcare" << endl;
                cout << "Charity" << endl;
                cout << "Special" << endl << endl;
                cout << "Under what category is this transaction classified?" << endl;
                getline(cin, category);
            }
            cout << "Would you like to give a brief description? (If no, please enter \"n\")" << endl;
            getline(cin, description);
            Transaction* newPtr;
            if (description == "n") {
                newPtr = new Transaction(amount, userMonth, day, year, vendor, category);
            }
            else {
                newPtr = new Transaction(amount, userMonth, day, year, vendor, category, description);
            }
            bool check = false;
            for (int i = 0; i < monthList.size(); i++) {
                if (monthList.at(i)->GetName() == userMonth) {
                    monthList.at(i)->AddTransaction(newPtr);
                    check = true;
                }
            }
            if (check == false) {
                Month* newMonth = new Month(userMonth);
                monthList.push_back(newMonth);
                newMonth->AddTransaction(newPtr);
            }
            
            cout << endl << "The following transaction was added to \"userMonth\":" << endl;
            cout << newPtr->ToString() << endl << endl;
        }
        
        //SAVE WORK TO FILE
        else if (userInput == "s") {
            SaveAll(monthList);
        }
        
        //PRINT REPORT
        else if (userInput == "r") {
            string fileName;
            string userMonth;
            ofstream ofs;
            cout << "Please enter an output file name (no spaces)" << endl;
            cin >> fileName;
            cout << endl << "Please enter a month from which you want the list of transactions:" << endl;
            cin >> userMonth;
            cin.ignore();
            ofs.open(fileName + ".txt");
            ofs << userMonth << " Transaction List" << endl;
            for (int i = 0; i < monthList.size(); i++) {
                if (monthList.at(i)->GetName() == userMonth) {
                    for (int j = 0; j < monthList.at(i)->transList.size(); j++) {
                        ofs << monthList.at(i)->transList.at(j)->ToString() << endl;
                    }
                }
            }
            ofs.close();
            cout << "File write complete." << endl << endl;
        }
        
        else if (userInput != "") {
            cout << "Invalid input.  ";
        }
        
        cout << "What would you like to do?" << endl << endl;
        cout << "These are the options:" <<endl;
        cout << "a - add new transaction" << endl;
        cout << "s - save information" << endl;
        cout << "r - print financial report" << endl;
        cout << "q - quit program" << endl;
        cin >> userInput;
        cout << endl;
        
        if (userInput == "q") {     //checks to save work when quitting program
            string temp;
            cout << "Would you like to save your work? (y/n)" << endl;
            cin >> temp;
            while (1 == 1) {
                if (temp == "y") {
                    SaveAll(monthList);
                    cout << "Work saved." << endl << endl;
                    break;
                }
                else if (temp == "n") {
                    cout << "Work not saved." << endl << endl;
                    break;
                }
                else {
                    cout << "Invalid input.  Would you like to save your work? (y/n)" << endl;
                    cin >> temp;
                }
            }
        }
    }
    cout << "Goodbye." << endl;
    return 0;
}

bool Initialize() {}

void SaveAll(vector<Month*> monthList) {
    ofstream ofs;
    ofs.open("saved.txt");
    for (int i = 0; i < monthList.size(); i++){
        vector<Transaction*> currMonth = monthList.at(i)->transList;
        for (int j = 0; j < currMonth.size(); j++) {
            ofs << currMonth.at(i)->ToSave();
        }
    }
    cout << endl << "Work saved." << endl << endl;
}