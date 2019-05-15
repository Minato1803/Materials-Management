#include <iostream>
#include <string.h>
#include <time.h>
#include "Functions.h"

#define MAXL_DETAIL 20
#define MAXL_EMP 500
using namespace std;


// create BST

struct Dates
{
	int day;
	int month;
	int year;
	
	bool isValid()
	{
		if(month<1 || month>12 || year<0 || day<0 || day>31)
		{
			return false;
		}
		
		if (month==2 || month==4 || month==4 || month==9 || month == 11)
		{
			if (day > 30)
				return false;
			if (month == 2)
			{
				if ((year%4 == 0 && year%100 != 0) || year%400 == 0)
				{
					if (day > 29)
						return false;
				}
				else
				{
					if (day > 28)
						return false;
				}
			}
		}
		return true;
	}
	
	
};


// CT_HOADON
struct Details
{
	char ID[20];
	char amount[20];
	char unit[20];
	int VAT;
	
	bool operator == (struct Details other)
	{
		return (strcmp(ID, other.ID) == 0);
	}
};


//===============DanhsachCT_HOADON==========
struct listBillDeta
{
	int n;
	struct Details nodeListDeta[20];
	
	bool isEmpty()
	{
		return (n==0);
	}
	
	bool isFull()
	{
		return (n == MAXL_DETAIL);
	}
	
	void Insert(struct Details newNode)		//push_back
	{
		nodeListDeta[n++] = newNode;
	}
	
	void Detele(int pos)
	{
		for (int j = pos+1; j < n; j++)
		{
			nodeListDeta[j-1] = nodeListDeta[j];
		}
	}
	
	void Clear()
	{
		n = 0;
	}
	
	int Search_info(struct Details info)
	{
		for (int i = 0; i < n; i++)
		{
			if (nodeListDeta[i] == info)
			{
				return i;
			}
		}
		return -1;
	}
};
//=============endDanhsachCT_HOADON========

//=============HOADON======================
struct Bills
{
	char Num[20];
	struct Dates date;
	char type;
	struct listBillDeta *listMat;
	
	bool operator == (struct Bills other)
	{
		return (strcmp(Num, other.Num) == 0);
	}
};

struct nodeListBill
{
	struct Bills info;
	struct nodeListBill *next;
};
typedef struct nodeListBill* NODE_LB;

void Initialize_LB(NODE_LB &First)
{
	First = NULL;
}

NODE_LB newNode_LB()
{
	NODE_LB p = new nodeListBill;
	return p;
}

bool Empty_LB(NODE_LB First)
{
	return (First == NULL);
}

void InsertFirst_LB(NODE_LB &First, Bills nodeN)
{
	NODE_LB p = newNode_LB();
	p->info = nodeN;
	p->next = First;
	First = p;
}

void InsertAfter_LB(NODE_LB pos, Bills nodeN)
{
	NODE_LB tmp = newNode_LB();
	tmp->info = nodeN;
	tmp->next = pos->next;
	pos->next = tmp;	
}

NODE_LB Search_LB(NODE_LB First, Bills nodeN)\
{
	for (NODE_LB p = First; p != NULL; p = p->next)
	{
		if (p->info == nodeN)
			return p;
	}
	return NULL;
}



//=============end--HOADON================

//=============NHANVIEN==================
struct Employee
{
	char ID[11];
	char firstName[31];
	char lastName[31];
	bool sex; //1: male
	NODE_LB listBill;
	Employee()
	{
		ID[0] = '\0';
		firstName[0] = '\0';
		lastName[0] = '\0';
		sex = 1;
	}	
//	bool operator == (struct Employees other)
//	{
//		return (strcmp(ID, other.ID) == 0);
//	}
};

struct listEmp
{
	int n;
	struct Employee *nodeListEmp[500];
	listEmp()
	{
		n = 0;
	}
	
	bool isEmpty()
	{
		return (n==0);
	}
	
	bool isFull()
	{
		return (n == MAXL_EMP);
	}
	
	void Insert(struct Employee *newNode)		//push_back
	{
		nodeListEmp[n++] = newNode;
	}
	
	void Detele(int pos)
	{
		for (int j = pos+1; j < n; j++)
		{
			nodeListEmp[j-1] = nodeListEmp[j];
		}
	}
	
	void Clear()
	{
		n = 0;
	}
	
	int Search_info(struct Employee *info)
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(nodeListEmp[i]->ID, info->ID) == 0)
			{
				return i;
			}
		}
		return -1;
	}
	
	struct Employee* Search_ID(char tmpID[11])
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(nodeListEmp[i]->ID, tmpID) == 0)
			{
				return nodeListEmp[i];
			}
		}
		return NULL;
	}
	
};



//==============endNHANVIEN============
