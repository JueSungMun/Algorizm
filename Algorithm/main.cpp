#include "MY_HEADER.h"

#ifdef TEST
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<int> canEat[50], eaters[50];
int best;

void search(vector<int>& edible, int chosen)
{
	if(chosen >= best)
		return;
	int first = -1, t_size = 50;
	for(int i = 0; i < n; ++i)
	{
		if(edible[i] == 0)
		{
			if(t_size > canEat[i].size())
			{
				t_size = canEat[i].size();
				first = i;
			}	
		}
	}
	if(first == -1)
	{
    //best = min(best, chosen);
		best = chosen;
		return ;
	}

	for(int i = 0; i < canEat[first].size(); ++i)
	{
		int food = canEat[first][i];
		
		for(int j = 0; j < eaters[food].size(); ++j)
		{
			edible[eaters[food][j]]++;
		}
		
		search(edible, chosen+1);
		
		for(int j = 0; j < eaters[food].size(); ++j)
		{
			edible[eaters[food][j]]--;
		}
	}
}

int solve()
{
	best = 987654321;
	vector<int> edible(n);
	search(edible, 0);
	return best;
}

int main()
{
	int tc;
	for(cin >> tc; tc-- > 0;)
	{
		cin >> n >> m;
		vector<string> friend_name(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> friend_name[i];
		}
		for(int i = 0; i < m; ++i)
		{
			int food_like_count;
			cin >> food_like_count;
			eaters[i].resize(food_like_count);
			for(int j = 0; j < food_like_count; ++j)
			{
				string like_friend_name;
				cin >> like_friend_name;
				for(int k = 0; k < n; ++k)
				{
					if(like_friend_name == friend_name[k])
					{
						eaters[i][j] = k;
						canEat[k].push_back(i);
						break;
					}
				}
			}
		}
		cout << solve() << endl;
	}
	return 0;
}


/*
int main()
{
	int* arr = new int[10];
	
	for(int i = 0; i<10; i++)
		arr[i] = i+1;

	cout<<"array Address : "<<arr<<endl;

	for(int i =0 ; i<10; i++)
	{
		cout<<"array["<<i<<"] Address : "<<&arr[i]<<endl;
	}

	int* arr2 = new int[10];
	
	for(int i = 0; i<10; i++)
		arr2[i] = i+1;


	cout<<"array Address : "<<arr2<<endl;

	for(int i =0 ; i<10; i++)
	{
		cout<<"array["<<i<<"] Address : "<<&arr2[i]<<endl;
	}

	int* arr3 = new int[10];
	
	for(int i = 0; i<10; i++)
		arr3[i] = i+1;


	cout<<"array Address : "<<arr3<<endl;

	for(int i =0 ; i<10; i++)
	{
		cout<<"array["<<i<<"] Address : "<<&arr3[i]<<endl;
	}

	delete[] arr;
	delete[] arr2;
	delete[] arr3;
	return 0;
}
*/
#endif