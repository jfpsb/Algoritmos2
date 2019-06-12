#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int charToIndex(char c) {
	switch (c)
	{
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	}
}

int main()
{
	int t, index, paths[7] = { 0 };
	char sprinklerseq[1000];
	stack <char> s;

	scanf("%d", &t);

	getchar();

	for (int i = 0; i < t; i++) {
		fgets(sprinklerseq, 1000, stdin);

		index = 0;

		while (sprinklerseq[index] != '\0') {
			//printf("%c", sprinklerseq[index]);
			if (index == 0) {
				s.push(sprinklerseq[index]);
				paths[charToIndex(sprinklerseq[index])] += 1;
			}
			else {
				if (s.size() != 0) {
					char top = s.top();

					printf("TOP: %c\n", top);

					if (sprinklerseq[index] == top) {
						s.pop();

						top = s.top();
						paths[charToIndex(top)] += 1;
					}
					else {
						s.push(sprinklerseq[index]);
						paths[charToIndex(sprinklerseq[index])] += 1;
					}
				}
			}

			index++;
		}

		for (int j = 0; j < 7; j++) {
			printf("%d\n", paths[j]);
		}
	}
}
