#ifndef __PASSWORDMANAGER_H__
#define __PASSWORDMANAGER_H__

#include <string>
#include <vector>
using namespace std;

class PasswordManager { 
  private:
    string current_password;
    vector<string> passList;

 public:
   PasswordManager();
   PasswordManager(const string&, vector<string>& );

   int userLogin();

   vector<string> userAdd();
   vector<string> userRemove();

};

#endif //__PASSWORDMANAGER_H__