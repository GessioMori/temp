#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
  int key;
  struct node *left, *right;
} Node;

/*
struct tree
{

}
*/

Node *createNode(int key);
Node *insert(Node *node, int key);
void inorder(Node *node);
void preorder(Node *node);
void postorder(Node *node);
Node *search(Node *node, int key);
Node *minValueNode(Node *node);
Node *deleteNode(Node *node, int key);
void createTree(Node *root);
void menu(Node *root);
void leftView(Node *node, int currentLevel, int *printedLevel);
int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255]);
void print_t(Node *tree);

int main()
{
  system("clear");

  Node *root = NULL;

  menu(root);

  return 0;
}

Node *createNode(int key)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

Node *insert(Node *node, int key)
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

void inorder(Node *node)
{
  if (node != NULL)
  {
    inorder(node->left);
    printf("%d ", node->key);
    inorder(node->right);
  }
}

void preorder(Node *node)
{
  if (node != NULL)
  {
    printf("%d ", node->key);
    preorder(node->left);
    preorder(node->right);
  }
}

void postorder(Node *node)
{
  if (node != NULL)
  {
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->key);
  }
}

Node *search(Node *node, int key)
{
  if (node == NULL || node->key == key)
  {
    return node;
  }
  if (key < node->key)
  {
    return search(node->left, key);
  }
  else
  {
    return search(node->right, key);
  }
}

Node *minValueNode(Node *node)
{

  if (node->left != NULL)
  {
    return minValueNode(node->left);
  }

  return node;
}

Node *deleteNode(Node *node, int key)
{

  if (node == NULL)
  {
    return node;
  }

  if (key < node->key)
  {
    node->left = deleteNode(node->left, key);
  }
  else if (key > node->key)
  {
    node->right = deleteNode(node->right, key);
  }
  else
  {
    if (node->left == NULL)
    {
      Node *temp = node->right;
      free(node);
      return temp;
    }
    else if (node->right == NULL)
    {
      Node *temp = node->left;
      free(node);
      return temp;
    }
    Node *temp = minValueNode(node->right);

    node->key = temp->key;

    node->right = deleteNode(node->right, temp->key);
  }
  return node;
}

void createTree(Node *root)

{
  insert(root, 3);
  insert(root, 10);
  insert(root, 1);
  insert(root, 6);
  insert(root, 14);
  insert(root, 4);
  insert(root, 7);
  insert(root, 13);
}

void menu(Node *root)
{
  int choice, key;
  while (1)
  {
    printf("\n");
    printf("1. Insert\n");
    printf("2. Inorder\n");
    printf("3. Preorder\n");
    printf("4. Postorder\n");
    printf("5. Search\n");
    printf("6. Delete\n");
    printf("7. Create\n");
    printf("8. Left view\n");
    printf("9. Show tree\n");
    printf("0. Exit\n");
    printf("Enter your choice:\t");

    scanf("%d", &choice);

    system("clear");

    switch (choice)
    {
    case 1:
      printf("Enter the key to be inserted: \n");
      scanf("%d", &key);
      if (root == NULL)
      {
        root = createNode(key);
      }
      else
      {
        insert(root, key);
      }
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      printf("Enter the key to be searched: \n");
      scanf("%d", &key);
      printf("Key address: %p \n", search(root, key));
      break;
    case 6:
      printf("Enter the key to be deleted: \n");
      scanf("%d", &key);
      printf("Deleted key address: %p \n", deleteNode(root, key));
      break;
    case 7:
      if (root != NULL)
      {
        printf("Tree already created");
      }
      else
      {
        root = createNode(8);
        createTree(root);
        printf("Tree created");
      }
      break;
    case 8:
      int printedLevel = 0;
      leftView(root, 1, &printedLevel);
      break;
    case 9:
      print_t(root);
      break;
    case 0:
      exit(0);
      break;
    default:
      printf("Wrong choice\n");
      break;
    }

    printf("\n___________________________\n");
  }
}

void leftView(Node *node, int currentLevel, int *printedLevel)
{

  if (node == NULL)
    return;

  if (*printedLevel < currentLevel)
  {
    printf("%d ", node->key);
    *printedLevel = currentLevel;
  }

  leftView(node->left, currentLevel + 1, printedLevel);
  leftView(node->right, currentLevel + 1, printedLevel);
}

int _print_t(Node *tree, int is_left, int offset, int depth, char s[20][255])
{
  char b[20];
  int width = 5;

  if (!tree)
    return 0;

  sprintf(b, "(%03d)", tree->key);

  int left = _print_t(tree->left, 1, offset, depth + 1, s);
  int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
  for (int i = 0; i < width; i++)
    s[depth][offset + left + i] = b[i];

  if (depth && is_left)
  {

    for (int i = 0; i < width + right; i++)
      s[depth - 1][offset + left + width / 2 + i] = '-';

    s[depth - 1][offset + left + width / 2] = '.';
  }
  else if (depth && !is_left)
  {

    for (int i = 0; i < left + width; i++)
      s[depth - 1][offset - width / 2 + i] = '-';

    s[depth - 1][offset + left + width / 2] = '.';
  }
#else
  for (int i = 0; i < width; i++)
    s[2 * depth][offset + left + i] = b[i];

  if (depth && is_left)
  {

    for (int i = 0; i < width + right; i++)
      s[2 * depth - 1][offset + left + width / 2 + i] = '-';

    s[2 * depth - 1][offset + left + width / 2] = '+';
    s[2 * depth - 1][offset + left + width + right + width / 2] = '+';
  }
  else if (depth && !is_left)
  {

    for (int i = 0; i < left + width; i++)
      s[2 * depth - 1][offset - width / 2 + i] = '-';

    s[2 * depth - 1][offset + left + width / 2] = '+';
    s[2 * depth - 1][offset - width / 2 - 1] = '+';
  }
#endif

  return left + width + right;
}

void print_t(Node *tree)
{
  char s[20][255];
  for (int i = 0; i < 20; i++)
    sprintf(s[i], "%80s", " ");

  _print_t(tree, 0, 0, 0, s);

  for (int i = 0; i < 20; i++)
    printf("%s\n", s[i]);
}