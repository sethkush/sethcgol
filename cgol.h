#ifndef CGOL_HEADER
#define CGOL_HEADER

extern cell **field;

int kbhit(void);
settings buildfield(int,int,int,int);
void printfield(settings);
void setnext(settings);
void updatefield(settings);
void setupcurses();

#endif