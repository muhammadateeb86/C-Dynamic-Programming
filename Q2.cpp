#include <iostream>
using namespace std;

const int MX = 1001;
int vals[MX];
int dp[MX][MX];

int calcInt(int s, int e) {
    int sum = 0;
    for (int i = s; i < e; i++)
    {
        for (int j = i + 1; j <= e; j++)
        {
            sum += vals[i] * vals[j];
        }
    }
    return sum;
}

int minInt(int s, int e, int sp)
{
    if (s >= e)
    {
        return 0;
    }
    if (sp == 0)
    {
        return calcInt(s, e);
    }

    if (dp[s][sp] != -1)
    {
        return dp[s][sp];
    }

    int minVal = calcInt(s, e);
    for (int p = s; p < e; p++)
    {
        int intSplit = minInt(s, p, 0) + minInt(p + 1, e, sp - 1);
        minVal = min(minVal, intSplit);
    }

    dp[s][sp] = minVal;
    return minVal;
}

int main() {
    int n, ms;
    cin >> n >> ms;

    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    for (int i = 0; i < MX; i++)
    {
        for (int j = 0; j < MX; j++)
        {
            dp[i][j] = -1;
        }
    }

    cout << "Min interaction cost: " << minInt(0, n - 1, ms) << endl;

    return 0;
}
