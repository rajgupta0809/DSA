#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class Graph {
    public:
    unordered_map<int,list<int> >graph;

    void addEdge(int u, int v, bool isDirected){
        graph[u].push_back(v);

        if(!isDirected){
            graph[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto node: graph){
            cout<<node.first<<"->";
            for(auto connected: node.second){
                cout<<connected<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(0,4,1);
    g.addEdge(1,3,1);
    g.addEdge(1,2,1);
    g.addEdge(3,2,1);
    g.addEdge(4,3,1);

    g.printGraph();
    return 0;
}