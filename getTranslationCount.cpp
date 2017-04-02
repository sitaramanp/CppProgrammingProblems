// there are 5 different ways to translate 12258. 1->a 12->l etc..

#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>

using namespace std;

int findNumWays(string& num)
{
	if(num.length() == 0)
		return 0;

	if(num[0] < '0' || num[0] > '9')
		throw invalid_argument("string not a valid number");
		
	int count = 0;
	vector<int> dp(2,1);
	
	for(int i=1; i<num.length(); ++i)
	{
		if(num[i] < '0' || num[i] > '9')
			throw invalid_argument("string not a valid number");
		
		if( num[i-1] > '2' || (num[i-1] == '2' && num[i] > '6') )
			count = dp[0];
		else
			count = dp[0] + dp[1];
		
		dp[1] = dp[0];
		dp[0] = count;
		count = 0;		
	}
	return dp[0];
}

int main()
{
	string num = "12258";
	cout << findNumWays(num) << endl;
}