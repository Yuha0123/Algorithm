#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int l, c;
vector<char> input;
vector<char> password;
int num_vowel = 0, num_conso = 0; 


bool is_vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return true;
	else
		return false;
}


void DFS(int count)
{
	if (password.size() == l)
	{
		if (num_vowel > 0 && num_conso > 1)
		{
			string s(password.begin(), password.end());
			cout << s << endl;
		}
		return;
	}
	if (count == c)
		return;

	for (int i = count; i < c; i++)
	{
		if (is_vowel(input[i]))
		{
			password.push_back(input[i]);
			num_vowel++;
			DFS(i + 1);
			password.pop_back();
			num_vowel--;
		}
		else {
			password.push_back(input[i]);
			num_conso++;
			DFS(i + 1);
			password.pop_back();
			num_conso--;
		}
	}



}

int main()
{
	cin >> l >> c;

	for (int i = 0; i < c; i++)
	{
		char c;
		cin >> c;
		input.push_back(c);
	}

	//sort alphabet
	sort(input.begin(), input.end());

	DFS(0);


}
