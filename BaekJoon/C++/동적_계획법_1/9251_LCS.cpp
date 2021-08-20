#include <iostream>
#include <vector>
using namespace std;

string str1, str2;

void Solve()
{
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));

    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[str1.size()][str2.size()];
}

int main()
{
    cin >> str1 >> str2;

    Solve();
}