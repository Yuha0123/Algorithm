#include<iostream>
#include<algorithm>
#define MAX 502
using namespace std;

int n;
int dp[MAX][MAX] = { 0, };


int main()
{
	cin >> n;

	int num;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> num;
			dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) + num;
		}
	}
	int result = *max_element(dp[n], dp[n] + MAX);
	cout << result;
}
