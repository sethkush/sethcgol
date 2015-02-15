#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>

#include "cgoltypes.h"
#include "cgol.h"

//----------------------------------------------------------------------------//

// function prototypes:
settings makeset(int,int,int,int);
settings allocate(settings);
void randomize(settings);
void setcelldata(settings);
void freememfail(int);

settings buildfield(int width, int height, int random, int sleep) {

  settings gameset = makeset(width, height, random, sleep);
  gameset = allocate(gameset);

  if(gameset.random) {
    randomize(gameset);
  }

  setcelldata(gameset);

  return gameset;

}

//----------------------------------------------------------------------------//

settings makeset(int width, int height, int random, int sleep) {

  settings gameset;
  
  gameset.width = width;

  gameset.height = height;
  
  gameset.random = random;

  gameset.sleep = sleep;

  return gameset;
}

//----------------------------------------------------------------------------//

settings allocate(settings gameset) {

  // allocate memory:
  field = malloc(gameset.width * sizeof(cell *));

  if(field == NULL) {
    // out of memory
    printf(
	   "Couldn't allocate sufficient memory for the first array dimension."
	   );
    gameset.memfail = 1;

    return gameset;
  }
  
  else {

    for(int i = 0; i < gameset.width; i++) {

      field[i] = malloc(gameset.height * sizeof(cell));

      if(field[i] == NULL) {
        // out of memory
        printf("Couldn't allocate sufficient memory for column %d", i);
        gameset.memfail = 1;

        freememfail(i);

        return gameset;
      }
    }
  }
  // if we made it this far, the field is a global 2D array.
  return gameset;
}

//----------------------------------------------------------------------------//

void randomize(settings gameset) {
  srand (time (NULL));
  for (int y = 0; y < gameset.height; y++) {
    for (int x = 0; x < gameset.width; x++) {
      field[x][y].state = rand () & 1;
    }
  }
}

void setcelldata(settings gameset) {

  // set positions:
  for (int y = 0; y < gameset.height; y++) {
    for (int x = 0; x < gameset.width; x++) {
      field[x][y].x = x;
      field[x][y].y = y;
    }
  }

  // set the cell's neighbour array:
  for (int y = 0; y < gameset.height; y++) {
    for (int x = 0; x < gameset.width; x++) {
      // set left, right, top and bottom:
      // these are in place so that the left bound continues
      // at the right bound, top to bottom, etc. The if
      // statements check if the cell is an edge cell:

      int left;
      int right;
      int top;
      int bottom;

      if (x == 0) {
        left = gameset.width - 1;
      }
      else {
        left = x - 1;
      }

      if (x == gameset.width - 1) {
        right = 0;
      }
      else {
        right = x + 1;
      }

      if (y == 0) {
        top = gameset.height - 1;
      }
      else {
        top = y - 1;
      }

      if (y == gameset.height - 1) {
        bottom = 0;
      }
      else {
        bottom = y + 1;
      }

      // set neighbours:
      // start left and go anticlockwise:
      field[x][y].neighbours[0].x = left;
      field[x][y].neighbours[0].y = y;

      field[x][y].neighbours[1].x = left;
      field[x][y].neighbours[1].y = bottom;

      field[x][y].neighbours[2].x = x;
      field[x][y].neighbours[2].y = bottom;

      field[x][y].neighbours[3].x = right;
      field[x][y].neighbours[3].y = bottom;

      field[x][y].neighbours[4].x = right;
      field[x][y].neighbours[4].y = y;

      field[x][y].neighbours[5].x = right;
      field[x][y].neighbours[5].y = top;

      field[x][y].neighbours[6].x = x;
      field[x][y].neighbours[6].y = top;

      field[x][y].neighbours[7].x = left;
      field[x][y].neighbours[7].y = top;
    }
  }
}

void freememfail(int i) {
  for(--i; i >= 0; i--){
    free(field[i]);
    free(field);
  }
}