#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int GCD(int a, int b);

int main()
{
	int num_1, num_2, den_1, den_2;	//numerator, denominator
	int num_result, den_result;
	vector<int> prime;

	cin >> num_1 >> den_1;
	cin >> num_2 >> den_2;

	
	int gcd_result = GCD(den_1, den_2);
	den_result = (den_1 * den_2) / gcd_result;

	num_result = num_1 * (den_result / den_1) + num_2 * (den_result / den_2);

	gcd_result = GCD(num_result, den_result);
	num_result /= gcd_result;
	den_result /= gcd_result;


	cout << num_result << " " << den_result;

}


int GCD(int a, int b)
{
	if (a%b == 0)
		return b;
	else
		return GCD(b, a%b);

}
