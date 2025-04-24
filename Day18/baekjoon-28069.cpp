#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    const int INF = 1e9;
    vector<int> dp(N + 1, INF);
    dp[0] = 0; // 시작 지점

    for (int i = 0; i <= N; ++i)
    {
        if (i + 1 <= N)
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i + i / 2 <= N)
            dp[i + i / 2] = min(dp[i + i / 2], dp[i] + 1);
    }

    if (dp[N] <= K)
        cout << "minigimbob" << endl;
    else
        cout << "water" << endl;

    return 0;
}
