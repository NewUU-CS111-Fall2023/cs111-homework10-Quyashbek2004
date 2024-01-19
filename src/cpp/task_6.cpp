#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Create an adjacency list to represent the graph
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& edge : times) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }

    // Initialize distances with infinity and set the distance to the source node to 0
    vector<int> distance(n + 1, INT_MAX);
    distance[k] = 0;

    // Priority queue to keep track of the nodes with the smallest distance
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        int u = pq.top().second;
        int u_distance = pq.top().first;
        pq.pop();

        if (u_distance > distance[u]) {
            continue;  // Skip if a shorter distance has already been found
        }

        // Relax edges outgoing from node u
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    // Check if all nodes are reachable and find the maximum time taken
    int maxTime = *max_element(distance.begin() + 1, distance.end());

    return (maxTime == INT_MAX) ? -1 : maxTime;
}

int main() {
    // Sample input
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n = 4;
    int k = 2;

    // Calculate the minimum time it takes for all nodes to receive the signal
    int result = networkDelayTime(times, n, k);

    // Output the result
    cout << "Minimum time: " << result << endl;

    return 0;
}
