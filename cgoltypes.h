#ifndef CGOLTYPES
#define CGOLTYPES

// this is simply a set of coordinates, not what they contain:
typedef struct point {
  int x;
  int y;
} point;

// this type is used to pass game settings to the functions
// rather than use global variables.
typedef struct settings {
  int width;
  int height;
  int random;
  int sleep;
  int memfail;
} settings;

// this structure is used for the individual cells on the screen:
// x and y are coordinates. state is the current life status and
// n_state is the status of the next progression.  neighbours is
// an array containing the points of the adjacent cells.
typedef struct cell {
  int x; // not using a point here for simplicity's sake.
  int y; // this way it only requires one '.'
  int state;
  int n_state;
  struct point neighbours[8];
} cell;

#endif