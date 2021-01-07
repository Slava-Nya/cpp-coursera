#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int sin, cnt;
	vector<int> nums;

	cin >> cnt;
	while (cnt > 0)
	{
		cin >> sin;
		nums.push_back(sin);
		cnt--;
	}
	sort(nums.begin(), nums.end(), [](int i, int j)
		{ return (abs(i) < abs(j)); });
	for (const auto& i : nums)
		cout << i << " ";
	cout << endl;
	return 0;
}
