#include "morse.h"

int morse(char *user_input, struct ascii_morse table[]) {
	/*
	for (int i = 0; i < 36; i++){
		printf("%s, %c\n", table[i].morse, table[i].character);
	}
	*/
	
	// Make the input uppercase
	makeUppercase(user_input);
	
	printMorse(user_input, table);

	
	printf("\n");
	//printf("usriput: |%s|\n", user_input);
	return 0;
}

// Returns 1 if the character is present
int isCharInString (char * string, char character) {
	
	// If character is a null
	if (character == '\0') {
		return 0;
	}
	
	// Boolean to check whether the character is present
	int isPresent = 0;
	
	// Go through the string until '\0'
	while (*string) {
		
		// If the characters are equal the character is evidently present
		if (character == *string) {
			
			isPresent = 1;
		}
		
		string++;
	}
	
	// Return the boolean value
	return isPresent;
}

void makeUppercase(char * string) {
	
	while (*string) {
		
		*string = toupper(*string);
		string++;
	}
}

void printMorse (char * input, struct ascii_morse table[]) {
	
	// Go through the input
	while (*input) {
		//printf("%d|\n", *input);
		
		// If the input letter is a character (ascii 65-90)
		if (*input >= 65 && *input <= 90) {
			
			printf("%s ", table[(int) *input - 65].morse);
		}
		// Else if the input letter is an ascii number (ascii 48-57)
		else if (*input >= 48 && *input <= 57) {
			
			// In our table the we want the numbers start from position 26
			printf("%s ", table[(int) *input - 48 + 26].morse);
		}
		// Else if the input letter is a space
		else if (*input == ' ') {
			
			printf("/ ");
		}
		input++;
	}
	printf("\b");
	
}