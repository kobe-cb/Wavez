#ifndef __REVIEW_H__
#define __REVIEW_H__
#include <string>

using namespace std;

class Review {
 private:
	string name;
	int rating;
	//string author;
	string body;

 public:

	// default constructor
	Review();
	// Parameterized constructor; 
	Review(/*const string &athr,*/ const string &nme, const string &body, const int &rat);
	
	/* Displays the Review using the following format:
	 *
	 * Name:
	 * Rating: /5
	 * Posted By: 
	 * Review: 
	 *
	 */
	void display() const;	
	string getName();
	string getBody();
	int getRating();
};
#endif
