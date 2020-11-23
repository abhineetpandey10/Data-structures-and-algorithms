#include<iostream>
using std::cin;
using std::cout;
#include<string>
using std::string;
int *generatelps(string s)
{
    int l=s.length();
    int i=1,len=0;
    int *lps=new int[l];
    lps[0]=0;
    while(i<l)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0) len--;
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
void kmp(string s,string p)
{
    int *lps=generatelps(p),l=s.length(),m=p.length();
    int i=0,j=0;
    while(i<l)
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"Pattern Found at "<<i-j<<'\n';
            j=lps[j-1];
        }
        else if(s[i]!=p[j])
        {
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
}
int main()
{
    string s,pattern;
    cin>>s>>pattern;
    kmp(s,pattern);
}
