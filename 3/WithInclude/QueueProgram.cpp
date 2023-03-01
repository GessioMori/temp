#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{

  system("clear");

  Queue *myQueue = new Queue();
  int choice, element;

  do
  {
    cout << "1. Push element\n"
         << "2. Pop element\n"
         << "3. Check if queue is empty\n"
         << "4. Print queue\n"
         << "0. Quit\n";

    cin >> choice;

    system("clear");

    switch (choice)
    {
    case 1:
      cout << "Enter element to push: ";
      cin >> element;
      myQueue->push(element);
      break;

    case 2:
      myQueue->pop();
      break;

    case 3:
      if (myQueue->isEmpty())
      {
        cout << "Queue is empty\n";
      }
      else
      {
        cout << "Queue is not empty\n";
      }
      break;

    case 4:
      if (myQueue->isEmpty())
      {
        cout << "Queue is empty\n";
      }
      else
      {
        myQueue->printQueue();
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