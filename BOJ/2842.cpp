#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

int n, num_dest = 0;
pair<int, int> start;
bool dest[50][50];
int map[50][50];

set<int> height;


int BFS(int low, int high)
{
	int count = 0;
	queue<pair<int, int>> q;
	int dr[8] = { -1, 1, 0, 0, 1, 1, -1, -1 };
	int dc[8] = { 0, 0, -1 , 1, 1, -1, 1, -1 };
	bool visited[50][50] = { 0, };

	q.push(start);

	while (!q.empty())
	{
		pair<int, int> pos = q.front();
		q.pop();
		
		if (pos.first < 0 || pos.second < 0 || pos.first >= n || pos.second >= n)
			continue;
		if (map[pos.first][pos.second] < low || map[pos.first][pos.second] > high)
			continue;
		if (visited[pos.first][pos.second])
			continue;
		
		if (dest[pos.first][pos.second] == 1)
			count++;

		visited[pos.first][pos.second] = 1;
		for (int i = 0; i < 8; i++)
			q.push(make_pair(pos.first + dr[i], pos.second + dc[i]));

	}

	return count;
}


int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char c;
		for (int j = 0; j < n; j++)
		{
			cin >> c;
			
			if (c == 'P')
				start = make_pair(i, j);
			else if (c == 'K')
			{
				dest[i][j] = 1;
				num_dest++;
			}
				
			else
				dest[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		int num;
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			map[i][j] = num;

			height.insert(num);
		}
	}

	int min_diff = 1000000;
	set<int>::iterator left = height.begin(), right = height.begin();

	while (right!=height.end())
	{
		while (left != height.end())
		{
			int count = BFS(*left, *right);
			if (count == num_dest)
			{
				min_diff = min(min_diff, *right - *left);
				left++;
			}
			else
				break;
		}

		right++;
	}

	cout << min_diff;
}

