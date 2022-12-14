/*
 * CIS 7 Course Project
 * File:   Vigenere.cpp
 * Author: Janaye Jackson
 * Created on: December 01, 2022
 * Purpose:  Encrypt and Decrypt messages using the Vigenere Cihper
 */

#include "Vigenere.h"


 //Constructor
Vigenere::Vigenere(string tmp1, string tmp2)
{
	//Declare and initialize variables 
	message = tmp1;     //Initiallize message to be encrypted
	keyword = tmp2;     //Initiallize encryption/decryption key
}

//Create full shift key to be used in encryption/decryption
void Vigenere::shiftKey()
{
	int m = 0;
	char tmp;

	//Add shift key value for each character in key
	for (int i = 0; i < message.length(); i++)
	{
		tmp = keyword[m];
		m++;

		//lowercase letter
		if (isupper(tmp))
			key.push_back(int(tmp - 65));
		//upper case letter
		else
			key.push_back(int(tmp - 97));

		//Start back at first letter of keyword
		if (m == keyword.length())
			m = 0;
	}
}

//Encrypt message
string Vigenere::encrypt()
{
	//Declare and initialize variable
	string tmp = "";

	shiftKey();           //Create shift key

	//Shift each letter in message
	for (int i = 0; i < message.length(); i++)
	{
		if (isupper(message[i]))
			tmp += char(int(message[i] + key[i] - 65) % 26 + 65);
		else
			tmp += char(int(message[i] + key[i] - 97) % 26 + 97);
	}

	//return encrypted message
	return tmp;
}


//Decrypt message 
string Vigenere::decrypt()
{
	//Declare and initialize variable
	string tmp = "";

	shiftKey();          //Create shift key


	//Shift each letter in message
	for (int i = 0; i < message.length(); i++)
	{
		if (isupper(message[i]))
			tmp += char(int(message[i] - key[i] + 65) % 26 + 65);
		else
			tmp += char(int(message[i] - key[i] + 97) % 26 + 97);
	}

	//return decrypted message
	return tmp;
}