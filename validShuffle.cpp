/* str1 = abc; str2= def; str3 = abdcef is one of a valid shuffle */

#include<iostream>
#include<string>
#include<set>

using namespace std;

set<pair<int, int> > cache;

bool validShuffle(const string& s1, const string& s2, const string& s3, int idx1, int idx2, int idx3)
{
    
    set<pair<int, int> >::iterator iter = cache.find(pair<int, int>(idx1, idx2));
    if(iter != cache.end())
        return false;

    if(idx1 == s1.length() && idx2 == s2.length() && idx3 == s3.length())
        return true;

    if(idx1>= s1.length() && idx2<s2.length())
        return(s2.compare(idx2, string::npos, s3, idx3, string::npos) == 0);

    if(idx2>= s2.length() && idx1<s1.length())
        return(s1.compare(idx1, string::npos, s3, idx3, string::npos) == 0);

    if(s1[idx1] == s3[idx3])
        if(validShuffle(s1, s2, s3, idx1+1, idx2, idx3+1))
            return true;
    
    if((s2[idx2] == s3[idx3]) && validShuffle(s1,s2,s3,idx1,idx2+1, idx3+1))
        return true;

    cache.insert(pair<int, int> (idx1, idx2));

    return false;    
}

int main()
{
    string s1, s2, s3;
    cin>>s1;
    cin>>s2;
    cin>>s3;
    bool valid = false;
    
    if(s1.length() + s2.length() == s3.length())
        valid = validShuffle(s1, s2, s3, 0, 0, 0);
    
    if(valid)
        cout << "Valid shuffle " << endl;
    else
        cout << "Not valid shuffle " << endl;
}
