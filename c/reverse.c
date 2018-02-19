#include <stdio.h>
#include <string.h>

void  reverse(char *str) {
	char *p1 = str;
	char *p2 = str;
	while (*p2)
		p2++;
	p2--;

	if (p1 == p2)
		return;

	while (p1 < p2) {
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		p1++;
		p2--;
	}
}

int main(void) {
	char str[6] = {0};
	strcpy(str, "abcde");
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
	return 0;
}
