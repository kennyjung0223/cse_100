// I used lecture notes and the following links for documentation:
//  - http://www.cplusplus.com/reference/list/list/
//  - http://www.cplusplus.com/reference/map/map/operator[]/
//  - http://www.cplusplus.com/reference/queue/queue/

#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Graph {
    list<string> vertices;
    map<string, list<string> > adjacent_edges;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void addVertex(string);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::addVertex(string vertex) {
    vertices.push_back(vertex);
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    edges[pair<string, string>(vert1, vert2)] = weight;
    adjacent_edges[vert1].push_back(vert2);
}

bool Graph::FindVertex(string vert1) {
    for (list<string>::iterator it = vertices.begin(); it != vertices.end(); it++) {
        if (*it == vert1) {
            return true;
        }
    }
    return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
    for (map<pair<string, string>, int>::iterator it = edges.begin(); it != edges.end(); it++) {
        if ((*it).first.first == vert1 && (*it).first.second == vert2) {
            return (*it).second;
        }
    }
    return -1;
}

int Graph::IsReachable(string vert1, string vert2) {
    int path = 0;

    if (vert1 == vert2) {
        return path;
    }

    queue<string> q;
    map<string, int> visited;
    q.push(vert1);
    visited[vert1] = 0;

    list<string> adjacents = adjacent_edges[q.front()];

    while (!q.empty()) {
        string current_vertex = q.front();
        path = visited[q.front()];
        list<string> adjacent_vertices = adjacent_edges[current_vertex];
        q.pop();

        for (list<string>::iterator it = adjacent_vertices.begin(); it != adjacent_vertices.end(); it++) {
            if (visited.find((*it)) == visited.end()) {
                if ((*it) == vert2) {
                    return path + 1;
                }
                q.push((*it));
                visited[(*it)] = path + 1;
            }
        }
    }

    return -1;
}

int main() {
    Graph G;

    bool running = true;
    bool inputting_vertex = true;
    bool inputting_edges = false;

    string input1;
    string input2;
    string input3;

    while (running) {
        cin >> input1;

        if (input1 == "0") {
            running = false;
        }
        else if (input1 == "1") {
            cin >> input2;
            cout << G.FindVertex(input2) << endl;
        }
        else if (input1 == "2") {
            cin >> input2;
            cin >> input3;
            cout << G.FindEdgeCost(input2, input3) << endl;
        }
        else if (input1 == "3") {
            cin >> input2;
            cin >> input3;
            cout << G.IsReachable(input2, input3) << endl;
        }
        else if (input1 == "END") {
            if (inputting_vertex) {
                inputting_vertex = false;
                inputting_edges = true;
            }
            else if (inputting_edges) {
                inputting_edges = false;
                G.PrintOut();
            }
        }
        else {
            if (inputting_vertex) {
                G.addVertex(input1);
            }
            else if (inputting_edges) {
                cin >> input2;
                cin >> input3;
                G.AddEdge(input1, input2, stoi(input3));
            }
        }
    }

    return 0;
}
