#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int CHAR_LIST_LENGTH = 92;

static inline bool string_equals(const char* a, const char* b) {
	return strcmp(a, b) == 0;
}

bool is_numeric(const char* string) {
	size_t i = 0, length = strlen(string);
	for (; i<length; i++)
		if (string[i] < '0' || string[i] > '9')
			return false;
	return true;
}

int main(int argc, const char** argv) {
	/* Declare variables */
	size_t i, length, charCount, which;
	const char* chars = "`~1!2@3#4$5%6^7&8*9(0)-_=+qQwWeErRtTyYuUiIoOpP[{]}aAsSdDfFgGhHjJkKlL;:'\"zZxXcCvVbBnNmM,<.>/?";
	
	/* If the user goofed, show them how this command works */
	if (argc != 2 || string_equals(argv[1], "-h") || string_equals(argv[1], "--help") || string_equals(argv[1], "\\h") || string_equals(argv[1], "/h") || string_equals(argv[1], "?")) {
		printf("Random password generator 1.0\n\n");
		printf("Usage:\n");
		printf("    random-password length\n\n");
		printf("Parameters:\n");
		printf("    length = How many characters (minimum is 8)\n");
		return 0;
	}
	
	/* Run some basic validation */
	if (argv[1][0] == '-') {
		printf("ERROR: Length can't be less than 8 characters.\n");
		return 0;
	}
	if (!is_numeric(argv[1])) {
		printf("ERROR: \"%s\" is not a whole number.\n", argv[1]);
		return 0;
	}
	length = atoi(argv[1]);
	if (length < 8) {
		printf("ERROR: Length can't be less than 8 characters.\n");
		return 0;
	}
	
	/* "Seed" the random number generator */
	srand(time(NULL));
	
	/* Generate the number */
	for (i=0; i<length; i++) {
		which = rand() % CHAR_LIST_LENGTH;
		printf("%c", chars[which]);
	}
	
	/* And we're done */
	return 0;
}
