#include<iostream>
using std::cin;
using std::cout;
#include<vector>
using std::vector;
#include<stack>
using std::stack;
#include<cstring>
class graph
{
public:
    int v,e;
    vector<int> *adjList;
    bool *visited;
    graph()
    {
        cout<<"Enter the number of vertices:\n";
        cin>>v;
        adjList=new vector<int>[v];
        cout<<"Enter the number of edges\n";
        cin>>e;
        cout<<"Enter the vertices constituting each edge\n"
            <<"Each vertex must be between 0 and "<<v-1<<", both 0 and "<<v-1<<" inclusive\n";
        for(int i=0;i<e;i++)
        {
            int a,b;
            cin>>a>>b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        visited=new bool[v];
        memset(visited,0,v*sizeof(bool));
    }
    void DFS(int n)
    {
        stack<int> s;
        s.push(n);
        //cout<<"The DFS traversal starting from the node "<<n<<"is:\n";
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            if(!visited[node])
            {
                visited[node]=true;
                cout<<node<<' ';
                for(int i=0;i<adjList[node].size();i++)
                    s.push(adjList[node][i]);
            }
        }
        cout<<'\n';
    }
    void DFS()
    {
        for(int i=0;i<v;i++)
            if(!visited[i])
                DFS(i);
    }
};
int main()
{
    graph g;
    g.DFS();
    return 0;
}
