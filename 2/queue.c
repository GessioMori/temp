#include <stdlib.h>
#include <stdio.h>

void display();
void push();
void pop();

struct node
{
  int info;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

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
    printf("4. Exit\n");
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

  if (front == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    ptr = front;
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

void push()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));

  if (temp == NULL)
  {
    printf("Out of Memory Space\n");
    return;
  }

  printf("Enter the data value for the node:\n");
  scanf("%d", &temp->info);

  temp->next = NULL;

  if (rear == NULL)
  {
    front = rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = temp;
  }
}

void pop()
{
  struct node *ptr;
  if (front == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else
  {
    ptr = front;
    front = front->next;
    printf("The deleted element is: %d\n", ptr->info);
    free(ptr);
  }
}