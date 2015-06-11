/* This is a pretty simple program for me to work on that will give me some sort of idea on how to use curl/libcurl for downloading files from a network.
This is pretty barebones thus far as I haven't implemented any actual downloading/uploading of files yet.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <windows.h>
#include <curl/curl.h>

void menu(){
	// Main Menu
	system("cls");
	std::cout << "Your inventory information: \n\n" << std::endl;
	std::cout << "(1) Check latest inventory" << std::endl;
	std::cout << "(2) Update local inventory" << std::endl;
	std::cout << "(3) Update server inventory" << std::endl;
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
}

void checkInvt(){
	SetCurrentDirectory("stock");
	std::ifstream in("current.txt");
	std::string contents((std::istreambuf_iterator<char>(in)), 
	    std::istreambuf_iterator<char>());
	system("cls");
	std::cout << contents << std::endl;
}

void updateInvt(){
	system("cls");
	SetCurrentDirectory("stock");
	std::string file = "notepad.exe current.txt";
	system(file.c_str());
}

int main(){
	// Main Menu
	int menuSelection;
	menu();
	std::cin >> menuSelection;

	// Check inventory. Displays what you currently have.
	if (menuSelection == 1){
		checkInvt();
		miniMenu();
	}

	// Update what you currently have, local only, nothing server wise
	if (menuSelection == 2){
		updateInvt();
		checkInvt();
		miniMenu();
	}

	// Update 
	
	return 0;
}