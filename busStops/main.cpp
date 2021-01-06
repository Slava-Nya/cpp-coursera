#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void new_bus(map <string, vector<string>> & bus)
{
	string	bus_name;
	string 	stop;
	int		cnt;

	cin >> bus_name;
	cin >> cnt;
	while (cnt >= 0)
	{
		cin >> stop;
		bus[stop].push_back(bus_name);
		cnt--;
	}
}

void buses_for_stop(map <string, vector<string>> & stop)
{
	string stop_name;

	cin >> stop_name;
	if (stop[stop_name].empty())
		cout << "No bus" << endl;
	else
	{
		for (auto & cnt : stop[stop_name])
			cout << cnt << " ";
		cout << endl;
	}
}

void stops_for_bus(map <string, vector<string>> & bus)
{


}

void all_buses(const map <string, vector<string>> & stop)
{

}

int main()
{
	map <string, vector<string>> stop;
	map <string, vector<string>> bus;
	int cnt;
	string cmd;

	cin >> cnt;
	while (cnt >= 0)
	{
		cin >> cmd;
		if (cmd == "NEW_BUS")
			new_bus(bus);
		else if (cmd == "BUSES_FOR_STOP")
			buses_for_stop(stop);
		else if (cmd == "STOPS_FOR_BUS")
			stops_for_bus(bus);
		else
			all_buses(stop);
		cnt--;
	}
	return 0;
}
