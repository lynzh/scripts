// ncurses5.c written by
// kenneth olsen
// 9/July/2014 

#include <ncurses.h>

#define DELAY 10000

int main(int argv, char *argc[]) {
//	int ch;
	char string;
//	string = "hello world";

	initscr();  /* start up the window */
	raw();      /* show raw input? */
	keypad(stdscr, TRUE); /* enable key input inside stdscr */
	noecho();   /* do not echo keys */

	printw("Hello there! ! !");
	refresh();
	while(1) {
		printw(string);   // print on stdscr, at current position
//  mvprintw(10, 10, string);  // move to x, y, print string
//  wprintw(win, string); /* print at window win at present cursor */
		                      /*	position */

//	mvwprintw(25, 25, string); /* move to x, y. relative to win */
		                           /* position and print string */
	}
	return 0; 
}
