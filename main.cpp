#include <iostream>

using namespace std;

struct Node {
    int key;
    Node *left;
    Node *right;
    Node (int k) { key = k; left = right = NULL; }
};

// insert key k into tree T, returning a pointer to the resulting tree
Node *insert(Node *T, int k)
{  
   // base case
   if (T == NULL) 
      return new Node(k);
   // insert recursively to the left
   if (k < T->key) 
      T->left = insert(T->left, k);
   // insert recursively to the right
   else 
      T->right = insert(T->right, k);
   return T;
}

// prints out the inorder traversal of T (i.e., the contents of T in sorted order)
void print_inorder(Node *T)
{  
   // base case
   if (T == NULL)
      return;
   print_inorder(T->left);
   cout << T->key << endl;
   print_inorder(T->right);
}

int main(void) 
{
    // array of size 10 with random numbers between 1-100
    int array[] = {85, 20, 8, 44, 73, 4, 33, 55, 99, 44};

    Node *bst = NULL;

    // insert numbers from array into bst
    for (int i=0; i<10; i++) 
    {
        bst = insert(bst, array[i]);
    }

    cout << "Printing BST\n";
    print_inorder(bst);

    return 0;
}