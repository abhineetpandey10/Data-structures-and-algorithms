#include<iostream>
using std::cin;
using std::cout;
#include<vector>
using std::vector;
#include<stack>
using std::stack;
#include<cstring>
class directedGraph
{
public:
    vector<int> *adjList;
    int numVertices;
    directedGraph(int n)
    {
        numVertices=n;
        adjList=new vector<int>[n];
    }
    void addEdge(int start, int end)
    {
        adjList[start].push_back(end);
    }
    void dfs(int n)
    {
        stack<int> s;
        s.push(n);
        bool visited[numVertices];
        memset(visited,0,sizeof(visited));
        visited[n]=true;
        cout<<"The DFS traversal of the given graph is :\n";
        while(!s.empty())
        {
            int v=s.top();
            s.pop();
            cout<<v<<' ';
            for(int i=0;i<adjList[v].size();i++)
            {
                if(!visited[adjList[v][i]])
                {
                    visited[adjList[v][i]]=true;
                    s.push(adjList[v][i]);
                }
            }
        }
        cout<<'\n';
    }
    void dfs()
    {
        dfs(0);
    }
};
int main()
{
    int v,e;
    cout<<"Enter the number of vertices and edges, respectively:\n";
    cin>>v>>e;
    cout<<"Enter the start and end vertex of each of the directed edge:\n";
    cout<<"(Each value must be between 0 and "<<e-1<<" , both inclusive )\n";
    directedGraph g(v);
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    g.dfs();
    int ini=0;
    cout<<"Enter the vertex from which you want to start the DFS:\n";
    cin>>ini;
    g.dfs(ini);
}
