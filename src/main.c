#include "morse.h"


int main(void) {
	
	// Welcome message
	printf("Welcome to the Morse translator.\n");
	
	// Define our morse table
	struct ascii_morse table[36];
	
	// Define our morse letters
	char * morse_letters[36] = {
		".-",   //A
		"-...", //B
		"-.-.", //C
		"-..",  //D
		".",    //E
		"..-.", //F
		"--.",  //G
		"....", //H
		"..",   //I
		".---", //J
		"-.-",  //K
		".-..", //L
		"--",   //M
		"-.",   //N
		"---",  //O
		".--.", //P
		"--.-", //Q
		".-.",  //R
		"...",  //S
		"-",    //T
		"..-",  //U
		"...-", //V
		".--",  //W
		"-..-", //X
		"-.--", //Y
		"--.."  //Z
	};
	
	char * morse_numbers[10] = {
		"-----", //0
		".----", //1
		"..---", //2
		"...--", //3
		"....-", //4
		".....", //5
		"-....", //6
		"--...", //7
		"---..", //8
		"----."  //9
	};
	
	// Our morse table will hold all the morse strings with their corresponding character
	
	// Write the letters to our structure called table
	for (int i = 0; i < 26; i++) {
		
		table[i].character = 65 + i; // The ascii decimal for the capital letters starts from 65 (A = 65, B = 67 ...)
		table[i].morse = morse_letters[i];
	}
	
	// Write the numbers to our structure
	for (int i = 0; i < 10; i++) {
		
		table[26 + i].character = 48 + i; // The ascii integers start from 48
		table[26 + i].morse = morse_numbers[i];
	}
	
	// Now with a table filled out we can take the user input
		
	printf("Enter input: ");

	// Take input
	char * user_input;
	user_input = malloc(BUF_SIZE * sizeof(char));
	fgets(user_input, BUF_SIZE, stdin);

	// point to first element
	char * p_input = user_input;

	// Remove the new line character
	while (*p_input) {
		
		// If a new line char replace it with null
		if (*p_input == '\n') {

			*p_input = '\0';
			*(p_input + 1) = '\0';
		}
		p_input++;
	}

	// Parse the input to morse.c to convert it
	morse(user_input, table);
	
	// Exit with no error
	exit(0);
}
