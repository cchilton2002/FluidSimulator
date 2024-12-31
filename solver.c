#include "solver.h"
#include <stdio.h>

void solve_advection_diffusion(double nu, double dt){
    Cell temp_grid[NX][NY];
    for(int i = 1; i < NX - 1; i++){
        for(int j = 1; j < NY - 1; j++){
            double u = grid[i][j].u;
            double v = grid[i][j].v;

            double du_advection = -u * (grid[i+1][j].u - grid[i-1][j].u) / 2.0 * DX - v * (grid[i][j+1].u - grid[i][j-1].u) / 2.0 * DY;
            double dv_advection = -u * (grid[i+1][j].v - grid[i-1][j].v) / 2.0 * DX - v * (grid[i][j+1].v - grid[i][j-1].v) / 2.0 * DY;

            double du_diffusion = (grid[i+1][j].u - 2.0 * u + grid[i-1][j].u) / (DX * DY) + (grid[i][j+1].u - 2.0 * grid[i][j-1].u) / (DX * DY);
            double dv_diffusion = (grid[i+1][j].v - 2.0 * v + grid[i+1][j].v) / (DX * DY) + (grid[i][j+1].v - 2.0 * grid[i][j-1].v) / (DX * DY);

            temp_grid[i][j].u = u + dt * (du_advection + nu * du_diffusion);
            temp_grid[i][j].v = v + dt * (dv_advection + nu * dv_diffusion);
        }
    }
}