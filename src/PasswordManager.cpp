#include "../header/PasswordManager.h"
#include <iostream>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <limits>

using namespace std;

PasswordManager::PasswordManager() {
    this->current_password = "";
}

PasswordManager::PasswordManager(const string& pass, vector<string>& pList) {
    this->current_password = pass;
    this->passList = pList;
}


int PasswordManager::userLogin() {
    for (unsigned i = 0; i < passList.size(); ++i) {
        if (current_password == passList.at(i)) {
            return i;
        }
    }
   // return INT_MIN;
   return -2147483648;
}

vector<string> PasswordManager::userAdd(){
    passList.push_back(this->current_password);
    return this->passList;

}

vector<string> PasswordManager::userRemove(){
    for (unsigned i = 0; i < passList.size(); ++i) {
        if (current_password == passList.at(i)) {
            passList.erase(passList.begin() + i);
        }
    }
    return this->passList;

    
}


