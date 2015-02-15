#ifndef CGOL_HEADER
#define CGOL_HEADER

extern cell **field;

int kbhit(void);
settings buildfield();
void printfield(settings);
void setnext(settings);
void updatefield(settings);

#endif