#include <iostream>
#include <vector>
using namespace std;

// int main(){
//     int nodes, edges;
//     cout<<"Enter Total Number Of Nodes: " << endl;
//     cin>>nodes;
//     vector<vector<int> > adj(nodes, vector<int>(nodes,0));

//     cout<<"Enter total number of edges:"<<endl;
//     cin>>edges;

//     cout<<"Enter the Edges:"<<endl;
//     for(int i=0;i<edges;i++){
//         int node1, node2;
//         cin>>node1>>node2;

//         adj[node1][node2] = 1;
//         adj[node2][node1] = 1;
//     }

//     for(int i=0;i<nodes;i++){
//         for(int j=0;j<nodes;j++){
//             cout<<adj[i][j];
//         }
//         cout<<endl;
//     }
// }

int main() {
    int nodes, edges;

    cout << "Enter Total Number Of Nodes: ";
    cin >> nodes;

    cout << "Enter total number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(nodes, vector<int>(nodes, 0));

    cout << "Enter the Edges:" << endl;
    for (int i = 0; i < edges; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        if (node1 >= 0 && node1 < nodes && node2 >= 0 && node2 < nodes) {
            adj[node1][node2] = 1;
            adj[node2][node1] = 1;
        } else {
            cout << "Invalid node indices. Nodes must be between 0 and " << (nodes - 1) << endl;
            // You might want to handle this error more gracefully, e.g., by re-prompting for valid input.
            return 1; // Exit with an error code.
        }
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}