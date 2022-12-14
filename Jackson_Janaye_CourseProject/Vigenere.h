/*
 * CIS 7 Course Project
 * File:   Vigenere.h
 * Author: Janaye Jackson
 * Created on: December 01, 2022
 * Purpose:  Encrypt and Decrypt messages using the Vigenere Cihper
 */

#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vigenere
{
private:
	string message, keyword;  //Strings to hold message and encryption/decryption key
	vector<int> key;          //Vector to hold shift key values

public:
	Vigenere(string, string); //Constructor
	void shiftKey();          //Create shift key values
	string encrypt();         //Encrypt message
	string decrypt();         //Decrypt message
};

#endif
