#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{

  system("clear");

  Stack *myStack = new Stack();
  int choice, element;

  do
  {
    cout << "1. Push element\n"
         << "2. Pop element\n"
         << "3. Check if stack is empty\n"
         << "4. Print stack\n"
         << "0. Quit\n";

    cin >> choice;

    system("clear");

    switch (choice)
    {
    case 1:
      cout << "Enter element to push: ";
      cin >> element;
      myStack->push(element);
      break;

    case 2:
      myStack->pop();
      break;

    case 3:
      if (myStack->isEmpty())
      {
        cout << "Stack is empty\n";
      }
      else
      {
        cout << "Stack is not empty\n";
      }
      break;

    case 4:
      if (myStack->isEmpty())
      {
        cout << "Stack is empty\n";
      }
      else
      {
        myStack->printStack();
      }
      break;

    case 0:
      cout << "Exiting program\n";
      break;

    default:
      cout << "Invalid choice, try again\n";
    }

    cout << endl;

  } while (choice != 0);

  return 0;
}