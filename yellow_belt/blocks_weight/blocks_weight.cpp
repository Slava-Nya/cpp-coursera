//
// Created by Halfhand Lorrine on 2/28/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int16_t r = 0;
	int32_t w, h, d;
	int32_t n;
	uint64_t res = 0;

	cin >> n >> r;
	while (--n >= 0)
	{
		cin >> w >> h >> d;
		res += (static_cast<uint64_t>(w) * static_cast<uint64_t>(h) * static_cast<uint64_t>(d));
	}
	res *= r;
	cout << res << endl;
}