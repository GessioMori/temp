#include <iostream>
#include "DLL.h"

using namespace std;

int main()
{

  system("clear");

  DoublyLinkedList *myList = new DoublyLinkedList();
  int choice, data;

  do
  {
    cout << "1. Insert at the front\n"
         << "2. Insert at the back\n"
         << "3. Remove from the front\n"
         << "4. Remove from the back\n"
         << "5. Print the list\n"
         << "0. Exit\n";

    cin >> choice;

    system("clear");

    switch (choice)
    {
    case 1:
      cout << "Enter data: ";
      cin >> data;
      myList->insertFront(data);
      break;

    case 2:
      cout << "Enter data: ";
      cin >> data;
      myList->insertBack(data);
      break;

    case 3:
      myList->removeFront();
      break;

    case 4:
      myList->removeBack();
      break;

    case 5:
      if (myList->isEmpty())
      {
        cout << "List is empty\n";
      }
      else
      {
        myList->printList();
      }
      break;
      break;

    case 0:
      cout << "Exiting program\n";
      break;

    default:
      cout << "Invalid choice. Please try again.\n";
      break;
    }

    cout << endl;
  } while (choice != 0);

  return 0;
}