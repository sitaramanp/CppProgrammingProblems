// Given a number as string, find a greater than that, which is also a palindrome

#include<iostream>
#include<string>
#include<math.h>

using namespace std;

string findNextPalindrome(string& sNum)
{
	int mid1=0, mid2=0;
	if(sNum.length()%2 != 0)
		mid1 = mid2 = sNum.length()/2;
	else
	{
		mid2 = sNum.length()/2;
		mid1 = mid2-1;
	}
	
	string orig = sNum;
	//mirror the left of mid2 to the right of mid2
	for(int i=0, j=sNum.length()-1; i <= mid2; ++i, --j)
		sNum[j] = sNum[i];
	
	if(sNum.compare(orig) > 0)
		return sNum;
	
	if(sNum[mid1] != '9')
	{
		sNum[mid2] = sNum[mid1] = sNum[mid1] + 1;
		return sNum;
	}
		
	int first = sNum[0] - '0' +1;
	int zeros = pow(10, sNum.length()-1);
	string value = to_string(first * zeros);
	return findNextPalindrome(value);

}

int main()
{
	string sNum;
	cin >> sNum;
	cout << findNextPalindrome(sNum)<<endl;
}