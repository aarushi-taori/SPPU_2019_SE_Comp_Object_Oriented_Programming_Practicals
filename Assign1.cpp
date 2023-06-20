/*COMPLEX NUMBERS CLASS - OPERATOR OVERLOADING
Implement a class 'complex' which represents complex number datatype. Implement the following :
a.) Constructor (a default constructor which creates a complex number 0+0i)
b.) Overload Operator '+' to add two complex number
c.) Overload Operator '*' tomultiply two complex nos.
d.) Overload Operator "<<" & ">>" to print & read complex nos. */

//Code
#include<iostream>
using namespace std;

class complex
{
	private:
	float real,imag;
	
	public:
	
	complex()
	{
		real=0;
		imag=0;
	}
	
	~ complex(){}
	
	friend istream &operator >>(istream&in, complex &t);
	friend ostream &operator <<(ostream&out, complex &t);
	complex operator+(complex t);
	complex operator*(complex t);
	
};

complex complex::operator+(complex t)
{
	complex add;
	add.real=real+t.real;
	add.imag=imag+t.imag;
	return add;
}

complex complex::operator*(complex t)
{
	complex temp;
	temp.real=real*t.real-imag*t.imag;
	temp.imag=real*t.imag+t.real*imag;
	return temp;
}

istream &operator >>(istream&in, complex &t)
{
	cout << "Enter Real Part :";
	in >> t.real;						
	cout << "Enter Imaginary Part :";
	in >> t.imag;
	return in;
}

ostream &operator <<(ostream&out, complex &t)
{
	if(t.imag>=0)
	{
		out<<t.real<<"+"<<t.imag<<"i\n";
	}
    else
    {
		out<<t.real<<t.imag<<"i\n";
	}
	return out;
}

int main()
{
	complex c1,c2,c3;
	int ch;
	
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"Enter 1st Complex Number:"<<endl;
	cin>>c1;
	cout<<"Enter 2nd Complex Number:"<<endl;
	cin>>c2;
	
	cout<<"\n* * * MENU * * *"<<endl;
	cout<<"Enter 1 for Addition of Complex Numbers\nEnter 2 for Multiplication of Complex Number\nEnter 3 to Exit"<<endl;
	cin>>ch;
	
	switch(ch)
	{
		case 1:	cout<<"-----------------------------------------------------------------"<<endl;
				cout<<"ADDITION OF COMPLEX NUMBERS :";
				c3=c1+c2;
				cout<<c3;
				break;
				
		case 2: cout<<"-----------------------------------------------------------------"<<endl;
				cout<<"MULTIPLICATION OF COMPLEX NUMBERS :";
				c3=c1*c2;
				cout<<c3;
				break;
				
		case 3: cout<<"Exiting the Program"<<endl;
				break;
				
		default: cout<<"Wrong Input !!!"<<endl;
	}
	return 0;
}

//Output :
/*
-----------------------------------------------------------------
Enter 1st Complex Number:
Enter Real Part :5
Enter Imaginary Part :3
Enter 2nd Complex Number:
Enter Real Part :7
Enter Imaginary Part :3

* * * MENU * * *
Enter 1 for Addition of Complex Numbers
Enter 2 for Multiplication of Complex Number
Enter 3 to Exit
1
-----------------------------------------------------------------
ADDITION OF COMPLEX NUMBERS :12+6i
*/