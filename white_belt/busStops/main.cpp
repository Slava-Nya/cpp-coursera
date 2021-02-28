#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void new_bus(map <string, vector<string>> & bus,
			 map <string, vector<string>> & stop)
{
	string	bus_name;
	string 	stop_name;
	int		cnt;

	cin >> bus_name;
	cin >> cnt;
	while (cnt > 0)
	{
		cin >> stop_name;
		bus[bus_name].push_back(stop_name);
		stop[stop_name].push_back(bus_name);
		cnt--;
	}
}

void buses_for_stop(map <string, vector<string>> & stop)
{
	string stop_name;

	cin >> stop_name;
	if (stop.count(stop_name) == 0)
		cout << "No stop" << endl;
	else
	{
		for (const auto & cnt : stop[stop_name])
			cout << cnt << " ";
		cout << endl;
	}
}

void stops_for_bus(map <string, vector<string>> & bus,
				   map <string, vector<string>> & stop)
{
	string bus_name;
	int d;
	cin >> bus_name;
	if (bus.count(bus_name) == 0)
	{
		cout << "No bus" << endl;
		return ;
	}
	for (auto & cnt_stops : bus[bus_name])
	{
		d = stop.count(cnt_stops);
		cout << "Stop " << cnt_stops << ": ";
		if (stop[cnt_stops].size() == 0 ||
		(stop[cnt_stops].size() == 1 && stop[cnt_stops][0] == bus_name))
		{
			cout << "no interchange";
		}
		else
		{
			for (const auto & cnt_buses : stop[cnt_stops])
			{
				if (cnt_buses != bus_name)
					cout << cnt_buses << " ";
			}
		}
		cout << endl;
	}

}

void all_buses(map <string, vector<string>> & bus)
{
	if (bus.empty())
	{
		cout << "No buses" << endl;
		return ;
	}
	for (const auto & bus_name : bus)
	{
		cout << "Bus " << bus_name.first << ": ";
		for (const string & stop_name : bus_name.second)
			cout << stop_name << " ";
		cout << endl;
	}
}

int main()
{
	map <string, vector<string>> stop;
	map <string, vector<string>> bus;
	int cnt;
	string cmd;

	cin >> cnt;
	while (cnt > 0)
	{
		cin >> cmd;
		if (cmd == "NEW_BUS")
			new_bus(bus, stop);
		else if (cmd == "BUSES_FOR_STOP")
			buses_for_stop(stop);
		else if (cmd == "STOPS_FOR_BUS")
			stops_for_bus(bus, stop);
		else
			all_buses(bus);
		cnt--;
	}
	return 0;
}
