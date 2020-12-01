#include <iostream>
#include "Forest.h"

using namespace std;

int main()
{
	cout << "******Implementation Forest******" << endl;
	ForestNode* x[9]; //only x[1], x[2], ..., x[8] will be used

	int i;
	for (i = 1; i <= 8; i++)
	{
		x[i] = new ForestNode(0, i, 0);
		make_set(x[i]);
	}

	for (i = 1; i <= 7; i += 2)
		un_sets(x[i], x[i + 1]);

	for (i = 1; i <= 7; i += 4)
		un_sets(x[i], x[i + 2]);

	un_sets(x[1], x[5]);

	print(x, 8);
	return 0;
}