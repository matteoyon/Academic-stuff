#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf(" %d", &n);
	int vettore[n];
	for (int i = 0; i < n; i++) {
		scanf(" %d", &vettore[i]);
	}



	int counter;
	int max = 1;

	for (int i = 0; i < n; i++) {
		counter = 0;
		for (int j = i; j < n-1; j++) {
			counter++;
			if (vettore[j+1] >= vettore[j]) {
				if (j+1 == n-1) {
					counter++;
				}
				continue;
			} else {
				break;
			}
			i = j-1;
		}
		if (max < counter) {
			max = counter;
		}
	}
	printf("%d", max);
}
