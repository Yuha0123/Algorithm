#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<int> input;


void DFS(vector<int> & result, vector<int> &num, int k);

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		input.push_back(num);
	}

	sort(input.begin(), input.end());

	vector<int> result;
	vector<int> num = input;
	DFS(result, num, 0);

}

void DFS(vector<int> &result, vector<int> &num, int k)
{
	if (result.size() == m)
	{
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << " ";
		cout << endl;
		return;
	}

	int prev_num = -1;

	for (int i = k; i < num.size(); i++)
	{
		if (num[i] != -1)
		{
			if (num[i] != prev_num)
			{
				result.push_back(num[i]);
				prev_num = num[i];
				num[i] = -1;
				DFS(result, num,i+1);
				result.pop_back();
				num[i] = input[i];
			}

		}
	}

}
