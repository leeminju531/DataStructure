#ifndef __Employee_H__
#define __Employee_H__

#define LEN 30
#define TRUE 1
#define FALSE 0

typedef struct _employee
{
	char* name;
	int num;
}Employee;

Employee* EmployeeSetting(char* name,int num);
void EmployeePrint(Employee* pEmployee);
int EmployeeEqaul(char* name,Employee* p); // if equal return true

#endif