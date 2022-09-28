#include "../header/wavez.h"
#include "../header/artist.h"
#include "../header/review.h"
#include "../header/song.h"
#include "../header/album.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

string name;

Wavez::Wavez(){
    title = "No Title";
    //User def();
}

Wavez::Wavez(const string &ttle){
    title = ttle;
    //User def();
}

void Wavez::loadReviews(const string& loadFile) {
    string artistName("");
    int albumRating(0);
    string albumName("");
    int songRating(0);
    string songName("");

    Artist* temp_Artist = nullptr;
    Album* temp_Album = nullptr;
    Song* temp_Song = nullptr;
    Review* album = nullptr;
    Review* song = nullptr;

    //Kanye
    temp_Artist = new Artist("Kanye West");
    artistList.push_back(temp_Artist);
    //album - life of pablo
    albumName = "Life of Pablo";
    albumRating = 4;
    temp_Album = new Album(albumName, albumRating);
    temp_Artist->addAlbum(temp_Album);
    album = new Review(albumName, "This album was really something else!", albumRating);
    temp_Album->addToVector(album);

    //song - wolves
    songName = "Wolves";
    songRating = 5;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "I love the instrumentals of this song!!", songRating);
    temp_Song->addToVector(song);

    //song - Famous
    songName = "Famous";
    songRating = 4;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "It has such a catchy beat that Kanye does best", songRating);
    temp_Song->addToVector(song);

    //song - Champion
    songName = "Champion";
    songRating = 4;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "Such a good song and sampling from Kanye", songRating);
    temp_Song->addToVector(song);

    //kendrick
    temp_Artist = new Artist("Kendrick Lamar");
    artistList.push_back(temp_Artist);
    //album - DAMN
    albumName = "DAMN";
    albumRating = 4;
    temp_Album = new Album(albumName, albumRating);
    temp_Artist->addAlbum(temp_Album);
    album = new Review(albumName, "True masterpiece of an Album", albumRating);
    temp_Album->addToVector(album);

    //song - element
    songName = "Element";
    songRating = 5;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "Such a great song to get you hyped up", songRating);
    temp_Song->addToVector(song);

    //song - Humble
    songName = "Humble";
    songRating = 4;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "Amazing song from Kendrick", songRating);
    temp_Song->addToVector(song);

    //song - DNA
    songName = "DNA";
    songRating = 5;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "Such an amazing song that resonates with you", songRating);
    temp_Song->addToVector(song);

    //song - DNA
    songName = "Love";
    songRating = 5;
    temp_Song = new Song(songName, songRating);
    temp_Artist->addSong(temp_Song);
    song = new Review(songName, "I never knew Kendrick could go to these levels, AMAZING!", songRating);
    temp_Song->addToVector(song);


}


bool Wavez::loadLogin(const string &userfile, const string &passfile){
    ifstream fin (userfile);
    ifstream fin_2 (passfile);


    if (!fin){
        return false;
    }
    else if (!fin_2) {
        return false;
    }
    else{

        string currUser;
        string currPass;
        while (fin >> currUser) {
            vUsers.push_back(currUser);
        }
        while (fin_2 >> currPass) {
            vPass.push_back(currPass);
        }

        if (vUsers.size() < vPass.size()) {
            cout << "There are less usernames than there are passwords, please check the files." << endl;
            return false;
        }

        else if (vUsers.size() > vPass.size()) {
            cout << "There are less passwords than there are usernames, please check the files." << endl;
            return false;
        }
/*
        for (unsigned i = 0; i < vUsers.size(); ++i) {
            User tempUser(vUsers.at(i), vPass.at(i));
            userList.push_back(tempUser);
        }
        //Purpose of this ?
        userList.pop_back();
        return true;
*/
    return true;
    }
}



