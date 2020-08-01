#include <bits/stdc++.h>
using namespace std;

class LCS
{
    //Longest Common Subsequence
public:
    int n, m;
    string s1, s2;
    vector<vector<int>> lcs;
    LCS(string a, string b)
    {
        s1 = a;
        s2 = b;
        n = s1.size();
        m = s2.size();
        lcs.assign(n + 1, vector<int>(m + 1, 0));
    }
    int calLCS()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                if (s1[i - 1] == s2[j - 1])
                {
                    lcs[i][j] = max(lcs[i][j], 1 + lcs[i - 1][j - 1]);
                }
            }
        }
        return lcs[n][m];
    }
    string getLCS()
    {
        string ans = "";
        int currx = n, curry = m;
        while (currx > 0 && curry > 0)
        {
            if (s1[currx - 1] == s2[curry - 1])
            {
                ans += s1[currx - 1];
                currx--;
                curry--;
            }
            else if (lcs[currx - 1][curry] > lcs[currx][curry - 1])
            {
                currx--;
            }
            else
            {
                curry--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};