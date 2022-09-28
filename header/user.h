#ifndef __USER_H__
#define __USER_H__
#include <string>
#include <vector>

using namespace std;
 
class User {
 private:
  string username;
  string password;
  vector<string> userList;
  vector<string> userPass;

 public:
  User();
  User(const string&, const string&, vector<string>&, vector<string>& );
  bool userLogin();
  vector<vector<string> > userAdd();
  vector<vector<string> > userRemove();
};

#endif //__USER_H__


//Check for duplicate account usernames