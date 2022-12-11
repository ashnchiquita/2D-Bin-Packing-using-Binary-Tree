#include "listBlock.h"
#include <stdio.h>

int max2(int w, int h) {
/* Mencari maksimum dari 2 bilangan */
    return w > h ? w : h;
}

boolean isFullLB(listBlock lb) {
/* Mengecek apakah list block penuh */
    return (lb.length == MAXLB);
}

void createLB(listBlock * lb) {
/* Membuat list block kosong */
    (*lb).length = 0;
}

void insertLB(listBlock *lb, block x) {
/* Memasukkan block x ke dalam list block */
    int i, idxSisip;
    boolean found;
    block currEl;

    /* ALGORITMA */
    found = false;
    for (i = 0; i < (*lb).length  && !found; i++) {
        currEl = (*lb).T[i];
        
        if (max2(w(currEl), h(currEl)) < max2(w(x), h(x))) {
            idxSisip = i;
            found = true;
        }
    }

    if (!found) {
        idxSisip = (*lb).length;
    }

    for (i = (*lb).length; i >= idxSisip + 1; i--) {
        (*lb).T[i] = (*lb).T [i - 1];
    }

    (*lb).length++;
    (*lb).T[idxSisip] = x;
}

void deleteLB(listBlock *lb, int idx, block *x) {
/* Menghapus elemen ke idx dari list block */
    int i;

    (*x) = (*lb).T[idx];

    for (i = idx + 1; i < (*lb).length; i++) {
        (*lb).T[i - 1] = (*lb).T[i];
    }
    (*lb).length--;
}

void copyLB(listBlock * hasil, listBlock lb) {
/* Mengcopy list block */
    int i;
    
    (*hasil).length = lb.length;

    for (i = 0; i <lb.length; i++) {
        (*hasil).T[i] = lb.T[i];
    }
}

void printLB(listBlock lb) {
/* Mengeprint isi list block */
    int i;
    for (i = 0; i < lb.length; i++) {
        printf("%c",lb.T[i].c);
        printf(", ");
    }
}