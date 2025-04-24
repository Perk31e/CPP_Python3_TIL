#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    // dp[i]: i번째 계단에 도달하기 위한 최소 이동 횟수
    vector<int> dp(N+1, -1);
    
    // 시작점 초기화
    dp[0] = 0;
    
    for (int i = 0; i <= N; i++) {
        if (dp[i] == -1) continue; // 아직 도달할 수 없는 계단
        
        // 한 칸 올라가기
        if (i + 1 <= N) {
            if (dp[i + 1] == -1 || dp[i + 1] > dp[i] + 1) {
                dp[i + 1] = dp[i] + 1;
            }
        }
        
        // 점프해서 올라가기 (i + [i/K])
        int jump = i + (i / K);
        if (jump <= N) {
            if (dp[jump] == -1 || dp[jump] > dp[i] + 1) {
                dp[jump] = dp[i] + 1;
            }
        }
    }
    
    // 결과 출력
    if (dp[N] != -1) {
        cout << "minigimbob" << '\n';
    } else {
        cout << "water" << '\n';
    }
    
    return 0;
}