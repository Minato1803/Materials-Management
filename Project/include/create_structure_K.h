#include <iostream>
#include <fstream>
#include <string.h>
#include "Functions.h"

using namespace std;
ofstream logs;

//=== create structures=== //
int CountM = 0;
struct Material	// info Materials
{
	char code[11];
	char name[51];
	char type[26];
	char amount[26];
	Material()
	{
		code[0] = '\0';
		name[0] = '\0';
		type[0] = '\0';
		amount[0] = '\0';
	}
};

struct NameMats
{
	char code[11];
	char name[51];
	int  revenue;
	int  rank;
	NameMats()
	{
		code[0] = '\0';
		name[0] = '\0';
		revenue = 0;
		rank = 0;
	}
	
	bool operator > (const struct NameMats &other)
	{
		return (this->revenue > other.revenue);
	}
	bool operator < (const struct NameMats &other)
	{
		return (this->revenue < other.revenue);
	}
	
};

struct Node			//AVL tree
{
	
	char key[11];
	Material info;
	int height;
	Node *left;
	Node *right;
//	Node()
//	{
//		key[0] = '0';
//		height = 1;
//	}
};
typedef struct Node *NODEPTR;

//====Functions====//


void Initalize(NODEPTR &root, int &CountM)
{
	CountM = 0;
	root = NULL;
}
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
	
	// Cap nhat chieu cao
	 
	y->height = max(Height(y->left), 
					Height(y->right)) + 1;
	x->height = max(Height(x->left), 
					Height(x->right)) + 1;
	return x; 
} 

NODEPTR rotateL(NODEPTR y) 
{ 
	NODEPTR x = y->right; 
	NODEPTR p = x->left; 
 
	x->left = y; 
	y->right = p; 

	// Cap nhat chieu cao
	y->height = max(Height(y->left), 
					Height(y->right)) + 1; 
	x->height = max(Height(x->left), 
					Height(x->right)) + 1; 
	return x; 
} 

int getBalance(NODEPTR p) 
{ 
	if (p == NULL) 
		return 0;
	return (Height(p->left) - Height(p->right)); 
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
			NODEPTR tmp; 
			tmp = NULL;
//			tmp = root->left ? root->left : root->right;
			if(root->left != NULL)
			{
				tmp = root->left;
			} 
			else
			{
				tmp = root->right;
			}
			if (tmp == NULL) 	// neu ko co nut con
			{ 
				tmp = root; 
				root = NULL; 
			} 
			else
			{
			 	// neu co 1 nut con 
				root = tmp;
				tmp = NULL;	 
			}
		}
		else
		{ 
			// neu co hai nut con thi lay node con tan cung ben trai cua nhanh ben phai 
			NODEPTR tmp = minValueNode(root->right); 
			strcpy(root->key,tmp->key);
			root->info = tmp->info;  
			// xoa node con
			root->right = deleteNode(root->right, tmp->key); 
		} 
	}  
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

NODEPTR newNode(char key[], Material a)  
{  
    NODEPTR node = new Node; 
    strcpy(node->key,key);
	strcpy(node->info.code,a.code);
	strcpy(node->info.name,a.name);
	strcpy(node->info.type,a.type);
	strcpy(node->info.amount,a.amount);
	node->height = 1;
	node->right = NULL; node->left = NULL;
	return (node);  
} 

NODEPTR Insert(NODEPTR root, char key[], Material a) 
{ 
//logs << key << endl;
	if (root == NULL) 
		return (newNode(key, a));
		
	if (strcmp(key,root->key) < 0) 
		root->left = Insert(root->left, key, a); 
	else if (strcmp(key,root->key) > 0) 
		root->right = Insert(root->right, key, a); 
	else
		return root; 

	//cap nhat height
	root->height = max(Height(root->left), Height(root->right)) + 1; 

	//can bang lai cay
	int balance = getBalance(root); 

	//4 truong hop mat can bang

	// Left Left 
	if (balance > 1 && (strcmp(key,root->left->key) < 0 )) 
		return rotateR(root); 

	// Right Right
	if (balance < -1 && (strcmp(key,root->right->key) > 0 )) 
		return rotateL(root); 

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

	
NODEPTR Search(NODEPTR &root, char x[11])
{
//	if(root == NULL || strcmp(root->key, x) == 0)
//		return root;
//	else if(strcmp(root->key, x) < 0)
//		 {
//		 	Search(root->right,x);
//		 }	
//		 else if(strcmp(root->key, x) > 0)
//		 	  {
//		 	  	Search(root->left,x);
//			  }
	//khu de quy
	NODEPTR p;
	p = root ;
	while(p != NULL && strcmp(p->key, x) != 0)
	{
		if(strcmp(p->key, x) < 0)
			p = p->right;
		else if(strcmp(p->key, x) > 0)
		 	 p = p->left;		 	
	}
	return p;
}	

//functions

void Qsort(NameMats info[], int left, int right )
{
	NameMats mid = info[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while(strcmp(info[i].name, mid.name) < 0)
			i++;
		while(strcmp(info[j].name, mid.name) > 0)
			j--;
		if(i <= j)
		{
			if(i < j)
			{
				NameMats tmp;
				tmp = info[i];
				info[i] = info[j];
				info[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		Qsort(info,left,j);
	if(right > i)
		Qsort(info,i,right);
}


// save and load

void saveNode(NODEPTR &tree, ofstream &outMat)
{
	if(tree != NULL)
	{
//		outMat << tree->key <<endl;
//		outMat << tree->height <<endl;
		saveNode(tree->left,outMat);
		outMat << tree->info.code <<endl;
		outMat << tree->info.name <<endl;
		outMat << tree->info.type <<endl;
		outMat << tree->info.amount <<endl;
		saveNode(tree->right,outMat);
	}
	else
		return;
}	

void saveMat(NODEPTR &tree, int &nMat)
{
	ofstream outMat;
	outMat.open("data/MaterialsInfo.txt", ios::out);
	outMat << nMat << endl;
	saveNode(tree, outMat);
	outMat.close();
}

void loadFile(NODEPTR &tree, int &CountM)
{
	Initalize(tree, CountM);
	ifstream inMat;
	inMat.open("data/MaterialsInfo.txt",ios::in);
	inMat >> CountM;
	inMat.ignore();
	logs << CountM << endl;
	for(int i = 0; i < CountM; i++)
	{
		Material tmp;	
		logs << i << endl;
//			tmp = new Node(); 
//			inMat.getline(tmp->key,sizeof(tmp->key));
//			inMat >> tmp->height;
//			inMat.ignore();
		inMat.getline(tmp.code,sizeof(tmp.code));
		inMat.getline(tmp.name, sizeof(tmp.name));
		inMat.getline(tmp.type, sizeof(tmp.type));
		inMat.getline(tmp.amount, sizeof(tmp.amount));
//		logs << tmp.code << endl;
//		logs << tmp.name << endl;
//		logs << tmp.type << endl;
//		logs << tmp.amount << endl;
		tree = Insert(tree,tmp.code,tmp);
	}	
	logs << "finish" << endl;
	inMat.close();
}
					
