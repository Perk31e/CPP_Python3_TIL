#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
    int num = 0;
    cin >> num;
    vector<string> target(num + 1, "");
    // target의 첫번째 인덱스에 패턴을 제공한다.
    for (int i = 0; i < num + 1; i++)
    {
        cin >> target[i];
    }
    int star_idx = target[0].find('*');
    string front = target[0].substr(0, star_idx);
    string back = target[0].substr(star_idx + 1);

    for (int i = 1; i < num + 1; i++)
    {
        if (target[i].length() >= front.length() + back.length())
        {
            if (target[i].substr(0, front.length()) == front && target[i].substr(target[i].length() - back.length()) == back)
            {
                cout << "DA" << '\n';
            }
            else
            {
                cout << "NE" << '\n';
            }
        }
        else
        {
            cout << "NE" << '\n';
        }
    }
    return 0;
}