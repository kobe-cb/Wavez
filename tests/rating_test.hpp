//TESTING FOR SONG/ALBUM/ARTIST RATINGS
#ifndef __RATING_TEST_HPP__
#define __RATING_TEST_HPP__

#include "gtest/gtest.h"
#include "../header/wavez.h"
#include "../header/song.h"
#include "../header/album.h"
#include "../header/artist.h"
#include "../header/review.h"
#include <fstream>
using namespace std;

//SONG
//check for rating, description, name
TEST(SongTesting, RatingMatch) {
    Song* test = new Song("Abc", 3);
    EXPECT_EQ(3, test->getRating());

    test = new Song("Abcc", 5);
    EXPECT_EQ(5, test->getRating());
}

TEST(SongTesting, DescMatch) {
    Song* test = new Song("Abc", 3);
    string userReview = "This is an awesome song!";

    Review* song = new Review("Abc", userReview, 3);
    test->addToVector(song);

    vector<Review*>testVector = test->getSongReview();
    string testReview = testVector.front()->getBody();
    EXPECT_EQ(userReview, testReview);

}

TEST(SongTesting, NameMatch) {
    string songName = "Abc";
    Song* test = new Song(songName, 3);
    EXPECT_EQ(songName, test->getName());

}

//ALBUM
//check for rating, description, name
TEST(AlbumTesting, RatingMatch) {
    Album* test = new Album("Abc", 3);
    EXPECT_EQ(3, test->getRating());

    test = new Album("Abcc", 5);
    EXPECT_EQ(5, test->getRating());

}

TEST(AlbumTesting, DescMatch) {
    Album* test = new Album("Abc", 3);
    string userReview = "This is an awesome song!";

    Review* Album = new Review("Abc", userReview, 3);
    test->addToVector(Album);

    vector<Review*>testVector = test->getAlbumReview();
    string testReview = testVector.front()->getBody();
    EXPECT_EQ(userReview, testReview);


}

TEST(AlbumTesting, NameMatch) {
    string albumName = "Abc";
    Album* test = new Album(albumName, 3);
    EXPECT_EQ(albumName, test->getName());


}

//ARTIST
//check for name, vectors??
TEST(ArtistTesting, NameMatch) {
    string userArtist = "Abc";
    Artist* test = new Artist(userArtist);
    EXPECT_EQ(userArtist, test->getName());

}

TEST(ArtistTesting, addSong) {
    Artist* test = new Artist("Michael");
    Song* song = new Song("Abc", 4);
    test->addSong(song);

    EXPECT_EQ(test->getSongVector().front()->getName(), "Abc");
    EXPECT_EQ(test->getSongVector().front()->getRating(), 4);

}

TEST(ArtistTesting, addAlbum) {
    Artist* test = new Artist("Michael");
    Album* album = new Album("Abc", 4);
    test->addAlbum(album);

    EXPECT_EQ(test->getAlbumVector().front()->getName(), "Abc");
    EXPECT_EQ(test->getAlbumVector().front()->getRating(), 4);


}


TEST(ArtistTesting, displaySongs) {
    Artist* test = new Artist("Michael");
    Song* song = new Song("Abc", 3);
    Review* songA = new Review("Abc", "Wow", 4);
    test->addSong(song);
    song->addToVector(songA);
    
    string expectedOut = 
    "---------------------------------------------------------\n";
    expectedOut +=
    "Review #1 for Abc: \n"; 
    expectedOut +=
    "	Rating: 4/5\n";
    expectedOut +=
    "	Review: Wow\n\n";
    expectedOut +=
    "---------------------------------------------------------\n\n";
    expectedOut +=
    "---------------------------------------------------------";
    cout << endl <<  "EXPECTED: " << endl << expectedOut << endl << endl;
    

    cout << "ACTUAL: " << endl;
    test->displaySongs();
}

TEST(ArtistTesting, displayAlbums) {
    Artist* test = new Artist("Michael");
    Album* album = new Album("Abc", 2);
    Review* albumA = new Review("Abc", "Awesome", 2);
    test->addAlbum(album);
    album->addToVector(albumA);
    
    string expectedOut = 
    "---------------------------------------------------------\n";
    expectedOut +=
    "Review #1 for Abc: \n"; 
    expectedOut +=
    "	Rating: 2/5\n";
    expectedOut +=
    "	Review: Awesome\n\n";
    expectedOut +=
    "---------------------------------------------------------\n\n";
    expectedOut +=
    "---------------------------------------------------------";
    cout << endl << "EXPECTED: " << endl << expectedOut << endl << endl;
    

    cout << "ACTUAL: " << endl;
    test->displayAlbums();

}









#endif // __RATING_TEST_HPP__