#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int cnt;
	string s;
	vector <string> res;

	cin >> cnt;
	while (cnt > 0)
	{
		cin >> s;
		res.push_back(s);
		cnt--;
	}
	sort(res.begin(), res.end(),
	  [](string i, string j){
		  for(auto& c : i)
			  c = tolower(c);
		  for(auto& c : j)
			  c = tolower(c);
		  return (i < j);
	});
	for (const auto& item : res)
		cout << item << " ";
	cout << endl;
	return 0;
}
