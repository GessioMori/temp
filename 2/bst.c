#include <stdlib.h>
#include <stdio.h>

#define COUNT 10

struct node
{
  int key;
  struct node *left, *right;
};

struct node *createNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert(struct node *node, int key)
{
  if (node == NULL)
  {
    return createNode(key);
  }

  if (key < node->key)
  {
    node->left = insert(node->left, key);
  }
  else if (key > node->key)
  {
    node->right = insert(node->right, key);
  }

  return node;
}

void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

void print2DUtil(struct node *root, int space)
{
  if (root == NULL)
    return;

  space += COUNT;

  print2DUtil(root->right, space);

  printf("\n");
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root->key);

  print2DUtil(root->left, space);
}

void print2D(struct node *root)
{
  print2DUtil(root, 0);
}

int main()
{
  struct node *root = NULL;

  system("clear");

  int choice, k;

  while (1)
  {
    printf("\n");
    printf("1. Display\n");
    printf("2. Insert\n");
    printf("3. Exit\n");
    printf("Enter your choice:\t");

    scanf("%d", &choice);

    system("clear");

    switch (choice)
    {
    case 1:
      print2D(root);
      break;
    case 2:
      printf("Enter the key to be inserted: \n");
      scanf("%d", &k);
      if (root == NULL)
      {
        root = createNode(k);
      }
      else
      {
        insert(root, k);
      }
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Wrong choice\n");
      break;
    }

    printf("\n___________________________\n");
  }

  return 0;
}