bool Wavez::login(){
    string currentUser;
    string currentPassword;
    int userAction(0);
    
    cout << "Welcome to Wavez" << endl;
    login_menu_start:
    while (true) {
        cout << "Please choose an option by entering the corresponding number:\n" <<
        "(1) Login" << endl <<
        "(2) Register an Account" << endl <<
        "(3) Deactivate an Account" << endl <<
        "(0) Quit" << endl;
        cin >> userAction;

        if (userAction == 1) {
            cout << "Please enter your username!\n";
            cin >> currentUser;
            cout << endl;            
            cout << "Now please enter your password!\n";         
            cin >> currentPassword;
            cout << endl;

            User temp_user(currentUser, currentPassword, vUsers, vPass);
            //User temp_user(currentUser, currentPassword, userList);

            if (!temp_user.userLogin()) {
                return false;
                //return true;
            }
            else {
                return true;
            }
        }
        else if (userAction == 2) {
            cout << "Please create your username!\n";          
            cin >> currentUser;           
            cout << endl;
            cout << "Please enter a password for " << currentUser << endl;            
            cin >> currentPassword;            
            cout << endl;

            User temp_user(currentUser, currentPassword, vUsers, vPass);
            vUsers = temp_user.userAdd().at(0);
            vPass = temp_user.userAdd().at(1);
            cout << currentUser << "'s Account has been successfully created!" << endl;
            goto login_menu_start;

        }
        else if (userAction == 3) {
            cout << "Please enter the username of the account you wish to delete" << endl;
            cin >> currentUser;  
            cout << "Please enter the password for " << currentUser << endl;
            cin >> currentPassword;
            cout << endl;
            cout << "Are you sure you want to delete this account? (Y/N)" << endl; //please enter the username one more time
            char userChoice;
            cin >> userChoice;
            if (tolower(userChoice) == 'y') {
                User temp_user(currentUser, currentPassword, vUsers, vPass);
                if (!temp_user.userLogin()) {
                    cout << "Invalid credentials, Returning to main menu" << endl;
                    goto login_menu_start;
                }
                else
                {
                    vUsers = temp_user.userRemove().at(0);
                    vPass = temp_user.userRemove().at(1);
                    cout << currentUser << "'s Account has been successfully deleted!" << endl;
                    goto login_menu_start;
                }
            }
            else if (tolower(userChoice) == 'n') {
                cout << "Understood, will not delete this account" << endl;
                goto login_menu_start;
            }
            else {
                cout << "Invalid answer, returning to main menu" << endl;
                goto login_menu_start;
            }
        }
        else if (userAction == 0) {
            return false;
        }
        else {
            cout << "Incorrect Option, Please try again" << endl;
            goto login_menu_start;
        }
        //break;
    }
    return true;
}


