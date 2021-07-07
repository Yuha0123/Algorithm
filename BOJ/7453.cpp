#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int A[4000], B[4000], C[4000], D[4000], ab[4000*4000], cd[4000*4000];


	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}



	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			ab[i*n + j] = (A[i] + B[j]);
			cd[i*n + j] = C[i] + D[j];
		}
	}

	long long result = 0;
	sort(cd, cd + n * n);
	long long m = n * n;

	for (int i = 0; i < n*n; i++)
	{
		int num = -ab[i];
		
		int upper = upper_bound(cd, cd + m, num) - cd;
		int low = lower_bound(cd, cd + m, num) - cd;

		result += upper - low;

	}



	cout << result;
}
