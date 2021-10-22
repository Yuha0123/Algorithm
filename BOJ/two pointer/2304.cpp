#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, max_h=0;

	vector<pair<int,int>> arr;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, h;
		cin >> l >> h;

		arr.push_back(make_pair(l, h));
		max_h = max(h, max_h);
	}

	sort(arr.begin(), arr.end());

	int left = 0, right = n-1, answer = 0, max_temp = 0;

	//왼쪽에서부터 찾은 최댓값의 위치 찾기
	while (left < n - 1 && arr[left].second < max_h)
	{
		max_temp = max(max_temp, arr[left].second);
		answer += (arr[left + 1].first - arr[left].first)*max_temp;
		left++;
	}

	max_temp = 0;
	while (right > 0 && arr[right].second < max_h)
	{
		max_temp = max(max_temp, arr[right].second);
		answer += (arr[right].first - arr[right - 1].first)*max_temp;
		right--;
	}

	answer += (arr[right].first - arr[left].first + 1)*max_h;

	cout << answer;

}
