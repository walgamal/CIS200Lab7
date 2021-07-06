/*

Program Name: Lab7
Programmer Name: Wasim Algamal
Description: Sorts linked lists and shows occurences of each node
Date Created: 10/23/2020

*/

#include "listNodeHeader.h"

int main() {
     //declare all variables and open output file
     listNode* list1 = NULL;
     listNode* list2 = NULL;
     listNode* list3;

     string word1;
     string word2;

     ofstream outFile;
     outFile.open("OutPutFile.txt");


     //asks user for words
     cout << "Enter first word: ";
     outFile << "Enter first word: ";
     getline(cin, word1);
     outFile << word1 << endl;

     cout << "Enter second word: ";
     outFile << "Enter second word: ";
     getline(cin, word2);
     cout << endl;
     outFile << word2 << endl << endl;

     //sort lists and print them for the two words
     list1 = usingWord(word1);
     cout << "word 1: \n";
     outFile << "word 1: \n";
     printList(list1, outFile);

     list2 = usingWord(word2);
     cout << "word 2: \n";
     outFile << "word 2: \n";
     printList(list2, outFile);

     //combine the two lists and print the new sorted list
     list3 = combine(list1, list2);
     cout << "combined: \n";
     outFile << "combined: \n";
     printList(list3, outFile);

     outFile.close();

     return 0;
}
