#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 1001

using namespace std;

int parent[MAX];

bool is_cycle(int a, int b);
int find_parent(int a);
void merge(int a, int b);

int main()
{

	int n, m;

	for (int i = 0; i < MAX; i++)
		parent[i] = -1;

	cin >> n >> m;

	vector <pair<int, pair<int, int>>> q(m);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;

		cin >> from >> to >> cost;
		q[i] = make_pair(cost, make_pair(from,to));
	}

	sort(q.begin(), q.end());

	int total_cost = 0;
	int num_edge = 0;
	for(int i=0;i<m;i++)
	{
		int cost = q[i].first, from = q[i].second.first, to = q[i].second.second;
		q[i];

		if (!is_cycle(from, to))
		{
			total_cost += cost;
			merge(from, to);
			num_edge++;

		}

		if (num_edge == n - 1)
			break;
	}

	cout << total_cost;
}

int find_parent(int a)
{
	if (parent[a] == -1)
		return a;

	return parent[a] = find_parent(parent[a]);
}

bool is_cycle(int a, int b)
{
	if (find_parent(a) == find_parent(b))
		return true;
	else
		return false;
}

void merge(int a, int b)
{
	int pa = find_parent(a), pb = find_parent(b);

	if (pa != pb)
		parent[pa] = pb;

}
