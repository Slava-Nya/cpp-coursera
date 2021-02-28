#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int	 busExist(map <vector<string>, int> &bus, vector <string> &new_bus)
{
	for (auto& it : bus)
		if (it.first == new_bus)
			return (it.second);
	return (-1);
}

int main()
{
	map <vector<string>, int> bus;
	string stop;
	vector<string> new_bus;
	int i;
	int cnt;
	int ret;

	cin >> i;
	while (i > 0)
	{
		cin >> cnt;
		while(cnt > 0)
		{
			cin >> stop;
			new_bus.push_back(stop);
			cnt--;
		}
		if ((ret = busExist(bus, new_bus)) == -1)
		{
			ret = bus.size() + 1;
			bus[new_bus] = ret;
			cout << "New bus " << ret << endl;
		}
		else
			cout << "Already exists for " << ret << endl;
		new_bus.clear();
		i--;
	}
	return 0;
}
