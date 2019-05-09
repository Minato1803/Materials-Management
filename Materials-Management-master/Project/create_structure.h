#include <iostream>
#include <cstring>
#include "Functions.h"
using namespace std;


// create BST

struct Materials
{
	char code[11];
	char name[50];
	char type[25];
	char amount[18];
};

struct Node
{
	char key;
	char info;
	Node *left;
	Node *right;
};
typedef struct Node *NODEPTR;

void Initalize (NODEPTR &root)
{
	root = NULL;
}



void Insert(NODEPTR &p,char x,Materials  a)
{
	if(p==NULL)
	{
		p = new node;
		strcopy(p->key, x);
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
				// existed, asked for edit
				//cong info;
			}		
		
}

void RemoveCase (NODEPTR &r, NODEPTR &rp)
{
	if(p->left = NULL)
		RemoveCase(r->left);
	else
	{
		strcpy(rp->key, r->key);
		strcpy(rp->info, r->info);
		rp = r;
		r = rp->right;
		
	}
}

void Remove(char x, NODEPTR &p)
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
						RemoveCase(rp->right);					
			}
		delete rp;	
	}
	
	bool Empty(NODEPTR &root)
	{
		return (root == NULL ? 1 : 0);
	}
	
	void Search(NODEPTR &root, char x)
	{
		NODEPTR p;
		p = root;
		while(p!=NULL && strcmp(p->key, x) != 0)
		{
			if(strcmp(x, p->left) < 0)
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
	
/*	void CreateTree(NODEPTR &root)
	{
		Materials info;
		while(1)
		{
			if(kbhit())
			{
				char key = getch();
				
			}
		}
		loopcode:
		char c;
		c = NhapSo();
		
		if(Search(root,info.code) != NULL)
		{
			//code existed 
			goto loopcode:;
		}
		loopname:
		cin>> info.name;
		if(Search(root,info.name) != NULL)
		{
			//name existed
			goto loopname:;
		}
		looptype:
		cin>>info.type;
		if(!CheckLetter(info.type))
				goto looptype:;
		loopamount:
		cin>>info.amount;
		if(!CheckNum(info.amount))
			goto loopamount:;
		Insert(root,info.name,info);
	}
*/	
					
}
