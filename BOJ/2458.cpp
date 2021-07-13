#include<iostream>
#include<algorithm>
#include<vector>
#define MAXLEN 501
#define INF 10000000

using namespace std;

int n, m;
int dp[MAXLEN][MAXLEN];

int main()
{
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF;
	}

	for (int i = 0; i <= n; i++)
		dp[i][i] = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		dp[a][b] = 1;
	}


	//Floyd Warshall
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
			{
				int new_dist = dp[i][k] + dp[k][j];

				if (dp[i][j] > new_dist)
					dp[i][j] = new_dist;
			}}}


	vector<int> cnt(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] < INF)
	{
				cnt[i]++;
				cnt[j]++;
			}}}

	int result = 0;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == n + 1)
			result++;

	cout << result;

}
