#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAXLEN 20001

using namespace std;

int n, m;
int start;
vector<pair<int, int>> node[MAXLEN];


int main()
{
	cin >> n >> m;
	cin >> start;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;

		cin >> u >> v >> w;
		node[u].push_back(make_pair(w, v));	//(cost, end)
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	vector<int> dist(n + 1, -1);

	q.push(make_pair(0, start));
	dist[start] = 0;

	while (!q.empty())
	{
		int cur_node = q.top().second, cost = q.top().first;
		q.pop();

		for (pair<int, int> p : node[cur_node])
		{
			int next_cost = p.first, next = p.second;
			int new_dist = next_cost + cost;

			if (dist[next] == -1 || new_dist < dist[next])
			{
				dist[next] = new_dist;
				q.push(make_pair(new_dist, next));
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == -1)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}
}
