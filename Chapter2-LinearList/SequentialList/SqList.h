#include <cstdlib>
#include <malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
#define ElemType int

struct SqList {
    ElemType * elem;
    int length;
    int listsize;
    int incrementsize;
};

void InitList_Sq(SqList &L, int maxsize=LIST_INIT_SIZE, int incresize=LISTINCREMENT) {
    L.elem = (ElemType *)malloc(maxsize*sizeof(ElemType));
    if(!L.elem) {
        exit(1);  // cannot malloc
    }
    L.length = 0;  // initially have no elements
    L.listsize = maxsize;  // maximum number of elements
    L.incrementsize = incresize;  // memory to increase if needed
}

int ListLength_Sq(SqList L) {
    return L.length;
}

bool ListEmpty_Sq(SqList L) {
  return L.length == 0;
}

int LocateElem_Sq(SqList L, ElemType e) {
    for(int i = 0; i < L.length; i++) {
        if(L.elem[i] == e)  return i;  // find the element at ith position
    }
    return -1;  // Don't have the element we need
}

bool ListInsert_Sq(SqList &L, int i, ElemType e) {
    // increase memory if needed
    int j;
    if(i < 0 || i > L.length)  return false;  // invalid i
    if(L.length >= L.listsize)  {  // increase memory
        L.elem=(ElemType *)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(ElemType));
        if(!L.elem) exit(1);  // error realloc
        L.listsize+=L.incrementsize;
    }
    for(j = L.length; j > i; j--) {
        L.elem[j] = L.elem[j-1];  // elements after i shift left
    }
    L.elem[i] = e;  // insert e
    L.length++;
    return true;
}

bool ListDelete_Sq(SqList &L, int i, ElemType &e) {
    int  j;
    if(i < 0 || i > L.length) return false;  // invalid i
    if(L.length <= 0)  return false;
    e = L.elem[i];
    for(j = i+1; j <= L.length-1; j++) { // element after i shift right
        L.elem [j-1]=L.elem [j];
    }
    L.length--;
    return true;
}

bool GetElem_Sq(SqList L,int i, ElemType &e) {
    if(i < 0 || i > L.length) return false;
    if(L.length <= 0) return false;
    e = L.elem[i];
    return true;
}

void ListTraverse_Sq(SqList L, void (* visit)(ElemType)) {
    for(int i = 0; i < L.length; i++) {
        visit(L.elem[i]);
    }
}

void DestroyList_Sq(SqList &L) {
    free(L.elem);
    L.elem=NULL;
    L.listsize=0;
    L.length=0;
}
