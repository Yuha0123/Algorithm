#include<iostream>
#include<algorithm>
#define PIV (1<<20)

using namespace std;

int n, m, k;
long input[1000001];
long long tree[PIV * 2] = { 0, };

void init();
void update(int node, long val);
long long query(int l, int r);


int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		long num;
		cin >> num;
		tree[PIV + i] = num;
	}	

	init();


	for (int i = 0; i < m + k; i++)
	{
		long cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 1)
			update(a - 1, b);
		else
		{
			cout <<	query(a - 1, b - 1) <<"\n";
		}
	}

}

void init()
{
	for (int i = PIV - 1; i > 0; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}
}

void update(int node, long val)
{
	node += PIV;
	tree[node] = val;
	node /= 2;

	while (node > 0)
	{
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		node /= 2;
	}
}

long long query(int l, int r)
{
	long long result = 0;

	l += PIV;
	r += PIV;

	while (l <= r)
	{
		if (l % 2 == 1)
			result += tree[l++];
		if (r % 2 == 0)
			result += tree[r--];
		l /= 2;
		r /= 2;

	}

	return result;
}
