#include<iostream>
#include<algorithm>
#define MAX 302

using namespace std;

int n;
int dp[MAX][2] = { 0, };	//i: i - 1번째 계단, j: 지금까지 밟은 계단의 수

int main()
{
	cin >> n;

	int num;
	for (int i = 2; i < n + 2; i++)
	{
		cin >> num;
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + num;
		dp[i][1] = dp[i - 1][0] + num;
	}


	int result = max(dp[n + 1][0], dp[n + 1][1]);
	cout << result;

}
