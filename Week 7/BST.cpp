#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

node *FindMin(node *root){
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
   if(root == NULL)
    return;

   traverseInOrder(root->left);
   cout<<root->key<<" ";
   traverseInOrder(root->right);
}

node *NewNode(int data)
{
    node *newNode = new struct node();
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Insert a node
struct node *insertNode(struct node *node, int key) {
    if(node == NULL){
        node = NewNode(key);
    }
    else if(key <= node->key){
        node->left = insertNode(node->left,key);
    }
    else{
        node->right = insertNode(node->right,key);
    }
    return node;

}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if(root == NULL)
        return root;
    else if(key < root->key)
        root->left = deleteNode(root->left,key);
    else if(key > root->key)
        root->right = deleteNode(root->right,key);
    else{
        //Case 1:No Child
        if(root->left == NULL && root->right == NULL){
            delete root;
            root = NULL;
        }
        //Case 2:One Child
        else if(root->left == NULL){
            node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL){
            node *temp = root;
            root = root->left;
            delete temp;
        }
        //Case 3:2 Children
        else{
            node *temp = FindMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);
        }
    }
    return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
