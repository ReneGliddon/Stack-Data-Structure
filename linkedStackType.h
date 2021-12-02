#ifndef LINKEDSTACKTYPE_H
#define LINKEDSTACKTYPE_H
#include "stackADT.h"
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;
template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class linkedStackType: public stackADT<Type>
{
    public:
        const linkedStackType<Type>& operator= (const linkedStackType<Type>&);
        //Overload the assignment operator.
        bool isEmptyStack() const;
        //Function to determine whether the stack is empty.
        //Postcondition: Returns true if the stack is empty;
        // otherwise returns false.
        bool isFullStack() const;
        //Function to determine whether the stack is full.
        //Postcondition: Returns false.
        void initializeStack();
        //Function to initialize the stack to an empty state.
        //Postcondition: The stack elements are removed;
        // stackTop = NULL;
        void push(const Type& newItem);
        //Function to add newItem to the stack.
        //Precondition: The stack exists and is not full.
        //Postcondition: The stack is changed and newItem is
        // added to the top of the stack.
        Type top() const;
        //Function to return the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: If the stack is empty, the program
        // terminates; otherwise, the top element of
        // the stack is returned.
        void pop();
        //Function to remove the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: The stack is changed and the top
        // element is removed from the stack.
        linkedStackType();
        //Default constructor
        //Postcondition: stackTop = NULL;
        linkedStackType(const linkedStackType<Type>& otherStack);
        //Copy constructor
        ~linkedStackType();
        //Destructor
        //Postcondition: All the elements of the stack are removed.
        bool isInLanguageL();
        int size;
    private:
        nodeType<Type> *stackTop; //pointer to the stack
        void copyStack(const linkedStackType<Type>& otherStack);

        //Function to make a copy of otherStack.
        //Postcondition: A copy of otherStack is created and
        // assigned to this stack.
};

template<class Type>
bool linkedStackType<Type>::isInLanguageL()
{
    /*stack<char> myStack;

    string str = w;

    char c[str.size()+1];
    str.copy(c, str.size()+1);

    for(int i = 0; i<str.size(); i++)
    {
        myStack.push(c[i]);
    }*/

    if((this->size%2)==0)
        return false;

    int halfSize = this->size/2;

    for (int i = 0; i <halfSize;i++)
    {
        if(this->top()=='b')
            this->pop();
        else
            return false;
    }

    for(int i =0;i<halfSize+1;i++)
    {
        if(this->top()=='a')
            this->pop();
        else
            return false;
    }
    return true;
}

template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop=NULL;
}


template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return (stackTop==NULL);
}

template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type> *temp;
    while(stackTop!=NULL)
    {
        temp=stackTop;
        stackTop=stackTop->link;
        delete temp;
    }
}

template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type> *newNode;
    newNode = new nodeType<Type>;
    newNode->info = newElement;
    newNode->link = stackTop;
    stackTop= newNode;
}

template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop!=NULL);
    return stackTop->info;
}

template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type> * temp;
    if (stackTop!=NULL)
    {
        temp = stackTop;
        stackTop = stackTop->link;
        delete temp;
    }
    else
        cout<<"Cannot delete from an empty stack."<<endl;
}//end pop

template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack)
{
    nodeType<Type> *newNode, *current, *last;

    if(stackTop!=NULL)
        initializeStack();

    if(otherStack.stackTop==NULL)
        stackTop==NULL;
    else
    {
        current=otherStack.stackTop;
        stackTop = new nodeType<Type>;
        stackTop->info=current->info;
        stackTop->link=NULL;
        last = stackTop;
        current=current->link;

        while(current!=NULL)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = NULL;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

//copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
    stackTop = NULL;
    copyStack(otherStack);
}//end copy constructor

//destructor
template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}//end destructor

template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator= (const linkedStackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);
    return *this;
}//end operator=


#endif // LINKEDSTACKTYPE_H
