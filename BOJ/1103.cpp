#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cctype>

using namespace std;

int n, m;
int limit;
vector<vector<int>> map;
vector<vector<int>> is_visit;	// using DP!

int max_cnt = 0;


void DFS(int i, int j, int cnt)
{
	if (i < 0 || j < 0 || i >= n || j >= m || map[i][j] == 0)
	{
		max_cnt = max(max_cnt, cnt);
		return;
	}
	else if (is_visit[i][j] >= cnt)
		return;
	
	else if (cnt > limit)
		return;

	int num = map[i][j];
	is_visit[i][j] = cnt;

	DFS(i + num, j, cnt + 1);
	DFS(i - num, j, cnt + 1);
	DFS(i, j + num, cnt + 1);
	DFS(i , j - num, cnt + 1);

}


int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vector<int> row;
		string str;
		
		cin >> str;

		for (int j = 0; j < m; j++)
		{
			if (isdigit(str[j]))
				row.push_back(str[j] - '0');
			else
			{	//H
				row.push_back(0);
			}
		}

		map.push_back(row);
		is_visit.push_back(vector<int> (m, -1));
	}

	limit = n * m;

	DFS(0, 0, 0);

	if (limit < max_cnt)
		cout << -1;
	else
		cout << max_cnt;
}
