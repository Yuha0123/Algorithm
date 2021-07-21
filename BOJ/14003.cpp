#include<iostream>
#include<algorithm>

#define MAX 1000000

using namespace std;

int n;
int dp[MAX];	//dp[i][1]: length of sequence
int datas[MAX], list[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	int num;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		datas[i] = num;
	}

	//dp
	dp[0] = 0;
	list[0] = datas[0];
	int cur_idx = 0;
	for (int i = 1; i < n; i++)
	{

		if (list[cur_idx] < datas[i])
		{
			list[++cur_idx] = datas[i];
			dp[i] = cur_idx;
		}
		else
		{
			int idx = lower_bound(list, list + cur_idx, datas[i]) - list;
			list[idx] = datas[i];
			dp[i] = idx;
		}

	}

	int cur_length = cur_idx;
	int result[MAX];
	for (int i = n - 1; i >= 0; i--)
	{
		if (dp[i] == cur_length)
		{
			result[cur_length] = datas[i];
			cur_length--;
		}
	}

	int length = cur_idx + 1;
	cout << length << "\n";

	for (int i = 0; i < length; i++)
		cout << result[i] << " ";
}
