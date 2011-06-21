#include <stdio.h>

/**
 * Convert a letter (given as a C char) to a morse string of "."s and "-"s.
 *
 * @param char letter The letter to convert into a morse string.
 * @return A string of dashes and periods representing the letter passed.
 */
char* convert(char letter) {
  // As tempting as it is to convert this list into two columns: don't.
  // Doing so will make our diffs and patches look like crap.
  switch (letter) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";
    case '0': return "-----";
    case '?': return "..--..";
    case '.': return ".-.-.-";
    case ',': return "--..--";
    case '-': return "-....-";
    case '/': return "-..-.";
  }
}

void blink_short() {
  printf("dit ");
}

void blink_long() {
  printf("dah ");
}

/**
 * Iterate through a string of text, and call the blink functions to represent
 * each dash or dot.
 *
 * @param char* text The text to blink
 */
void perform_blink(char* text) {
  // For each letter in the text, ...
  while (*text) {

    // Handle special cases here.
    switch (*text) {
      case ' ':
        printf("\n");
        text++;
        continue;
    }

    // Print the letter first.
    printf("%c: ", *text);
    
    // Convert the letter to morse, ...
    char* morseified = convert(*text);

    // For each char of the morse string, ...
    while (*morseified) {
      switch (*morseified) {
        case '.':
          blink_short();
          break;
        case '-':
          blink_long();
          break;
      }
      morseified++;
    }
    // For debugging...
    printf("\n");
    text++;
  }
}

int main(int argc, char* argv[]) {
  if (argc > 1) {
    perform_blink(argv[1]);
    return 0;
  } else {
    printf("Usage: ./morse 'text to morse'\n");
    return 1;
  }
}

