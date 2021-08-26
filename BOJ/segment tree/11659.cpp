#include<iostream>
#include<algorithm>
#define PIV (1<<18)

using namespace std;

int n, m;
int tree[PIV * 2] = { 0, };

void init();
int query(int l, int r);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tree[PIV + i] = num;
	}

	init();

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << query(a - 1, b - 1) << "\n";
	}

}

void init()
{
	for (int i = PIV - 1; i > 0; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
}

int query(int l, int r)
{
	l += PIV;
	r += PIV;

	int result = 0;
	while (l <= r)
	{
		if (l % 2 == 1)
			result += tree[l++];
		if(r % 2 == 0)
			result += tree[r--];
		l /= 2;
		r /= 2;
	}
	return result;
}
