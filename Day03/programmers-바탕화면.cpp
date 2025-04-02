#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper)
{
    vector<pair<int, int>> location;
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].length(); j++)
        {
            if (wallpaper[i][j] == '.')
            {
                continue;
            }
            if (wallpaper[i][j] == '#')
            {
                location.push_back({i, j});
            }
        }
    }
    int small_x = location[0].first;
    int small_y = location[0].second;
    int large_x = location[0].first;
    int large_y = location[0].second;
    for (int k = 0; k < location.size(); k++)
    {
        small_x = min(small_x, location[k].first);
        small_y = min(small_y, location[k].second);
        large_x = max(large_x, location[k].first);
        large_y = max(large_y, location[k].second);
    }
    vector<int> answer = {small_x, small_y, large_x + 1, large_y + 1};
    return answer;
}