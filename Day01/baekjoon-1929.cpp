#include <iostream>
using namespace std;

int main(void)
{
    int m, n, cnt;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        cnt = 0;
        // 1은 무조건 되니까 2부터 자기자신까지 중에 약수가 되는지 파악한다.
        for (int j = 2; j <= i; j++)
        {
            if (i % j == 0)
            {
                cnt++;
            }
            // cnt가 1보다 크면 자기자신 외에 약수가 된다는게 있다는것을 의미하니까 중단.
            if (cnt > 1)
            {
                break;
            }
            // 끝까지 도달했고 1을 제외하고 자기자신 밖에 없다면 해당 숫자 출력
            if ((j == i) && (cnt == 1))
            {
                cout << i << '\n';
            }
        }
    }
    return 0;
}
