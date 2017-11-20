// Remove Alternate Duplicate characters from a char array you have to do it in Place.
// Like keeping only the odd occurences of each character.
//   Example: Input: “you got beautiful eyes”
//   Output: ”you gtbeaiful s”
// Allowed Time Complexity was O(n) and Space Complexity was O(1)

#include <string.h>
#include <stdio.h>
using namespace std;

void remove_dubl(char *str) {

	unsigned int bit_mask = 0;

	char *p = str;
	char *cur_p = p;
	while (*p) {
		// Processing Whitespace
		if (*p == ' ') {
			//printf("%c", *p);
			*cur_p = *p;
			p++;
			cur_p++;
			continue;
		}

		// Processing regular symbol
		int idx = *p - 'a';
		if (!(bit_mask & (1 << idx))) {
			//printf("%c", *p);
			bit_mask |= 1 << idx;
			*cur_p = *p;
			p++;
			cur_p++;
		} else {
			p++;
		}
	}

	// Handling situation when the resulting string is shorter the the initial one
	if (cur_p != p)
		*cur_p = 0;

	//printf("%s\n", str);
}

int main(void) {

	{
		const char *str_input = "you got beautiful eyes";
		char str[64];
		strncpy(str, str_input, strlen(str_input));
		remove_dubl(str);
		printf("%s\n", str);
	}

	{
		const char *str_input = "a";
		char str[64] = {0};
		strncpy(str, str_input, strlen(str_input));
		remove_dubl(str);
		printf("%s\n", str);
	}

	{
		const char *str_input = "abcd";
		char str[64] = {0};
		strncpy(str, str_input, strlen(str_input));
		remove_dubl(str);
		printf("%s\n", str);
	}

	return 0;
}
