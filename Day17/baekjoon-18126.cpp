#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<pair<int, ll>> graph[5001]; // 그래프 (연결된 방, 거리)
bool visited[5001]; // 방문 여부
ll max_dist = 0; // 최대 거리

// DFS로 최대 거리를 탐색
void dfs(int node, ll dist) {
    visited[node] = true;
    max_dist = max(max_dist, dist);
    
    for (auto& next : graph[node]) {
        int next_node = next.first;
        ll next_dist = next.second;
        
        if (!visited[next_node]) {
            dfs(next_node, dist + next_dist);
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    // 그래프 입력 받기
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        ll C;
        cin >> A >> B >> C;
        
        // 양방향 그래프 구성
        graph[A].push_back({B, C});
        graph[B].push_back({A, C});
    }
    
    // 1번 방에서 시작
    dfs(1, 0);
    
    cout << max_dist << endl;
    
    return 0;
}