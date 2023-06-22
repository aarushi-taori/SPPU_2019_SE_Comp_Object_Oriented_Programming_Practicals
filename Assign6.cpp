/*
Write C++ program using STL for sorting and searching user defined records such as Item
records (Item code, name, cost, quantity etc) using vector container.
*/


//Code
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class ItemRecords
{
	public:
	
	char name[30];
	int cost;
	int quantity;
	int code;
			 
	//Operator Overloading
	bool operator==(const ItemRecords & item)
	{
		if(code==item.code)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	bool operator<(ItemRecords & item)
	{
		if(code<item.code)
		{
			return 1;
		}
		else 
		{
			return 0;
		}
	}
	
};

vector <ItemRecords> v1;
void insertRecord();
void print(ItemRecords & item);
void displayRecord();
void searchRecord();
void deleteRecord();

int main()
{
	int ch;
	
	do 
	{
		cout<<"\n-----------------------------------------------------------------------------"<<endl;
		cout<<"* * * MENU * * *"<<endl;
		cout<<"Enter 1 to Insert Records\nEnter 2 to Display Records\nEnter 3 to Search Records\nEnter 4 to Sort Records\nEnter 5 to Delete Records\nEnter 6 to Exit"<<endl;
		cout<<"Enter your Choice :";
		cin>>ch;
		
		switch(ch)
		{
			case 1: insertRecord();
					break;

			case 2: cout<<"\nDISPLAYING RECORDS DETAILS:"<<endl;
					displayRecord();
					break;
					
			case 3: searchRecord();
					break;
					
			case 4: sort(v1.begin(),v1.end());
					cout<<"\nSORTED RECORDS:"<<endl;
					displayRecord();
					break;
					
			case 5: deleteRecord();
					break;
					
			case 6: cout<<"\nEXITING THE PROGRAM!!!"<<endl;
					break;
		}
		
	}while(ch!=6);
	
	return 0;
}

//Function Definitions

void insertRecord()
{
	ItemRecords item;
	cout<<"\nEnter Item Records :"<<endl;
	cout<<"Enter Name :";
	cin>>item.name;
	cout<<"Enter Code :";
	cin>>item.code;
	cout<<"Enter Cost :";
	cin>>item.cost;	
	cout<<"Enter Quantity :";
	cin>>item.quantity;
	v1.push_back(item);
	cout<<"Item Inserted Sucessfully!!"<<endl;
}

void displayRecord()
{
	for_each(v1.begin(),v1.end(),print);
}

void print(ItemRecords & item)
{
	cout<<"Name :"<<item.name<<endl;
	cout<<"Code :"<<item.code<<endl;
	cout<<"Cost :"<<item.cost<<endl;
	cout<<"Quantity :"<<item.quantity<<endl;
	
}

void searchRecord()
{
	vector<ItemRecords>::iterator it;
	ItemRecords item;
	cout<<"Enter Item Code to search :";
	cin>>item.code;
	it=find(v1.begin(),v1.end(),item);
	if (it!=v1.end())
	{
		cout<<"Item Code is found"<<endl;
	}
	else 
	{
		cout<<"Item Code not found"<<endl;
	}
}

void deleteRecord()
{
	vector<ItemRecords>::iterator it;
	ItemRecords item;
	cout<<"Enter Item Code to Delete :";
	cin>>item.code;
	it=find(v1.begin(),v1.end(),item);
	if (it!=v1.end())
	{
		v1.erase(it);
		cout<<"Item Code is found"<<endl;
		cout<<"\nAFTER DELETING, RECORDS ARE:"<<endl;
		displayRecord();
	}
	else 
	{
		cout<<"Item Code not found"<<endl;
	}
}

//Output
/*
-----------------------------------------------------------------------------
* * * MENU * * *
Enter 1 to Insert Records
Enter 2 to Display Records
Enter 3 to Search Records
Enter 4 to Sort Records
Enter 5 to Delete Records
Enter 6 to Exit
Enter your Choice :1

Enter Item Records :
Enter Name :ABC
Enter Code :123
Enter Cost :90
Enter Quantity :4
Item Inserted Sucessfully!!

-----------------------------------------------------------------------------
* * * MENU * * *
Enter 1 to Insert Records
Enter 2 to Display Records
Enter 3 to Search Records
Enter 4 to Sort Records
Enter 5 to Delete Records
Enter 6 to Exit
Enter your Choice :2

DISPLAYING RECORDS DETAILS:
Name :ABC
Code :123
Cost :90
Quantity :4

-----------------------------------------------------------------------------
* * * MENU * * *
Enter 1 to Insert Records
Enter 2 to Display Records
Enter 3 to Search Records
Enter 4 to Sort Records
Enter 5 to Delete Records
Enter 6 to Exit
Enter your Choice :6

EXITING THE PROGRAM!!!
*/