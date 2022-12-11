#ifndef NODE_H
#define NODE_H

#include "../boolean/boolean.h"

typedef struct {
    char c;
    int w;
    int h;
} block;

typedef struct {
    int x;
    int y;
    int w;
    int h;
    int usedByIdx;
} nodeDesc;

#define w(x) (x).w
#define h(x) (x).h

/* Fungsi dan Prosedur */
void createND(nodeDesc *nd, int x, int y, int w, int h, int idx);
/* Membuat/Mengset node desc */

boolean isNodeUsed(nodeDesc nd);
/* Mengecek apakah node digunakan */

boolean isFit(block test, nodeDesc nd);
/* Mengecek apakah block fit ke dalam node */

#endif