#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define MAXLEN 501
#define INF 10000000

using namespace std;

int n;
int cost[MAXLEN];
vector<int> pre[MAXLEN];
int degree[MAXLEN] = { 0, };

int result[MAXLEN] = { 0, };


int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin >> temp;
		cost[i] = temp;

		cin >> temp;
		while (temp != -1)
		{
			pre[temp].push_back(i);
			degree[i]++;
			cin >> temp;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
			result[i] = cost[i];
		}
	}


	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : pre[cur])
		{
			result[next] = max(result[next], cost[next] + result[cur]);
			degree[next]--;

			if (degree[next] == 0)	//선행되야할 건물을 모두 지음.
				q.push(next);
			
		}

	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << "\n";

}

