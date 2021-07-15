#include<iostream>
#include<algorithm>
#include<climits>
#define MAX 500 + 1

using namespace std;

int n;
int table[MAX][MAX];
int r[MAX] = { 0, }, c[MAX] = { 0, };

int dp(int l, int r);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;

	int a, b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		r[i] = a;
		c[i] = b;
	}

	for (int i = 0; i <= n ; i++){
		for (int j = 0; j <= n; j++)
			table[i][j] = -1;
	}

	cout << dp(1, n);
}


int dp(int left, int right)
{
	if (table[left][right] != -1)
		return table[left][right];

	if (right == left)
		return 0;
	
	int result = INT_MAX;
	
	if (right - left == 1)
		table[left][right] = r[left] * c[left] * c[right];
	else 
	{
		for (int i = left; i <= right; i++)
		{
			result = min(result, dp(left, i) + dp(i + 1, right) + r[left] * c[i] * c[right]);
			table[left][right] = result;
		}
	}


	return table[left][right];

}
