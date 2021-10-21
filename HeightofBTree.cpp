#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
};

Node *CreateNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}


void DisplayPreOrder(Node *root)
{
    if(root != NULL)
    {
        cout << " " << root->data;
        DisplayPreOrder(root->left);
        DisplayPreOrder(root->right);
    }
}

int maxHeight(Node *node)
{
    if(node == NULL)
        return 0;
    else
    {
        int leftHeight = maxHeight(node->left);
        int rightHeight = maxHeight(node->right);
        
        return max(leftHeight + 1, rightHeight + 1);
    }
}

int main() 
{
	Node *root = CreateNode(1);
	root->left = CreateNode(2);
	root->right = CreateNode(3);
	root->left->left = CreateNode(4);
	root->left->left->left = CreateNode(6);
	root->left->left->right = CreateNode(7);
	root->left->right = CreateNode(5);
	
	DisplayPreOrder(root);
	cout << endl;
	cout << "Height: " << maxHeight(root);
	
	return 0;
}
