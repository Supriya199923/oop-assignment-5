//Name:Supriya Das   Roll-301910501008
//3.	Employee has unique emp-id, name, designation and basic pay. An employee is either a permanent one or contractual. For permanent employee salary is computed as basic pay+ hra (30% of basic pay) + da (80% of basic pay). For contractual employee it is basic pay + allowance (it is different for different contractual employee). An employee pointer may point to either of the two categories and accordingly the salary has to be created.
//Design the classes and implement

#include<bits/stdc++.h>
using namespace std;

class employee
{
	int emp_id;
	char name[30];
	int designation;
	float basicpay;
	float salary;
	
	public:
	
	static int total;
	friend int is_unique(int id);
	friend void search(int id);
	
	void getdata();
	void display()
	{
		cout<<"\n Employee Name : "<<name;
		cout<<"\n Employee Id	: "<<emp_id;
		if(designation==0)
			cout<<"\n Employee Designation : Contractual ";
		else
			cout<<"\n Employee Designation : Permanent ";
		cout<<"\n Basic Pay : "<<basicpay;
		cout<<"\n Salary	: "<<salary;
	}
};

int employee::total=0;
employee emp[50];

int is_unique(int id)
{
	int i;
	for(i=0;i<emp[0].total;i++)
	{
		if(emp[i].emp_id==id)
			return 0;
	}
	return 1;
}

void search(int id)
{
	int i,check=0;
	for(i=0;i<emp[0].total;i++)
	{
		if(emp[i].emp_id==id)
		{
			emp[i].display();
			check=1;
		}
	}
	if(check==0)
		cout<<"\n Employee not found!!! ";
}

void employee::getdata()
	{
		int temp_id,result;
		float allowance;		
		cout<<"\n Enter employee Id : ";
		cin>>temp_id;
		result=is_unique(temp_id);
		if(result==0)
		{
			cout<<"\n Employee Id not Unique. Returning to main menu ";
			return;
		}
		emp_id=temp_id;
		cout<<"\n Enter employee name : ";
		cin>>name;
		cout<<"\n Enter employee designation ( input 1 for permanent and 0 for contractual ) ";
		cin>>designation;
		cout<<"\n Enter baic pay : ";
		cin>>basicpay;
		if(designation==0)
		{
			cout<<"\n Enter employee allowance : ";
			cin>>allowance;
			salary=basicpay+allowance;
		}
		else
			salary=basicpay+(0.30*basicpay)+(0.80*basicpay);
		total++;
	}

int main()
{
	int choice,id;	
	while(1)	
	{
		cout<<"\n 1. Enter Employee Data ";
		cout<<"\n 2. Display Employee Data ";
		cout<<"\n 3. Exit Program ";
		cout<<"\n\n\t\tEnter Choice : ";
		cin>>choice;
		if(choice==1)
			emp[emp[0].total].getdata();
		else if(choice==2)
			{
				cout<<"\n Enter Employee Id to Display Details : ";
				cin>>id;
				search(id);
			}
		else if(choice==3)
			return 1;
		else
			cout<<"\n Invalid Input!! ";
	}
	return 0;
}
