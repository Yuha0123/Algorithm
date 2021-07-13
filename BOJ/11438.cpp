#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 100001
#define MAX_DEPTH 18

using namespace std;
int n, m;
vector<int> node[MAX];
bool visited[MAX] = { 0, };
int parent[MAX_DEPTH][MAX];
int depth[MAX];

void DFS(int x);

int LCA(int a, int b);

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);


	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}

	//make tree
	for (int i = 0; i < MAX_DEPTH; i++) {
		for (int j = 0; j <= n; j++)
			parent[i][j] = -1;
	}

	depth[1] = 1;
	DFS(1);


	
	for (int i = 1; i < MAX_DEPTH; i++){
		for (int j = 1; j <= n; j++)
			parent[i][j] = parent[i-1][parent[i - 1][j]];
	}


	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << LCA(a, b) << "\n";

	}
}

void DFS(int cur_node)
{
	visited[cur_node] = 1;

	for (int next_node : node[cur_node])
	{
		if (visited[next_node] == 1)
			continue;

		parent[0][next_node] = cur_node;
		depth[next_node] = depth[cur_node] + 1;
		DFS(next_node);
	}
}

int LCA(int a, int b)
{
	
	if (depth[a] > depth[b])
		swap(a, b);
	int diff = depth[b] - depth[a];
	
	//두 노드의 높이를 맞춰 줌.
	for (int i = 0; i < MAX_DEPTH; i++)
	{
		int power = 1 << i;

		if ((power&diff) == power)
			b = parent[i][b];
	}

	//한 노드가 다른 노드의 자식 노드였을 경우
	if (b == a)
		return a;

	//거슬러 올라가며 공통 부모를 찾는다
	for (int i = MAX_DEPTH - 1; i >= 0; i--)
	{
		if (parent[i][a] != parent[i][b])
		{
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return parent[0][a];

}
