// print all combinations

#include<iostream>
#include<stack>

using namespace std;

void printAllCombinations(string& str, int idx, stack<char>& result)
{
	if(idx == str.length())
	{
		printStack(result);
		return;
	}
	
	result.push(str[idx]);
	printAllCombinations(str, idx+1, result);
	result.pop();
	
	printAllCombinations(str,idx+1,result);
}
