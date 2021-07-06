/*

Program Name: Lab7
Programmer Name: Wasim Algamal
Description: Sorts linked lists and shows occurences of each node
Date Created: 10/23/2020

*/

#pragma once

using namespace std;
#include<iostream>
#include <fstream>
#include <string>

struct listNode {
     char letter;
     int occurences;
     listNode* next;
};
//struct holds variables associated with ever link list

//Description: Function updates passed string to all uppercase letters
//Pre-condition: user passes a string 
//Post-condition: all indexes of the string are updated to be uppercase
string toUpperFunc(string word) {
     for (int x = 0; x < word.size(); x++) {
          word[x] = toupper(word[x]);
     }

     return word;
}


//Description: Function updates a link list into a sorted linked list AND counts occurences
//Pre-condition: user passes a string 
//Post-condition: function returns an updated link list based on the passed string
listNode* usingWord(string word) {
     int alphaArray[26] = { 0 };         // has an element for each letter of the alphabet                   

     listNode* headNode = NULL;
     listNode* tempNode = NULL;

     word = toUpperFunc(word);           //updates word to uppercase letters

     for (int i = 0; i < word.length(); i++) {
          if (word[i] >= 'A' && word[i] <= 'Z') {     // increrments when letter is found, ignores any non-alpha chars
               alphaArray[word[i] - 'A']++;
          }
     }
     for (int i = 0; i < 26; i++) {

          listNode* node = new listNode;                     //inserts a node for every letter

          if (alphaArray[i] > 0) {                            // updates each letter if it occurs

               node->letter = 'A' + (i);
               node->occurences = alphaArray[i];
               node->next = NULL;

               if (headNode == NULL) {
                    headNode = node;
               }
               else {
                    tempNode->next = node;
               }

               tempNode = node;
          }

          node = NULL;
          delete node;

     }
     return headNode;
}

//Description: Function prints link list 
//Pre-condition: user passes listNode and the output file
//Post-condition: function prints to console AND output file
void printList(listNode* temp, ofstream& outFile) {
     if (temp == NULL) {
          cout << "Word is empty!\n\n";
          outFile << "Word is empty!\n\n";
          return;
     }

     while (temp != NULL) {
          cout << "'" << temp->letter << "' occured " << temp->occurences << " times;\n";
          outFile << "'" << temp->letter << "' occured " << temp->occurences << " times;\n";
          temp = temp->next;
     }
     cout << endl;
     outFile << endl;
}

//Description: Function combines two listNodes into one
//Pre-condition: user passes two link lists to be combined
//Post-condition: function returns new combined listNode
listNode* combine(listNode* list1, listNode* list2) {

     listNode* list3 = NULL;
     listNode* loc = NULL;
     listNode* preLoc = NULL;

     // if first list is empty, then return second list and vice versa
     if (list1 == NULL) {
          return list2;
     }
     if (list2 == NULL) {
          return list1;
     }

     list3 = list1;

     while (list1 != NULL && list2 != NULL) {
          if (list1->letter > list2->letter) {
               loc = list2->next;

               if (preLoc == NULL) {
                    list2->next = list1;
                    list3 = list2;
               }
               else {
                    list2->next = list1;
                    preLoc->next = list2;
               }

               preLoc = list2;
               list2 = loc;
          }
          else if (list1->letter < list2->letter) {
               preLoc = list1;
               list1 = list1->next;
          }
          else {
               preLoc = list1;
               list1->occurences = list1->occurences + list2->occurences;
               list1 = list1->next;
               list2 = list2->next;
          }
     }
     return list3;
}
