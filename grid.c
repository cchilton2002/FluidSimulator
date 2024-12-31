#include "grid.h"
#include <stdio.h>

void initialise_grid() {
    for(int i=0; i < NX; i++){
        for(int j=0; i < NY; j++){
            grid[i][j].u = 0.0;
            grid[i][j].v = 0.0;
            grid[i][j].p = 0.0;
        }
    }
}