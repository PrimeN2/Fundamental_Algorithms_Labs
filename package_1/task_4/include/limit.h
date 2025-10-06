#ifndef LIMIT_H
#define LIMIT_H

int calculate_e_limit(unsigned long long limit, double *e);
int calculate_pi_limit(unsigned long long limit, double *pi);
int calculate_ln2_limit(unsigned long long limit, double *ln2);
int calculate_sqrt_x_limit(double epsi, double *sqrt_x);
int calculate_gamma_limit(unsigned long long limit, double *gamma);

#endif
