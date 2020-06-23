#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int testCases;
	cin >> testCases;
	int priorities[10];

	while (testCases--)
	{
		queue< pair<int, int>> printing;
		memset(priorities, 0, sizeof(priorities));

		int jobs;
		int myPosition;
		cin >> jobs >> myPosition;

		for (int i = 0; i < jobs; ++i)
		{
			int priority;
			cin >> priority;

			++priorities[priority];
			printing.push(make_pair(priority, i));
		}

		int minutes = 0;
		bool isPrinted = false;

		while (!isPrinted)
		{
			bool mostImportant = true;
			pair<int, int> currentJob = printing.front();

			for (int i = currentJob.first + 1; i < 10; ++i)
			{
				if (priorities[i] > 0)
				{
					mostImportant = false;
					break;
				}
			}

			if (mostImportant)
			{
				++minutes;
				
				if (currentJob.second == myPosition)
				{
					isPrinted = true;
					cout << minutes << "\n";
					break;
				}

				--priorities[currentJob.first];
			}

			else
				printing.push(currentJob);
			
			printing.pop();
		}
	}

	return 0;
}