#include<iostream>
#include<algorithm>
#include<cstring>

#define MAX 100001
using namespace std;

int n, m;
int parent[MAX];
int diff[MAX];

void merge(int a, int b, int new_diff);
int find_parent(int a);
void cal_diff(int a, int b);


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	

	while (true)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			break;
		memset(parent, 0xFF, sizeof(int)*(n+1));
		memset(diff, 0, sizeof(int)*(n + 1));

		for (int i = 0; i < m; i++)
		{
			char cmd;
			int a, b, c;

			cin >> cmd;
			
			if (cmd == '!')
			{
				cin >> a >> b >> c;
				merge(a, b, c);
			}
			else
			{
				cin >> a >> b;
				cal_diff(a, b);
			}
		}
	}
}

void merge(int a, int b, int new_diff)
{
	int pa = find_parent(a), pb = find_parent(b);

	if (pa != pb)
	{
		parent[pb] = pa;
		diff[pb] = new_diff - diff[b]  + diff[a];
	}
}

int find_parent(int a)
{
	if (parent[a] == -1)
		return a;

	int b = parent[a];
	int root = find_parent(b);
	diff[a] = diff[a] + diff[b];

	return parent[a] = root;
}

void cal_diff(int a, int b)
{
	if (find_parent(a) == find_parent(b))
		cout << diff[b] - diff[a] << "\n";
	else
		cout << "UNKNOWN\n";
}
