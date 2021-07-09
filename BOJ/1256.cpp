#include<iostream>
#include<string>
#include<algorithm>

#define MAX_K 1000000000
using namespace std;

int n, m, k;
int dp[101][101];

int number_case(int i, int j);
string get_word(int i, int j, int k);

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			dp[i][j] = -1;
	}
	
	for (int i = 0; i < 101; i++)
	{
		dp[0][i] = 1;
		dp[i][0] = 1;
	}

	int cnt = number_case(n,m);

	if (cnt < k)
		cout << -1;
	
	else 
		cout << get_word(n,m,k);
}

int number_case(int i, int j)
{
	if (i == 0 || j == 0)
		return 1;

	if (dp[i][j] != -1)
	{
		return dp[i][j];
	}
	
	dp[i][j] = min(number_case(i, j - 1) + number_case(i - 1, j),MAX_K);

	return dp[i][j];
}


string get_word(int i, int j, int k)
{
	string result = "";

	if (i == 0)
	{
		for (int s = 0; s < j; s++)
			result = result + "z";

		return result;
	}
	else if(j == 0)
	{
		for (int s = 0; s < i; s++)
			result = result + "a";

		return result;
	}

	if (k <= dp[i - 1][j])
		return "a" + get_word(i - 1, j, k);
	else
		return "z" + get_word(i, j - 1, k - dp[i - 1][j]);

}
