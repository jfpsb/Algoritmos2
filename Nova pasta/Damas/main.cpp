#include <cstdio>

#define MAXVET 20

void NDamas(int v[MAXVET], int index, int n, int &cont) {
	if(index==n) {
		printf("%d: %d", cont++, v[0]);
		for(int i=1; i<n; i++)
			printf(" %d", v[i]);
		printf("\n");
	}
	else {
		for(int i=1; i<=n; i++) {
			bool ok = true;
			for(int j=0; j<index; j++) {
				if(v[j]==i) {
					ok=false;
					break;
				}
				int diff = index-j;
				if (v[j]== i-diff || v[j]== i+diff) {
					ok=false;
					break;
				}
			}

			if(ok && (index + 1) == )

			if(ok) {
				v[index] = i;
				NDamas(v, index+1, n, cont);
			}
		}
	}
}

int main() {
	int v[MAXVET];
	int cont = 1;
	NDamas(v, 0, 8, cont);
}
