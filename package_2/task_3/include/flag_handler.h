#ifndef FLAG_HANDLER_H
#define FLAG_HANDLER_H

#include <stdlib.h>
#include "custom_print.h"

int handle_c(char c, sbuf_t *buffer);
int handle_d(int n, sbuf_t *buffer);
int handle_Ro(int n, sbuf_t *buffer);
int handle_Zr(unsigned int n, sbuf_t *buffer);
int handle_Cv(int n, int base, sbuf_t *buffer);
int handle_CV(int n, int base, sbuf_t *buffer);
int handle_to(const char *num_str, int base, sbuf_t *buffer);
int handle_TO(const char *num_str, int base, sbuf_t *buffer);
int handle_mi(int n, sbuf_t *buffer);
int handle_mu(unsigned int n, sbuf_t *buffer);
int handle_md(double d, sbuf_t *buffer);
int handle_mf(float f, sbuf_t *buffer);

#endif
