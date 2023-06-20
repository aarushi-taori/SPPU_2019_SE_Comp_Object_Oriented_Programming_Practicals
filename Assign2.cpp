/* Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll 
number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. Construct the
database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member 
functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception 
handling.
*/


//Code
#include <iostream>
#include<bits/stdc++.h>
#include<string.h>
#define max_len 25
using namespace std;

class student
{
public:
	int Roll_no;
	char Name[max_len];
	int srno;
	char Cls[7];
	char Div[3];
	char DOB[10];
	char blood_grp[8];
	long long int Contact;
	static int count;			 //Static data variable

	void getdata();
	friend void display(student & obj);

	student()					//Constructor
      { 
		Roll_no:0;
		Roll_no=count;
		count++;
      }

	~student()					//Destructor
      {
		count++;
      }
	
	static void getcount()		//static member fuction
	{
		cout<<"\nCount"<<count;
	}

	student(int Roll_no) 	 	//parameterized constructor
	{
		this->Roll_no=Roll_no;
	}
	
	student(student & obj)		 // Copy constructor
	{
		Roll_no=obj.Roll_no;
		strcpy(Name,obj.Name);
		strcpy(Cls,obj.Cls);
		strcpy(Div,obj.Div);
		strcpy(DOB,obj.DOB);
		Contact=obj.Contact;
		strcpy(blood_grp,obj.blood_grp);
		srno=count;
		count++;
	}
};	

	
int student::count=0;			//static variable default declaration

void student::getdata()			//Function Definitions	
{
	cout<<"\nEnter Name:";
	cin>>Name;
	cout<<"\nEnter Roll No:";
	cin>>Roll_no;
	cout<<"\nEnter class :";
	cin>>Cls;
	cout<<"\nEnter Div:";
	cin>>Div;
	cout<<"\nEnter Date Of Birth:";
	cin>>DOB;
	cout<<"\nEnter Contact No:";
	cin>>Contact;
	cout<<"\nEnter Blood group:";
	cin>>blood_grp;
}

void display(student & obj) 	//friend Fuction
{
	cout<<"\n"<<obj.Roll_no;
	cout<<"\t"<<obj.Name;
	cout<<"\t\t"<<obj.Cls;
	cout<<"\t"<<obj.Div;
	cout<<"\t\t"<<obj.DOB;
	cout<<"\t"<<obj.Contact;
	cout<<"\t"<<obj.blood_grp;
}

int main()
{
	student s1;
	student s2(s1); 				 //copy constructor
	student *s[50];					//array of object
	int i,n;

	cout<<"\n How many student objects do you want to create ?: ";			//Input of no. of students from User
	cin>>n;

	for (i=0;i<n;i++)
	{	
		s[i]=new student(); 		//dynamic memory allocation operator
	}
	
	for(i=0;i<n;i++)				//Input of Student's Data
	{
		cout<<"\nENTER THE DATA FOR "<<i+1<<"th STUDENT :"<<endl;
		s[i]-> getdata();
	}

	cout<<"\nDETAILS OF THE STUDENT :"<<endl;							//Display of Student's Data
	cout<<"\nRoll no\tName\t\tClass\tDivision\tD.O.B.\t\tContact No.\tBlood Group\n";
	cout<<"\n-------------------------------------------------------------------------";
	for (i=0;i<n;i++)
	{
		display(*s[i]);
		cout<<"\n-------------------------------------------------------------------------------------";
	}

	for (i=0;i<n;i++)
	{
		delete (s[i]);				 //dynamic memory de-allocation operator
	}
	cout<<"\n";
	return 0 ;
}

//Output 
/*
How many student objects do you want to create ?: 2
ENTER THE DATA FOR 1th STUDENT :
Enter Name:ABC
Enter Roll No:01
Enter class :SE
Enter Div:B
Enter Date Of Birth:01/01/01
Enter Contact No:029838763
Enter Blood group:B
ENTER THE DATA FOR 2th STUDENT :
Enter Name:XYZ
Enter Roll No:02
Enter class :SE
Enter Div:B
Enter Date Of Birth:01/02/01
Enter Contact No:3892737238
Enter Blood group:B+

DETAILS OF THE STUDENT :
Roll no Name            Class   Division        D.O.B.          Contact No.     Blood Group
-------------------------------------------------------------------------------------
1       ABC             SE      B               01/01/01        29838763        B
-------------------------------------------------------------------------------------
2       XYZ             SE      B               01/02/01        3892737238      B+
-------------------------------------------------------------------------------------
*/





