#include <bits/stdc++.h>

using namespace std;

int n, m;
string factorial[101][101];

string bigNumAdd(string n1, string n2)
{
    int sum = 0;
    string result;

    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r)
{
    if (n == r || r == 0)
        return "1";
    string &result = factorial[n][r];

    if (result != "")
        return result;

    result = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}

void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
}

int main()
{
    input();
    cout << combination(n, m);

    return 0;
}