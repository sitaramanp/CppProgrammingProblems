#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void reverseString(string& str)
{
    reverse(str.begin(), str.end());

    int i=0; 
    int strSize = str.size();
    int start = 0;
    while(str[i] == ' ' && i<strSize) ++i;
    start = i;
    for(; i<strSize; ++i)
    {
        
        if(str[i] == ' ')
        {
            reverse(str.begin()+start, str.begin()+i);
            while(str[i] == ' ' && i<strSize) ++i;
            start = i;
        }
    }
    if(str[strSize-1] != ' ')
    {
        reverse(str.begin()+start, str.end());
    }
}

int main()
{
    string s = "      ";
    reverseString(s);
    cout << s << endl;
    string s2 = "       you are   in                y";
    reverseString(s2);
    cout << s2 << endl;
}


