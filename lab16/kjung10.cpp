// I used the lecture notes, TA Arman's skeleton code, and video: https://www.youtube.com/watch?v=cplfcGZmX7I&ab_channel=MichaelSambol
// I also used this typedef to reduce clutter: https://en.cppreference.com/w/cpp/language/typedef
// Here are more references I used for understanding the pair documentation
//  - http://www.cplusplus.com/reference/utility/pair/
//  - http://www.cplusplus.com/reference/utility/pair/operators/

#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pairs;

void run_prim(vector<vector<pairs>> g) {
    priority_queue<pairs, vector<pairs>, greater<pairs>> q;
    vector<int> keys(g.size(), INT_MAX);
    vector<int> pred(g.size(), 0);
    vector<bool> visited(g.size(), false);

    q.push(make_pair(0, 0));

    while (!q.empty()) {
        int u = q.top().second;
        visited[u] = true;

        q.pop();

        for (pairs p : g[u]) {
            int v = p.first;
            int w = p.second;

            if (!visited[v] && w < keys[v]) {
                keys[v] = w;
                pred[v] = u;
                q.push(make_pair(w, v));
            }
        }
    }

    for (int i = 1; i < g.size(); i++) {
        cout << pred[i] << endl;
    }
}

int main() {

    int v_size;
    int e_size;

    cin >> v_size;
    cin >> e_size;

    vector<vector<pairs>> g;

    for (int i = 0; i < v_size; i++) {
        vector<pairs> temp;
        g.push_back(temp);
    }

    for (int i = 0; i < e_size; i++) {
        int u, v, w;
        cin >> u;
        cin >> v;
        cin >> w;

        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }

    run_prim(g);

    return 0;
}