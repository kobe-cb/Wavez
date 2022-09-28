#include "../header/user.h"
#include "../header/UsernameManager.h"
#include "../header/PasswordManager.h"
using namespace std;
#include <iostream>

User::User() {
    username = "";
    password = "";
}

User::User(const string& user, const string& pass, vector<string>& vUsers, vector<string>& vPass ) {
    this->username = user;
    this->password = pass;
    this->userList = vUsers;
    this->userPass = vPass;
}

bool User::userLogin() {
    //UsernameManager temp_user = userLogin(this->username);
    //PasswordManager temp_pass= userLogin(this->password);
    UsernameManager temp_user = UsernameManager(this->username, userList);
    PasswordManager temp_pass = PasswordManager(this->password, userPass);

    if (temp_user.userLogin() == temp_pass.userLogin()) {
        return true;
    }
    else {
        return false;
    }
}

vector<vector<string> > User::userAdd(){ 

    UsernameManager temp_user = UsernameManager(this->username, userList);

    vector<string> newUser = temp_user.userAdd();

    PasswordManager temp_pass = PasswordManager(this->password, userPass);

    vector<string> newPass = temp_pass.userAdd();

    vector<vector<string> > tempList;

    tempList.push_back(newUser);
    tempList.push_back(newPass);

    return tempList;

}

vector<vector<string> > User::userRemove(){ 
    UsernameManager temp_user = UsernameManager(this->username, userList);
    vector<string> newUser = temp_user.userRemove();

    PasswordManager temp_pass = PasswordManager(this->password, userPass);
    vector<string> newPass = temp_pass.userRemove();

    vector<vector<string> > tempList;
    tempList.push_back(newUser);
    tempList.push_back(newPass);
    return tempList;

}


//vector password and usernames in usernamman,. passwordman, respeftievly
//user login calls on usernameman login which returns, passwordman, returns
//if return of .at(i) is equal, login success


//vector of password and usernames
//inside user.h

//verify checks with those vectors

//if user
//add to user

//if password
//add to password


//login(username, users) -> Users -> UsernameManager
//login(password, pass) -> Users -> PasswordManager 