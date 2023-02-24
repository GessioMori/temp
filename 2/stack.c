#include <stdlib.h>
#include <stdio.h>

void display();
void push();
void pop();
void calcSize();

struct node
{
  int info;
  struct node *next;
};

//
struct node *head = NULL;

int main()
{
  system("clear");

  int choice;

  while (1)
  {
    printf("\n");
    printf("1. Display\n");
    printf("2. Push\n");
    printf("3. Pop\n");
    printf("4. Size\n");
    printf("5. Exit\n");
    printf("Enter your choice:\t");

    scanf("%d", &choice);

    system("clear");

    switch (choice)
    {
    case 1:
      display();
      break;
    case 2:
      push();
      break;
    case 3:
      pop();
      break;
    case 4:
      calcSize();
      break;
    case 5:
      exit(0);
      break;
    default:
      printf("Wrong choice\n");
      break;
    }

    printf("___________________________");
    printf("\n");
  }
  return 0;
}

void display()
{
  struct node *ptr;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    ptr = head;
    printf("The list is:\n");
    printf("\n");
    printf("[ ");
    while (ptr != NULL)
    {
      printf("%d ", ptr->info);
      ptr = ptr->next;
    }
    printf("]\n");
  }
}

//
void push()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));

  if (!temp)
  {
    printf("Out of Memory Space\n");
    return;
  }

  printf("Enter the data value for the node:\n");
  scanf("%d", &temp->info);

  temp->next = NULL;

  if (head == NULL)
  {
    head = temp;
  }
  else
  {
    temp->next = head;
    head = temp;
  }
}

//
void pop()
{
  struct node *ptr;
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    ptr = head;
    head = head->next;
    printf("The deleted element is: %d\n", ptr->info);
    free(ptr);
  }
}

void calcSize()
{
  struct node *ptr = (struct node *)malloc(sizeof(struct node));

  int counter = 0;

  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }

  ptr = head;

  counter++;

  while (ptr->next != NULL)
  {
    counter++;
    ptr = ptr->next;
  }

  printf("List contains %d elements", counter);
}