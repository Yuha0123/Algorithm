#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
pair<int, int> input[500000];
int tree[1 << 20] = { 0, };

bool my_compare(pair<int, int> a, pair<int, int>b)
{
	return a.second < b.second;
}


int seg_tree(int start, int end, int node, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && right >= end)
		return tree[node];

	int mid = (start + end) / 2;
	return seg_tree(start, mid, node * 2, left, right) + seg_tree(mid + 1, end, node * 2 + 1, left, right);
}

//index: node with changed value
void update_tree(int start, int end, int node, int index, int diff)
{
	if (index < start || index > end)
		return;


	if (start == end)
	{
		tree[node] += diff;
		return;
	}
		

	int mid = (start + end) / 2;
	update_tree(start, mid, node * 2, index, diff);
	update_tree(mid + 1, end, node * 2 + 1, index, diff);

	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input[i].second;
		input[i].first = i + 1;
	}

	sort(input, input + n, my_compare);

	//relabeling
	for (int i = 0; i < n; i++)
		input[i].second = i + 1;

	sort(input, input + n);

	for (int i = 0; i < n; i++)
	{
		int cur_power = input[i].second;
		int cnt = 0;

		cnt = seg_tree(0, n, 1, 0, cur_power - 1);

		update_tree(0, n, 1, cur_power, 1);


		cout << i + 1 - cnt << '\n';
	}


}
