#include<iostream>
#include<algorithm>
#define MAX_WEIGHT 100000
#define MAX_NUM 100
using namespace std;

int n, k;

int dp[MAX_NUM + 1][MAX_WEIGHT + 1] = { 0, };

int main()
{
	cin >> n >> k;
	
	int w, v;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;

		for (int j = 1; j <= k;j++)
		{
			if (j >= w)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}


	int result = *max_element(dp[n], dp[n] + k + 1);
	cout << result;
}
