//Homework 33

/* 
 * Filename:        linkedStackADT.h
 * 
 * Purpose:         Definition and Implementation of linkedStackADT class.
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       April 3, 2017, 9:18 PM
 */

//--------------------------------------------------------------------------//

#ifndef LINKEDSTACKADT_H
#define LINKEDSTACKADT_H

//--------------------------------------------------------------------------//

#include <iostream>
#include "unorderedLinkedList.h"
using namespace std;
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

template <class Type>
void linkedStackType<Type>::initializeStack()
{
    unorderedLinkedList<Type>::initializeList();
}

template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return unorderedLinkedList<Type>::isEmptyList();
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    unorderedLinkedList<Type>::insertFirst(newElement);
}

template <class Type>
Type linkedStackType<Type>::top() const
{
    return unorderedLinkedList<Type>::front();
}

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> *temp;
    temp = first;
    first = first->link;
    delete temp;
}