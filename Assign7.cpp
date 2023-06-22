/*7	Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the
populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the 
map, using the state name as an index and returns the population of the state.
*/

//Code
#include<iostream>
#include<map>
#include<iterator>
#include<string>
using namespace std;

int main()
{
	map<string,int>populationMap;
	string name,stateSearch;
	int population,n;
	cout<<"How many State's Population you want to enter :";
	cin>>n;
	
	//Inserting Details in Population Map
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the name & population of State "<<i+1<<" :"<<endl;;
		cin>>name>>population;
		populationMap[name]=population;
	}
	
	//Creating Iterator
	map<string,int>::iterator it;
	
	//Calculating Size of Population Size
	cout<<"Size of the Population Map :"<<populationMap.size()<<endl;
	
	//Displaying Population Map
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Displaying Population Map :"<<endl;
	cout<<"State : Population"<<endl;
	for (it=populationMap.begin();it!=populationMap.end();it++)
	{
		cout<<it->first<<" : "<<it->second<<endl;
	}
	cout<<"----------------------------------------------------------------------"<<endl;
	
	//Searching State in Population Map
	cout<<"Enter the name of state to be searched :";
	cin>>stateSearch;
	it=populationMap.find(stateSearch);
	if (it!=populationMap.end())
	{
		cout<<"State Found in Population Map"<<endl;
		cout<<stateSearch<<"'s Population is : "<<it->second<<endl;
	}
	else
	{
		cout<<"State not Found"<<endl;
	}
	populationMap.clear();
	return 0;
}

//Output
/*
How many State's Population you want to enter :3
Enter the name & population of State 1 :
Maharashtra
3000
Enter the name & population of State 2 :
Goa    
4000
Enter the name & population of State 3 :
Kerala
2000
Size of the Population Map :3
----------------------------------------------------------------------
Displaying Population Map :
State : Population
Goa : 4000
Kerala : 2000
Maharashtra : 3000
----------------------------------------------------------------------
Enter the name of state to be searched :Goa
State Found in Population Map
Goa's Population is : 4000
*/	
