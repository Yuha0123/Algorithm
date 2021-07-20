#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define MAX 1000000000

using namespace std;



int main()
{
	while (true)
	{
		vector<string> cmd;
		string input;

		//input command
		while (cin >> input)
		{
			if (input == "QUIT")
				return 0;
			if (input == "END")
				break;

			cmd.push_back(input);
		}

		int n, num;
		vector<int> datas;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			datas.push_back(num);
		}

		for (int i = 0; i < n; i++)
		{
			vector<long long> stack;
			bool error = false;

			stack.push_back(datas[i]);

			for (int j = 0; j < cmd.size(); j++)
			{
				string cur_cmd = cmd[j];


				//no operand
				if (cur_cmd == "NUM")
				{
					int num = stoi(cmd[++j]);
					stack.push_back(num);
				}
				//one operand
				else if (cur_cmd == "POP")
				{
					if (stack.size() < 1) {
						error = true;
						break;
					}

					stack.pop_back();
				}
				else if (cur_cmd == "INV")
				{
					if (stack.size() < 1) {
						error = true;
						break;
					}

					stack[stack.size() - 1] = stack.back() * -1;
				}
				else if (cur_cmd == "DUP")
				{
					if (stack.size() < 1) {
						error = true;
						break;
					}

					stack.push_back(stack.back());
				}
				//two operands
				else if (cur_cmd == "ADD")
				{
					if (stack.size() < 2) {
						error = true;
						break;
					}

					long long b = stack.back();
					stack.pop_back();
					long long a = stack.back();
					stack.pop_back();

					stack.push_back(a + b);

				}
				else if (cur_cmd == "SUB")
				{
					if (stack.size() < 2) {
						error = true;
						break;
					}

					long long b = stack.back();
					stack.pop_back();
					long long a = stack.back();
					stack.pop_back();

					stack.push_back(a - b);
				}
				else if (cur_cmd == "MUL")
				{
					if (stack.size() < 2) {
						error = true;
						break;
					}

					long long b = stack.back();
					stack.pop_back();
					long long a = stack.back();
					stack.pop_back();

					stack.push_back(a * b);
				}
				else if (cur_cmd == "SWP")
				{
					if (stack.size() < 2) {
						error = true;
						break;
					}

					long long b = stack.back();
					stack.pop_back();
					long long a = stack.back();
					stack.pop_back();

					stack.push_back(b);
					stack.push_back(a);
				}

				else if (cur_cmd == "DIV")
				{
					if (stack.size() < 2) {
						error = true;
						break;
					}

					long long b = stack.back();
					stack.pop_back();
					long long a = stack.back();
					stack.pop_back();

					if (b == 0)
					{
						error = true;
						break;
					}

					int sign;

					if ((a^b) >= 0)
						sign = 1;
					else
						sign = -1;

					a = abs(a);
					b = abs(b);

					stack.push_back(sign * (a / b));

				}
				else if (cur_cmd == "MOD")
				{
					if (stack.size() < 2) {
						error = true;
						break;
					}
					long long b = stack.back();
					stack.pop_back();
					long long a = stack.back();
					stack.pop_back();

					if (b == 0)
					{
						error = true;
						break;
					}

					int sign;

					if (a > 0)
						sign = 1;
					else
						sign = -1;

					a = abs(a);
					b = abs(b);

					stack.push_back(sign * (a % b));
				}


				if (stack.size() > 0) {
					if (abs(stack.back()) > MAX)
					{
						error = true;
						break;
					}
				}
				
				
			}


			if (error || stack.size() != 1)
				cout << "ERROR\n";
			else
				cout << stack.back() << "\n";

		}



		cout << "\n";
	}


}
