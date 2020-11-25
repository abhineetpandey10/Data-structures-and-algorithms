#include<iostream>
using std::cin;
using std::cout;
#include<vector>
using std::vector;
#include<queue>
using std::queue;
#include<cstring>
class graph
{
public:
    int listSize;
    vector<int> *adjList;
    bool *visited;
    graph(int n)
    {
        listSize=n;
        adjList=new vector<int>[n];
        visited=new bool[listSize];
        for(int i=0;i<listSize;i++) visited[i]=false;
    }
    void addEdge(int a,int b)
    {
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    void bfs(int a)
    {
        queue<int> q;
        q.push(a);
        visited[a]=true;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            cout<<node<<' ';
            for(int i=0;i<adjList[node].size();i++)
            {
                if(!visited[adjList[node][i]])
                {
                    visited[adjList[node][i]]=true;
                    q.push(adjList[node][i]);
                }
            }
        }
        cout<<'\n';
    }
    void connectedComp()
    {
        for(int i=0;i<listSize;i++)
        {
            if(!visited[i]) bfs(i);
        }
    }
};
int main()
{
    int v,e;
    cout<<"Enter the number of vertices: \n";
    cin>>v;
    graph g(v);
    cout<<"Enter the number of edges: \n";
    cin>>e;
    cout<<"Enter the vertices of each edge: \n";
    while(e--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);   
    }
    g.connectedComp();
}
