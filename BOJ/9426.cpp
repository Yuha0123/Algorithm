#include<iostream>
#include<algorithm>
#define PIV (1<<18)
#define MAX 250000
using namespace std;

int n, k;
int tree[PIV * 2];
//count query: 

long long answer = 0;
int datas[MAX];

int query(int x);	//x번째에 있는 값을 찾아 반환
void update(int node, int diff);

int main()
{
	cin >> n >> k;

	int temp;
	for (int i = 0; i < k - 1; i++)
	{ 
		cin >> temp;
		datas[i] = temp;
		update(datas[i], 1);
	}

	int num = (k + 1) / 2;

	for (int i = k - 1; i < n; i++)
	{
		cin >> temp;
		datas[i] = temp;

		update(datas[i], 1);
		answer += query(num);
		update(datas[i - k + 1], -1);
	}

	cout << answer;
}

void update(int node, int diff)
{
	node += PIV;

	while (node > 0)
	{
		tree[node] += diff;
		node /= 2;
	}
}

int query(int x)
{
	//find index
	int index = 1;

	while (index < PIV)
	{
		index = index << 1;
		if (x > tree[index])
			x -= tree[index++];
	}

	return index - PIV;
}
