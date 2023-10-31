#include <iostream>
using namespace std;
#include <ctype.h>
#include <string>

/*
Omar Essam Hegazy
*/

int main()
{

    string plainText, keyword, englishAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int keywordLength, letterLength = 0, plainTextLength;
    int *keywordNum, *ciphertextNum, *plainNum;
    char *ciphertext;
    // Get the plaintext from the user
    cout << "Enter the plaintext: ";
    getline(cin, plainText);
    plainTextLength = plainText.length();
    // Get the keyword from the user
    cout << "\nEnter the keyword: ";
    cin >> keyword;
    keywordLength = keyword.length();
    // Counting the letters in the plaintext, only letter
    for (size_t i = 0; i < plainTextLength; i++)
        if (isalpha(plainText[i]))
            letterLength++;
    // Initializing variables
    keywordNum = new int[keywordLength];
    ciphertext = new char[letterLength];
    ciphertextNum = new int[letterLength];
    plainNum = new int[letterLength];
    // finding the numerical representation for the keyword
    for (size_t i = 0; i < keywordLength; i++)
        keywordNum[i] = englishAlphabet.find(toupper(keyword[i]));
    for (size_t i = 0, counter = 0; i < plainTextLength; i++)
    {
        if (isalpha(plainText[i]))
        {
            plainNum[counter] = englishAlphabet.find(toupper(plainText[i]));
            ciphertextNum[counter] = ((keywordNum[(counter % keywordLength)] + plainNum[counter]) % 26);
            ciphertext[counter] = englishAlphabet[ciphertextNum[counter]];
            counter++;
        }
    }
    int option;
    // Menu
    cout<<"====================== Credit to : Omar Essam Hegazy =========================";
    while (true)
    {
        cout << "\nChoose the option\n [1] display the Numerical keywords\n [2] display the Numerical plaintext \n [3] display the numerical ciphertext \n [4] display the ciphertext \n [5] exit \n";
        cout << "Your option : ";
        cin >> option;
        cout<<"-------------------------\n";
        if(option == 1) { // display the Numerical keywords
            for (size_t i = 0; i < keywordLength; i++)
                cout<<keywordNum[i]<<" ";
        }

        else if(option == 2){ // display the Numerical plaintext
            for (size_t i = 0; i < letterLength; i++)
                cout<<plainNum[i]<<" ";
        }
        else if(option == 3){ // display the Numerical ciphertext
            for (size_t i = 0; i < letterLength; i++)
                cout<<ciphertextNum[i]<<" ";
        }
        else if(option == 4){ // display the ciphertext
            for (size_t i = 0; i < letterLength; i++)
                cout<<ciphertext[i]<<" ";
        }
        else break;
        cout<<"\n-------------------------";
    }
    // Deallocate memory
    delete[] keywordNum;
    delete[] ciphertextNum;
    delete[] plainNum;
    delete[] ciphertext;
}