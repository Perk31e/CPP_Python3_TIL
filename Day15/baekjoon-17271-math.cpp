#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main()
{
    int N, M;
    cin >> N >> M;

    // dp[i] = i초 동안 스킬을 사용하는 모든 경우의 수
    vector<long long> dp(N + 1, 0);
    dp[0] = 1; // 아무것도 사용하지 않는 경우(0초)는 1가지

    for (int i = 1; i <= N; i++)
    {
        // A 스킬을 사용하는 경우 (1초)
        dp[i] = dp[i - 1];

        // B 스킬을 사용하는 경우 (M초)
        if (i >= M)
        {
            dp[i] = (dp[i] + dp[i - M]) % MOD;
        }
    }

    cout << dp[N] << endl;
    return 0;
}