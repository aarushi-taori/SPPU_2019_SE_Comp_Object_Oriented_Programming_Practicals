/*Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and 
read the information from the file.
*/


//Code
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ofstream fout("StudentDetails.txt");		//Opening File in Write Mode using Constructor 
	int roll_no;
	char name[20];
	char address[60];
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Enter Student Details -"<<endl;
	cout<<"Enter Roll No. :";
	cin>>roll_no;
	fout<<"Roll no. :"<<roll_no<<endl;
	cout<<"Enter Name :";
	cin.ignore();
	cin.getline(name,20);
	fout<<"Name :"<<name<<endl;
	cout<<"Enter Address :";
	//cin.ignore();
	cin.getline(address,60);
	fout<<"Address :"<<address<<endl;
	fout.close();
	
	
	ifstream fin;
	fin.open("StudentDetails.txt");		//Opening file in Read mode using functions
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Student Details are :"<<endl;
	fin>>roll_no;
	fin>>name;
	fin>>address;
	cout<<"\nRoll No. :"<<roll_no<<"\nName :"<<name<<"\nAddress :"<<address<<endl;
	fin.close();
	
	
	/*ofstream file;						//Opening File in Append Mode using functions
	int roll_no;
	char name[20];
	char address[60];
	file.open("StudentDetails.txt",ios::app);
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"Enter Student Details -"<<endl;
	for (int i=0;i<2;i++)
	{
		cout<<"Enter Roll No. :";
		cin>>roll_no;
		file<<"Roll no. :"<<roll_no<<endl;
		cout<<"Enter Name :";
		cin.ignore();
		cin.getline(name,20);
		file<<"Name :"<<name<<endl;
		cout<<"Enter Address :";
		cin.getline(address,60);
		file<<"Address :"<<address<<endl;
	}
	file.close();
	*/
	
	return 0;
}

//Output
/*
-------------------------------------------------------------------------
Enter Student Details -
Enter Roll No. :01
Enter Name :XYZ
Enter Address :Ram Road,Sita Colony
-------------------------------------------------------------------------
Student Details are :
Roll No. :0
Name :XYZ
Address :Ram Road,Sita Colony
*/