//Given two strings A and B, the task is to convert A to B if possible
//The only operation allowed is to put any character from A and insert it at front.
//Input:  A = "EACBD", B = "EABCD"
//Output: 3
//
//

#include<iostream>
#include<string.h>

using namespace std;

int findNumMoves(const string &s1, const string &s2)
{
    if(s1.length() != s2.length())
        return -1;
    int hash[256];
    memset(hash, 0, sizeof(hash));
    for(int i=0; i<s1.length(); ++i)
        hash[s1[i] ] = hash[s1[i] ] +1;

    for(int i=0; i<s2.length(); ++i)
        hash[s2[i] ] = hash[s2[i] ] - 1;
    
    for(int i=0; i<256; ++i)
        if(hash[i] != 0)
            return -1;

    int ret = 0;
    int i = s1.length()-1;
    int j = i;
    while(i>=0 && j>=0)
    {
        if(s1[i] == s2[j])
        {
            --i;
            --j;
        }
        else{
            ++ret;
            --i;
        }
    }

    return ret;    
        
}

int main()
{
    string s1, s2;
    cin>>s1;
    cin>>s2;
    int res = findNumMoves(s1,s2);
    if(res == -1)
        cout << "Not possible " << endl;
    else
        cout << "moves = " << res << endl;
    return 0;
}
