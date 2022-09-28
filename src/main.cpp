#include "../header/wavez.h"

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
   //===================PROGRAM INITIALIZATION===================
   Wavez prog("Wavez Program");

   //===================REVIEWS READ===================
   int userChoice(0);
   cout << "Load preset Reviews(1) or blank state?(2)" << endl;
   cin >> userChoice;
   if (userChoice == 1) {
      prog.loadReviews("reviews.txt");
   }
   else if (userChoice != 1 && userChoice != 2) {
      cout << "Incorrect Choice" << endl;
      return 1;
   }
   //===================LOGIN READ===================
   string userfile; // = argv[1];
   string passfile;
   cout << "Load default(1) or custom credential database?(2)" << endl;
   int userAction(0);
   cin >> userAction;
//   cout << "AHH" << userAction;
   if (userAction == 1) {
      userfile = "usernames.txt";
      passfile = "passwords.txt";
   }
   else if (userAction == 2) {
      cout << "Please enter the username's filename: " << endl;
      cin >> userfile;
      cout << endl;

      cout << "Please enter the password's filename: " << endl;
      cin >> passfile;
      cout << endl;
   }
   else {
      cout << "Incorrect Option, ending program" << endl;
      return 1;
   }

   if (!prog.loadLogin(userfile, passfile)) {
      cout << "Error loading users from file " << userfile << endl;
      return 1;
   }

   if (!prog.login()) {
      cout << "Now exiting the program" << endl;
      prog.offloadLogin(userfile, passfile);
      return 1;
   }
   

   //===================PROGRAM RUN===================
   prog.run();


   //===================SAVE LOGIN INFO TO FILE===================
   prog.offloadLogin(userfile, passfile);

   return 0;
}
