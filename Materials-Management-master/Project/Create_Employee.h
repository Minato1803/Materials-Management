#include <iostream>
#include "create_structure";
#include "Functions"

// create list
struct Bills_Detail
{
	char MaterialCode[11];
	char amount[18];
	char Bills[18];
	char VAT[3]; 
}

struct list_Bill
{
	int n = 0;
	Bill_Detail node[20];
}

//create linked list
struct Dates
{
	char days[2];
	char months[2];
	char years[4];
}

struct Bills
{
	char BillsNum[20];
	Dates Date_Bills;
	char types[5];
	Bills_Detail *Details;
}

struct node
{
	Bills HD;
	struct node *next;
}
typedef struct node *NODEPTR;

//create list

struct Name
{
	char FistN[10];
	char LastN[10];
}

struct Employs
{
	char Emp_Code[50];
	Name Emp_Name;
	// char gender;
	Bills *Emp_Bills; 
}

struct Emp_list
{
	int n = 0;
	Employs *node[];
}

