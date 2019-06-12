#include <iostream>
#include <string.h>
#include <time.h>
#include "Functions.h"

#define MAXL_DETAIL 20
#define MAXL_EMP 500
using namespace std;

//Global Vaiable

ofstream logs;
//=====funtions======

struct NamesInfoEmp
{
	char fName[31];
	char lName[31];
	char ID[11];
	
	bool operator > (const struct NamesInfoEmp &other)
	{
		if (strcmp(this->fName, other.fName) > 0)
		{
			return true;
		}
		else if (strcmp(this->fName, other.fName) == 0)
		{
			if (strcmp(this->lName, other.lName) > 0)
			{
				return true;
			}
			else
				return false;
		}
		else 
			return false;
	}
	
	bool operator < (const struct NamesInfoEmp &other)
	{
		if (strcmp(this->fName, other.fName) < 0)
		{
			return true;
		}
		else if (strcmp(this->fName, other.fName) == 0)
		{
			if (strcmp(this->lName, other.lName) < 0)
			{
				return true;
			}
			else
				return false;
		}
		else 
			return false;
	}
};

void sortEmp(struct NamesInfoEmp *arr, int left, int right)
{
	NamesInfoEmp mid = arr[(left + right) / 2];
	int i = left, j = right;
	do
	{
		while(arr[i] < mid)
			i++;
		while(arr[j] > mid)
			j--;
		if(i <= j)
		{
			if(i < j)
			{
				NamesInfoEmp tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		sortEmp(arr, left, j);
	if(right > i)
		sortEmp(arr, i, right);
}

struct Dates
{
	int day;
	int month;
	int year;
	
	Dates()
	{
		day = 1;
		month = 1;
		year = 1;
	}
	bool isValid()
	{
		if(month<1 || month>12 || year<0 || day<0 || day>31)
		{
			return false;
		}
		
		if (month==2 || month==4 || month==6 || month==9 || month == 11)
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
	
	bool operator > (const struct Dates &other)
	{
		if (this->year > other.year)
			return true;
		else if (this->year == other.year) 
		{
			if(this->month > other.month)
				return true;
			else if (this->month == other.month)
			{
				if (this->day > other.day)
					return true;
			}
		}
		
		return false;
	}
	
	bool operator < (const struct Dates &other)
	{
		if (this->year < other.year)
			return true;
		else if (this->year == other.year) 
		{
			if(this->month < other.month)
				return true;
			else if (this->month == other.month)
			{
				if (this->day < other.day)
					return true;
			}
		}
		
		return false;
	}
	
	bool operator == (const struct Dates &other)
	{
		if (this->year == other.year)
			if (this->month == other.month)
				if (this->day == other.day)
					return true;
		return false;
	}
};

//==========Struct============



// CT_HOADON
struct Details
{
	char ID[20];
	int amount;
	int unit;
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
	
	listBillDeta()
	{
		n = 0;
	}
	
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
		n-=1;
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
	
	bool cmp_ID(char keyID[])
	{
		for(int i = 0; i < n; i++)
		{
			if(strcmp(nodeListDeta[i].ID, keyID) == 0)
			{
				return 1;
			}
		}
		return 0;
	}
};
//=============endDanhsachCT_HOADON========

//=============HOADON======================
struct Bills
{
	char Num[20];
	struct Dates date;
	char type;
	struct listBillDeta *details;
	Bills()
	{
		Num[0] = '\0';
		details = new listBillDeta;
	}
	bool operator == (struct Bills other)
	{
		return(strcmp(Num, other.Num) == 0);
	}
	
	long value()
	{
		long res = 0;
		for (int i = 0; i < details->n; i++)
		{
			res += (details->nodeListDeta[i].amount*details->nodeListDeta[i].unit)*((100+details->nodeListDeta[i].VAT)/100.0);
		}
		return res;
	}
};

struct nodeListBill
{
	struct Bills info;
	struct nodeListBill *next;
};
typedef struct nodeListBill* NODE_LB;


struct ListBill
{
	int Size;
	NODE_LB firstNode;
	
	ListBill()
	{
		Size = 0;
		firstNode = NULL;
	}
	
	bool isEmpty()
	{
		return (firstNode == NULL);
	}
	
	void insertFirst(Bills &nodeN)
	{
		NODE_LB p = new nodeListBill;
		p->info = nodeN;
		p->next = firstNode;
		firstNode = p;
		Size++;
	}
	
	void insertFirst(NODE_LB p)
	{
		p->next = firstNode;
		firstNode = p;
		Size++;
	}
	
	void loadNODE_LB(NODE_LB p)
	{
		p->next = firstNode;
		firstNode = p;
	}
	
	void insertAfter(NODE_LB pos, Bills nodeN)
	{
		NODE_LB tmp = new nodeListBill;
		tmp->info = nodeN;
		tmp->next = pos->next;
		pos->next = tmp;
		Size++;	
	}
	
	NODE_LB Search_LB(Bills nodeN)
	{
		for (NODE_LB p = firstNode; p != NULL; p = p->next)
		{
			if (p->info == nodeN)
				return p;
		}
		return NULL;
	}
	
	bool checkID(char ID[])
	{
		for (NODE_LB p = firstNode; p != NULL; p = p->next)
		{
			if (strcmp(p->info.Num, ID) == 0)
				return false;
		}
		return true;
	}
	
	Bills findBill(char IDBill[20])
	{
		for (NODE_LB p = firstNode; p != NULL; p = p->next)
		{
			if (strcmp(p->info.Num, IDBill) == 0)
				return p->info;
		}
	}
};




//=============end--HOADON================

//=============NHANVIEN==================
struct Employee
{
	char ID[11];
	char firstName[31];
	char lastName[31];
	bool sex; //1: male
	struct ListBill listBill;
	Employee()
	{
		ID[0] = '\0';
		firstName[0] = '\0';
		lastName[0] = '\0';
		sex = 1;
	}
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
		n--;
	}
	
	void DeteleID(char tmpID[11])
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(nodeListEmp[i]->ID, tmpID) == 0)
			{
				this->Detele(i);
				break;
			}
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
	
	//check ID nhan vien, tra ve NULL neu k trung
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
	
	//return false neu co ID trung
	bool checkIDBill(char idBill[20])
	{
		for (int numE = 0; numE < n; numE++)
		{
			if (nodeListEmp[numE]->listBill.checkID(idBill) == false) // co ID trung
				return false;
		}
		return true;
	}
	
	Employee *FindEmp(char IDBill[20])
	{
		for (int numE = 0; numE < n; numE++)
		{
			if (nodeListEmp[numE]->listBill.checkID(IDBill) == false) // co ID trung
				return nodeListEmp[numE];
		}
		return NULL;
	}
	
	
	void addBill(char idEmp[11], Bills &newBill)
	{
		struct Employee* p = Search_ID(idEmp);
		p->listBill.insertFirst(newBill);
	}
	
//	struct Employee* Search_ID(char tmpID[11])
//	{
//		for (int i = 0; i < n; i++)
//		{
//			if (strcmp(nodeListEmp[i]->ID, tmpID) == 0)
//			{
//				return nodeListEmp[i];
//			}
//		}
//		return NULL;
//	}
	
};
//==============endNHANVIEN============


//=====================================
struct billDateNode
{
	struct Bills *info;
	struct Employee *Emp;
	struct billDateNode *next;
};
typedef struct billDateNode* NODE_BDate;


struct listBillDate
{
	int Size;
	NODE_BDate firstNode;
	
	listBillDate()
	{
		Size = 0;
		firstNode = NULL;
	}
	
	void insert(struct Bills &bill, struct Employee *Emp)
	{
		NODE_BDate newNode, before, after;
		newNode = new billDateNode;
		newNode->info = &bill;
		newNode->Emp = Emp;
		for (after = firstNode; 
			after != NULL && after->info->date < newNode->info->date;
			before = after, after = after->next);
			
		if (after == firstNode)
		{
			newNode->next = firstNode;
			firstNode = newNode;
		}
		else
		{
			before->next = newNode;
			newNode->next = after;
		}
		Size++;
	}
	
	NODE_BDate index(int stt)
	{
		NODE_BDate newNode = firstNode;
		for (int i = 0; i < stt; newNode = newNode->next, i++);
		return newNode;
	}
};
//=====================================




//=============SAVE-and-LOAD===========

void writeDetail(ofstream &file, Details node)
{
	file << node.ID << endl;
	file << node.amount << endl;
	file << node.unit << endl;
	file << node.VAT << endl;
}

void writeBill(ofstream &file, NODE_LB node)
{
	file << node->info.Num << endl;
	file << node->info.date.day << " " << node->info.date.month << " " << node->info.date.year << endl;
	file << node->info.type << endl;
	file << node->info.details->n << endl;
}

void writeEmp(ofstream &file, struct Employee *node)
{
	file << node->ID << endl;
	file << node->firstName << endl;
	file << node->lastName << endl;
	file << node->sex << endl;
	file << node->listBill.Size << endl;
}

void saveEmp(struct listEmp &ListEmployees)
{
	ofstream numList;
	ofstream fileListEmp;
	ofstream fileListBill;
	ofstream fileListDetail;
	numList.open("data/numList.txt", ios::out);
	fileListEmp.open("data/EmployeesList.txt", ios::out);
	fileListBill.open("data/BillsList.txt", ios::out);
	fileListDetail.open("data/DetailList.txt", ios::out);
	
	numList << ListEmployees.n << endl;
//	numList << numOfBill << endl;
	for (int i = 0; i < ListEmployees.n; i++)
	{
		writeEmp(fileListEmp, ListEmployees.nodeListEmp[i]);
		struct ListBill tmpLB = ListEmployees.nodeListEmp[i]->listBill;
		for (NODE_LB p = tmpLB.firstNode; p != NULL; p = p->next)
		{
			writeBill(fileListBill, p);
			struct listBillDeta *tmpDT = new listBillDeta;
			tmpDT = p->info.details;
			for (int j = 0; j < tmpDT->n; j++)
			{
				writeDetail(fileListDetail, tmpDT->nodeListDeta[j]);
			}
			delete(tmpDT);
		}
	}
	fileListEmp.close();
	fileListBill.close();
	fileListDetail.close();
}

void readDetail(ifstream &file, struct Details &node)
{
	file >> node.ID;
	file >> node.amount;
	file >> node.unit;
	file >> node.VAT;
}

void readBill(ifstream &file, NODE_LB node)
{
	file >> node->info.Num;
	file >> node->info.date.day >> node->info.date.month >> node->info.date.year;
	file >> node->info.type;
	file >> node->info.details->n;
}

void readEmp(ifstream &file, struct Employee *node)
{
	file >> node->ID;
	file.ignore();
	file.getline(node->firstName, sizeof(node->firstName));
	file.getline(node->lastName, sizeof(node->lastName));
	file >> node->sex;
	file >> node->listBill.Size;
}

void loadEmp(struct listEmp &ListEmployees)
{
	ifstream numList;
	ifstream fileListEmp;
	ifstream fileListBill;
	ifstream fileListDetail;
	numList.open("data/numList.txt", ios::in);
	fileListEmp.open("data/EmployeesList.txt", ios::in);
	fileListBill.open("data/BillsList.txt", ios::in);
	fileListDetail.open("data/DetailList.txt", ios::in);
	
	numList >> ListEmployees.n;
	for (int i = 0; i < ListEmployees.n; i++)
	{
		ListEmployees.nodeListEmp[i] = new Employee;
		readEmp(fileListEmp, ListEmployees.nodeListEmp[i]);
		struct ListBill tmpLB = ListEmployees.nodeListEmp[i]->listBill;
		for (int j = 0; j < tmpLB.Size; j++)
		{
			NODE_LB p = new nodeListBill;
			readBill(fileListBill, p);
			ListEmployees.nodeListEmp[i]->listBill.loadNODE_LB(p);			
			for (int noNode = 0; noNode < p->info.details->n; noNode++)
			{
				readDetail(fileListDetail, p->info.details->nodeListDeta[noNode]);	
			}
		}
	}
	fileListEmp.close();
	fileListBill.close();
	fileListDetail.close();
}
