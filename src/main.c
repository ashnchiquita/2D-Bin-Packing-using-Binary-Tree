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
    printf("Masukkan width bin: ");
    scanf("%d", &binW);
    printf("Masukkan height bin: ");
    scanf(" %d", &binH);

    createTA(&t, binW, binH);
    printf("\nPilih Metode Fitting:\n");
    printf("1. First Fit Decreasing\n");
    printf("2. Best Fit Decreasing\n");
    printf("\nPilih metode: ");
    scanf(" %d", &met);
    printf("\n");

    while (working) {
        printf("List command:\n");
        printf("1. Masukkan block ke bin\n");
        printf("2. Ambil block dari bin\n");
        printf("3. Selesai\n");

        printf("\nPilih command: ");
        scanf("%d", &command);

        if (command == 1) {
            if (isFullLB(lb)) {
                printf("ListBlock penuh.\n");
            } else {
                printf("\nMasukkan data block: \n");
                printf("Kode char : "); 
                scanf(" %c", &(blok.c));

                printf("Width : "); 
                scanf(" %d", &(blok.w));

                printf("Height : "); 
                scanf(" %d", &(blok.h));
                
                insertBin(&t,&lb,blok,&success, met);
                
                if (success) {
                    printf("Block berhasil dimasukkan ke dalam bin.\n");
                } else {
                    printf("Block gagal dimasukkan ke dalam bin karena bin tidak cukup.\n");
                }
            }


        } else if (command == 2) {           
            if (lb.length == 0) {
                printf("Bin kosong.\n");
            } else {
                printf("\nNomor block di bin: "); 
                scanf(" %d", &idx);
                idx--;
                
                deleteBin(&t, &lb, idx, &blok, &success, met);
                
                if (success) {
                    printf("Block berhasil dihapus dari bin.\n");
                } else {
                    printf("Block gagal dihapus dari bin.\n");
                }
                
                printf("\n\nData block yang diambil: \n");
                printf("Kode char : %c\n", blok.c); 
                printf("Width : %d\n", w(blok));
                printf("Height : %d\n", h(blok));
            }

        } else {
            working = false;
        }

        printf("\nSTATE BIN:\n");
        matrixBin(&mat, t, lb);
        printBin(mat, lb);
        printf("\n");
    }
}