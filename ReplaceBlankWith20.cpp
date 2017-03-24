//replace each blank in a string with “%20”.
//
//“We%20are%20happy.” if the input is “We are happy.”.

#include<iostream>
#include<string>

using namespace std;

void replaceString(string& str)
{
    int numSpace = 0;
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] == ' ')
            ++numSpace;
    }

    if(numSpace == 0)
        return;
    int oldEnd = str.length();    
    int newEnd = 1+str.length() + 2*numSpace ;
    str.resize(newEnd);
    
    //str[newEnd] = '\0';
    int j = oldEnd-1;
    for(int i = newEnd-1; i >=0; --j, --i)
    {
        if(str[j] != ' ')
            str[i] = str[j];
        else
        {
            str[i] = '0';
            str[--i] = '2';
            str[--i] = '%';
        }
    }
}

int main()
{
    string str = "   We are   Happy   ";
    replaceString(str);
    cout << str << endl;
}
