#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 16
#define MAXLEN (1<<16)

using namespace std;

int cost[MAX][MAX] = { 0, };
int n, p , cur_num = 0;
int dp[MAXLEN], cnt[MAXLEN] = { 0, };
int state = 0;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int num;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			cost[i][j] = num;
		}
	}
	//cin.clear();
	
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'Y')
		{
			state = state | (1 << i);
			cur_num++;
		}
		
	}

	cin >> p;
	
	memset(dp, -1, sizeof(dp));

	dp[state] = 0;
	cnt[state] = cur_num;

	for (int i = 0; i < (1 << n); i++)
	{
		if (dp[i] == -1)
			continue;

		for (int j = 0; j < n; j++)
		{
			if ((i & (1 << j)) == 0)
				continue;

			for (int k = 0; k < n; k++)
			{
				if (j == k)
					continue;

				int next_state = i | (1 << k);
				if (dp[next_state] == -1)
					dp[next_state] = dp[i] + cost[j][k];
				else
					dp[next_state] = min(dp[i] + cost[j][k], dp[next_state]);

				if(cnt[next_state]== 0)
					cnt[next_state] = cnt[i] + 1;
				else
					cnt[next_state] = min(cnt[i] + 1, cnt[next_state]);
				
			}
		}
	}


	int result = -1;

	for (int i = 0; i < (1 << n); i++ )
	{
		if (dp[i] == -1)
			continue;
		if (cnt[i] < p)
			continue;

		if (result == -1)
			result = dp[i];
		else
			result = min(result, dp[i]);

	}


	cout << result;
}

