#include <iostream>
#include <string.h>
#include <time.h>
#include "Functions.h"

#define MAXL_DETAIL 20
#define MAXL_EMP 500
using namespace std;

//Global Vaiable
int numOfBill = 0;

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


struct billDate
{
	char billNum[20];
	struct Dates date;
	
	bool operator > (const struct billDate &other)
	{
		if (this->date.year > other.date.year)
			return true;
		else if (this->date.month > other.date.month)
			return true;
		else if (this->date.day > other.date.day)
			return true;
		else
			return false;
	}
	
	bool operator < (const struct billDate &other)
	{
		if (this->date.year < other.date.year)
			return true;
		else if (this->date.month < other.date.month)
			return true;
		else if (this->date.day < other.date.day)
			return true;
		else
			return false;
	}	
};

void sortBill(struct billDate *arr, int left, int right)
{
	billDate mid = arr[(left + right) / 2];
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
				billDate tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			i++; j--;
		}
	} while(i<=j);
	if(left < j)
		sortBill(arr, left, j);
	if(right > i)
		sortBill(arr, i, right);
}


//==========Struct============



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
	struct listBillDeta *details;
	
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


struct ListBill
{
	int Size;
	NODE_LB firstNode;
	
	ListBill()
	{
		Size = 0;
		firstNode = NULL;
	}
	
//	void Initialize_LB()
//	{
//		firstNode = NULL;
//	}
	
	bool isEmpty()
	{
		return (firstNode == NULL);
	}
	
	void insertFirst(Bills nodeN)
	{
		NODE_LB p = new nodeListBill;
		p->info = nodeN;
		p->next = firstNode;
		firstNode = p;
		Size++;
		numOfBill++;
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
	
	bool checkID(char ID[20])
	{
		for (NODE_LB p = firstNode; p != NULL; p = p->next)
		{
			if (strcmp(p->info.Num, ID) == 0)
				return false;
		}
		return true;
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
	
	
	void addBill(char idEmp[11], Bills newBill)
	{
		struct Employee* p = Search_ID(idEmp);
		p->listBill.insertFirst(newBill);
	}
	
};
//==============endNHANVIEN============




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
		for (int j = 0; j < tmpLB.Size; i++)
		{
			NODE_LB p = new nodeListBill;
			readBill(fileListBill, p);
			ListEmployees.nodeListEmp[i]->listBill.insertFirst(p->info);
			
			struct listBillDeta *tmpDT = new listBillDeta;
			tmpDT = p->info.details;
			for (int j = 0; j < tmpDT->n; j++)
			{
				readDetail(fileListDetail, tmpDT->nodeListDeta[j]);	
			}
			delete(tmpDT);
		}
	}
	fileListEmp.close();
	fileListBill.close();
	fileListDetail.close();
}

