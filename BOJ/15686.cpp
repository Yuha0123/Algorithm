#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_SHOP 13
#define MAX_HOUSE 100
using namespace std;

int n, m, answer = (1<<30), cnt_house = 0,cnt_shop = 0;
pair<int, int> house[MAX_HOUSE], shop[MAX_SHOP];
vector<pair<int, int>> selected;

void DFS(int idx);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	

	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			
			if (num == 1)
				house[cnt_house++] = make_pair(i, j);
			else if (num == 2)
				shop[cnt_shop++] = make_pair(i, j);
		}
	}

	DFS(0);

	cout << answer;
}

void DFS(int idx)
{
	if (selected.size() > m)
		return;

	if (selected.size() == m)
	{
		//도시의 치킨 거리를 구한다. 
		int total_distance = 0;
		for (int i = 0; i < cnt_house; i++)
		{
			int distance = (1<<30), x_house = house[i].first, y_house = house[i].second;

			for (int j = 0; j < m; j++)
			{
				int x_shop = selected[j].first, y_shop = selected[j].second;
				distance = min(distance, abs(x_house - x_shop) + abs(y_house - y_shop));
			}
			total_distance += distance;
		}

		answer = min(answer, total_distance);
		return;
	}

	for (int i = idx; i < cnt_shop; i++)
	{
		selected.push_back(shop[i]);
		DFS(i + 1);
		selected.pop_back();
	}
}
