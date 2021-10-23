#include "PGMOut.h"

void PGMOut::save(vector<vector<int>> output)
{
	for (auto x : output)
	{
		for (auto y : x)
		{
			cout << y << " ";
		}
		cout << endl;
	}
}
