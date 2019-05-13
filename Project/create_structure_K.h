#include <iostream>
#include <string.h>
#include "Functions.h"
using namespace std;

//=== create structures=== //

struct Materials	// info Materials
{
	char code[11];
	char name[51];
	char type[26];
	char amount[19];
	int  RealAmount;
	Materials()
	{
		code[0] = '\0';
		name[0] = '\0';
		type[0] = '\0';
		amount[0] = '\0';
		RealAmount = 0;
	}
};

struct NameMats
{
	char code[11];
	char name[51];
};

struct Node			//AVL tree
{
	char key[];
	Materials info;
	int height ;
	Node *left;
	Node *right;
	
	Node()
	{
		height = 1;
	}
};
typedef struct Node *NODEPTR;
//====Functions====//
//void Initalize (NODEPTR &root)
//{
//	root = NULL;
//}
	//can bang lai cay 
int Height(NODEPTR p)
{
	if(p==NULL)
		return 0;
	else
		return p->height;	
}

NODEPTR rotateR(NODEPTR y) 
{ 
	NODEPTR x = y->left; 
	NODEPTR p = x->right; 
 
	x->right = y; 
	y->left = p; 
	
	// Update height
	 
	x->height = max(Height(x->left), 
					Height(x->right)) + 1;
	y->height = max(Height(y->left), 
					Height(y->right)) + 1;
	return x; 
} 

NODEPTR rotateL(NODEPTR y) 
{ 
	NODEPTR x = y->right; 
	NODEPTR p = x->left; 
 
	x->left = y; 
	y->right = p; 

	// Update height
	x->height = max(Height(x->left), 
					Height(x->right)) + 1; 
	y->height = max(Height(y->left), 
					Height(y->right)) + 1; 
	return x; 
} 

int getBalance(NODEPTR p) 
{ 
	if (p == NULL) 
		return 0;
	else	 
		return Height(p->left) - Height(p->right); 
} 

NODEPTR minValueNode(NODEPTR root) 
{ 
	NODEPTR p = root; 
	while (p->left != NULL) 
		p = p->left; 

	return p; 
} 

NODEPTR deleteNode(NODEPTR root, char key[]) 
{ 
	if (root == NULL) 
		return root; 
	if ( strcmp(key,root->key) < 0 ) 
		root->left = deleteNode(root->left, key);
	else if( strcmp(key,root->key) > 0 ) 
		root->right = deleteNode(root->right, key);  
	else
	{ 
		if( (root->left == NULL) || (root->right == NULL) ) // neu chi co 1 nut con hoac ko co 
		{ 
			NODEPTR tmp = root->left ? root->left : root->right; 
			if (tmp == NULL) 	// neu ko co nut con
			{ 
				tmp = root; 
				root = NULL; 
			} 
			else 				// neu co 1 nut con 
			root = tmp; 
			free(tmp); 
		} 
		else
		{ 
			// node with two children: Get the inorder 
			// successor (smallest in the right subtree) 
			NODEPTR tmp = minValueNode(root->right); 
			strcpy(root->key,tmp->key); 
			// Delete the inorder successor 
			root->right = deleteNode(root->right, tmp->key); 
		} 
	} 
	// If the tree had only one node 
	// then return 
	if (root == NULL) 
	return root; 
	
	//update node hien tai 
	root->height =max(Height(root->left), Height(root->right)) + 1; 
						
	//can bang lai cay
	int balance = getBalance(root); 
	//4 truong hop mat can bang
	// Left Left 
	if (balance > 1 && getBalance(root->left) >= 0) 
		return rotateR(root); 
	// Left Right 
	if (balance > 1 && getBalance(root->left) < 0) 
	{ 
		root->left = rotateL(root->left); 
		return rotateR(root); 
	} 
	// Right Right 
	if (balance < -1 && getBalance(root->right) <= 0) 
		return rotateL(root); 
	// Right Left
	if (balance < -1 && getBalance(root->right) > 0) 
	{ 
		root->right = rotateR(root->right); 
		return rotateL(root); 
	} 
	return root; 
}

NODEPTR Insert(NODEPTR &root, char key[], Materials a) 
{ 
	if (root == NULL) 
	{
		root = new Node;
		strcpy(root->key,key);
		strcpy(root->info.code,a.code);
		strcpy(root->info.name,a.name);
		strcpy(root->info.type,a.type);
		strcpy(root->info.amount,a.amount);
		root->height = 1;
		root->info.RealAmount = a.RealAmount;
		root->right =NULL; root->left = NULL;
	}
	if (strcmp(key,root->key) < 0) 
		root->left = Insert(root->left, key, a); 
	else if (strcmp(key,root->key) > 0) 
		root->right = Insert(root->right, key, a); 
	else
		return 0; 

	//cap nhat height
	root->height = max(Height(root->left), 
						Height(root->right)) + 1; 

	//can bang lai cay
	
	int balance = getBalance(root); 

	//4 truong hop mat can bang

	// Left Left 
	if (balance > 1 && (strcmp(key,root->left->key) > 0 )) 
		return rotateR(root); 

	// Right Right
	if (balance < -1 && (strcmp(key,root->right->key) > 0 )) 
		return rotateR(root); 

	// Left Right 
	if (balance > 1 && (strcmp(key,root->left->key) > 0 )) 
	{ 
		root->left = rotateL(root->left); 
		return rotateR(root); 
	} 

	// Right Left 
	if (balance < -1 &&(strcmp(key,root->right->key) < 0 )) 
	{ 
		root->right = rotateR(root->right); 
		return rotateL(root); 
	} 

	return root; 
} 

//// A utility function to print preorder 
//// traversal of the tree. 
//// The function also prints height 
//// of every node 
//void preOrder(Node *root) 
//{ 
//	if(root != NULL) 
//	{ 
//		cout << root->key << " "; 
//		preOrder(root->left); 
//		preOrder(root->right); 
//	} 
//} 
	
NODEPTR Search(NODEPTR &root, char x[])
{
	NODEPTR p;
	p = root;
	while(p!=NULL && strcmp(p->key, x) != 0)
	{
		if(strcmp(p->key,x) < 0)
			p = p-> left;
		else
		 	p = p->right;			 	
	}
	return p;
}	
	void Inorder(NODEPTR &p)
	{
		if(p != NULL)
		{
			Inorder(p->left);
//			cout<<p->info;
			//show
			Inorder(p->right);
			
		}
	}
// save and load file

void saveFile(NODEPTR tree)
{
	ofstream outMat;
	outMat.open("Materialsinfo.txt", ios::out);
	if(tree != NULL)
	{
		outMat << tree->key <<" ";
		outMat << tree->height <<" ";
		outMat << tree->info.code <<" ";
		outMat << tree->info.name <<" ";
		outMat << tree->info.type <<" ";
		outMat << tree->info.amount <<" ";
		saveFile(tree->left);
		saveFile(tree->right);
	}
	outMat.close();
}	
					
