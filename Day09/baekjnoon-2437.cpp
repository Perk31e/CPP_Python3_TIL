#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int num;
    cin >> num;
    vector<int> weights(num, 0);
    for (int i = 0; i < num; i++)
    {
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());
    int target = 1;
    for (int weight : weights)
    {
        if (weight > target)
        {
            break;
        }
        target += weight;
    }
    cout << target;
    return 0;
}