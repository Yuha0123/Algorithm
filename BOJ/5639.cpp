#include<iostream>
#include<algorithm>


using namespace std;


class node
{
public:
	int value = 0;
	node * left = nullptr;
	node * right = nullptr;

	node(int num)
	{
		value = num;
	}

	node()
	{
	}

};

void post_traverse(node * root);
node * create_node(int arr[], int start, int end);

int main()
{
	

	//get root
	int value, num = 0;
	int input[10000];
	node * root;

	while (cin >> value)
	{

		if(cin.eof())
			break;

		input[num++] = value;
	}

	root = create_node(input, 0, num);

	post_traverse(root);
}

void post_traverse(node * root)
{
	if (root != nullptr)
	{
		post_traverse(root->left);
		post_traverse(root->right);
		cout << root->value << endl;
	}
}

node * create_node(int arr[], int start, int end)
{
	if (end - start == 0)
		return nullptr;
	

	node * root = new node(arr[start]);

	if (end - start > 1)
	{
		int mid = upper_bound(arr + start + 1, arr + end, arr[start]) - arr;

		root->left = create_node(arr, start + 1, mid);
		root->right = create_node(arr, mid, end);
	}

	return root;
}
