#ifndef TREEARR_H
#define TREEARR_H

#include "../boolean/boolean.h"
#include "../node/node.h"
#include "../listBlock/listBlock.h"

#define MAXTA 100

typedef struct {
    nodeDesc T[MAXTA];
    int length;
    int binW;
    int binH;
} treeArr;

/* Tree */
void createTA(treeArr * t, int binW, int binH);
/* Membuat tree array kosong */

boolean isFullTA(treeArr t);

void insertTA(treeArr * t, nodeDesc nd, int idx);
/* Memasukkan nd sebagai elemen ke idx dari list kulkas */

void copyTA(treeArr * hasil, treeArr t);
/* Mengcopy tree array */

/* Bin Arrangement */
int findNodeFF(treeArr t, block test);
/* Mencari node (First Fit) yang cukup untuk menyimpan block test */

int findNodeBF(treeArr t, block test);
/* Mencari node (Best Fit) yang cukup untuk menyimpan block test */

void splitNode(treeArr * t, int node, listBlock lb, int lbIdx);
/* Memecah node menjadi 3 node (1 terisi, 2 kosong)*/

void arrangeBin(treeArr * t, listBlock lb, boolean * success, int method);
/* Meng-arrange listBlock menjadi tree kulkas, success jika semua elemen list kulkas fit ke dalam kulkas */

void insertBin(treeArr * t, listBlock * lb, block test, boolean * success, int method);
/* Menginsert block ke dalam kulkas. Insertion mungkin gagal */

void deleteBin(treeArr *t, listBlock *lb, int lbIdx, block *val, boolean * success, int method);

void printTA(treeArr t);

#endif