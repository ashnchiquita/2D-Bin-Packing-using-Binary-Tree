#ifndef MATBIN_H
#define MATBIN_H

#include "../boolean/boolean.h"
#include "../node/node.h"
#include "../listBlock/listBlock.h"
#include "../treeArr/treeArr.h"

#define MAXHEIGHT 50
#define MAXWIDTH 50

typedef struct {
   int mem[MAXHEIGHT][MAXWIDTH];
   int height; /* banyaknya/ukuran baris yg terdefinisi */
   int width; /* banyaknya/ukuran kolom yg terdefinisi */
} MatBin;

#define HEIGHT(M) (M).height
#define WIDTH(M) (M).width
#define EL(M, i, j) (M).mem[(i)][(j)]

/* Matrix Bin */
void CreateMatBin(int nRows, int nCols, MatBin *m);

/* IO */
void matrixBin(MatBin * mat, treeArr t, listBlock lb);
/* Membuat matriks bin */

void printBin(MatBin mat, listBlock lb);
/* Mendisplay state bin */

#endif