// HW 33
//
// File:            linkedStackType.h

// Date Created:    March 27, 2017, 9:08 PM
// Author:          Zachary Charles Stewart
// Purpose:         The purpose of this program is to 

//--------------------------------------------------------------------------//

//Preprocessor Directives
#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include <iostream>
#include "unorderedLinkedList.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class linkedStackType: public unorderedLinkedList<Type>
{
public:
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const Type& newItem);
    Type top() const;
    void pop();
};


//--------------------------------------------------------------------------//


template <class Type>
void linkedStackType<Type>::initializeStack()
{
    unorderedLinkedList<Type>::initializeList();
}

//--------------------------------------------------------------------------//

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return unorderedLinkedList<Type>::isEmptyList();
}

//--------------------------------------------------------------------------//

 
template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

//--------------------------------------------------------------------------//


template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    unorderedLinkedList<Type>::insertFirst(newElement);
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose: 
template <class Type>
Type linkedStackType<Type>::top() const
{
    return unorderedLinkedList<Type>::front();
}

//--------------------------------------------------------------------------//


template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;
    temp = (this->first);
    (this->first) = (this->first)->link;
    delete temp;
}

//--------------------------------------------------------------------------//

#endif /* LINKEDSTACKTYPE_H */

