#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>

#include "cgoltypes.h"
#include "cgol.h"

// this creates a pointer for the field. We'll do a malloc()
// call a little later to give it some memory and turn it
// into a 2D array.
cell **field;

//----------------------------------------------------------------------------//

int main (int argc, char *argv[]) {

  // setup the field
  settings gameset = buildfield(150,45,1,250);

  if(gameset.memfail) {
    // If you are here, a malloc() call failed in the allocate() function in
    // buildfield.c it will have given an error message and freed up any
    // memory that was successfully allocated.
    return 1;
  }

  setupcurses();

  int run = 1;
  int paused = 0;

  // this is the main loop, it is infinite:
  while(run == 1) {
    if(paused == 0){
      printfield(gameset);
      setnext(gameset);
      updatefield(gameset);
      usleep(gameset.sleep*1000);
    }
    if(kbhit()) {
      int keydown = getch();

      switch(keydown){
        case 'p':
        if(paused == 0)
          paused = 1;
        else if(paused != 0)
          paused = 0;
        break;

        case 'q':
        run = 0;
        break;
      }
    }
  }

  // free up the memory given to the field
  for(int i = 0; i < gameset.width; i++) {
    free(field[i]);
  }
  free(field);

  // kill ncurses to return the terminal back to normal:
  endwin();

  return 0;
}