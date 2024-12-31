#ifndef GRID_H
#define GRID_H

#define NX 100
#define NY 100
#define DX 0.01
#define DY 0.01
#define DT 0.001

typedef struct 
{
    double u;
    double v;
    double p;
} Cell;

extern Cell grid[NX][NY];

#endif
