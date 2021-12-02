#ifndef STACKTYPE_H
#define STACKTYPE_H

#include <iostream>
#include <cassert>
#include "stackADT.h"

using namespace std;


template <class Type>
class stackType: public stackADT<Type>
{
    public:
        const stackType<Type>& operator=(const stackType<Type>&);
        //Overload the assignment operator.
        void initializeStack();
        //Function to initialize the stack to an empty state.
        //Postcondition: stackTop = 0;
        bool isEmptyStack() const;
        //Function to determine whether the stack is empty.
        //Postcondition: Returns true if the stack is empty,
        // otherwise returns false.
        bool isFullStack() const;
        //Function to determine whether the stack is full.
        //Postcondition: Returns true if the stack is full,
        // otherwise returns false.
        void push(const Type& newItem);
        //Function to add newItem to the stack.
        //Precondition: The stack exists and is not full.
        //Postcondition: The stack is changed and newItem is
        // added to the top of the stack.
        Type top() const;
        //Function to return the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: If the stack is empty, the program terminates; otherwise, the top element of the stack
        // is returned.
        void pop();
        //Function to remove the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: The stack is changed and the top element is
        // removed from the stack.
        stackType(int stackSize = 100);
        //Constructor
        //Create an array of the size stackSize to hold
        //the stack elements. The default stack size is 100.
        //Postcondition: The variable list contains the base address
        // of the array, stackTop = 0, and maxStackSize = stackSize
        stackType(const stackType<Type>& otherStack);
        //Copy constructor
        ~stackType();
        //Destructor
        //Remove all the elements from the stack.
        //Postcondition: The array (list) holding the stack
        // elements is deleted.
        bool sameStack (stackType<Type> w);
        bool arrayIsInLanguageL(string w);
        int getStackTop();
    private:
        int maxStackSize; //variable to store the maximum stack size
        int stackTop; //variable to point to the top of the stack
        Type *list; //pointer to the array that holds the stack elements
        void copyStack(const stackType<Type>& otherStack);
        //Function to make a copy of otherStack.
        //Postcondition: A copy of otherStack is created and assigned
        // to this stack.
};

template<class Type>
int stackType<Type>::getStackTop()
{
    return stackTop;
}
template<class Type>
bool stackType<Type>::arrayIsInLanguageL(string w)
{
    bool isInLanguage;

    stack<char> firstStack;
    stack<char> myStack;

    string str = w;

    char c[str.size()+1];
    str.copy(c, str.size()+1);

    for(int i = 0; i<str.size(); i++)
    {
        firstStack.push(c[i]);
    }


   /* for(int i = 0; i<str.size();i++)
    {
        char entry = firstStack.top();
        myStack.push(entry);
        firstStack.pop();
    }*/

    int size = str.size();
    cout<<endl<<"the size is "<<size;

    int halfSize = size/2;

    cout<<endl<<"the halfsize is "<<halfSize;

    if (size%2 == 0)
    {
        cout<<endl<<"modulus == 0";
        return false;
    }
    else
        cout<<endl<<"size is "<<size;
        cout<<endl<<" half size plus 1 is "<<halfSize+1;
    {
        for(int i = 0; i<halfSize+1; i++)
        {
             cout<<endl<<"We are at index "<<i;
            if (firstStack.top() == 'b')
            {
                cout<<endl<<"its a b.";
                isInLanguage=true;
                firstStack.pop();
            }
            else if(firstStack.top() != 'b')
            {
                cout<<endl<<"supposed to be 'b' but isn't";
                isInLanguage=false;
                return isInLanguage;
            }
        }
        for(int i = 0; i<halfSize; i++)
        {
            cout<<endl<<"We are at index "<<i;
            if(firstStack.top()=='a')
            {
                cout<<endl<<"it's an a";
                isInLanguage=true;
                firstStack.pop();
            }

            else if(firstStack.top()!='a')
            {
                cout<<endl<<"This was supposed to be 'a' but is not.";
                isInLanguage=false;
                return isInLanguage;
            }
        }
    }

    return isInLanguage;

}
template <class Type>
bool stackType<Type>::sameStack (stackType<Type> w)
{
    bool same=true;

    while(w.stackTop>0 && same)
    {
        if((list[stackTop])!=(w.list[stackTop]))
        {
            same = false;
            return false;
        }

        else if ((list[stackTop])==(w.list[stackTop]))
        {
            stackTop--;
            w.stackTop--;

        }

    }
    same = true;
    return same;
}

template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}//end initializeStack

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return(stackTop == 0);
}//end isEmptyStack

template <class Type>
bool stackType<Type>::isFullStack() const
{
    return(stackTop==maxStackSize);
}

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if(!isFullStack())
    {
        list[stackTop]= newItem;
        stackTop++;
    }
    else
        cout<<"Cannot add to a full stack."<<endl;
}//end ppush

template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop!=0);
    return list[stackTop-1];
}//end top

template <class Type>
void stackType<Type>::pop()
{
    if(stackTop!=0)
    {
        stackTop--;
    }
    else
        cout<<"Cannot remove from an empty stack."<<endl;
}//end pop


template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;
    list = new Type[maxStackSize];
    //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack

template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout<<"Size of the array must be positive. "<<endl;
        cout<<"Creating an array of size 100."<<endl;
        maxStackSize = 100;
    }
    else
    {
        maxStackSize=stackSize;
    }

    stackTop=0;
    list = new Type[maxStackSize];
}//end constructor

template <class Type>
stackType<Type>::~stackType()//destructor
{
    delete [] list;
}//end destructor

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = NULL;
    copyStack(otherStack);
}//end copy constructor

template <class Type>
const stackType<Type>& stackType<Type>::operator= (const stackType<Type>& otherStack)
{
    if(this!=&otherStack)
        copyStack(otherStack);
    return *this;
}
#endif // STACKTYPE_H
