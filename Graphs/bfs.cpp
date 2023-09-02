#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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

    void bfs(int src,unordered_map<int,bool>& visited){
      queue<int> q;

      q.push(src);
      visited[src] = true;

      while(!q.empty()){
        int front = q.front();
        q.pop();
        cout<<front<<", ";

        for(auto neighbour: graph[front]){
            if(!visited[neighbour]){
              q.push(neighbour);
              visited[neighbour] = true;
          }
        }
      }
    }
};

int main(){
    int n = 5; // number of nodes in the graph
    Graph g;
    unordered_map<int,bool> visited;
    g.addEdge(0,1,1);
    g.addEdge(0,4,1);
    g.addEdge(1,3,1);
    g.addEdge(1,2,1);
    g.addEdge(3,2,1);
    g.addEdge(4,3,1);

    g.printGraph();

    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.bfs(i, visited);
        }
    }
    return 0;
}