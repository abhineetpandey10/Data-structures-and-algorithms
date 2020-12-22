#include<iostream>
using std::cin;
using std::cout;
#include<vector>
using std::vector;
#include<set>
using std::set;
#include<cstring>
class edge
{
public:
    int src,dest;
    edge(int a,int b)
    {
        src=a;
        dest=b;
    }
};
class disjoint_sets
{
public:
    int n;
    int *parent,*rank;
    disjoint_sets(int n)
    {
        parent=new int[n];
        rank=new int[n];
        memset(rank,0,sizeof(rank));
        for(int i=0;i<n;i++) 
            parent[i]=i;
    }
    int find(int u)
    {
        if(parent[u]!=u)
            parent[u]=find(parent[u]);
        return parent[u];
    }
    void merge(int x,int y)
    {
        if(rank[x]>rank[y])
            parent[y]=x;
        else
            parent[x]=y;
        if(rank[x]==rank[y])
            rank[y]+=1;
    }
}; 
class graph
{
public:
    vector<edge> edgeList;
    int V,E;
    graph()
    {
        cout<<"Enter the number of vertices:\n";
        cin>>V;
        cout<<"Enter the numberof edges:\n";
        cin>>E;
        cout<<"Enter the vertices constituting each edge \n"
            <<"Each vertex must be between 0 and "<<V-1<<", both 0 and "<<V-1<<" inclusive\n";
        for(int i=0;i<E;i++)
        {
            int a,b;
            cin>>a>>b;
            edge newEdge(a,b);
            edgeList.push_back(newEdge);
        }
    }
    bool containsLoop()
    {
        disjoint_sets sets(V);
        for(int i=0;i<E;i++)
        {
            int a=sets.find(edgeList[i].src),b=sets.find(edgeList[i].dest);
            if(a==b) return true;
            else
                sets.merge(a,b);
        }
        return false;
    }
};
int main()
{
    graph g;
    if(g.containsLoop())
        cout<<"The graph contains Loop\n";
    else 
        cout<<"The graph does not contain a loop\n";
}
