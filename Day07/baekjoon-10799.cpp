#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
int count_pieces(vector<char> target)
{
    stack<char> stack;
    int count = 0;

    for (int i = 0; i < target.size(); i++)
    {
        if (target[i] == '(')
        {
            stack.push('(');
        }
        // ')' 인경우
        else
        {
            // 여태 '(' 만 넣다가 ')' 등장했으니 바로 () 짝이 만났다는것을 의미 => pop 수행
            stack.pop();

            // 레이저인 경우 (바로 이전 문자가 '(' 이면)
            if (target[i - 1] == '(')
            {
                count += stack.size();
            }
            else
            {
                count += 1;
            }
        }
    }
    return count;
}
int main(void)
{
    string s1;
    getline(cin, s1);
    vector<char> arrangement(s1.begin(), s1.end());
    cout << count_pieces(arrangement);
    return 0;
}