void Wavez::run(){
    string cont;
    int loop = 0;
    while (loop == 0){
        displayMenu();
        cout << "Choose an option: ";
        cin >> cont;
	cout << "========================" << endl << endl;

        if ((cont == "D") || (cont == "d")){
            if (artistList.size() == 0){
                cout << "Nothing to Display." << endl;
                cout << endl;
            }
            else{
		string artistName;
		cout << "Which artist would you like to see reviews or a rating for?" << endl;
		cin.ignore();
		getline(cin,artistName);
		cout << endl;
		Artist* selectedArtist = nullptr;
		bool foundArtist = false;
                for (unsigned int i = 0; i < artistList.size(); ++i){
              		if(artistList.at(i)->getName() == artistName){
				foundArtist = true;
				selectedArtist = artistList.at(i);
			}
	    	}
		
		if (!foundArtist){
			cout << "Artist does not exist in Wavez." << endl;
		}
		else{
			string displayChoice;	
			cout << "Do you want to see a rating (R), Song reviews (S), or Album reviews (A) for this artist?" << endl;
			cin >> displayChoice;
			if (displayChoice == "S" || displayChoice == "s"){
				selectedArtist->displaySongs();
			}
			else if (displayChoice == "A" || displayChoice == "a"){
				selectedArtist->displayAlbums();
			}
			else if (displayChoice == "R" || displayChoice == "r"){
				selectedArtist->setRating();
				}
			else{
				cout << "Invalid entry" << endl;
			}
		}
	    }
        }



        else if ((cont == "A") || (cont == "a")){
    	
		//ask user for input
    		string artistName;
    		cout << "Enter name of artist you wish to review: " << endl;
    		cin.ignore();
            getline(cin, artistName);
    		cout << "Album(1); Song(2)" << endl;
    		string choice;
    		cin >> choice;

		//search if artist already exists
    		Artist* reviewArtist = nullptr;
    		bool foundArtist = false;
    		for (unsigned int i = 0; i < artistList.size(); ++i){
        		if(artistList.at(i)->getName() == artistName){
            			reviewArtist = artistList.at(i);
            			foundArtist = true;
        		}
    		}

    		if (!foundArtist){
        		reviewArtist = new Artist(artistName);
        		artistList.push_back(reviewArtist);
    		}
	
		//handle choices
    		if(choice == "1"){
        		int albumRating;
        		string albumName;

        		cout << "Enter An Album You Would Like to Review: " << endl;
        		cin.ignore();
			getline(cin, albumName);
        		cout << "Give A Rating Out of Five For '" << albumName << "': " << endl;
        		cin >> albumRating;

			//artist was just created, so need to create album object
        		if(!foundArtist){
            			Album* newAlbum = new Album(albumName, albumRating);
            			reviewArtist->addAlbum(newAlbum);
				newAlbum->addReview();
            			
        		}
        		else{
				//need to search album vector within the artist to see if an instance of the album already exists
            			bool foundAlbum = false;
            			Album* album = nullptr;
            			for(unsigned int j = 0; j < reviewArtist->getAlbumVector().size(); ++j){
                			if(reviewArtist->getAlbumVector().at(j)->getName() == albumName){
                    				album = reviewArtist->getAlbumVector().at(j);
                    				foundAlbum = true;
                			}
            			}
	
				//if instance of album was found, simply call addreview on it, otherwise create new Album obj, push it to vector, and call addreview on it
            			if(foundAlbum){
					album->setRating(albumRating);
                			album->addReview();
            			}
            			else{
                			album = new Album(albumName, albumRating);
                			reviewArtist->addAlbum(album);
                			album->addReview();
            			}

        		}	
    		}


    		else if (choice == "2"){
        		int songRating;
        		string songName;

        		cout << "Enter A Song You Would Like to Review: " << endl;
			cin.ignore();
        		getline(cin, songName);
        		cout << "Give A Rating Out of Five For '" << songName << "': " << endl;
        		cin >> songRating;

			//artist was just created, so need to create song object
        		if(!foundArtist){
            			Song* newSong = new Song(songName, songRating);
            			reviewArtist->addSong(newSong);
				newSong->addReview();
            			
        		}
        		else{
				 //need to search song vector within the artist to see if an instance of the song already exists
            			bool foundSong = false;
            			Song* song = nullptr;
            			for(unsigned int j = 0; j < reviewArtist->getSongVector().size(); ++j){
                			if(reviewArtist->getSongVector().at(j)->getName() == songName){
                    				song = reviewArtist->getSongVector().at(j);
                    				foundSong = true;
                			}
            			}

				//if instance of song was found, simply call addreview on it, otherwise create new Song obj, push it to vector, and call addreview on it
            			if(foundSong){
					song->setRating(songRating);
                			song->addReview();
            			}
            			else{
                			song = new Song(songName, songRating);
                			reviewArtist->addSong(song);
                			song->addReview();
            			}
        		}
		}
    		
		else{
        		cout << "Not a valid input. Try again." << endl;
        	
    		}

	}	


                

	else if ((cont == "S") || (cont == "s")){
		string searchChoice;
		cout << "Do you want to search for an Artist (1), an Album (2), or a Song (3)?" << endl;
		cin.ignore();
		cin >> searchChoice;
		
		if (searchChoice == "1"){
			string artistName;
			cout << "What Artist are you looking for?" << endl;
			cin.ignore();
			getline(cin, artistName);

			Artist* searchArtist = nullptr;
                	bool foundArtist = false;
                	for (unsigned int i = 0; i < artistList.size(); ++i){
                        	if(artistList.at(i)->getName() == artistName){
                                	searchArtist = artistList.at(i);
                                	foundArtist = true;
                        	}
                	}

                	if (!foundArtist){
                        	cout << "Artist '" << artistName << "' not found in Wavez!" << endl;
                	}
			else{
				cout << "Artist found! Do you wish to see reviews for " << searchArtist->getName() << "? Y/N" << endl;
				string artistChoice;
				getline(cin, artistChoice);
				
				if (artistChoice == "Y" || artistChoice == "y"){
					cout << "Album Reviews: " << endl;
					searchArtist->displayAlbums();
					cout << endl;
					cout << "Song Reviews: " << endl;
					searchArtist->displaySongs();
				}
				
			}
	
		}
		else if (searchChoice == "2"){
			string artistName;
			cout << "Who is the Artist of the Album you are looking for?" << endl;
			cin.ignore();
                        getline(cin, artistName);

                        Artist* searchArtist = nullptr;
                        bool foundArtist = false;
                        for (unsigned int i = 0; i < artistList.size(); ++i){
                                if(artistList.at(i)->getName() == artistName){
                                        searchArtist = artistList.at(i);
                                        foundArtist = true;
                                }
                        }

                        if (!foundArtist){
                                cout << "Artist '" << artistName << "' not found in Wavez!" << endl;
                        }
                        else{
                                cout << "What Album are you looking for?" << endl;
                                string albumSearch;
                                getline(cin, albumSearch);
				
				bool foundAlbum = false;
				Album* searchAlbum = nullptr;
				for (unsigned int j = 0; j < searchArtist->getAlbumVector().size(); ++j){
					if (searchArtist->getAlbumVector().at(j)->getName() == albumSearch){
						foundAlbum = true;
						searchAlbum = searchArtist->getAlbumVector().at(j);
					}
				}

				if (!foundAlbum){
					cout << "Album " << albumSearch << " not found!" << endl;
				}
				else{
					cout << "Album found! Do you wish to see reviews for " << searchAlbum->getName() << "? Y/N" << endl;
					string albumChoice;
					getline(cin, albumChoice);
				
                                	if (albumChoice == "Y" || albumChoice == "y"){
						cout << "---------------------------------------------------------" << endl;
                                        	for (unsigned int k = 0; k < searchAlbum->getAlbumReview().size(); ++k){
							cout << "Review #" << (k + 1) << " for " << searchAlbum->getAlbumReview().at(k)->getName() << ": " << endl;
							searchAlbum->getAlbumReview().at(k)->display();
							cout << endl;
						}
						cout << "---------------------------------------------------------" << endl;
                				cout << endl;
                                	}
				}
                        }
		}
		else if (searchChoice == "3"){
			string artistName;
                        cout << "Who is the Artist of the Song you are looking for?" << endl;
                        cin.ignore();
                        getline(cin, artistName);

                        Artist* searchArtist = nullptr;
                        bool foundArtist = false;
                        for (unsigned int i = 0; i < artistList.size(); ++i){
                                if(artistList.at(i)->getName() == artistName){
                                        searchArtist = artistList.at(i);
                                        foundArtist = true;
                                }
                        }

                        if (!foundArtist){
				cout << "Artist '" << artistName << "' not found in Wavez!" << endl;                                
                        }
                        else{
                                cout << "What Song are you looking for?" << endl;
                                string songSearch;
                                getline(cin, songSearch);

                                bool foundSong = false;
                                Song* searchSong = nullptr;
                                for (unsigned int j = 0; j < searchArtist->getSongVector().size(); ++j){
                                        if (searchArtist->getSongVector().at(j)->getName() == songSearch){
                                                foundSong = true;
                                                searchSong = searchArtist->getSongVector().at(j);
                                        }
                                }

                                if (!foundSong){
                                        cout << "Song " << songSearch << " not found!" << endl;
                                }
                                else{
                                        cout << "Song found! Do you wish to see reviews for " << searchSong->getName() << "? Y/N" << endl;
                                        string songChoice;
                                        getline(cin, songChoice);

                                        if (songChoice == "Y" || songChoice == "y"){
                                                cout << "---------------------------------------------------------" << endl;
                                                for (unsigned int k = 0; k < searchSong->getSongReview().size(); ++k){
                                                        cout << "Review #" << (k + 1) << " for " << searchSong->getSongReview().at(k)->getName() << ": " << endl;
                                                        searchSong->getSongReview().at(k)->display();
                                                        cout << endl;
                                                }
                                                cout << "---------------------------------------------------------" << endl;
                                                cout << endl;
                                        }
                                }
                        }
		}
		else{
			cout << "Invalid input." << endl;
		}
	}
        else if ((cont == "Q") || (cont == "q")){
            cout << "Goodbye!" << endl;
            ++loop;
        }
    }
}

