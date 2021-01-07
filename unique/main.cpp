#include <iostream>
#include <set>

using namespace std;

int main()
{
	int cnt;
	set <string> s;
	string word;

	cin >> cnt;
	while (cnt > 0)
	{
		cin >> word;
		s.insert(word);
		cnt--;
	}
	cout << s.size() << endl;
	return 0;
}
