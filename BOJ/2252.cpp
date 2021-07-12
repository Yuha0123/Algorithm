#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 32001
using namespace std;

int n, m;

vector<int> node[MAX];
int degree[MAX] = { 0, };

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;

		cin >> from >> to;

		node[from].push_back(to);
		degree[to]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		cout << v << " ";

		for (int i = 0; i < node[v].size(); i++)
		{
			int to = node[v][i];
			if ((--degree[to]) == 0)
				q.push(to);
		}
	}
}
