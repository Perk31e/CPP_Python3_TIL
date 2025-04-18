#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n = 0, m = 0;
set<string> combinations;
// A 스킬의 시전 시간은 1초고, B 스킬의 시전 시간은 M초이다.
// 사용할 수 있는 모든 조합은?
void dp(int cur_time, string current)
{
    // 목표 시간 도달했을 때
    if (cur_time == n)
    {
        combinations.insert(current);
        return;
    }

    // 시간 초과 방지
    if (cur_time > n)
        return;

    // A 스킬 (1초)
    dp(cur_time + 1, current + 'a');

    // B 스킬 (m초)
    dp(cur_time + m, current + 'b');
}

// 찾아낸 조합 모아두기용

int main(void)
{
    cin >> n >> m;

    dp(0, "");
    cout << combinations.size();
    return 0;
}
