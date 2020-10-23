#include<iostream>
using std::cin;
using std::cout;
#include<string>
using std::string;
#include<set>
using std::set;
#include<vector>
using std::vector;
#include<functional>
using std::greater;
class Graph
{
private:
    int numVertices;
    set<int,greater<int>> *adjacencyList;
public:
    Graph(int n)
    {
        this->numVertices=n;
        adjacencyList=new set<int,greater<int>>[n]; 
    }
    void addEdge(int a,int b)
    {
        adjacencyList[a].insert(b);
        adjacencyList[b].insert(a);
    }
    void printGraph()
    {
        for(auto i=0;i<numVertices;i++)
        {
            cout<<i<<"-->";
            set<int,greater<int>> tmp=adjacencyList[i];
            for(auto i=tmp.begin();i!=tmp.end();i++)
            {
                cout<<*i<<' ';
            }
            cout<<'\n';
        }
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(0,4);
    g.addEdge(4,1);
    g.addEdge(3,1);
    g.printGraph();
}