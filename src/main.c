#include "./ADT/boolean/boolean.h"
#include "./ADT/node/node.h"
#include "./ADT/listBlock/listBlock.h"
#include "./ADT/treeArr/treeArr.h"
#include "./ADT/matBin/matBin.h"

#include <stdio.h>

int main() {
    block blok;
    int command, binH, binW, idx, met;
    boolean working, success;
    listBlock lb;
    treeArr t;
    MatBin mat;

    working = true;
    createLB(&lb);
    printf("\n2D Bin Packing Simulation\n\n");
    printf("Masukkan width bin: ");
    scanf("%d", &binW);
    printf("Masukkan height bin: ");
    scanf(" %d", &binH);

    createTA(&t, binW, binH);
    printf("\nPilih Algoritma Pendekatan :\n");
    printf("1. First Fit Decreasing\n");
    printf("2. Best Fit Decreasing\n");
    printf("\nPilihan : ");
    scanf(" %d", &met);
    printf("\n");

    while (working) {
        printf("List command:\n");
        printf("1. Masukkan balok ke bin\n");
        printf("2. Ambil balok dari bin\n");
        printf("3. Selesai\n");

        printf("\nPilih command: ");
        scanf("%d", &command);

        if (command == 1) {
            if (isFullLB(lb)) {
                printf("ListBlock penuh.\n");
            } else {
                printf("\nMasukkan data balok : \n");
                printf("Kode balok : "); 
                scanf(" %c", &(blok.c));

                printf("Width : "); 
                scanf(" %d", &(blok.w));

                printf("Height : "); 
                scanf(" %d", &(blok.h));
                
                insertBin(&t,&lb,blok,&success, met);
                
                if (success) {
                    printf("Balok berhasil dimasukkan ke dalam bin.\n");
                } else {
                    printf("Balok gagal dimasukkan ke dalam bin karena bin tidak cukup.\n");
                }
            }

        } else if (command == 2) {           
            if (lb.length == 0) {
                printf("Bin kosong.\n");
            } else {
                printf("\nNomor balok di bin: "); 
                scanf(" %d", &idx);
                idx--;
                
                deleteBin(&t, &lb, idx, &blok, &success, met);
                
                if (success) {
                    printf("Balok berhasil dihapus dari bin.\n");
                } else {
                    printf("Balok gagal dihapus dari bin.\n");
                }
                
                printf("\n\nData balok yang diambil: \n");
                printf("Kode balok : %c\n", blok.c); 
                printf("Width : %d\n", w(blok));
                printf("Height : %d\n", h(blok));
            }

        } else {
            working = false;
        }

        printf("\nTampilan Bin\n");
        matrixBin(&mat, t, lb);
        printBin(mat, lb);
        printf("\n");
    }
}