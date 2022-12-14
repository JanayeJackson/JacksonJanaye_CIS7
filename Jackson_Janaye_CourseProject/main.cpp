/*
 * CIS 7 Course Project
 * File:   main.cpp
 * Author: Janaye Jackson
 * Created on: December 01, 2022
 * Purpose:  Encrypt and Decrypt messages using the Vinegere Cihper
 */

#include <iostream>
#include <string>
#include "Vigenere.h"

using namespace std;

int main()
{
	//Declare and initialize variable
	int choice;              //Menu choice
	string message, key;     //User message and key
	bool valid = false;      //Menu validation 

	//menu
	do {
		//Output menu
		cout << "Vigener Cipher Encryption/Decryption\n";
		cout << "Would you like to: \n";
		cout << "[1] Encrypt \n";
		cout << "[2] Decrypt \n";
		cout << "[3] Exit \n";

		//user choice
		cin >> choice;

		//validation
		if (choice >= 1 && choice <= 3)
			valid = true;
		else
			cout << "Please choose a valid option\n";
	} while (!valid);

	//Option 1 - Encrypt
	if (choice == 1) {
		//Get user menu and encryption key
		cout << "\nWhat message would you like to encrypt: ";
		cin >> message;
		cout << "What is the keyword: ";
		cin >> key;

		//Create Vinegere object
		Vigenere cipher(message, key);
		//Output encryped message
		cout << "\nYour encrypted message is: "<< cipher.encrypt() << endl;
	}
	//Option 2 - Decrypt
	else if (choice == 2)
	{
		//Get user messsage and decryption key
		cout << "\nWhat message would you like to decrypt: ";
		cin>>message;
		cout << "What is the keyword: ";
		cin >> key;

		//Create Vinegere object
		Vigenere cipher(message, key);
		//Output decrypted message
		cout << "\nYour decrypted message is: "<< cipher.decrypt() << endl;
	}
	//Option 3 - Exit
	else
	{
		cout << "You have choosen to exit. Goodbye."<<endl;
	}

	system("pause");
	return 0;
}