void Wavez::displayMenu() const{
    cout << "======Wavez Menu======" << endl;
    cout << "=================================================" << endl;
    cout << "Display Available Reviews: ENTER 'D\' OR \'d\'" << endl;
    cout << "=================================================" << endl;
    cout << "Add A New Review: ENTER \'A\' OR \'a\'" << endl;
    cout << "=================================================" << endl;
    cout << "Make A Search: ENTER \'S\' OR \'s\'" << endl;
    cout << "=================================================" << endl;
    cout << "Quit Wavez: ENTER \'Q\' OR \'q\'" << endl;
    cout << "=================================================" << endl;
}

void Wavez::offloadLogin(const string & userFile, const string & passFile) {
    ofstream ofs(userFile);
    ofs.open(userFile, ofstream::out | ofstream::trunc);
    ofstream ofs_2(passFile);
    ofs.open(passFile, ofstream::out | ofstream::trunc);
    ofs.close();
    ofs_2.close();

    ofs.open(userFile);
    ofs_2.open(passFile);
    for (unsigned i = 0; i < vUsers.size(); ++i) { 
        ofs << vUsers.at(i) << endl;
    }
    for (unsigned i = 0; i < vPass.size(); ++i) {
        ofs_2 << vPass.at(i) << endl;
    }
    ofs.close();
    ofs_2.close();
    
}
