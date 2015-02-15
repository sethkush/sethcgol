#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "cgoltypes.h"
#include "cgol.h"

//----------------------------------------------------------------------------//



void printfield(settings gameset) {
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

void setnext(settings gameset) {

  for (int y = 0; y < gameset.height; y++) {
  	
  	for (int x = 0; x < gameset.width; x++) {

      // count live neighbours: 
      int livecount = 0;
      for (int i = 0; i < 8; i++) {
        if (field[field[x][y].neighbours[i].x][field[x][y].neighbours[i].y].state == 1) {
          livecount++;
        }
      }

      // these if statements are the rules to the game:
      if (livecount == 3) {
        // any cell with 3 live neighbours will be live in the next turn:
        field[x][y].n_state = 1;
      }
      else if (livecount < 2 || livecount > 3) {
        // any cell with less than 2 or more than 3 live neighbours will
        // be dead in the next turn:
        field[x][y].n_state = 0;
      }
      else if (livecount == 2) {
        // any cell with 2 live neighbours remains in it's state:
        field[x][y].n_state = field[x][y].state;
      }
    }
  }
}

void updatefield(settings gameset) {
  for (int y = 0; y < gameset.height; y++) {
	for (int x = 0; x < gameset.width; x++) {
      field[x][y].state = field[x][y].n_state;
    }
  }
}