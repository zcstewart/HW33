//Homework 32

/* 
 * Filename:    main.cpp
 * Purpose:     Execution of program through inclusion of files.
 * 
 * Author:      Zachary Charles Stewart
 * Student ID:  105903414
 * Created on   March 22, 2017, 4:34 PM
 */

#include <cstdlib>
#include <iostream>
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
#include "linkedList.h"
using namespace std;

//--------------------------------------------------------------------------//
//
//Main Function
//
//Inputs:       int argc, char** argv
//Outputs:      int
//
//Purpose:      Main program file. Other necessary files are included here 
//              in order to be run

int main(int argc, char** argv) 
{
    orderedLinkedList<int> oList;
    unorderedLinkedList<int> uList;
    intLinkedList combinedList;
    intLinkedList evenList;
    intLinkedList oddList;
    int input;
    
    cout << "Enter numbers." << endl;
    cout << "Enter -999 to stop." << endl;
    cin >> input;
    
    while(input != -999)
    {
        oList.insertLast(input);
        uList.insertLast(input);
        combinedList.insertLast(input);
        cin >> input;
    }
    
    cout << endl << endl;
    
    cout << "Ordered List: " << endl;
    oList.print();
    cout << endl << endl;
    
    cout << "Unordered List: " << endl;
    uList.print();
    cout << endl << endl;
    
    cout << "Rotation: " << endl;
    oList.rotate();
    uList.rotate();
    
    cout << "Ordered List after Rotation: " << endl;
    oList.print();
    cout << endl << endl;
    cout << "Unordered List after Rotation: " << endl;
    uList.print();
    cout << endl << endl;
    
    cout << "Function to split even and odd numbers: " << endl << endl;
    combinedList.splitEvensOddsList(evenList, oddList);
    
    cout << "List with even numbers: " << endl;
    evenList.print();
    cout << endl << endl;
    cout << "List with odd numbers: " << endl;
    oddList.print();
    
    //Terminate program upon successful execution
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

