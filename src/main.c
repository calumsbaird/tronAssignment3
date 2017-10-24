#include "morse.h"

int main(void) {
	
	printf("Welcome to the Morse translator.\n");
	
	while (1) {
		
		printf("Enter input: ");
		
		// Take input
		char * user_input;
		user_input = malloc(BUF_SIZE * sizeof(char));
		fgets(user_input, BUF_SIZE, stdin);
		
		// point to first element
		char * p_input = user_input;
		
		// Remove the new line character
		while (*p_input) {
			//printf("character :|%c|", *p_input);
			
			if (*p_input == '\n') {
				
				*p_input = '\0';
				*(p_input + 1) = '\0';
			}
			p_input++;
		}
		
		// Parse the user input to checkInput
		if (checkInput(user_input) == 1) {
			
			continue;
		}
		
		// Parse the input to morse.c to convert it
		morse(user_input);
	}
}
