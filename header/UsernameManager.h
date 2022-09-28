#ifndef __USERNAMEMANAGER_H__
#define __USERNAMEMANAGER_H__

#include <string>
#include <vector>
using namespace std;

class UsernameManager { 
 private:
  string current_user;
  vector<string> userList;

 public:
  UsernameManager();
   //pass by ref here to save mem, no new copy
  UsernameManager(const string&, vector<string> &);

  int userLogin();

  vector<string> userAdd();
  vector<string> userRemove();
   


};

#endif //__USERNAMEMANAGER_H__