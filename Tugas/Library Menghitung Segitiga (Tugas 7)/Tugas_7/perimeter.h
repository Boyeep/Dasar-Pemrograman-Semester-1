#ifndef PERIMETER_H
#define PERIMETER_H

#include <math.h>

double jarak(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

double keliling_segitiga(double x1, double y1, double x2, double y2, double x3, double y3) {
    return jarak(x1, y1, x2, y2) + jarak(x2, y2, x3, y3) + jarak(x3, y3, x1, y1);
}

#endif
