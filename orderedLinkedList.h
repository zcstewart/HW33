//Homework 32

/* 
 * Filename:        orderedLinkedList.h
 * Purpose:         Definition and Implementation of orderedLinkedList
 *                  class
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       March 22, 2017, 8:43 PM
 */

#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H

//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include "linkedList.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//


template <class Type>
class orderedLinkedList: public linkedListType<Type>
{
    public:
        bool search(const Type& searchItem) const;
        //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the list,
        //otherwise the value false is returned.
        void insert(const Type& newItem);
        //Function to insert newItem in the list.
        //Postcondition: first points to the new list, newItem
        //is inserted at the proper place in the
        //list, and count is incremented by 1.
        void insertFirst(const Type& newItem);
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is
        //inserted at the proper place in the list,
        //last points to the last node in the
        //list, and count is incremented by 1.
        void insertLast(const Type& newItem);
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem is
        //inserted at the proper place in the list,
        //last points to the last node in the
        //list, and count is incremented by 1.
        void deleteNode(const Type& deleteItem);
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing
        //deleteItem is deleted from the list;
        //first points to the first node of the
        //new list, and count is decremented by 1.
        //If deleteItem is not in the list, an
        //appropriate message is printed.
};

//Function:     bool search(const Type& searchItem) const
//
//Inputs:       const Type& searchItem
//Outputs:      Returne type bool
//Purpose:      The purpose of this function is to search a linked list of 
//              type orderedLinkedList<Type> for a node whose member variable
//              info is equal to Type searchItem, the formal parameter
//              argument passed by reference. 
//              This is accomplished by creating a temporary pointer
//              *current of type nodeType<Type>. A boolean 'flag' variable
//              'found' is initialized to false. A loop traverses through the
//              list so long as current is not equal to 'nullptr' and found
//              is false. If the current nodes info member variable is equal
//              to the formal parameter argument searchItem, found is set to
//              true and the loop is terminated. Otherwise, current skips to
//              the next node. The value of found is returned. True is
//              returned if found, otherwise false is returned. 
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
bool orderedLinkedList<Type>::search(const Type& searchItem) const
{
    bool found = false;
    nodeType<Type> *current;
    
    current = this->first;
    
    while (current !=nullptr && !found)
        if (current->info >= searchItem)
            found = true;
        else 
            current = current->link;
    if (found)
        found = (current->info == searchItem);
    
    return found;
}

//Function:     void insert(const Type& newItem)
//
//Inputs:       const Type& newItem
//Outputs:      Return type void
//Purpose:      The purpose of this function is to insert a node of type
//              nodeType<Type> into a linked list of type 
//              orderedLinkedList<Type>. The function will create a new node,
//              and assign field the value passed in the formal parameter
//              argument of Type newItem (passed by reference).
template<class Type>
void orderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    nodeType<Type> *newMode;
    
    bool found;
    
    newMode = new nodeType<Type>;
    newMode ->info = newItem;
    newMode->link = nullptr;
    
    if (this->first == nullptr)
    {
        this->first = newMode;
        this->last = newMode;
        this->count++;
    }
    else 
    {
        current = this->first;
        found = false;
        
        while (current != nullptr && !found)
        {
            if (current->info >= newItem)
                found = true;
            else 
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == this->first)
        {
            newMode->link = this->first;
            this->first = newMode;
            linkedListType<Type>::count++;
        }
        else
        {
            trailCurrent->link = newMode;
            newMode->link= current;
            if (current == nullptr)
                this->last = newMode;
            this->count++;
        }
    }//end else
}// end insert

//Function:     void insertFirst(const Type& newItem)
//
//Inputs:       const Type& newItem
//Outputs:      Return type void
//Purpose:      The purpose of this function is to insert a node of type
//              nodeType<Type> into the beginning of a linked list of type 
//              orderedLinkedList<Type>. The function will call the
//              insert(newItem) function. Because the list is an
//              ordered linked list, the predefined insert(newItem) function
//              will automatically insert the node into its appropriate
//              position based on its order.
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
void orderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    insert(newItem);
}//end insertFirst

//Function:     void insertLast(const Type& newItem)
//
//Inputs:       const Type& newItem
//Outputs:      Return type void
//Purpose:      The purpose of this function is to insert a node of type
//              nodeType<Type> into the end of a linked list of type 
//              orderedLinkedList<Type>. The function will call the
//              insert(newItem) function. Because the list is an
//              ordered linked list, the predefined insert(newItem) function
//              will automatically insert the node into its appropriate
//              position based on its order.
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
void orderedLinkedList<Type>::insertLast(const Type& newItem)
{
    insert(newItem);
}//end insertLast

//Function:     void deleteNode(const Type& deleteItem)
//
//Inputs:       const Type& deleteItem
//Outputs:      Return type void
//Purpose:      The purpose of this function is to delete an node of type
//              nodeType<Type> from the ordered linked list. The function
//              will traverse the list, examining the list member functions
///             of each node. If the list member function
//
//              NOTE: This function is the implementation of the pure virtual
//                    function declared in the linkedListType class.
template <class Type>
void orderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent;
    bool found;
    
    if (this->first == nullptr)
        cout << "Cannot delete from an empty list. "<< endl;
    else 
    {
        current = this->first;
        found = false;
        
        while (current != nullptr && !found)
        {
            if (current->info >=deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == nullptr)
            cout << "The item to be deleted is not in the list." << endl;
        else
            if (current->info == deleteItem)
            {
                if(this ->first == current)
                {
                    this->first = this->first->link;
                    if (this->first == nullptr)
                        this->last = nullptr;
                    delete current;
                }
                else 
                {
                    trailCurrent->link = current->link;
                    
                    if (current == this->last)
                        this->last = trailCurrent;

                    delete current;
                }
                this->count--;
            }
            else 
                cout << "The item to be deleted is not in the list." << endl;    
    }
}// end deleteNode

//--------------------------------------------------------------------------//

#endif /* ORDEREDLINKEDLIST_H */

