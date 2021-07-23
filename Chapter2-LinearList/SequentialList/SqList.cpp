#include <iostream>
#include "SqList.h"

void visit(ElemType i) {
    std::cout << i;
}

int main() {
    SqList L;
    InitList_Sq(L);

    ListInsert_Sq(L, 0, 1);
    ListInsert_Sq(L, 1, 2);
    ListInsert_Sq(L, 2, 3);

    std::cout << "Length: " << ListLength_Sq(L) << std::endl;

    ListTraverse_Sq(L, visit);
    std::cout << std::endl;

    int d;
    ListDelete_Sq(L, 2, d);

    ListTraverse_Sq(L, visit);
    std::cout << std::endl;

    std::cout << d << std::endl;

    DestroyList_Sq(L);

    if (ListEmpty_Sq(L)) {
        std::cout << "Destroy successfully" << std::endl;
    }

    return 0;
}
