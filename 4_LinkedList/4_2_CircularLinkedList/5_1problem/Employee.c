#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

Employee* EmployeeSetting(char* name,int num)
{
	Employee* p = (Employee*)malloc(sizeof(Employee));
	p->name = name;
	p->num = num;
	return p;
}
void EmployeePrint(Employee* pEmployee)
{
	printf("name : %s || num : %d \n",pEmployee->name,pEmployee->num);
}

int EmployeeEqaul(char* name,Employee* p)
{
	if(*name == *(p->name))
		return TRUE;
	else 
		return FALSE;
} 