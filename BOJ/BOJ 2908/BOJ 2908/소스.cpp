#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
	char num1[4] = { 0 };
	char num2[4] = { 0 };
	char tmp1, tmp2;

	scanf("%s %s", num1, num2);

	tmp1 = num1[0], tmp2 = num2[0];
	num1[0] = num1[2], num2[0] = num2[2];
	num1[2] = tmp1, num2[2] = tmp2;

	if (strcmp(num1, num2)>=1)
		printf("%s\n", num1);
	else
		printf("%s\n", num2);

	return 0;
}