/**
 * Jarvis Algorithm to find the convex hull of a set of points
 */
#include<iostream>
using std::cin;
using std::cout;
#include<utility>
using std::pair;
#include<vector>
using std::vector;
int crossProduct(pair<int,int> a, pair<int,int> b, pair<int,int> c)
{
    int res=(b.first-a.first)*(c.second-a.second)-(c.first-a.first)*(b.second-a.second);
    if(res<0) return -1; //vector(ab) is to the right of vector(ab)
    else if(res>0) return 1; //vector(ab) is to the left of vector(ab)
    else return 0; //a, b, c are collinear
}
void jarvisAlgorithm(pair<int,int> points[],int n)
{
    vector<pair<int,int>> hull;
    vector<pair<int,int>> collinearPoints;
    int leftmost=0;
    for(int i=0;i<n;i++)
        if(points[i].first<points[leftmost].first)
            leftmost=i;
    int current=leftmost;
    int next=0;
    do
    {
        //cout<<'a';
        hull.push_back(points[current]);
        next=(current+1)%n;
        for(int i=0;i<n;i++)
        {
            if(crossProduct(points[current],points[next],points[i])==1) next=i;
        }
        if(!collinearPoints.empty())
        {
            if(collinearPoints[collinearPoints.size()-1].first==collinearPoints[next].first && collinearPoints[collinearPoints.size()-1].second==collinearPoints[next].second)
                for(int j=0;j<collinearPoints.size();j++)
                    hull.push_back(collinearPoints[j]);
                collinearPoints.clear();
        }
        current=next;
    }while(current!=leftmost);
    for(int i=0;i<hull.size();i++) cout<<hull[i].first<<' '<<hull[i].second<<'\n';
    //cout<<'\n';
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<int,int> points[n];
        for(int i=0;i<n;i++) cin>>points[i].first>>points[i].second;
        jarvisAlgorithm(points,n);
    }
}
