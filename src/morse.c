#include "morse.h"

int morse(char *user_input, struct ascii_morse table[]) {
	/*
	for (int i = 0; i < 36; i++){
		printf("%s, %c\n", table[i].morse, table[i].character);
	}
	*/
	
	// Work out whether the input is characters is characters or morse
	int is_characters = 0;
	int is_morse = 1;
	
	// Make the input uppercase
	makeUppercase(user_input);
	
	// If a character input
	if (is_characters == 1 && is_morse == 0) {
		
		printMorse(user_input, table);
	}
	// else if a morse input
	else if (is_characters == 0 && is_morse == 1) {

		printCharacters(user_input, table);
	}
	// Else the input must be invalid
	else {
		
		printf("Invalid input\n");
	}
	
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

void printCharacters (char * input, struct ascii_morse table[]) {
	
	// Create a temporary string to feed the input on to
	char *temp;
	temp = malloc(7*sizeof(char));
	char * p_temp = temp;
	
	
	// Go through the input
	while (*(input)) {
		//printf("%c|\n", *input);
		
		// If the input is a dot or dash
		if (*input == '.' || *input == '-') {
			
			// Put the input onto the string
			*p_temp = *input;
			//printf("%s\n", temp);
			// Go to the next element of our temp string
			p_temp++;
		}
		// If the input is a space or the next character is a null
		if (*input == ' ' || *(input+1) == '\0') {
			
			//printf("test");
			// Put a null character at the end of the strin
			*p_temp = '\0';
			
			//printf("%s\n", temp);
			
			// Go through our structure and see which is the correct code
			for (int i = 0; i < 36; i++) {
				if (strcmp(temp, table[i].morse) == 0) {
					
					printf("%c", table[i].character);
				}
			}
			
			// Wipe our temp string
			temp = malloc(7*sizeof(char));
			p_temp = temp;
		}
		
		if (*input == '/') {
			printf(" ");
		}

		
		input++;
	}
	printf("\b");
	
}