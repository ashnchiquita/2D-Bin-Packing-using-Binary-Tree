#include "treeArr.h"
#include <stdio.h>

void createTA(treeArr * t, int binW, int binH) {
/* Membuat tree array kosong */
    nodeDesc nd;

    createND(&nd, 0, 0, binW, binH, -1);
    (*t).length = 1;
    (*t).T[0] = nd;
    (*t).binW = binW;
    (*t).binH = binH;
}

boolean isFullTA(treeArr t) {
    return (t.length == MAXTA);
}

void insertTA(treeArr * t, nodeDesc nd, int idx) {
/* Memasukkan nd sebagai elemen ke idx dari list kulkas */
    int i;

    for (i = (*t).length; i >= idx + 1; i--) {
        (*t).T[i] = (*t).T [i - 1];
    }

    (*t).length++;
    (*t).T[idx] = nd;
}

void copyTA(treeArr * hasil, treeArr t) {
/* Mengcopy tree array */
    int i;
    
    (*hasil).length = t.length;

    for (i = 0; i < t.length; i++) {
        (*hasil).T[i] = t.T[i];
    }
}

/* Bin Arrangement */
int findNodeFF(treeArr t, block test) {
/* Mencari node (First Fit) yang cukup untuk menyimpan block test */
    int i, node;

    node = -1;

    for (i = t.length - 1; i >= 0  && node == -1; i--) {
        if (!isNodeUsed(t.T[i]) && isFit(test, t.T[i])) {
            node = i;
        }
    }

    return node;
}

int findNodeBF(treeArr t, block test) {
/* Mencari node (Best Fit) yang cukup untuk menyimpan block test */
    int i, idxMin;
    boolean found;

    found = false;
    idxMin = 0;

    for (i = t.length - 1; i >= 0; i--) {
        if (!isNodeUsed(t.T[i]) && isFit(test, t.T[i])) {
            found = true;
            if (t.T[i].w * t.T[i].h < t.T[idxMin].w * t.T[idxMin].h) {
                idxMin = i;
            }
        }
    }

    if (!found) {
        idxMin = -1;
    }

    return idxMin;
}

void splitNode(treeArr * t, int node, listBlock lb, int lbIdx) {
/* Memecah node menjadi 3 node (1 terisi, 2 kosong)*/
    nodeDesc ndRight, ndDown;
    int wm, hm, temp;

    (*t).T[node].usedByIdx = lbIdx;
    wm = lb.T[lbIdx].w;
    hm = lb.T[lbIdx].h;
    temp = node;

    if (!isFullTA(*t) && (*t).T[node].h - hm != 0) {
        temp++;
        createND(&ndDown, (*t).T[node].x, (*t).T[node].y + hm, (*t).T[node].w, (*t).T[node].h - hm, -1);
        insertTA(t, ndDown, temp);
    }

    if (!isFullTA(*t) && (*t).T[node].w - wm != 0) {
        temp++;
        createND(&ndRight, (*t).T[node].x + wm, (*t).T[node].y, (*t).T[node].w - wm, hm, -1);
        insertTA(t, ndRight, temp);
    }
}
void arrangeBin(treeArr * t, listBlock lb, boolean * success, int method) {
/* Meng-arrange listBlock menjadi tree kulkas, success jika semua elemen list kulkas fit ke dalam kulkas */
    int i, node;
    *success = true;

    for (i = 0; i < lb.length && *success; i++) {
        if (method == 1) {
            node = findNodeFF(*t, lb.T[i]);
        } else {
            node = findNodeBF(*t, lb.T[i]);
        }

        if (node != -1) {
            splitNode(t, node, lb, i);
        } else {
            *success = false;
        }
    }
}

void insertBin(treeArr * t, listBlock * lb, block test, boolean * success, int method) {
/* Menginsert block ke dalam kulkas. Insertion mungkin gagal */
    treeArr tempTree;
    listBlock tempLB;
    boolean fit;

    createTA(&tempTree, (*t).binW, (*t).binH);
    copyLB(&tempLB, *lb);
    insertLB(&tempLB, test);

    arrangeBin(&tempTree, tempLB, &fit, method);

    if (fit) {
        copyTA(t, tempTree);
        copyLB(lb, tempLB);
    }
    (*success) = fit;
}

void deleteBin(treeArr *t, listBlock *lb, int lbIdx, block *val, boolean * success, int method) {
    boolean fit;
    treeArr tempTree;

    createTA(&tempTree,(*t).binW, (*t).binH);

    deleteLB(lb,lbIdx, val);
    arrangeBin(&tempTree, *lb, &fit, method);

    if (fit) {
        copyTA(t, tempTree);
    }
    (*success) = fit;
}

void printTA(treeArr t) {
    int i;

    for (i = 0; i < t.length; i++) {
        printf("%d ", t.T[i].usedByIdx);
    }
}