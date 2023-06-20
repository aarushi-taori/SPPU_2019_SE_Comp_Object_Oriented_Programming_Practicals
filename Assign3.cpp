/*3	Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores 
the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type 
int) and tape which adds a playing time in minutes (type float).Write a program that instantiates the book and tape class, allows 
user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.
*/

//Code
#include<iostream>
#include<string.h>
using namespace std;

class publication
{
	protected:
	char name[30];
	float price;
	
	public:
	virtual void get_data()=0;
	virtual void display_data()=0;
	
};

class book:public virtual publication
{
	private:
	int page_count;
	
	public:
	void get_data();
	void display_data();
};

class tapes:public virtual publication
{
	private:
	int tape_time;
	
	public:
	void get_data();
	void display_data();
	
};

void book::get_data()
{
	cout<<"\nEnter the Title of the Book :";
	cin>>name;
	try
	{
		cout<<"\nEnter the Price of the Book :";
		cin>>price;
		if (price>1000)
		{
			throw price;
		}
	}
	catch (float) 
	{
		cout << "\n Price is too high !! Enter Afforable Price :";
		cin>>price;
	}
	cout<<"\nEnter the Page Count of the Book :";
	cin>>page_count;
}

void tapes::get_data()
{
	cout<<"\nEnter the Title of the Audio Cassette :";
	cin>>name;
	
	try
	{
		cout<<"\nEnter the Price of the Audio Cassette :";
		cin>>price;
		if (price>1000)
		{
			throw price;
		}
	}
	catch (float) 
	{
		cout << "\n Price is too high !! Enter Afforable Price :";
		cin>>price;
	}
	cout<<"\nEnter the Time of Cassette in Minutes :";
	cin>>tape_time;
}

void book::display_data()
{
	cout<<"TITLE OF BOOK: "<<name<<endl;
	cout<<"PRICE OF BOOK: "<<price<<endl;
	cout<<"PAGE COUNT: "<<page_count<<endl;
}

void tapes::display_data()
{
	cout<<"TITLE OF AUDIO CASSETTE: "<<name<<endl;
	cout<<"PRICE OF AUDIO CASSETTE: "<<price<<endl;
	cout<<"TIME OF AUDIO CASSETTE: "<<tape_time<<endl;
}


int main()
{
	publication *p[50];
	int ch,n;
	int i=0;
	
	do
	{
		cout<<"\n\tMENU"<<endl;
		cout<<"Enter 1 for Book Input\nEnter 2 for Audio Cassette Input\nEnter 3 for Display\nEnter 4 for Exit"<<endl;
		cin>>ch;
		
		switch(ch)
		{
			case 1: cout<<"\n----------------------------------------------------------------------------\n";
					cout<<"BOOK INPUT :"<<endl;
					p[i]=new book();
					p[i]->get_data();
					i++;
					cout<<"----------------------------------------------------------------------------\n";
					break;
			
			case 2: cout<<"\n----------------------------------------------------------------------------\n";
					cout<<"AUDIO CASSETTE INPUT :"<<endl;
					p[i]=new tapes();
					p[i]->get_data();
					i++;
					cout<<"----------------------------------------------------------------------------\n";
					break;
					
			case 3: cout<<"\nDISPLAYING PUBLICATION RECORDS :"<<endl;
					n=i;
					for (i=0;i<n;i++)	
					{
						cout<<"----------------------------------------------------------------------------\n";
						p[i]->display_data();
						cout<<"----------------------------------------------------------------------------\n";
					}
					break;
			case 4: cout<<"\nEXITING THE PROGRAM !!"<<endl;
					exit(0);
					break;
					
			}
	}while(ch>=1 && ch<=4);
	return 0;

}

//Output
/*
        MENU
Enter 1 for Book Input
Enter 2 for Audio Cassette Input
Enter 3 for Display
Enter 4 for Exit
1
----------------------------------------------------------------------------
BOOK INPUT :
Enter the Title of the Book :ABC
Enter the Price of the Book :90
Enter the Page Count of the Book :100
----------------------------------------------------------------------------
        MENU
Enter 1 for Book Input
Enter 2 for Audio Cassette Input
Enter 3 for Display
Enter 4 for Exit
2
----------------------------------------------------------------------------
AUDIO CASSETTE INPUT :
Enter the Title of the Audio Cassette :XYZ
Enter the Price of the Audio Cassette :40
Enter the Time of Cassette in Minutes :120
----------------------------------------------------------------------------
        MENU
Enter 1 for Book Input
Enter 2 for Audio Cassette Input
Enter 3 for Display
Enter 4 for Exit
3
DISPLAYING PUBLICATION RECORDS :
----------------------------------------------------------------------------
TITLE OF BOOK: ABC
PRICE OF BOOK: 90
PAGE COUNT: 100
----------------------------------------------------------------------------
----------------------------------------------------------------------------
TITLE OF AUDIO CASSETTE: XYZ
PRICE OF AUDIO CASSETTE: 40
TIME OF AUDIO CASSETTE: 120
----------------------------------------------------------------------------
        MENU
Enter 1 for Book Input
Enter 2 for Audio Cassette Input
Enter 3 for Display
Enter 4 for Exit
4
EXITING THE PROGRAM !!
*/