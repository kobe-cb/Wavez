#ifndef __WAVEZ_H__
#define __WAVEZ_H__

#include "review.h"
#include "user.h"
#include "artist.h"

#include <string>
#include <vector>
using namespace std;

class Wavez {
   
 private:
    string title;
    User currentUser;
    vector<string> vUsers;
    vector<string> vPass;
    vector<Artist*> artistList;

 public:
    Wavez();
    Wavez(const string &);
    void loadReviews(const string &);
    bool loadLogin(const string &, const string &);
    bool login();
    void run();
    void offloadLogin(const string &, const string &);

 private:
    void displayMenu() const;
};

#endif
