#include <iostream>
#include <string.h>
#include "Functions.h"
using namespace std;


// create BST
struct Employees
{
	char ID[11];
	char firstName[31];
	char lastName[31];
	bool sex; //1: male
	Emplyees()
	{
		ID[0] = '\0';
		firstName[0] = '\0';
		lastName[0] = '\0';
		sex = 1;
	}
};
