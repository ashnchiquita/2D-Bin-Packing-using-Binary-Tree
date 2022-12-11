#include "node.h"

/* Fungsi dan Prosedur */
void createND(nodeDesc *nd, int x, int y, int w, int h, int idx) {
/* Membuat/Mengset node desc */
    (*nd).x = x; 
    (*nd).y = y;
    (*nd).w = w;
    (*nd).h = h;
    (*nd).usedByIdx = idx;
}

boolean isNodeUsed(nodeDesc nd) {
/* Mengecek apakah node digunakan */
    return (nd.usedByIdx != -1);
}

boolean isFit(block test, nodeDesc nd) {
/* Mengecek apakah block fit ke dalam node */
    return (w(test) <= nd.w) && (h(test) <= nd.h);
}