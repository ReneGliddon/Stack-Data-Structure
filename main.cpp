#include <iostream>
#include "linkedStackType.h"
#include "stackType.h"
#include <string>
using namespace std;

void testCopy(linkedStackType<int> OStack);

template <class Type>
bool sameStack (stackType<Type> s, stackType<Type> w)
{
    bool same=true;

    //first let's check if one or both are empty and evaluate whether they are the same in that condition
    //one if empty, one is not: not the same
    if(s.getStackTop()==NULL&&(w.getStackTop()!=NULL))
       {
           same = false;
            return same;
       }
    else if(s.getStackTop()!=NULL&&(w.getStackTop()==NULL))
       {
           same = false;
            return same;
       }
       //if they are both empty then they are equal
    else if(s.getStackTop()==NULL&&(w.getStackTop()==NULL))
       {
           same = true;
            return same;
       }

    while(w.getStackTop()>0 && s.getStackTop()>0 && same)
    {
        if((s.top())!=(w.top()))
        {
            same = false;
            return false;
        }

        else if ((s.top())==(w.top()))
        {
            s.pop();
            w.pop();

        }

    }
    same = true;
    return same;
}


bool checkParens(const string &s)
{
    bool balance;
    int length = s.length();
    stackType<char> checker;

    for(int i = 0;i<length; i++)
    {
        if (s[i]=='(')
                checker.push('X');
        else if (s[i]==')'&&!checker.isEmptyStack())
            checker.pop();
        else if (s[i]==')'&&checker.isEmptyStack())
        {
            balance =false;
            return balance;
        }

    }

    if (checker.isEmptyStack())
    {
        balance = true;
        return balance;
    }
    else
    {
        balance = false;
        return balance;

    }

}

int main()
{


    stackType<int> stackOne;
    stackType<int> stackTwo;
    cout<<endl<<"Enter values for Stack 1, ending with -999:  "<<endl;
    int value;
    cin>>value;
    while(value!=-999)
    {
        stackOne.push(value);
        cin>>value;
    }

    cout<<endl<<endl<<"Now enter values for Stack 2, ending with -999: "<<endl;
    int value2;
    cin>>value2;
    while(value2!=-999)
    {
        stackTwo.push(value2);
        cin>>value2;
    }

    //int same = stackOne.sameStack(stackTwo);
    int same = sameStack(stackOne, stackTwo);
     cout<<endl<<"Returned: "<<same<<endl;

    if (same==true)
    {
        cout<<"The stacks are the same";
    }

    else
    {
        cout<<"They are not the same.";
    }


    cout<<endl<<"Stack one: "<<endl;
     while (!stackOne.isEmptyStack())
    {
        cout << stackOne.top() << endl;
        stackOne.pop();
    }

     cout<<endl<<"Stack two: "<<endl;
     while (!stackTwo.isEmptyStack())
    {
        cout << stackTwo.top() << endl;
        stackTwo.pop();
    }

    cout<<endl<<"Okay, now we are checking a math equation for parentheses balance.";
    cout<<endl<<"Please enter your equation: ";
    bool balance;
    string expression;
    cin>>expression;

    cout<<endl<<"Okay, let's check..."<<endl;

    balance = checkParens(expression);

    if(balance)
    {
        cout<<endl<<"You have matched parentheses!";
    }
    else
    {
        cout<<endl<<"Oops you have an error.";
    }



//    int same = stackOne.sameStack(stackTwo);




   // linkedStackType<char> myStack;


    stackType<char> myStack;
    string word;

    cout<<endl<<"Enter a word for testing: ";
    cin>>word;

    string str = word;

    char c[str.size()+1];
//    myStack.size = str.size();
  //  cout<<endl<<"size is "<<myStack.size;
    str.copy(c, str.size()+1);

    for(int i = 0; i<str.size(); i++)
    {
        myStack.push(c[i]);
    }
//if the string fits the language of WORD: number(a) = number(b) + 1b
    if(myStack.arrayIsInLanguageL(word))
        cout<<endl<<endl<<"Yes. It is in the language."<<endl;
    else
        cout<<endl<<endl<<"Not in the language."<<endl;
    linkedStackType<int> stack;
    linkedStackType<int> otherStack;
    linkedStackType<int> newStack;

    //Add elements into stack
    stack.push(34);
    stack.push(43);
    stack.push(27);

    //Use the assignment operator to copy the elements of stack into newStack
    newStack = stack;
    cout << "After the assignment operator, newStack: "<< endl;
    //Output the elements of newStack
    while (!newStack.isEmptyStack())
    {
        cout << newStack.top() << endl;
        newStack.pop();
    }

    //Use the assignment operator to copy the elements of stack into otherStack
    otherStack = stack;
    cout << "Testing the copy constructor." << endl;
    testCopy(otherStack);
    cout << "After the copy constructor, otherStack: " << endl;
    while (!otherStack.isEmptyStack())
    {
        cout << otherStack.top() << endl;
        otherStack.pop();
    }
    return 0;
}



//Function to test the copy constructor
void testCopy(linkedStackType<int> OStack)
{
    cout << "Stack in the function testCopy:" << endl;
    while (!OStack.isEmptyStack())
    {
            cout << OStack.top() << endl;
            OStack.pop();
    }
}

