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

void PreOrder(Node *node)
{
    if(node != NULL)
    {
        cout << " " << node->data; 
        PreOrder(node->left);
        PreOrder(node->right);
    }
}

void InOrder(Node *node)
{
    if(node != NULL)
    {
        InOrder(node->left);
        cout << " " << node->data; 
        InOrder(node->right);
    }
}

void PostOrder(Node *node)
{
    if(node != NULL)
    {
        PostOrder(node->left);
        PostOrder(node->right);
        cout << " " << node->data; 
    }
}

int main() 
{
	Node *root = CreateNode(1);
	root->left = CreateNode(2);
	root->right = CreateNode(3);
	root->left->left = CreateNode(4);
	root->left->right = CreateNode(5);
	
	cout << "preorder traversal: ";
    PreOrder(root);
    cout << "\nInorder traversal: ";
    InOrder(root);
    cout << "\nPostorder traversal: ";
    PostOrder(root);

	return 0;
}
