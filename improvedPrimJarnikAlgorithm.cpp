#include<iostream>
using std::cin;
using std::cout;
#include<vector>
using std::vector;
#include<queue>
using std::priority_queue;
#include<utility>
using std::pair;
using std::make_pair;
#include<functional>
using std::greater;
class Compare
{
public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second>b.second;
    }
};
class Graph
{
public:
    vector<pair<int,int>> *adjList;
    int V;
    Graph()
    {}
    void addEdge(int u,int v,int wt)
    {
        adjList[u].push_back(make_pair(v,wt));
        adjList[v].push_back(make_pair(u,wt));
    }
    void primMST()
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
        vector<int> parent(V,-1);
        vector<bool> visited(V,false);
        vector<int> key(V,INT32_MAX);
        key[0]=0;
        //visited[0]=true;
        pq.push(make_pair(0,0));
        while(!pq.empty())
        {
            int nextNode=pq.top().first;
            pq.pop();
            if(visited[nextNode]) continue;
            visited[nextNode]=true;
            for(int i=0;i<adjList[nextNode].size();i++)
            {
                if(adjList[nextNode][i].second<key[adjList[nextNode][i].first] && !visited[adjList[nextNode][i].first])
                {
                    parent[adjList[nextNode][i].first]=nextNode;
                    key[adjList[nextNode][i].first]=adjList[nextNode][i].second;
                    pq.push(adjList[nextNode][i]);
                }
            }
        }
        cout<<"Edge\tWeight\n";
        for(int i=1;i<V;i++)
        {
            cout<<parent[i]<<"-"<<i<<" "<<key[i]<<'\n';
        }
    }
    void initGraph()
    {
        cout<<"Enter the number of Vertices:\n";
        int V,E;
        cin>>V;
        cout<<"Enter the vertices constituting each edge, followed by the weight of each edge in the next "<<E<<" lines\n"
            <<"The vertices must be between 0 and "<<V-1<<" ,both 0 and "<<V-1<<" inclusive\n";
        this->V=V;
        adjList=new vector<pair<int,int>>[V];
        for(int i=0;i<E;i++)
        {
            int u,v,wt;
            cin>>u>>v>>wt;
            addEdge(u,v,wt);
        }
    }
};
int main()
{
    Graph g;
    g.initGraph();
    g.primMST();
}
