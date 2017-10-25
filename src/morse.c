#include "morse.h"

// Morse determines whether we have a morse or ascii input and sends the input to be printed
int morse(char *user_input, struct ascii_morse table[]) {

	
	// Work out whether the input is characters is characters or morse
	int is_characters = 0;
	int is_morse = 0;
	
	// Go through the input
	char * p_input = user_input;
	while(*p_input) {
		
		// If there are morse characters in the input
		if (isCharInString(".-", *p_input) == 1) {
			is_morse = 1;
		}
		// If the are alphanumeric characters in the input
		else if (isalpha(*p_input) || isdigit(*p_input)) {
			is_characters = 1;
		}
		
		p_input++;
	}
	
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
	// Else the input must be invalid (a combination of both or neither)
	else {
		
		printf("Invalid input!\n");
		exit(1);
	}
	
	printf("\n");

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

// Makes all the characters in a string upercase
void makeUppercase(char * string) {
	
	// GO through string
	while (*string) {
		
		// Make uppercase
		*string = toupper(*string);
		string++;
	}
}

// Prints morse code from an alphanumeric input
void printMorse (char * input, struct ascii_morse table[]) {
	
	// Go through the input
	while (*input) {
		
		// If the input letter is a letter (ascii 65-90)
		if (*input >= 65 && *input <= 90) {
			
			// Print the corresponding morse from the table
			printf("%s", table[(int) *input - 65].morse);
		}
		// Else if the input letter is an ascii number (ascii 48-57)
		else if (*input >= 48 && *input <= 57) {

			// In our table the we want the numbers start from position 26
			printf("%s", table[(int) *input - 48 + 26].morse);
			
		}
		// Else if the input letter is a space we want a slash output between words
		else if (*input == ' ') {
			
			printf("/");
		}
		
		// Print a space, unless we are at the end
		if (*(input+1) != '\0') {
			printf(" ");
		}
		
		input++;
	}
}

// Prints alphanumeric characters from a morse input
void printCharacters (char * input, struct ascii_morse table[]) {
	
	// Create a temporary string to feed the input on to
	char *temp;
	temp = malloc(7*sizeof(char));
	char * p_temp = temp;
	
	// Boolean for determining whether the input morse has a valid output
	int isValidMorse = 0;
	
	// Go through the input
	while (*(input)) {
		
		// If the input is a dot or dash
		if (*input == '.' || *input == '-') {
			
			// Put the input onto the string
			*p_temp = *input;
			
			// Go to the next element of our temp string
			p_temp++;
		}
		// If the input is a space or the next character is a null
		if (*input == ' ' || *(input+1) == '\0') {
			
			// Put a null character at the end of the string
			*p_temp = '\0';
			
			// Go through our structure and see which is the correct code
			for (int i = 0; i < 36; i++) {
				
				// Compare our morse string to the strings in our structure
				if (strcmp(temp, table[i].morse) == 0) {
					
					// Print the corresponding character
					printf("%c", table[i].character);
					
					// If we find an equal morse string, the morse string exists
					isValidMorse = 1;
				}
			}
			
			// If we are still invalid, print error and exit with non-zero value
			if (isValidMorse == 0) {

				printf("Invalid Morse code!\n");
				exit(1);
			}
			
			// Wipe our temp string
			temp = malloc(7*sizeof(char));
			p_temp = temp;
		}
		
		// If the input is a slash it is a new word
		if (*input == '/') {
			
			printf(" ");
		}
		
		// GO to next character in the input
		input++;
	}
}