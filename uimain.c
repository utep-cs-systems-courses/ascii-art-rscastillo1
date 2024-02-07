#include <stdio.h>
#include "draw.h" // project-related declarations

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Arrow = a, Chars = c) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      fputs("Select which font you want to print (5, 8, 11)\n", stdout);
      int f;
      scanf("%d", &f);

      switch (f) {
      case 5 :
	puts("You selected 5x7");
	for(char f = 'A'; f < 'D'; f++)
	  print_char_5x7(f);
	break;
      case 8:
	puts("You selected 8x11");
	for(char f = 'A'; f < 'D'; f++)
	  print_char_8x12(f);
	break;
      case 11:
	for (char f = 'A'; f < 'D'; f++)
	  print_char_11x16(f);
	break;
      default:
	printf("Not a font, try again");
	break;
      }
      break;
    case 'a':
      puts("You selected arrow");
      print_triangle(5, 7);
      print_arrow(5,5);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
