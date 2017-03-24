//matching re having . and * with a string
//
#include <iostream>
#include <string>

using namespace std;

bool matchPatternUtil(const char* string, const char* pattern)
{
    if(*string == '\0' && *pattern == '\0')
        return true;

    if(*string != '\0' && *pattern == '\0')
        return false;
    
    if(*(pattern+1) == '*')
    {
       if(*pattern == *string || (*pattern == '.' && *string != '\0'))
       {
           return(matchPatternUtil(string+1, pattern) ||
                    matchPatternUtil(string+1, pattern+2) ||
                    matchPatternUtil(string, pattern+2));    
        
       }
       else
          return(matchPatternUtil(string, pattern+2));   
    }
    else if(*string == *pattern || (*pattern == '.' && *string != '\0'))
        return matchPatternUtil(string+1, pattern+1);
    
    return false;
}

bool matchPattern(const char* string, const char* pattern)
{
    while(*pattern != '\0' && *pattern == '*')
        pattern++;
    if(*string == '\0' && *pattern == '\0')
        return true;
    
    return matchPatternUtil(string, pattern);
}

int main()
{
    string str = "aaa";
    //string pat = "ab*ac*a";
    string pat = "aa.a";

    cout << matchPattern(str.c_str(), pat.c_str()) << endl;
}
