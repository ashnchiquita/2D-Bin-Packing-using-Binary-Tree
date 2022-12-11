# 2D Bin Packing Algorithm using Binary Tree Concept
## Sebagai Penunjang Tugas Makalah IF2120 Matematika Diskrit
### Created by Chiquita Ahsanunnisa (13521129)

### About This Program
2D Bin Packing Problem adalah salah satu NP-Problem ....

Program ini adalah program berbasis Command Line Interface (CLI) yang dibangun dengan bahasa pemrograman C. Program ini mensimulasikan susunan balok-balok dalam bin dua dimensi yang dapat meminimumkan space yang tidak terpakai pada bin. Pengguna dapat memilih metode penyusunan balok, yaitu dengan metode First Fit Decreasing dan Best Fit Decreasing. Konsep yang digunakan dalam membuat algoritma program ini adalah konsep pohon biner.

### How To Run Program
1. Clone repository ini
2. Pastikan sudah ada GNU Compiler (gcc) di device kamu. Keberadaan GNU Compiler dapat dicek dengan memasukkan command  ```gcc --version``` pada terminal.
3. Pindahkan terminal ke folder `src` dengan `cd src`.
4. Compile program dengan memasukkan command `gcc -o main main.c ./ADT/node/node.c ./ADT/listBlock/listBlock.c ./ADT/treeArr/treeArr.c ./ADT/matBin/matBin.c` di terminal.
5. Run program dengan memasukkan command `./main` di terminal.

### Folder Structure
```
|   README.md
|
└── doc
|       Penggunaan Pohon Biner untuk Memecahkan Persoalan Two Dimensional Bin Packing - Chiquita Ahsanunnisa - 13521129.pdf
│
└── src
    |   main
    |   main.c
    |
    └── ADT
        ├── boolean
        |       boolean.h
        |    
        ├── listBlock
        |       listBlock.c
        |       listBlock.h
        |
        ├── matBin
        |       matBin.c
        |       matBin.h
        |
        ├── node
        |       node.c
        |       node.h
        |
        └── treeArr
                treeArr.c
                treeArr.h
```