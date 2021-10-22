#include<iostream>
#include<algorithm>
#define MAX_NUM 500
using namespace std;

int main()
{
	int h, w;
	int heights[500] = { 0, }, max_left[MAX_NUM] = { 0, }, max_right[MAX_NUM] = { 0, };

	cin >> h >> w;

	for (int i = 0; i < w; i++)
	{
		int data;
		cin >> data;
		heights[i] = data;
	}

	max_left[0] = heights[0];
	max_right[w - 1] = heights[w - 1];
	for (int i = 0; i < w - 1; i++)
		max_left[i + 1] = max(max_left[i], heights[i + 1]);
	for (int i = w - 1; i > 0; i--)
		max_right[i - 1] = max(max_right[i], heights[i - 1]);

	int answer = 0;

	for (int i = 0; i < w; i++)
	{
		answer += min(max_left[i], max_right[i]) - heights[i];
	}

	cout << answer;
}
