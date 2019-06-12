#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main()
{
	int t, index;
	char sprinklerseq[1000];

	scanf("%d", &t);

	getchar();

	for (int i = 0; i < t; i++) {
		fgets(sprinklerseq, 1000, stdin);

		stack <char> s;
		int paths[26] = { 0 };

		s.push(sprinklerseq[0]);

		index = 1;

		while (sprinklerseq[index] != '\0') {
			char top = s.top();

			if (sprinklerseq[index] == top) {
				if (s.size() != 1) {
					s.pop();
					paths[s.top() - 'A'] += 1;
				}
			}
			else {
				s.push(sprinklerseq[index]);
				paths[sprinklerseq[index] - 'A'] += 1;
			}

			index++;
		}

		printf("Case %d\n", i + 1);
		for (int j = 0; j < 26; j++) {
			if(paths[j] != 0)
				printf("%c = %d\n", 'A' + j, paths[j]);
		}
	}
}
