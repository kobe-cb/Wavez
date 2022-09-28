//TESTING for REVIEW
#ifndef __REVIEW_TEST_HPP__
#define __REVIEW_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/wavez.h"
#include "../header/song.h"
#include "../header/album.h"
#include "../header/artist.h"
#include "../header/review.h"
#include <fstream>
using namespace std;

//REVIEW
//Test for name, body, rating
TEST(ReviewTest, nameCheck) {
    Review* test = new Review("Abc", "Wow", 3);
    EXPECT_EQ(test->getName(), "Abc");

}

TEST(ReviewTest, bodyCheck){
    Review* test = new Review("Abc", "Wow", 3);
    EXPECT_EQ(test->getBody(), "Wow");

}

TEST(ReviewTest, ratingCheck){
    Review* test = new Review("Abc", "Wow", 3);
    EXPECT_EQ(test->getRating(), 3);

}

//Test DISPLAY
TEST(ReviewTest, displayCheck){
    Review* test = new Review("Abc", "Wow", 3);
    string testInput = "\tRating: 3/5\n";
    testInput += "\tReview: Wow\n";
    testing::internal::CaptureStdout();
    test->display();
    string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(testInput, output);

}




#endif // __REVIEW_TEST_HPP__