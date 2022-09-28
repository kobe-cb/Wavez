#ifndef __LOGIN_TEST_HPP__
#define __LOGIN_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/wavez.h"
#include "../header/user.h"
#include "../header/UsernameManager.h"
#include "../header/PasswordManager.h"

#include <fstream>
using namespace std;


//====================Loading in Files====================
TEST(loadLogin, SuccessfulImport) {
   Wavez prog("Wavez Program");
   string userfile = "usernames.txt";
   string passfile = "passwords.txt";

   ASSERT_TRUE(prog.loadLogin(userfile,passfile));
}
TEST(loadLogin, FailedImport_BOTH) {
   Wavez prog("Wavez Program");
   string userfile = "fakeusernames.txt";
   string passfile = "fakepasswords.txt";

   ASSERT_FALSE(prog.loadLogin(userfile,passfile));
}
TEST(loadLogin, FailedImport_USER) {
   Wavez prog("Wavez Program");
   string userfile = "fakeusernames.txt";
   string passfile = "passwords.txt";

   ASSERT_FALSE(prog.loadLogin(userfile,passfile));
}
TEST(loadLogin, FailedImport_PASS) {
   Wavez prog("Wavez Program");
   string userfile = "usernames.txt";
   string passfile = "fakepasswords.txt";

   ASSERT_FALSE(prog.loadLogin(userfile,passfile));
}

//====================UserLogin====================
TEST(userLogin, SuccessfulLogin_BEGIN) {
   string username = "kobe";
   string password = "kobe123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   EXPECT_TRUE(tempUser.userLogin());

}
TEST(userLogin, SuccessfulLogin_MID) {
   string username = "test";
   string password = "test123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   EXPECT_TRUE(tempUser.userLogin());

}
TEST(userLogin, SuccessfulLogin_END) {
   string username = "apple";
   string password = "apple123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   EXPECT_TRUE(tempUser.userLogin());

}
TEST(userLogin, FailedLogin_BOTH) {
   string username = "kobeH";
   string password = "kobe122";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   EXPECT_FALSE(tempUser.userLogin());
}
TEST(userLogin, FailedLogin_USER) {
   string username = "kobeH";
   string password = "kobe123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   EXPECT_FALSE(tempUser.userLogin());
}
TEST(userLogin, FailedLogin_PASS) {
   string username = "kobe";
   string password = "kobe122";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   EXPECT_FALSE(tempUser.userLogin());
}

//====================UserAdd====================
TEST(userAdd, AddingUserSuccess) {
   string username = "robin";
   string password = "robin123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userAdd();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.back(), "robin");
   EXPECT_EQ(passList.back(), "robin123");
}

TEST(userAdd, AddingUserSuccess_Space) {
   string username = " robin";
   string password = "robin 123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userAdd();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.back(), " robin");
   EXPECT_EQ(passList.back(), "robin 123");
}

TEST(userAdd, AddingUserSuccess_SpecialChar) {
   string username = "@robin";
   string password = "robin@123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userAdd();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.back(), "@robin");
   EXPECT_EQ(passList.back(), "robin@123");
}
//====================UserRemove====================
TEST(userRemove, RemovingUser_End) {
   string username = "apple";
   string password = "apple123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userRemove();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.front(), "kobe");
   EXPECT_EQ(passList.front(), "kobe123");
   EXPECT_EQ(userList.back(), "test");
   EXPECT_EQ(passList.back(), "test123");
}
TEST(userRemove, RemovingUser_Mid) {
   string username = "test";
   string password = "test123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userRemove();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.front(), "kobe");
   EXPECT_EQ(passList.front(), "kobe123");
   EXPECT_EQ(userList.back(), "apple");
   EXPECT_EQ(passList.back(), "apple123");
}
TEST(userRemove, RemovingUser_Top) {
   string username = "kobe";
   string password = "kobe123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userRemove();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.front(), "test");
   EXPECT_EQ(passList.front(), "test123");
   EXPECT_EQ(userList.back(), "apple");
   EXPECT_EQ(passList.back(), "apple123");
}
TEST(userRemove, RemovingUser_NonUser) {
   string username = "candy";
   string password = "candy123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userRemove();
   userList = test.at(0);
   passList = test.at(1);
   EXPECT_EQ(userList.front(), "kobe");
   EXPECT_EQ(passList.front(), "kobe123");
   EXPECT_EQ(userList.at(1), "test");
   EXPECT_EQ(passList.at(1), "test123");
   EXPECT_EQ(userList.back(), "apple");
   EXPECT_EQ(passList.back(), "apple123");
}

//====================Add_RemoveLogin====================
TEST(Add_Remove, SameUser) {
   string username = "candy";
   string password = "candy123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userAdd();
   userList = test.at(0);
   passList = test.at(1);

   vector<vector<string>> test1 = tempUser.userRemove();
   userList = test1.at(0);
   passList = test1.at(1);

   EXPECT_EQ(userList.front(), "kobe");
   EXPECT_EQ(passList.front(), "kobe123");
   EXPECT_EQ(userList.at(1), "test");
   EXPECT_EQ(passList.at(1), "test123");
   EXPECT_EQ(userList.back(), "apple");
   EXPECT_EQ(passList.back(), "apple123");
}

TEST(Add_Remove, RemoveOther) {
   string username = "candy";
   string password = "candy123";
   vector<string> userList = {"kobe", "test", "apple"};
   vector<string> passList = {"kobe123", "test123", "apple123"};

   User tempUser(username, password, userList, passList);

   vector<vector<string>> test = tempUser.userAdd();
   userList = test.at(0);
   passList = test.at(1);

   username = "test";
   password = "test123";

   User tempUser2(username, password, userList, passList);
   vector<vector<string>> test1 = tempUser2.userRemove();
   userList = test1.at(0);
   passList = test1.at(1);

   EXPECT_EQ(userList.front(), "kobe");
   EXPECT_EQ(passList.front(), "kobe123");
   EXPECT_EQ(userList.at(1), "apple");
   EXPECT_EQ(passList.at(1), "apple123");
   EXPECT_EQ(userList.back(), "candy");
   EXPECT_EQ(passList.back(), "candy123");
}
//====================OffloadToFiles====================
TEST(offloadLogin, Type) {
   Wavez prog("Wavez Program");
   string userfile = "usernames.txt";
   string passfile = "passwords.txt";

   vector<string> userList;
   vector<string> passList;
   string user;
   string pass;

   ASSERT_TRUE(prog.loadLogin(userfile, passfile));
   ifstream fin(userfile);
   ifstream fin_2(passfile);

   ASSERT_TRUE(fin);
   ASSERT_TRUE(fin_2);

   while (fin >> user) {
      userList.push_back(user);
   }
   while (fin_2 >> pass) {
      passList.push_back(pass);
   }
   fin.close();
   fin_2.close();

   prog.offloadLogin(userfile,passfile);
   fin.open(userfile);
   fin_2.open(passfile);

   ASSERT_TRUE(fin);
   ASSERT_TRUE(fin_2);

   for (unsigned i = 0; i < userList.size(); ++i) {
      fin >> user;
      EXPECT_EQ(user, userList.at(i));
   }
   for (unsigned i = 0; i < passList.size(); ++i) {
      fin_2 >> pass;
      EXPECT_EQ(pass, passList.at(i));
   }

}

/*
 TEST(BinaryTest, AddTest) {
    Op* two = new Op(2);
    Op* three = new Op(3);

    Add* test = new Add(two, three);
    EXPECT_EQ(test->evaluate(), 5);
 */










#endif //__LOGIN_TEST_HPP
