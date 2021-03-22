#include <stdio.h>

typedef struct _empInfo
{
	int empNum; // key
	int age;
} EmpInfo;

int GetHashValue(int empNum)
{
	return empNum % 100;
}

int main(void)
{
	EmpInfo empInfo[100];

	EmpInfo emp1 = {20120003,42};
	EmpInfo emp2 = {20120012,33};
	EmpInfo emp3 = {20120049,27};

	EmpInfo r1,r2,r3;

	// store using key involve with index
	empInfo[GetHashValue(emp1.empNum)] = emp1;
	empInfo[GetHashValue(emp2.empNum)] = emp2;
	empInfo[GetHashValue(emp3.empNum)] = emp3;

	// searching using key
	r1 = empInfo[GetHashValue(20120003)];
	r2 = empInfo[GetHashValue(20120012)];
	r3 = empInfo[GetHashValue(20120049)];

	printf(" Emp : %d || Age : %d\n",r1.empNum,r1.age);
	printf(" Emp : %d || Age : %d\n",r2.empNum,r2.age);
	printf(" Emp : %d || Age : %d\n",r3.empNum,r3.age);

	return 0;

}