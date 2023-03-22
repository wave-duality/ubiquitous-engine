#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef pair<int, int> Cow;  // fav -> second fav
typedef pair<int, int> Edge;  // first: cow, second: to_node

Cow COWS[100001];  // cow 1..100000
vector<Edge> NODES[100001];  // each node represents a cereal 1..10000
unordered_set<int> VISITED;  // visited nodes

void dfs_component(int node, vector<int>& cows_in_span_tree, unordered_set<int>& component) {
    component.insert(node);
    for (const auto& e : NODES[node]) {
        if (component.count(e.second)) continue;

        cows_in_span_tree.push_back(e.first);
        dfs_component(e.second, cows_in_span_tree, component);
    }
}

vector<int> find_cows_not_in_tree(const unordered_set<int>& component, const unordered_set<int>& cows_in_tree) {
    unordered_set<int> cows_not_in_tree;
    for (const auto& node : component) {
        for (const auto& e : NODES[node]) {
            if (!cows_in_tree.count(e.first)) {
                cows_not_in_tree.insert(e.first);
            }
        }
    }
    vector<int> result;
    for (int c : cows_not_in_tree) result.push_back(c);
    return result;
}

int find_next_cow(int node, const unordered_set<int>& cows) {
    for (const auto& e : NODES[node]) {
        if (cows.count(e.first)) {
            return e.first;
        }
    }
    return -1;
}

void dfs_cows(int c, unordered_set<int>& cows, vector<int>& ordered_cows) {
    if (cows.empty()) return;

    ordered_cows.push_back(c);
    cows.erase(c);

    if (auto n = find_next_cow(COWS[c].first, cows); n > 0) {
        dfs_cows(n, cows, ordered_cows);
    }
    if (auto n = find_next_cow(COWS[c].second, cows); n > 0) {
        dfs_cows(n, cows, ordered_cows);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
 
    for (int i = 1; i <= N; ++i) {
        auto& x = COWS[i];
        cin >> x.first >> x.second;

        NODES[x.first].push_back(make_pair(i, x.second));
        NODES[x.second].push_back(make_pair(i, x.first));
    }

    int hungry = 0;
    vector<int> result;
    for (int node = 1; node <= M; ++node) {
        if (VISITED.count(node)) continue;

        vector<int> selected_cows;
        unordered_set<int> component;
        dfs_component(node, selected_cows, component);

        unordered_set<int> cows_in_tree;
        for (int c : selected_cows) cows_in_tree.insert(c);
        auto cows_not_in_tree = find_cows_not_in_tree(component, cows_in_tree);
        if (cows_not_in_tree.empty()) { // spanning tree has all the edges (i.e. cows)
            result.insert(result.end(), selected_cows.begin(), selected_cows.end());
        } else {
            hungry += cows_not_in_tree.size()-1;

            int saved_cow = cows_not_in_tree[0];
            result.push_back(saved_cow);
            
            int start_cow = -1;
            for (int c : selected_cows) {
                const auto& cow = COWS[c];
                if (cow.first == COWS[saved_cow].first || cow.second == COWS[saved_cow].first) { // must exist one
                    start_cow = c;
                    break;
                }
            }           
            vector<int> reordered_cows;
            dfs_cows(start_cow, cows_in_tree, reordered_cows);
            result.insert(result.end(), reordered_cows.begin(), reordered_cows.end());       

            for (int i = 1; i < cows_not_in_tree.size(); ++i) {  // hungry cows
                result.push_back(cows_not_in_tree[i]);
            }
        }

        // mark all nodes in the component as visited
        for (const auto& node : component) {
            VISITED.insert(node);
        }
    }
    cout << hungry << endl;
    for (const auto& r : result) {
        cout << r << endl;
    }
    
    return 0;
}