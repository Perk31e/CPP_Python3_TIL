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

    // 각 단어 처리
    for (int i = 0; i < test.size(); i++)
    {
        for (int j = 0; j < test[i].length(); j++)
        {
            if (j == 0)
            {
                // 첫 글자는 대문자로 변환
                if (test[i][j] >= 'a' && test[i][j] <= 'z')
                {
                    test[i][j] = test[i][j] - 32;
                }
            }
            else
            {
                // 나머지 글자는 소문자로 변환
                if (test[i][j] >= 'A' && test[i][j] <= 'Z')
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