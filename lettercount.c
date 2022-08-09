
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char buffer[1024], input, curchar;
  int i = 0, count[26];

  // request and read in the string from the user
  printf("Enter text for analysis: ");
  while ( (input = getchar()) != '\n' ) {
    buffer[i++] = input;
  }
  buffer[i] = '\0';

  // set the letter counts to zero
  for (i = 0; i < 26; i++) count[i] = 0;
 
  // Count the occurences of each letter a-z in the string (case insenstive) 
  // in the count array with count[0] for 'a', count[1] for 'b' and so on.  
  // We ensure the character being examined is an uppercase character with 
  // toupper() and then we check if it is in the ASCII range for A-Z (65-90)
  // to determine if we need to increment a count... if it is we increment 
  // the right index using 65 as an 'offset'.
  for (i = 0; i < strlen(buffer); i++) {
    curchar = toupper(buffer[i]);
    if (curchar >= 65 && curchar <= 90) count[curchar - 65]++; 
  }

  // Create the letter analysis table
  printf("\n\nLetter Analysis Complete!");
  printf("\n\nLetter    Occurrences    Percentage\n");
  printf("*****************************************\n");
  for (i = 0; i < 26; i++) {
    printf("%-10c%-15d%-15.2f\n", i + 65, 
                               count[i], 
                               (((float) count[i]) / strlen(buffer)) * 100);
  }

  // Find the max and min occuring character in the string, in particular the 
  // position in the count array of each character
  int max, min, max_pos, min_pos;
  max = min = count[0];
  min_pos = max_pos = 0;
  for (i = 0; i < 26; i++) {
    if (count[i] < min) 
    {
      min_pos = i;
      min = count[i];
    }
    if (count[i] > max) 
    {
      max_pos = i;
      max = count[i];
    }
  }

  // Output the max and min occuring character, again using 65 as an offset to 
  // output the character character given ASCII A-Z range from 65-90
  printf("\nThe most frequently occurring character is %c.\n", max_pos + 65);
  printf("The least frequently occurring character is %c.\n", min_pos + 65);

  return 0;
}
