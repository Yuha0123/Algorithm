#include<iostream>
#include<algorithm>
#define PIV (1<<11)

using namespace std;

int n, m;
int tree[PIV * 2] = { 0, };
pair<int, int> datas[4000000];


long long acc_sum(int start);
void update(int node);

int main()
{
	cin >> n >> m;
	int a, b;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		datas[i] = make_pair(a, b);
	}

	sort(datas, datas + m);

	long long cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cnt += acc_sum(datas[i].second);
		update(datas[i].second - 1);
	}

	cout << cnt;
}



long long acc_sum(int start)
{
	long long result = 0 ;

	int end = PIV + n - 1;
	start += PIV;

	while (start <= end)
	{
		if (start % 2 == 1)
		{
			result += tree[start++];
		}
		if (end % 2 == 0)
		{
			result += tree[end--];
		}
		start /= 2;
		end /= 2;
	}
	return result;
}

void update(int node)
{
	node += PIV;

	while (node > 0)
	{
		tree[node]++;
		node /= 2;
	}
}
