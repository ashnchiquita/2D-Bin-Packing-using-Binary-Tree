#include "matBin.h"
#include <stdio.h>

/* Matrix Bin */
void CreateMatBin(int nRows, int nCols, MatBin *m) {
    int i, j;

    HEIGHT(*m) = nRows;
    WIDTH(*m) = nCols;
    for (i = 0; i < nRows; i++) {
        for(j = 0; j < nCols; j++) {
            EL(*m, i, j) = -1;
        }
    }
}

void matrixBin(MatBin * mat, treeArr t, listBlock lb) {
/* Membuat matriks bin */
    int i, j, k;
    CreateMatBin(t.binH, t.binW, mat);

    for (i = 0; i < t.length; i++) {
        if (isNodeUsed(t.T[i])) {
            for (k = t.T[i].y; k < t.T[i].y + lb.T[t.T[i].usedByIdx].h; k++) {
                for (j = t.T[i].x; j < t.T[i].x + lb.T[t.T[i].usedByIdx].w; j++) {
                    EL(*mat, k, j) = t.T[i].usedByIdx + 1;
                }
            }
        }
    }
}

void printBin(MatBin mat, listBlock lb) {
/* Mendisplay state bin */
    int i, j;
    for (i = 0; i < HEIGHT(mat); i++) {
        for (j = 0; j < WIDTH(mat); j++) {
            if (EL(mat, i, j) == -1) {
                printf("* ");
            } else {
                printf("%d ", EL(mat, i, j));
            }
            
        }
        printf("\n");
    }
    printf("\n");

    if (lb.length == 0) {
        printf("Bin kosong.\n");
    } else {
        printf("Isi Bin (Sorted dari ukuran terbesar):\n");
        printf("(nomor. kode char)\n");
        for (i = 0; i < lb.length; i++) {
            printf("%d. ", i + 1);
            printf("%c",lb.T[i].c);
            printf("\n");
        }
    }
}