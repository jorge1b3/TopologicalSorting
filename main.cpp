#include <list>
#include <iostream>

using std::list;
void add_edge(list<int> adj_list[], int u, int v);
void indegree(list<int> adj_list[], int indegree[], int n);
list<int> topological_sort(list<int> adj_list[], int indegree[], int n);

int main() {
    constexpr int V = 8;
    list <int> adj_list[V];
    add_edge(adj_list, 0, 2);
    add_edge(adj_list, 1, 2);
    add_edge(adj_list, 1, 3);
    add_edge(adj_list, 1, 4);
    add_edge(adj_list, 3, 5);
    add_edge(adj_list, 4, 6);
    add_edge(adj_list, 5, 6);
    add_edge(adj_list, 6, 7);
    add_edge(adj_list, 5, 7);


    int indegreeList[V];
    for (int i = 0; i < V; i++) {
        indegreeList[i] = 0;
    }

    indegree(adj_list, indegreeList, V);
    list<int> sortedList = topological_sort(adj_list, indegreeList, V);

    for (int i : sortedList) {
        std::cout << i << " ";
    }

    return 0;
}

void add_edge(list<int> adj_list[], int u, int v) {
    adj_list[u].push_back(v);
}
void indegree(list<int> adj_list[], int indegree[], int n) {
    for (int i = 0; i < n; i++) {
        for (auto j = adj_list[i].begin(); j != adj_list[i].end(); j++) {
            indegree[*j]++;
        }
    }
}
list<int> topological_sort(list<int> adj_list[], int indegree[], int n) {
    list<int> queue;
    list<int> topological_order;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue.push_back(i);
        }
    }
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        topological_order.push_back(u);
        for (auto i = adj_list[u].begin(); i != adj_list[u].end(); i++) {
            indegree[*i]--;
            if (indegree[*i] == 0) {
                queue.push_back(*i);
            }
        }
    }
    if(topological_order.size() != n) {
        std::cout << "Hay un ciclo en el grafo" << std::endl;
    }
    return topological_order;
}
