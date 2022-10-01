//Homework 34

/* 
 * Filename:        linkedLIst.h
 * Purpose:         Definition and Implementation of linkedListType
 *                  class
 * 
 * Author:          Zachary Charles Stewart
 * Student ID:      105903414
 * Created on       March 23, 2017, 9:52 AM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <assert.h>

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

//Structure implementation of nodeType of type <Type>
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

template <class Type>
class linkedListIterator
{
    public:
        linkedListIterator();
        //Default constructor.
        //Postcondition: current = nullptr;
        linkedListIterator(nodeType<Type> *ptr);
        //Constructor with a parameter.
        //Postcondition: current = ptr;
        Type operator*();
        //Function to overload the dereferencing operator *.
        //Postcondition: Returns the info contained in the node.
        linkedListIterator<Type> operator++();
        //Overload the pre-increment operator.
        //Postcondition: The iterator is advanced to the next
        //node.
        bool operator==(const linkedListIterator<Type>& right) const;
        //Overload the equality operator.
        //Postcondition: Returns true if this iterator is equal to
        //the iterator specified by right,
        //otherwise it returns false.
        bool operator!=(const linkedListIterator<Type>& right) const;
        //Overload the not equal to operator.
        //Postcondition: Returns true if this iterator is not equal
        //to the iterator specified by right,
        //otherwise it returns false.
    private:
        nodeType<Type> *current; //pointer to point to the current
        //node in the linked list
};

//------------------------------------------------------------------------- //
//Member Function Implementations:

//Function:     linkedListIterator()
//
//Inputs:       None
//Outputs:      None, Constructor Implementation
//Purpose:      The purpose of this function is to define the default 
//              constructor for an object of the linkedListIterator class.
template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}

//Function:     linkedListIterator(nodeType<Type> *ptr)
//
//Inputs:       nodeType<Type> *ptr
//Outputs:      None, Constructor Implementation
//Purpose:      The purpose of this function is to define the
//              linkedListIterator constructor with a formal paramater of
//              nodeType<Type> *ptr.
template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr)
{
    current = ptr;
}

//Function:     Type operator*()
//
//Inputs:       None
//Outputs:      Return type Type
//Purpose:      The purpose of this function is to overload the dereferencing
//              operator (*).
//              The function will return the private member variable info
//              of type Type pointed to by the linkedListIterator private
//              member variable pointer *current (type nodeType<Type>).
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}

//Function:     linkedListIterator<Type> operator++()
//
//Inputs:       None
//Outputs:      Return type linkedListIterator<Type>
//Purpose:      The purpose of this function is to overload the 
//              post-increment operator (++linkedListIterator<Type>). 
//              The function will set the linkedListIterator private member 
//              variable pointer *current (type nodeType<Type>) to the node
//              pointed to by the link pointer. This effectively advances
//              the iterator up the linked list by one.
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}

//Function:     bool operator==(const linkedListIterator<Type>& right) const
//
//Inputs:       const linkedListIterator<Type>& right
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to overload the equality 
//              operator for the linkedListIterator<Type> class.
//              The address of current will be compared to the address of 
//              right.current (current value for object passed in formal
//              parameter argument). The function will return true if equal
//              false otherwise.
template <class Type>
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}

//Function:     bool operator!=(const linkedListIterator<Type>& right) const
//
//Inputs:       const linkedListIterator<Type>& right
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to overload the inequality
//              operator for the linkedListIterator<Type> class.
//              The address of current will be compared to the address of 
//              right.current (current value for object passed in formal
//              parameter argument). The function will return false if equal
//              true otherwise.
template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//


template <class Type>
class linkedListType
{
    public:
        const linkedListType<Type>& operator=(const linkedListType<Type>&);
        //Overload the assignment operator.

        void initializeList();
        //Initialize the list to an empty state.
        //Postcondition: first = nullptr, last = nullptr, count = 0;

        bool isEmptyList() const;
        //Function to determine whether the list is empty.
        //Postcondition: Returns true if the list is empty,
        //otherwise it returns false.

        void print() const;
        //Function to output the data contained in each node.
        //Postcondition: none

        int length() const;
        //Function to return the number of nodes in the list.
        //Postcondition: The value of count is returned.

        void destroyList();
        //Function to delete all the nodes from the list.
        //Postcondition: first = nullptr, last = nullptr, count = 0;

        Type front() const;
        //Function to return the first element of the list.
        //Precondition: The list must exist and must not be
        //empty.
        //Postcondition: If the list is empty, the program
        //terminates; otherwise, the first
        //element of the list is returned.

        Type back() const;
        //Function to return the last element of the list.
        //Precondition: The list must exist and must not be
        //empty.
        //Postcondition: If the list is empty, the program
        //terminates; otherwise, the last
        //element of the list is returned.

        virtual bool search(const Type& searchItem) const = 0;
        //Function to determine whether searchItem is in the list.
        //Postcondition: Returns true if searchItem is in the
        //list, otherwise the value false is
        //returned.

        virtual void insertFirst(const Type& newItem) = 0;
        //Function to insert newItem at the beginning of the list.
        //Postcondition: first points to the new list, newItem is
        //inserted at the beginning of the list,
        //last points to the last node in the list,
        //and count is incremented by 1.

        virtual void insertLast(const Type& newItem) = 0;
        //Function to insert newItem at the end of the list.
        //Postcondition: first points to the new list, newItem
        //is inserted at the end of the list,
        //last points to the last node in the list,
        //and count is incremented by 1.

        virtual void deleteNode(const Type& deleteItem) = 0;
        //Function to delete deleteItem from the list.
        //Postcondition: If found, the node containing
        //deleteItem is deleted from the list.
        //first points to the first node, last
        //points to the last node of the updated
        //list, and count is decremented by 1.

        linkedListIterator<Type> begin();
        //Function to return an iterator at the begining of the
        //linked list.
        //Postcondition: Returns an iterator such that current is
        //set to first.

        linkedListIterator<Type> end();
        //Function to return an iterator one element past the
        //last element of the linked list.
        //Postcondition: Returns an iterator such that current is
        //set to nullptr.

        linkedListType();
        //default constructor
        //Initializes the list to an empty state.
        //Postcondition: first = nullptr, last = nullptr, count = 0;

        linkedListType(const linkedListType<Type>& otherList);
        //copy constructor

        ~linkedListType();
        //destructor
        //Deletes all the nodes from the list.
        //Postcondition: The list object is destroyed.
        
        void rotate();
        // Function to remove the first node of a linked list and
        // put it at the end of the linked list

    protected:
        int count;
        //variable to store the number of
        //elements in the list

        nodeType<Type> *first; //pointer to the first node of the list
        nodeType<Type> *last; //pointer to the last node of the list
    private:
        void copyList(const linkedListType<Type>& otherList);
        //Function to make a copy of otherList.
        //Postcondition: A copy of otherList is created and
        //assigned to this list.
};

//--------------------------------------------------------------------------//
//--------------------------------------------------------------------------//

//Member Function Implementations

//Function:     bool isEmptyList() const
//
//Inputs:       None
//Outputs:      Return type bool
//Purpose:      The purpose of this function is to determine whether the
//              list contained by the linkedListType<Type> class is empty.
//              The function will determine the value of the protected member
//              variable first. The function will return true if first is
//              a null pointer. Otherwise, it returns false.
template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}

//Function:    linkedListType()
//
//Inputs:       None
//Outputs:      None, Constructor implementation
//Purpose:      The purpose of this function is to define the default
//              constructor implementation of an object of type 
//              linkedListType<Type>. The protected member variable pointers
//              first and last are assigned the value of 'nullptr', and count
//              is assigned the value of 0.
template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
    first = nullptr;
    last = nullptr;
    count = 0;
}

//Function:     void destroyList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to define the implementation
//              of the destroyList() function. The function will create a
//              pointer to a nodeType<Type> object. The function will delete
//              each node in the list individually. The pointer temp is
//              assigned the value of the pointer first. The pointer first
//              is advanced to the node it points to, and the temporary 
//              pointer is destroyed with the 'delete' keyword. This occurs
//              while first is not equal to 'nullptr'. When first = nullptr
//              the loop exits, sets last to 'nullptr', and sets count to 0.
template <class Type>
void linkedListType<Type>::destroyList()
{
    nodeType<Type> *temp;
    //pointer to deallocate the memory
    //occupied by the node

    while (first != nullptr) //while there are nodes in the list
    {
        temp = first;
        //set temp to the current node
        first = first->link; //advance first to the next node
        delete temp;
        //deallocate the memory occupied by temp
    }
    last = nullptr; //initialize last to nullptr; first has already
    //been set to nullptr by the while loop
    count = 0;
}

//Function:     void initializeList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to initialize the list,
//              which is effectively deleting the list. This is accomplished
//              by calling the function destroyList().
template <class Type>
void linkedListType<Type>::initializeList()
{
    destroyList(); //if the list has any nodes, delete them
}

//Function:     void print() const
//
//Inputs:       None
//Outputs:      Return type void
//Purpose:      The purpose of this function is to print all of the
//              nodeType<Type> objects of the linkedListType<Type> class.
//              a pointer of type nodeType<Type> named *current was created.
//              The pointer will print the contents of info (accessed by
//              current->info), then advance current to the next 
//              nodeType<Type> object that it points to. The function will
//              continue to print the contents of current and advance the
//              node until current equals 'nullptr' (current is the last
//              node).
template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current;
    //pointer to traverse the list
    current = first;
    //set current so that it points to
    //the first node
    while (current != nullptr) //while more data to print
    {
        cout << current->info << " ";
        current = current->link;
    }
}

//Function:     int length() const
//
//Inputs:       None
//Outputs:      Return type int
//Purpose:      
template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}

//Function:     Type front() const
//
//Inputs:       None
//Outputs:      Return type Type
//Purpose:      The purpose of this function is to return the data saved
//              in the protected member variable info at the front of the 
//              list. The function will only proceed if the list isn't 
//              empty. It returns the value of info, which is of type Type.
template <class Type>
Type linkedListType<Type>::front() const
{
    assert(first != nullptr);
    return first->info; //return the info of the first node
}//end front

//Function:     Type back() const
//
//Inputs:       None
//Outputs:      Return type Type
//Purpose:      The purpose of this function is to return the data saved
//              in the protected member variable info at the back of the 
//              list. The function will only proceed if the list isn't 
//              empty. It returns the value of info, which is of type Type.
template <class Type>
Type linkedListType<Type>::back() const
{
    assert(last != nullptr);
    return last->info; //return the info of the last node
}//end back

//Function:     linkedListIterator<Type> begin()
//
//Inputs:       None
//Outputs:      Return Type linkedListIterator<Type>
//Purpose:      The purpose of this function is is to return an iterator
//              to the beginning of the linked list. A linkedListType<Type>
//              object temp is created with the passed in value of the pointer
//              first. The pointer temp is returned
template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
    linkedListIterator<Type> temp(first);
    return temp;
}

//Function:     linkedListIterator<Type> end()
//
//Inputs:       None
//Outputs:      Return Type linkedListIterator<Type>
//Purpose:      The purpose of this function is to reutn an iterator to the
//              end of the linked list. A linkedListType<Type> object temp is
//              created with the passed in value of 'nullptr', and the pointer
//              temp is returned.
template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
    linkedListIterator<Type> temp(nullptr);
    return temp;
}

//Function:     void copyList(const linkedListType<Type>& otherList)
//
//Inputs:       const linkedListType<Type>& otherList
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to copy the list of a
//              linkedListType object into the linkedListType object
//              calling the function.
template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
    nodeType<Type> *newNode;
    //pointer to create a node
    nodeType<Type> *current;
    //pointer to traverse the list
    
    if (first != nullptr) //if the list is not empty, make it empty
        destroyList();
    
    if (otherList.first == nullptr)//otherList is empty
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else 
    {
        current = otherList.first;
        //current points to the list to be copied
        
        count = otherList.count;
        
        //copy the first node and create the node
        first = new nodeType<Type>;
        first->info = current->info;
        //copy the info
        first->link = nullptr;
        //set the link field of the node to NULL
        last = first;
        //make last point to the first node
        current = current->link;
        //make current point to the next node
        
        while (current != nullptr)//copy the remaining list
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            
            last -> link = newNode;
            //attach newNode after last
            last = newNode;
            //make last point to the actual last node
            current = current->link;
            //make current point to the next node
            
        }//end while         
    }//end else
}//end copyList

//Function:     ~ linkedListType()
//
//Inputs:       None
//Outputs:      None, destructor implementation
//Purpose:      The purpose of this function is to define the destructor
//              implementation of the linkedListType<Type> class. This is 
//              accomplished by invoking its own destroyList() function.
template <class Type>
linkedListType<Type>:: ~ linkedListType() //destructor
{
    destroyList();
}

//Function:     linkedListType(const linkedListType<Type>& otherList)
//
//Inputs:       const linkedListType<Type>& otherList
//Outputs:      None, Copy Constructor
//Purpose:      The purpose of this function is to define the implementation
//              of the copy constructor. The first pointer is set to null,
//              and the copyList(otherList) function is called. This copies
//              the values of the object of the formal parameter argument
//              into the values of the object calling the function.
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
    first = nullptr;
    copyList(otherList);
}//end copy constructor

//Function:     const linkedListType<Type>& 
//              operator=(const linkedListType<Type>& otherList)
//
//Inputs:       const linkedListType<Type>& otherList
//Outputs:      linkedListType<Type>&
//Purpose:      The purpose of this function is to overload the assignment
//              operator for the linkedListType<Type> class. The object will
//              be checked to ensure it won't self copy. It will then call
//              the copyList(otherLast) function of the linkedListType class.
//              This would effectively copy the values of the formal
//              parameter argument into the object calling the function.
template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
    if (this != &otherList) //avoid self-copy
    {
        copyList(otherList);
    }//end else
    
    return *this;
}

//Function:     void rotate()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to "rotate" the order of the
//              items in the linked list. The node that last points to will
//              be assigned to point to the node that first points to.
//              The first node will be advanced by one, and the last node will
//              by one. This is, in effect, a "circular" linked list.
//              Finally, the link pointer of the node pointed to will be set
//              to null to undo the circular list and make it a linear list.
template <class Type>
void linkedListType<Type>::rotate()
{
    last->link = first;
    first = first->link;
    last = last->link;
    last->link = nullptr; 
}
//--------------------------------------------------------------------------//


#endif /* LINKEDLIST_H */


