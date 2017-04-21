// classic. print all permutation of given string

#include<iostream>
#include<string>

using namespace std;

void printPermute(string& str, int start)
{
	
	if(start == str.length())
	{
		cout << str <<  endl;
		return;
	}
	
	for(int i=start; i<str.length(); ++i)
	{
	    swap(str[i], str[start]);
		printPermute(str,start+1);
	    swap(str[i], str[start]);
	}	
}

void printPermute(string& str)
{
	printPermute(str, 0);
}
