#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // 빈도수를 저장할 해시 테이블 (키: 요소, 값: 빈도수)
        unordered_map<int, int> count;
        for (int value : nums)
        {
            count[value]++;
        }
        // 정렬을 위해 빈도수와 요소를 쌍으로 벡터에 저장
        vector<pair<int, int>> freq_vec;
        for (auto &pair : count)
        {
            freq_vec.push_back({pair.second, pair.first}); // {빈도수, 요소} => 거꾸로 한것은 sort가 기본적으로 첫번째 인자를 기준으로 하기 때문
        }
        // 빈도수 기준 내림차순 정렬
        sort(freq_vec.begin(), freq_vec.end(), greater<>());
        vector<int> result;
        // 상위 k개의 요소만 결과 벡터에 저장
        for (int i = 0; i < k; i++)
        {
            result.push_back(freq_vec[i].second);
        }
        return result;
    }
};