#include<iostream>
#define MAX 1000
#define DIV 10007

using namespace std;

int main()
{
	int n, k;
	int dp[MAX + 1][MAX + 1] = { 0, };

	cin >> n >> k;

	//init
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			dp[i + 1][j + 1] = (dp[i][j] + dp[i][j + 1]) % DIV;
		}
	}

	cout << dp[n][k];
}
