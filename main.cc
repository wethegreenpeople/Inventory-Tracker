/* This is a pretty simple program for me to work on that will give me some sort of idea on how to use curl/libcurl for downloading files from a network.
This is pretty barebones thus far as I haven't implemented any actual downloading/uploading of files yet.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
#include <curl/curl.h>

void clearScreen(){
	#ifdef _WIN32
		std::system("cls");
	#else
		std::system("clear");
	#endif
}

void menu(){
	// Main Menu
	clearScreen();	
	std::cout << "Your inventory information: \n\n" << std::endl;
	std::cout << "(1) Check latest inventory" << std::endl;
	std::cout << "(2) Update local inventory" << std::endl;
	std::cout << "(3) Download server inventory" << std::endl;
	std::cout << "(4) Check Archives" << std::endl;
	std::cout << "(5) Exit \n" << std::endl;
	std::cout << "Selection: ";
}

void miniMenu(){
	std::cout << "\n\n(1)Return Home, (2)Exit Program: ";
	int miniMenuSelection;
	std::cin >> miniMenuSelection;
	if (miniMenuSelection == 1){
		menu();
	}
	else {
		clearScreen();
	}
}

void checkInvt(){
	std::ifstream in("current.txt");
	std::string contents((std::istreambuf_iterator<char>(in)), 
	    std::istreambuf_iterator<char>());
	clearScreen();
	std::cout << contents << std::endl;
}

void updateInvt(){
	clearScreen();
	std::string file = "notepad.exe current.txt";
	system(file.c_str());
}

int main(){
	// Main Menu
	int menuSelection;
	menu();
	std::cin >> menuSelection;

	// Defining where a couple of often used paths are
	const char *const path = "stock/";
	const char *const file = "current.txt";

	// Check inventory. Displays what you currently have.
	if (menuSelection == 1){
		chdir ((path));
		checkInvt();
		miniMenu();
	}

	// Update what you currently have, local only, nothing server wise
	if (menuSelection == 2){
		chdir((path));
		updateInvt();
		checkInvt();
		miniMenu();
	}

	// Download server file 
	if (menuSelection == 3){
		clearScreen();

		CURL *curl;
		CURLcode res;

		curl = curl_easy_init();
		if(curl){
			curl_easy_setopt(curl, CURLOPT_URL, "http://sansassimports.com/current.txt");

			res = curl_easy_perform(curl);

			// Check for errors
			if (res != CURLE_OK){
				std::cerr << "Sorry, didn't work" << std::endl;
			}

			curl_easy_cleanup(curl);
			miniMenu();
		}


	} 

	// Exit program
	else{
		clearScreen();
	}

	return 0;
}
