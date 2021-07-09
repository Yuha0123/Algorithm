#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

void cal_prime_number(vector<int> &arr);

int main()
{
	int N;
	vector<int> arr;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	}


	vector<int> prime_number;
	cal_prime_number(prime_number);
	vector<int> counter(prime_number.size(), 0);
	
	vector<vector<int>> prime_factor;

	//count prime factors of all number
	for (int i = 0; i < arr.size(); i++)
	{
		int num = arr[i];

		vector<int> temp(prime_number.size(), 0);

		for (int j = 0; j<prime_number.size(); j++)
		{

			int c = 0;
			while (num % prime_number[j] == 0)
			{
				c++;
				num = num/prime_number[j];
			}
			
			temp[j] += c;
			counter[j] += c;
		}

		prime_factor.push_back(temp);
	}


	int result = 1;
	int cnt = 0;

	for (int i = 0; i < counter.size(); i++)
	{
		int quotient = counter[i] / N;

		if (quotient > 0)
		{
			result *= pow(prime_number[i], quotient);

			for (int j = 0; j < N; j++)
			{
				if (prime_factor[j][i] < quotient)
					cnt += quotient - prime_factor[j][i];
			}

		}
	}


	cout << result << " " << cnt;
}

void cal_prime_number(vector<int> &arr)
{
	bool num[1000001] = { 0, };

	for (int i = 2; i <= 1000000; i++)	
	{
		if (num[i])
			continue;

		for (int j = i + i; j <= 1000000; j += i)
		{
			num[j] = true;
		}
	}

	for (int i = 2; i <= 1000000; i++)
	{
		if (!num[i])
			arr.push_back(i);
	}


}
