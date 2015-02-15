#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "cgoltypes.h"
#include "cgol.h"
#include "uicurses.h"

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

int uicurses_getcmd(void) {
  if(kbhit()) {
  	int keydown = getch();

    switch(keydown){
      case 'p':
        return 1;
        break;

      case 'q':
        return 2;
        break;
    }
  }
  return 0;
} 

void uicurses_setup(void) {
  // setup ncurses:
  initscr();
  noecho();
  curs_set(FALSE);
  nodelay(stdscr, TRUE);
}

void uicurses_printfield(settings gameset) {
  for (int y = 0; y < gameset.height; y++) {
    for (int x = 0; x < gameset.width; x++) {

      // prints ' ' for dead or '*' for alive to
      // the next refresh:
      switch (field[x][y].state) {
      case 0:
        mvprintw (y, x, " ");
        break;
      case 1:
        mvprintw (y, x, "*");
        break;
      }
    }
  }
}