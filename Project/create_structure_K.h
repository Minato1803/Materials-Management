#include <iostream>
#include <string.h>
#include "Functions.h"
using namespace std;


// create BST

struct Materials
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

struct Node
{
	char key[];
	Materials info;
	Node *left;
	Node *right;
};
typedef struct Node *NODEPTR;

void Initalize (NODEPTR &root)
{
	root = NULL;
}



int Insert(NODEPTR &p,char x[],Materials  a)
{
	if(p==NULL)
	{
		p = new Node;
		strcpy(p->key, x);
		strcpy(p->info.code, a.code);
		strcpy(p->info.name, a.name);
		strcpy(p->info.type, a.type);
		strcpy(p->info.amount, a.amount);
		p->left = NULL; p->right = NULL;
	}
	else
		if(strcmp(x, p->key) < 0)
			Insert(p->left,x,a);
		else if(strcmp(x, p->key) > 0)
				Insert(p->right,x,a);
			else
			{
				return 0;
			}		
		
}

void RemoveCase (NODEPTR &r, NODEPTR &rp)
{
	if(rp->left = NULL)
		RemoveCase(r->left,rp);
	else
	{
		strcpy(rp->key, r->key);
		strcpy(rp->info.code, r->info.code);
		strcpy(rp->info.name, r->info.name);
		strcpy(rp->info.type, r->info.type);
		strcpy(rp->info.amount, r->info.amount);
		rp = r;
		r = rp->right;
	}
}

void Remove(char x[], NODEPTR &p)
{
	NODEPTR rp;
	if(p = NULL)
	{
		//warning not found;
	}
	else
	{
		if(strcmp(x, p->key) < 0 )
			Remove(x, p->left);
		else
			if(strcmp(x, p->key) > 0)
				Remove(x, p->right);
			else
			{
				rp = p;
				if(rp->right = NULL)
					p = rp->left;
				else if(rp->left == NULL)
						p = p->right;
					else
						RemoveCase(rp->right,rp);					
			}
		delete rp;	
	}
}
	
	bool Empty(NODEPTR &root)
	{
		return (root == NULL ? 1 : 0);
	}
	
	NODEPTR Search(NODEPTR &root, char x[])
	{
		NODEPTR p;
		p = root;
		while(p!=NULL && strcmp(p->key, x) != 0)
		{
			if(stricmp(p->key,x) < 0)
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
	
					
