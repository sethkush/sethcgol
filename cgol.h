#ifndef CGOL_HEADER
#define CGOL_HEADER

extern cell **field;

int kbhit(void);
settings buildfield(int,int,int,int);
void setnext(settings);
void updatefield(settings);

#endif