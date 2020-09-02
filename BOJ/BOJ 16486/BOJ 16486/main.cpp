#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	double d, r;
	scanf("%lf %lf", &d, &r);
	printf("%.6lf", (2 * d) + (2 * 3.141592 * r));
}