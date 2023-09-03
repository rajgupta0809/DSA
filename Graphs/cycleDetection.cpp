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

    //TC :-> O(V*E)
    bool isCyclePresentBFS(int src, unordered_map<int,bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;

        unordered_map<int,int> parent;
        parent[src]= -1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(auto nbr: graph[frontNode]){
                if(!visited[nbr]){
                    //not visited
                    q.push(nbr);
                    visited[nbr]= true;
                    parent[nbr] = frontNode;
                }else{
                    //visited
                    if(parent[frontNode] != nbr){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    //TC :-> O(V*E)
    bool isCyclePresentDFS(int src, unordered_map<int,bool> &visited, int parent){
        visited[src] = true;

        for(auto nbr: graph[src]){
            if(!visited[nbr]){
                bool aggeKaAns = isCyclePresentDFS(nbr,visited,src);
                if(aggeKaAns) return true;
            }else{
                if(nbr != parent) return true;
            }
        }
        return false;
    }

    //TC :-> O(V*E)
    bool isCyclePresentInDirectedDFS(int src, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited){
        visited[src] = true;
        dfsVisited[src] = true;

        for(auto nbr: graph[src]){
            if(!visited[nbr]){
                bool aageKaAns = isCyclePresentInDirectedDFS(nbr, visited, dfsVisited);
                if(aageKaAns) return true;
            }else{
                if(dfsVisited[nbr] == true) return true;
            }
        }
        dfsVisited[src] = false;
        return false;
    }
};

int main(){
    int n = 5; // number of nodes in the graph
    Graph g;
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,0,1);

    g.printGraph();

    bool ans = false;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            ans = g.isCyclePresentInDirectedDFS(i, visited, dfsVisited);
        }
    }

    cout<<ans<<endl;
    return 0;
}