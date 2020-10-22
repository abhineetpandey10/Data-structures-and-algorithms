#include<iostream>
using std::cin;
using std::cout;
#include<cstring>
#include<cstdlib>
#include<vector>
using std::vector;
#include<stack>
using std::stack;
class Graph
{
private:
    int V;
    vector<int> *adjacencyList;
public:
    Graph(int n)
    {
        this->V=n;
        adjacencyList=new vector<int>[V];
    }
    void addEdge(int a,int b)
    {
        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }
    void DFS(int start)
    {   
        stack<int> s;
        bool visited[V];
        memset(visited,0,sizeof(visited));
        int ptr=0;
        visited[start]=true;
        cout<<start<<' ';
        s.push(start);
        while(!s.empty())
        {
            for(int i=0;i<adjacencyList[s.top()].size();i++)
            {
                if(!visited[adjacencyList[s.top()][i]])
                {
                    visited[adjacencyList[s.top()][i]]=true;
                    cout<<adjacencyList[s.top()][i]<<' ';
                    s.push(adjacencyList[s.top()][i]);
                    i=0;
                }
                
            }
            s.pop();
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    //g.addEdge(3,4);
    //g.addEdge(4,5);
    //g.addEdge(0,5);
    //g.addEdge(0,7);
    //g.addEdge(6,7);
    //g.addEdge(3,6);
    g.addEdge(0,3);
    g.addEdge(2,4);
    g.addEdge(0,4);
    g.DFS(0);
}
