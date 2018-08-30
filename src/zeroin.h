/*
Header file added to flowCore by John Ramey
The `R_zeroin` function used to be and is no longer apart of the R API.
See the following link for more information:
http://developer.r-project.org/blosxom.cgi/R-devel/2012/08/15#n2012-08-15
*/
#ifndef ZEROIN_H
#define ZEROIN_H

double  R_zeroin(double ax, double bx, double (*f)(double, void *), void *info, double *Tol, int *Maxit);
double R_zeroin2(double ax,double bx,double fa, double fb,double (*f)(double x, void *info),void *info,double *Tol,int *Maxit);
#endif /* ZEROIN_H */
