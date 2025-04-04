#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    vector<int> temps(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> temps[i];
    }
    int sum_result = accumulate(temps.begin(), temps.begin() + k, 0);
    int max_total = sum_result;
    for (int j = 0; j < n - k; j++)
    {
        sum_result = sum_result - temps[j] + temps[j + k];
        max_total = max(sum_result, max_total);
    }
    cout << max_total;
    return 0;
}