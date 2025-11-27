#ifndef CIRCUMCENTER_H
#define CIRCUMCENTER_H

#include <math.h>

void circumcenter(double x1, double y1, double x2, double y2, double x3, double y3,
                  double *ox, double *oy) 
{
    double d = 2 * (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    if (fabs(d) < 1e-9) {
        *ox = *oy = NAN;
        return;
    }

    double x = ((x1*x1 + y1*y1)*(y2 - y3) +
                (x2*x2 + y2*y2)*(y3 - y1) +
                (x3*x3 + y3*y3)*(y1 - y2)) / d;

    double y = ((x1*x1 + y1*y1)*(x3 - x2) +
                (x2*x2 + y2*y2)*(x1 - x3) +
                (x3*x3 + y3*y3)*(x2 - x1)) / d;

    *ox = x;
    *oy = y;
}

#endif
