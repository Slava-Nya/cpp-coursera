#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

void add(map <string, set<string>>& dict)
{
	string w1;
	string w2;

	cin >> w1 >> w2;
	dict[w1].insert(w2);
	dict[w2].insert(w1);
}

void count(map <string, set<string>>& dict)
{
	string word;

	cin >> word;
//		if (it.count(word) == 1)
			cout << dict[word].size() << endl;
}

void check(map <string, set<string>>& dict)
{
	string w1;
	string w2;

	cin >> w1 >> w2;
	if (dict.count(w1) > 0)
	{
		for (const auto& s : dict[w1])
			if (s == w2)
			{
				cout << "YES" << endl;
				return;
			}
	}
	cout << "NO" << endl;

}

int main()
{
	map <string, set<string>> dict;
	int cnt;
	string cmd;

	cin >> cnt;
	while (cnt > 0)
	{
		cin >> cmd;
		if (cmd == "ADD")
			add(dict);
		else if (cmd == "COUNT")
			count(dict);
		else
			check(dict);
		cnt--;
	}

	return 0;
}
