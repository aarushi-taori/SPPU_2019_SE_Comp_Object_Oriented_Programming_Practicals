/*5	Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.	
*/

//Code
#include <iostream>
using namespace std;

template <class S>

class sorting
{
	private:
	S array[200],temp;
	int n,min_pos;
	
	public:
	void take_input();
	void display();
	void selection_sort();
	
};

template <class S>
void sorting<S> :: take_input()
{
	cout<<"Enter the number of elements present in Array :";
	cin>>n;
	
	for (int i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<" : ";
		cin>>array[i];
	}
}

template <class S>
void sorting<S> :: display()
{
	for (int i=0;i<n;i++)
	{
		cout<<array[i]<<"\t";
	}
	cout<<"\n";
}

template <class S>
void sorting<S> :: selection_sort()
{
	int i,j;
	min_pos=0;
	for (i=0;i<n;i++)
	{
		min_pos=i;
		for (j=i;j<n;j++)
		{
			if (array[j]<array[min_pos])
			{
				min_pos=j;
			}
		}
		temp=array[i];
		array[i]=array[min_pos];
		array[min_pos]=temp;
	}
}
	
int main()
{
	sorting <int> integer;
	sorting <float> decimal;
	sorting <char> character;
	sorting <string> strings[30];
	
	int ch,i;
	char con;
	
	do
	{
		cout<<"-------------------------------------------------------------------------------------"<<endl;
		cout<<"\t\t* * * MENU * * *"<<endl;
		cout<<"1. Integer Array\n2. Float Array\n3. Character Array\n4. String Array"<<endl;
		cout<<"Enter your Choice : ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:	cout<<"-----------------------------------------------------------------------------"<<endl;
					cout<<"INTEGER ARRAY"<<endl;
					integer.take_input();
					cout<<"Array Elements are :"<<endl;
					integer.display();
					integer.selection_sort();
					cout<<"Sorted Array is :"<<endl;
					integer.display();
					break;
					
			case 2: cout<<"-----------------------------------------------------------------------------"<<endl;
					cout<<"FLOAT ARRAY"<<endl;
					decimal.take_input();
					cout<<"Array Elements are :"<<endl;
					decimal.display();
					decimal.selection_sort();
					cout<<"Sorted Array is :"<<endl;
					decimal.display();
					break;
			
			case 3: cout<<"-----------------------------------------------------------------------------"<<endl;
					cout<<"CHARACTER ARRAY"<<endl;
					character.take_input();
					cout<<"Array Elements are :"<<endl;
					character.display();
					character.selection_sort();
					cout<<"Sorted Array is :"<<endl;
					character.display();
					break;
			
			case 4: cout<<"-----------------------------------------------------------------------------"<<endl;
					cout<<"STRING ARRAY"<<endl;
					strings[i].take_input();
					cout<<"Array Elements are :"<<endl;
					strings[i].display();
					strings[i].selection_sort();
					cout<<"Sorted Array is :"<<endl;
					strings[i].display();
					break;
					
			default: cout<<"--------------------------------------------------------------------------------"<<endl;
					 cout<<"Wrong Input...Enter a Correct Choice!!!"<<endl;
					 break;
		}
		cout<<"Do you want to continue (y/n) :";
		cin>>con;
		
	}while(con=='y' || con=='Y');

	return 0;
}

//Output
/*
-------------------------------------------------------------------------------------
                * * * MENU * * *
1. Integer Array
2. Float Array
3. Character Array
4. String Array
Enter your Choice : 1
-----------------------------------------------------------------------------
INTEGER ARRAY
Enter the number of elements present in Array :5
Enter element 1 : 9
Enter element 2 : 3
Enter element 3 : 6
Enter element 4 : 0
Enter element 5 : 2
Array Elements are :
9       3       6       0       2
Sorted Array is :
0       2       3       6       9
Do you want to continue (y/n) :y
-------------------------------------------------------------------------------------
                * * * MENU * * *
1. Integer Array
2. Float Array
3. Character Array
4. String Array
Enter your Choice : 3
-----------------------------------------------------------------------------
CHARACTER ARRAY
Enter the number of elements present in Array :4
Enter element 1 : A
Enter element 2 : O
Enter element 3 : Y
Enter element 4 : B
Array Elements are :
A       O       Y       B
Sorted Array is :
A       B       O       Y
Do you want to continue (y/n) :n
*/