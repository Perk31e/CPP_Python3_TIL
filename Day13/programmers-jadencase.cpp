#include <string>
#include <vector>

using namespace std;
vector<string> split(string target)
{
    vector<string> result;
    int start = 0;
    while (true)
    {
        int idx = target.find(" ", start);
        if (idx == string::npos)
        {
            result.push_back(target.substr(start));
            break;
        }
        else
        {
            int length = idx - start;
            result.push_back(target.substr(start, length));
            start = idx + 1;
        }
    }
    return result;
}
string solution(string s)
{
    vector<string> test = split(s);
    // 문장 내 각 문자열 내에서
    for (int i = 0; i < test.size(); i++)
    {
        for (int j = 0; j < test[i].length(); j++)
        {
            if (j == 0)
            {
                // A = 97, Z = 122
                if (static_cast<int>(test[i][0]) >= 97 && static_cast<int>(test[i][0]) <= 122)
                {
                    test[i][j] = test[i][j] - 32;
                }
            }
            else
            {
                // a = 65, z = 90
                if (static_cast<int>(test[i][j]) >= 65 && static_cast<int>(test[i][j]) <= 90)
                {
                    test[i][j] = test[i][j] + 32;
                }
            }
        }
    }
    string answer = "";
    for (int i = 0; i < test.size(); i++)
    {
        answer += test[i];
        if (i < test.size() - 1)
        {
            answer += " ";
        }
    }
    return answer;
}