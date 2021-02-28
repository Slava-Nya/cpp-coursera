#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
	map <set<string>, int> bus;
	set<string > new_bus;
	int cnt, ret, w_cnt;
	string s;

	cin >> cnt;
	while (cnt > 0)
	{
		cin >> w_cnt;
		while (w_cnt > 0)
		{
			cin >> s;
			new_bus.insert(s);
			w_cnt--;
		}
		if (bus.count(new_bus) > 0)
			cout << "Already exists for " << bus[new_bus] << endl;
		else
		{
			ret = bus.size() + 1;
			bus[new_bus] = ret;
			cout << "New bus " << ret << endl;
		}
		new_bus.clear();
		cnt--;
	}
	return 0;
}
