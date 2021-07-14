#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXLEN 101

using namespace std;

int n, m;
int dp[MAXLEN][MAXLEN];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	memset(dp, 0x3f, sizeof(dp));

	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;

		dp[a][b] = min(dp[a][b], cost);
	}

	for (int i = 1; i <= n; i++)
		dp[i][i] = 0;

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
		}
	}

	int num = 0x3f3f3f3f;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == num)
				cout << "0 ";
			else
				cout << dp[i][j] << " ";
		}
			
		cout << "\n";
	}

}
