#include<iostream>
using std::cin;
using std::cout;
#include<vector>
using std::vector;
#include<queue>
using std::queue;
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
    void bfs(int n)
    {
        queue<int> q;
        q.push(n);
        bool visited[numVertices];
        memset(visited,0,sizeof(visited));
        visited[n]=true;
        cout<<"The BFS traversal of the given graph is :\n";
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            cout<<v<<' ';
            for(int i=0;i<adjList[v].size();i++)
            {
                if(!visited[adjList[v][i]])
                {
                    visited[adjList[v][i]]=true;
                    q.push(adjList[v][i]);
                }
            }
        }
        cout<<'\n';
    }
    void bfs()
    {
        bfs(0);
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
    g.bfs();
    int ini=0;
    cout<<"Enter the vertex from which you want to start the BFS:\n";
    cin>>ini;
    g.bfs(ini);
}
