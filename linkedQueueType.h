// HW 33
//
// File:            linkedQueueType.h

// Date Created:    March 27, 2017, 9:09 PM
// Author:          Zachary Charles Stewart
// Purpose:         The purpose of this program is to 

//--------------------------------------------------------------------------//

//Preprocessor Directives
#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H
#include <iostream>
#include "unorderedLinkedList.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class linkedQueueType: public unorderedLinkedList<Type>
{
public:
    void initializeQueue();
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void addQueue(const Type& queueElement);
    Type front() const;
    Type back() const;
    void deleteQueue();
};


template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    unorderedLinkedList<Type>::initializeList();
}

//--------------------------------------------------------------------------//
     
template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return unorderedLinkedList<Type>::isEmptyList();
}

//--------------------------------------------------------------------------//
     
template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
}

//--------------------------------------------------------------------------//
     
template <class Type>
void linkedQueueType<Type>::addQueue(const Type& queueElement)
{
    unorderedLinkedList<Type>::insertLast(queueElement);
}

//--------------------------------------------------------------------------//

template <class Type>
Type linkedQueueType<Type>::front() const
{
    unorderedLinkedList<Type>::front();
}

//--------------------------------------------------------------------------//

template <class Type>
Type linkedQueueType<Type>::back() const
{
    unorderedLinkedList<Type>::back();
}

//--------------------------------------------------------------------------//

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;
    temp = (this->first);
    (this->first) = (this->first)->link;
    delete temp;
}

//--------------------------------------------------------------------------//


#endif /* LINKEDQUEUETYPE_H */

