#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int64_t n, d, x, avg = 0;
	vector<int> degs;

	cin >> n;
	while (--n >= 0)
	{
		cin >> d;
		degs.push_back(d);
	}
	if (degs.size() == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	x = 0;
	for (auto i : degs)
		x += i;
	avg = x / static_cast<int64_t>(degs.size());
	x = 0;
	for (auto i : degs)
		if (i > avg)
			x += 1;
	cout << x << endl;
	for (size_t i = 0; i < degs.size(); ++i)
		if (degs[i] > avg)
			cout << i << ' ';
	cout << endl;
	return (0);
}
