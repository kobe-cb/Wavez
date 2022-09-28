#include "../header/artist.h"
#include "../header/album.h"
#include "../header/song.h"
#include <iostream>
using namespace std;

Artist::Artist(){ //constructor that sets empty name
	Name = "";
}

Artist::Artist(string nam){
	Name = nam;
}

void Artist::setRating(){
        double sum = 0;
        int size = 0;
	int currRating = 0;
        for (unsigned int i = 0; i < albumList.size(); ++i){
                size = size + albumList.at(i)->getAlbumReview().size();
		for (unsigned int j = 0; j < albumList.at(i)->getAlbumReview().size(); ++j){
			currRating = albumList.at(i)->getAlbumReview().at(j)->getRating();
			sum = sum + currRating;
		}
        }
	this->rating = (sum/size);
 	cout << "Rating for " << Name << ": " << this->rating << endl;
	cout << "Calculated from: " << size << " Album ratings." << endl << endl;
	return;
}

void Artist::addSong(Song* newSong){
	songList.push_back(newSong);
}

void Artist::addAlbum(Album* newAlbum){
        albumList.push_back(newAlbum);
}

string Artist::getName(){
	return Name;
}

vector<Song*> Artist::getSongVector(){
	return songList;
}

vector<Album*> Artist::getAlbumVector(){
	return albumList;
}

double Artist::getRating(){
	return rating;
}

void Artist::addReview(){
	return;
}


void Artist::displaySongs(){
	if(songList.size() != 0){

	for (unsigned int i = 0; i < songList.size(); ++i){
		cout << "---------------------------------------------------------" << endl;
		for(unsigned int j = 0; j < songList.at(i)->getSongReview().size(); ++j){
	                cout << "Review #" << (j + 1) << " for " << songList.at(i)->getSongReview().at(j)->getName() << ": " << endl;
	                songList.at(i)->getSongReview().at(j)->display();
			cout << endl;
	
		}
	        cout << "---------------------------------------------------------" << endl;
		cout << endl;
	}
	cout << "---------------------------------------------------------" << endl;
	}
	else{
		cout << "No song reviews to display!" << endl << endl;
	}

}


void Artist::displayAlbums(){
	if (albumList.size() != 0){	

	for (unsigned int i = 0; i < albumList.size(); ++i){
        	cout << "---------------------------------------------------------" << endl;
                vector<Review*> displayVector = albumList.at(i)->getAlbumReview();
		for(unsigned int j = 0; j < displayVector.size(); ++j){
                	cout << "Review #" << (j + 1) << " for " << displayVector.at(j)->getName() << ": " << endl;
                	displayVector.at(j)->display();
			cout << endl;

		}
	        cout << "---------------------------------------------------------" << endl;
        }
        cout << "---------------------------------------------------------" << endl;
	}
	else{
		cout << "No album reviews to display!" << endl << endl;
	}
	
}

