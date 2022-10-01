// HW 33
//
// File:            main.cpp
// Date Created:    March 27, 2017, 7:55 PM
// Author:          Zachary Charles Stewart
// Purpose:         The purpose of this program is to 

//--------------------------------------------------------------------------//
//Preprocessor Directives
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include "linkedList.h"
#include "linkedStackType.h"
#include "linkedQueueType.h"


//Namespace
using namespace std;

//--------------------------------------------------------------------------//
//Function Prototypes

void run(linkedQueueType<char> &inQueue);

void shuntingYard(linkedStackType<char> &stack, 
                  linkedQueueType<char> &inQueue, 
                  linkedQueueType<char> &outQueue);

double postfix(linkedStackType<double> &stack, 
               linkedQueueType<char> &outQueue);

//--------------------------------------------------------------------------//
//Function:         main() function
//
//Inputs:           int argc, char** argv
//Outputs:          None
//Purpose:          The purpose of this program is to execute the main 
//                  program with included files, if any.

int main(int argc, char** argv) 
{
    linkedStackType<char> _Stack;
    linkedStackType<double> doubleStack;
    linkedQueueType<char> inQueue;

    linkedQueueType<char> outQueue;
    double answer = 0;
    char input[80];
    
    run(inQueue);

    
    shuntingYard(_Stack, inQueue, outQueue);
    linkedQueueType<char> copyQueue(outQueue);    
    answer = postfix(doubleStack, outQueue);
    
    cout << "Postfix Equation: ";
    copyQueue.print();
    cout << endl << endl;
    cout << "Answer: " << answer << endl << endl;
    
    //Terminate program upon successful completion
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      

void shuntingYard(linkedStackType<char>& stack, 
                  linkedQueueType<char>& inQueue, 
                  linkedQueueType<char>& outQueue)
{
    char temp1, temp2;
    while(!inQueue.isEmptyQueue())
    {
        temp1 = inQueue.front();
        if(temp1 == '0' || temp1 == '1' || temp1 == '2' || temp1 == '3' 
                       || temp1 == '4' || temp1 == '5' || temp1 == '6' 
                       || temp1 == '7' || temp1 == '8' || temp1 == '9')
        {
            outQueue.addQueue(temp1);
        }
        else if(temp1 == '-' || temp1 == '+' || temp1 == '/' || temp1 == '*' 
                            || temp1== '^')
        {
            while(!stack.isEmptyStack())
            { 
                temp2 = stack.top();
                
                if((temp1 == '/' || temp1 == '*') && 
                   (temp2 == '^' || temp2 == '/' || temp2 == '*'))
                {
                    stack.pop();
                    outQueue.addQueue(temp2);
                }
                if((temp1 == '+' || temp1 == '-') && (temp2 == '+' || 
                    temp2 == '-'|| temp2 == '*' || temp2 == '/' 
                                || temp2 == '^'))
                {
                    stack.pop();
                    outQueue.addQueue(temp2);
                }
            }
            stack.push(temp1);
        }

        if(temp1 == '(')
        {
           stack.push(temp1);
        }
        if(temp1 == ')')
        {
            temp2 = stack.top();
            while(temp2 != '(')
            {
                stack.pop();
                outQueue.addQueue(temp2);
                temp2 = stack.top();
            }
            stack.pop();
            if(stack.isEmptyStack())
            {
                exit(EXIT_FAILURE);
            }
        }
        inQueue.deleteQueue();
    }
    
    while(!stack.isEmptyStack())
    {
        temp1 = stack.top();
        if(temp1 == '(' || temp1 == ')')
        {
            cout << "Incorrect Expression!" << endl;
            cout << "Not enough/too many parentheses!" << endl;
        }
        else
        {
            stack.pop();
            outQueue.addQueue(temp1);
        }
    }
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      

double postfix(linkedStackType<double>& stack, 
               linkedQueueType<char>& outQueue)
{
    double input;
    char read; 
    double temp1, temp2;
    while(!outQueue.isEmptyQueue())
    {
        read = outQueue.front();
        if(read == '0' || read == '1' || read == '2' || read == '3' || 
           read == '4' || read == '5' || read == '6' || read == '7' || 
           read == '8' || read == '9')
        {
            switch(read)
            {
                case '0': 
                    input = 0;
                    break;
                case '1': 
                    input = 1;
                    break;
                case '2': 
                    input = 2;
                    break;
                case '3': 
                    input = 3;
                    break;
                case '4': 
                    input = 4;
                    break;
                case '5': 
                    input = 5;
                    break;
                case '6': 
                    input = 6;
                    break;
                case '7':
                    input = 7;
                    break;
                case '8':
                    input = 8;
                    break;
                case '9':
                    input = 9;
                    break;
                default:
                    input = 0;
                    break;
            }       
            stack.push(input);
            
        }
        else
        {
            if(read == '^')
            {
                temp1 = stack.top();
                stack.pop();
                if(!stack.isEmptyStack())
                {
                    cout << "Not enough tokens!" << endl;
                    exit(EXIT_FAILURE);
                }
                else
                {
                    temp2 = stack.top();
                    stack.pop();
                    stack.push((pow(temp2, temp1)));
                }
            }
            
            else if(read == '*')
            {
                temp1 = stack.top();
                stack.pop();
                if(stack.isEmptyStack())
                {
                    cout << "Not enough tokens!" << endl;
                    exit(EXIT_FAILURE);
                }
                else    
                {
                    temp2 = stack.top();
                    stack.pop();
                    stack.push((temp1 * temp2));
                }
            }
            
            else if(read == '/')
            {
                temp1 = stack.top();
                stack.pop();
                if(stack.isEmptyStack())
                {
                    cout << "Not enough tokens!" << endl;
                    exit(EXIT_FAILURE);
                }
                else
                {
                    temp2 = stack.top();
                    stack.pop();
                    if(temp2 == 0)
                    {
                        cout << "Cannot divide by zero!" << endl;
                        exit(EXIT_FAILURE);
                    }
                    else
                    {
                        stack.push((temp2 / temp1));
                    }
                }
                
                
            }
            else if(read == '+')
            {
                temp1 = stack.top();
                stack.pop();
                if(stack.isEmptyStack())
                {
                    cout << "Not enough tokens!" << endl;
                    exit(EXIT_FAILURE);
                }
                else
                {
                    temp2 = stack.top();
                    stack.pop();
                    stack.push((temp1 + temp2));
                }
            }
            else if(read == '-')
            {
                temp1 = stack.top();
                stack.pop();
                if(stack.isEmptyStack())
                {
                    cout << "Not enough tokens!" << endl;
                    exit(EXIT_FAILURE);
                }
                else
                {
                    temp2 = stack.top();
                    stack.pop();
                    stack.push((temp2 - temp1));
                    
                }
            }
            else
            {
                cout << "Wrong." << endl;
            }
            
        }
        outQueue.deleteQueue();
    }
    
    if(stack.isEmptyStack())
    {
        cout << "Incorrect Expression!" << endl;
        exit(EXIT_FAILURE);
    }
    else
    {
        temp1 = stack.top();
        stack.pop();
        if(!stack.isEmptyStack())
        {
            cout << "Incorrect Expression!" << endl;
            exit(EXIT_FAILURE);
        }
    }
    return temp1;
}

//--------------------------------------------------------------------------//

//Function:     
//
//Inputs:       
//Outputs:      
//Purpose:      

void run(linkedQueueType<char>& inQueue)
{
    char input[80];
    
    cout << "Enter a mathematical expression to evaluate: " << endl;
    cin >> input;
    int length;

    length = strlen(input);
    for(int i = 0; i < length; i++)
    {
        if(input[i] == '0' || input[i] == '1' || input[i] == '2' 
                           || input[i] == '3' || input[i] == '4' 
                           || input[i] == '5' || input[i] == '6' 
                           || input[i] == '7' || input[i] == '8' 
                           || input[i] == '9' || input[i] == '+' 
                           || input[i] == '-' || input[i] == '*' 
                           || input[i] == '/' || input[i] == '^')
        {
            inQueue.addQueue(input[i]);
        }
        cout << "Iteration: " << i << endl;
        cout << endl;
    }
}

//--------------------------------------------------------------------------//