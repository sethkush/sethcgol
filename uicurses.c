#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "cgoltypes.h"
#include "cgol.h"

//----------------------------------------------------------------------------//


int kbhit(void) {
  int ch = getch();

  if (ch != ERR) {
    ungetch(ch);
    return 1;
  } 
  else {
    return 0;
  }
}


void setupcurses() {
  // setup ncurses:
  initscr();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
}