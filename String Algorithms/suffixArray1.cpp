#include<iostream>
using std::cin;
using std::cout;
#include<algorithm>
using std::sort;
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<utility>
using std::pair;
bool compare(pair<string,int> a, pair<string,int> b)
{
    if(a.first<b.first) return true;
    return false;
}
int main()
{
    cout<<"Enter the string whose suffix array is to be formed: \n";
    string s;
    cin>>s;
    vector<pair<string,int>> suffixes;
    cout<<"The suffixes of the string are: \n";
    for(int i=0;i<s.length();i++)
    {
        string str=s.substr(i,s.length()-i);
        cout<<str<<' ';
        pair<string,int> tmp;
        tmp.first=str;
        tmp.second=i;
        suffixes.push_back(tmp);
    }
    cout<<'\n';
    sort(suffixes.begin(),suffixes.end(),compare);
    cout<<"The suffixes of the string sorted in lexicographical order are: \n";
    for(int i=0;i<suffixes.size();i++) cout<<suffixes[i].first<<' ';
    cout<<'\n';
    cout<<"The suffix array for the gievn string is: \n";
    for(int i=0;i<suffixes.size();i++)
        cout<<suffixes[i].second<<' ';
    cout<<'\n';
}
