#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char str[100] = { 0 };
	int i, wordNum=0;

	scanf("%[^\n]", str);
	for (i = 0; str[i] != '\0'; i++) {
		if ((int)str[i] == 32)
			wordNum++;
	}
	if ((int)str[0] == 32) wordNum--;
	if ((int)str[i - 1] == 32)wordNum--;

	printf("%d\n", wordNum+1);

	return 0;
}