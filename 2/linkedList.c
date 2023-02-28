#include <stdlib.h>
#include <stdio.h>

struct node
{
  int value;
  struct node *next;
  struct node *prev;
};

typedef struct list
{
  int size;
  struct node *start;
  struct node *end;
} List;

void display(List *list);
void insert_begin(struct list *list, int value);
void insert_end(struct list *list, int value);
void delete_begin(struct list *list);
void delete_end(struct list *list);

int main()
{
  system("clear");

  struct list *myList = (struct list *)malloc(sizeof(struct list));

  myList->size = 0;
  myList->start = NULL;
  myList->end = NULL;

  int choice;
  int tempValue;

  while (1)
  {
    printf("\n");
    printf("1.Display\n");
    printf("2.Insert at the beginning\n");
    printf("3.Insert at the end\n");
    printf("4.Delete from beginning\n");
    printf("5.Delete from the end\n");
    printf("6.Exit\n");
    printf("Enter your choice:\t");

    scanf("%d", &choice);

    system("clear");

    switch (choice)
    {
    case 1:
      display(myList);
      break;
    case 2:
      printf("Enter the data value for the node:\n");
      scanf("%d", &tempValue);
      insert_begin(myList, tempValue);
      break;
    case 3:
      printf("Enter the data value for the node:\n");
      scanf("%d", &tempValue);
      insert_end(myList, tempValue);
      break;
    case 4:
      delete_begin(myList);
      break;
    case 5:
      delete_end(myList);
      break;
    case 6:
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

void display(List *list)
{
  struct node *ptr;

  printf("List contains %d element(s)\n", list->size);

  if (list->start == NULL)
  {
    return;
  }
  else
  {
    ptr = list->start;
    printf("The list is:\n");
    printf("[ ");
    while (ptr != NULL)
    {
      printf("%d ", ptr->value);
      ptr = ptr->next;
    }
    printf("]\n");
  }
}

void insert_begin(struct list *list, int value)
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));

  if (temp == NULL)
  {
    printf("Out of Memory Space\n");
    return;
  }

  temp->next = NULL;
  temp->prev = NULL;
  temp->value = value;

  if (list->start == NULL)
  {
    list->start = temp;
    list->end = temp;
  }
  else
  {
    temp->next = list->start;
    list->start->prev = temp;
    list->start = temp;
  }
  list->size++;
}

void insert_end(struct list *list, int value)
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));

  if (temp == NULL)
  {
    printf("Out of Memory Space:\n");
    return;
  }

  temp->next = NULL;
  temp->prev = NULL;
  temp->value = value;

  if (list->start == NULL)
  {
    list->start = temp;
    list->end = temp;
  }
  else
  {
    temp->prev = list->end;
    list->end->next = temp;
    list->end = temp;
  }
  list->size++;
}

void delete_begin(struct list *list)
{
  struct node *ptr;
  if (list->start == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else if (list->start->next == NULL)
  {
    ptr = list->start;
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    free(list->start);
    printf("The deleted element is : %d\n", ptr->value);
  }
  else
  {
    ptr = list->start;
    list->start->next->prev = NULL;
    list->start = list->start->next;
    printf("The deleted element is : %d\n", ptr->value);
    free(ptr);
    list->size--;
  }
}

void delete_end(struct list *list)
{
  struct node *ptr;

  if (list->start == NULL)
  {
    printf("List is empty\n");
    return;
  }
  else if (list->start->next == NULL)
  {
    ptr = list->start;
    list->size = 0;
    list->start = NULL;
    list->end = NULL;
    free(list->start);
    printf("The deleted element is : %d\n", ptr->value);
  }
  else
  {
    ptr = list->end;
    list->end->prev->next = NULL;
    list->end = list->end->prev;
    printf("The deleted element is: %d\n", ptr->value);
    free(ptr);
    list->size--;
  }
}
