#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std;

int n, t;
int card[MAX];
int table[MAX][MAX];
int take[MAX];

int dp(int l, int r, int player);


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> n;

		int num;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			card[j] = num;
			sum += num;
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				table[i][j] = -1;

		int cnt = (n + 1) / 2;	//근우가 가져갈 카드의 수

		cout << dp(0, n - 1, 0) << "\n";
	}


}

int dp(int l, int r, int player)
{
	if (table[l][r] != -1)
		return table[l][r];
	if (l > r)
		return 0;


	if(player == 0)	//근우 차례
		return table[l][r] = max(card[l] + dp(l + 1, r, (player + 1) % 2), card[r] + dp(l, r - 1, (player + 1) % 2));
	else
		return table[l][r] = min(dp(l + 1, r, (player + 1) % 2), dp(l, r - 1, (player + 1) % 2));

}
