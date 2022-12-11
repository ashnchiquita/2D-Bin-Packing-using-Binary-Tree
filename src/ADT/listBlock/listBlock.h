#ifndef LISTBLOCK_H
#define LISTBLOCK_H

#include "../boolean/boolean.h"
#include "../node/node.h"

#define MAXLB 200

typedef struct {
    block T[MAXLB];
    int length;
} listBlock; /* Ordered Array yang menyimpan blocks mana saja yang ada di bin */

/* Fungsi dan Prosedur */
int max2(int w, int h);
/* Mencari maksimum dari 2 bilangan */

boolean isFullLB(listBlock lb);
/* Mengecek apakah list block penuh */

void createLB(listBlock * lb);
/* Membuat list block kosong */

void insertLB(listBlock *lb, block x);
/* Memasukkan block x ke dalam list block */

void deleteLB(listBlock *lb, int idx, block *x);
/* Menghapus elemen ke idx dari list block */

void copyLB(listBlock * hasil, listBlock lb);
/* Mengcopy list block */

void printLB(listBlock lb);
/* Mengeprint isi list block */

#endif