#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n = 0;
    cin >> n;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i <= 2)
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = arr[i - 1] + arr[i - 3];
        }
    }
    cout << arr[n - 1];
}