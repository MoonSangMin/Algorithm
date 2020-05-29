#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	for (int i = n; i > 0; i--) {
		for (int k = i; n - k > 0; k++) {
			printf(" ");
		}
		for (int j = i; j > 0; j--) {
			printf("*");
		}
		
		printf("\n");
	}
}