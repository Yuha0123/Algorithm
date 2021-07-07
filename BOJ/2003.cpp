#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m;
	vector<int> arr;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;

		cin >> num;
		arr.push_back(num);
	}

	int left =0 , right =0, sum = 0;
	int result = 0;

	while (true)
	{


		if (sum >= m)
		{
			sum = sum - arr[left];
			left++;
		}
		else if (right == n)
			break;
		else // if (sum < m)
		{
			sum = sum + arr[right];
			right++;
		}

		if (sum == m)
			result++;
		
	}

	
	cout << result;

	return 0;
}
