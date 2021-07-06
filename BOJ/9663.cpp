#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int board[14] = { 0, };
int n, cnt = 0;

void DFS(int line);
bool check(int line);

void DFS(int line)
{
	if (line == n)
	{
		cnt++;

		return;
	}

	for (int i = 0; i < n; i++)
	{
		board[line] = i;
		if (check(line))
		{
			DFS(line + 1);
		}
	}



}

bool check(int line)
{
	if (line == 0)
		return true;

	for (int i = 0; i < line; i++)
	{
		if (board[line] == board[i])
			return false;

		if (abs(board[line] - board[i]) == line - i)
			return false;
	}

	return true;
}

int main()
{
	cin >> n;

	DFS(0);
	

	cout << cnt;
}
