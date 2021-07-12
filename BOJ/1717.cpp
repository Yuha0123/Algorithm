#include<iostream>
#define MAX_LEN 1000001

using namespace std;

int arr[MAX_LEN];
int n, m;

void merge(int a, int b);
bool union_find(int a, int b);
int find_parent(int a);

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	ios_base::sync_with_stdio(false);


	cin >> n >> m;

	for (int i = 0; i <= n; i++)
		arr[i] = -1;

	for (int i = 0; i < m; i++)
	{
		int cmd, a, b;

		cin >> cmd >> a >> b;

		if (cmd == 0)
			merge(a, b);
		else
		{
			if (union_find(a, b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

}

void merge(int a, int b) 
{
	int pa, pb;

	pa = find_parent(a);
	pb = find_parent(b);

	if (pa != pb)
		arr[pa] = pb;

}


int find_parent(int a)
{
	if (arr[a] == -1)
		return a;

	int parent = arr[a];

	return arr[a] = find_parent(parent);
}

bool union_find(int a, int b)
{
	if (find_parent(a) == find_parent(b))
		return true;
	else
		return false;
}
