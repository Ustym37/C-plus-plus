#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <string>
#include <math.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

#define N 50

double
Z = 1.0,
R = 1.0,

phi[N][N], A[N][N], B[N][N], C[N][N], D[N][N], E[N][N],
delta_z_r, norm_F,
MAX_ITER = 3000,
epsilon0 = 8.85e-12,
e = 1.6e-19,
n0 = 1.0e14,
EPS = 1.0e-6,
rho = 1.0 - 0.5 * ((M_PI * M_PI) / (N * N)),
f[N][N], rho_grid[N][N], r_grid[N];
char ch[3] = { 'X', 'X', 'X' };

void initialize_phi()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            phi[i][j] = 0.0;
        }
    }
}

void calculate_rho()
{
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            rho_grid[i][j] = 1.0e-5 * n0 * e * sin(2.0 * M_PI * i * delta_z_r / Z)* sin(2.0 * M_PI * j * delta_z_r / R);
        }
    }
}

void calculate_f()
{
	norm_F = 0;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            f[i][j] = -1.0 * rho_grid[i][j] / epsilon0;
            norm_F += f[i][j] * f[i][j];
        }
    }
}

void calculate_r()
{
    delta_z_r = R / (N - 2);
    r_grid[0] = 0.0;

    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = 1; j < N - 1; ++j)
        {
            r_grid[j] = r_grid[j - 1] + delta_z_r;
        }
    }
}

void calculate_coeficients()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A[i][j] = 1.0 / (delta_z_r * delta_z_r);

            B[i][j] = 1.0 / (delta_z_r * delta_z_r);

            C[i][j] = 1.0 / (delta_z_r * delta_z_r);

            D[i][j] = 1.0 / (delta_z_r * delta_z_r) + 1.0 / (r_grid[j] * delta_z_r);

            E[i][j] = -2.0 / (delta_z_r * delta_z_r) - 2.0 / (delta_z_r * delta_z_r) - 1.0 / (r_grid[j] * delta_z_r);
        }
    }
}

void SOR_Chebyshov()
{
    double omega = 1.0;
    double norm = 0.0;
    double residual;

    for (int num_of_iter = 1; num_of_iter <= MAX_ITER; num_of_iter++)
    {
        norm = 0.0;
        
        for (int i = 1; i < N - 1; i++)
        {
            for (int j = 1; j < N - 1; j++)
            {
                if ((i + j) % 2 != (num_of_iter % 2))
                {
                    continue;
                }

                residual = A[i][j] * phi[i + 1][j] + B[i][j] * phi[i - 1][j] + C[i][j] * phi[i][j + 1] +
                                  D[i][j] * phi[i][j - 1] + E[i][j] * phi[i][j] - f[i][j];
                norm += residual * residual;

                phi[i][j] = phi[i][j] - omega * residual / E[i][j];
            }
        }
        
        for (int i = 1; i < N - 1; i++)
        {
            phi[i][0] = phi[i][1];
            if (i <= (N - 10))
            {
            	phi[N - 1][i] = phi[N - 2][i];
			}
        }

        omega = 1.0 / (1.0 - (0.25 * rho * rho * omega));

        if (num_of_iter == 1)
        {
            omega = 1.0 / (1.0 - (0.5 * rho * rho));
        }

        if (norm < EPS * norm_F)
        {
            break;
        }
    }
}

//void SOR_method() 
//{
//    double omega = 1.0;
//    double norm = 0.0;
//    double residual_R;
//
//    for (int num_of_iter = 1; num_of_iter <= MAX_ITER; num_of_iter++)
//    {
//        for (int i = 1; i < N - 1; i++) 
//        {
//            for (int j = 1; j < N - 1; j++) 
//            {
//                if ((i + j) % 2 != (num_of_iter % 2))
//                {
//                    continue;
//                }
//
//                double phi_old = phi[i][j];
//                double residual_R = (phi[i + 1][j] + phi[i - 1][j] + phi[i][j + 1] + phi[i][j - 1] - 4.0 * phi[i][j] - f[i][j]);
//                phi[i][j] = phi_old + omega * residual_R / 4.0;
//                norm += residual_R * residual_R;
//            }
//        }
// 
//        omega = 1.0 / (1.0 - (0.25 * rho * rho * omega));
//
//        if (num_of_iter == 1)
//        {
//            omega = 1.0 / (1.0 - (0.5 * rho * rho));
//        }
//
//        if (norm < EPS)
//        {
//            break;
//        }
//    }
//}

void wrt_Phi()
{
    int i, j;
    ch[0] = 'p';
    ch[1] = 'h';
    ch[2] = 'i';

    FILE* out;

    out = fopen(ch, "wt");

    for (i = 0; i <= N - 1; ++i) {


        for (j = 1; j < N - 1; ++j)

        fprintf(out, "%e\t", phi[i][j]);
        fprintf(out, "\n");
    }
    fclose(out);
}

int main()
{
    initialize_phi();
    calculate_r();
    calculate_rho();
    calculate_f();
    calculate_coeficients();
    SOR_Chebyshov();
    wrt_Phi();
}
