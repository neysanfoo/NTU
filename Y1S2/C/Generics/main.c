/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct {
 char name[40];
 char telno[40];
 int id;
 double salary;
} Employee;
void printEmp(Employee *emp, int size);
int readin(Employee *emp);
int search(Employee *emp, int size, char *target);
int addEmployee(Employee *emp, int size, char *target);
int main()
{
 Employee emp[MAX];
 char name[40], *p;
 int size, choice, result;

 printf("Select one of the following options: \n");
 printf("1: readin() \n");
 printf("2: search() \n");
 printf("3: addEmployee() \n");
 printf("4: print() \n");
 printf("5: exit() \n");
 do {
		printf("Enter your choice: \n");
		scanf("%d", &choice);
		switch (choice) {
			 case 1:
					size = readin(emp);
					break;
			 case 2:
					printf("Enter search name: \n");
					scanf("\n");
					fgets(name, 40, stdin);
					if ((p=strchr(name,'\n'))) *p = '\0';
					result = search(emp,size,name);
					if (result != 1)
						 printf ("Name not found! \n");
					break;
			 case 3:
					printf("Enter new name: \n");
					scanf("\n");
					fgets(name, 40, stdin);
					if ((p=strchr(name,'\n'))) *p = '\0';
					result = search(emp,size,name);
					if (result != 1)
						 size = addEmployee(emp, size, name);
					else
						 printf("The new name has already existed in the database\n");
					break;
			 case 4:
					printEmp(emp, size);
					break;
			 default:
					break;
		}
 } while (choice < 5);
 return 0;
}
void printEmp(Employee *emp, int size)
{
 int i;

 printf("The current employee list: \n");
 if (size==0)
		printf("Empty array\n");
 else
 {
		for (i=0; i<size; i++)
			 printf("%s %s %d %.2f\n",emp[i].name,emp[i].telno,emp[i].id,
emp[i].salary);
 }
}
int readin(Employee *emp)
{
/*edit*/
 /* Write your code here */
	char name[40];
	char tel[40];
	int id;
	double salary;
	int index = 0;
	printf("Enter name: \n");
	char temp;
	while ((temp = getchar()) != '\n');
	fgets(name, 40 ,stdin);
	printf("%lu",strlen(name));
	name[strlen(name)-1] = '\0';
	while (strcmp(name,"#") != 0)
	{
			printf("Enter tel: \n");
			fgets(tel, 40 ,stdin);
			printf("Enter id: \n");
			scanf("%d", &id);
			printf("Enter salary: \n");
			scanf("%lf",&salary);
			printf("Enter name: \n");
			strcpy(emp[index].name, name);
			strcpy(emp[index].telno, tel);
			emp[index].id = id;
			emp[index].salary = salary;
			index++;
			while ((temp = getchar()) != '\n');
			fgets(name, 40 ,stdin);
			printf("%lu",strlen(name));
			name[strlen(name)-1] = '\0';
			printf("%s\n",name);
	}
	return 1;
/*end_edit*/
}
int search(Employee *emp, int size, char *target)
{
/*edit*/
 /* Write your code here */
	char name[40];
	printf("Enter search name: \n");
	fgets(name,40,stdin);
	for (int i = 0; i < size; i++)
	{
			if (strcmp(emp[i].name,target)==0)
			{
					printf("Employee found at index location: %d",i);
					printf("%s %s %d %f", emp[i].name,emp[i].telno,emp[i].id,emp[i].salary);
					return 1;
			}
	}
	return 0;

/*end_edit*/
}
int addEmployee(Employee *emp, int size, char *target)
{
/*edit*/
 /* Write your code here */
	char tel[40];
	int id;
	double salary;
	printf("Enter tel: \n");
	scanf("%s",tel);
	printf("Enter id: \n");
	scanf("%d", &id);
	printf("Enter salary: \n");
	scanf("%lf",&salary);

	strcpy(emp[size].name, target);
	strcpy(emp[size].telno, tel);
	emp[size].id = id;
	emp[size].salary = salary;
	printf("Added as position %d\n", size);
	return size+1;

/*end_edit*/
}
