#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>

using namespace std;

struct band
{
    string nama, judul;
};
typedef band infotype;
typedef struct elmList *address;
struct elmList
{
    infotype info;
    address Prev;
    address Next;
};
struct List
{
    address First;
    address Last;
};

bool isEmpty_1304212134(List L);
void createList_1304212134(List &L);
address createNewElmt_1304212134(infotype X, address P);
void insertFirst_1304212134(List &L, address P);
void insertAfter_1304212134(List &L, address Prec, address P);
void insertLast_1304212134(List &L, address P);
void deleteFirst_1304212134(List &L, address P);
void deleteAfter_1304212134(List &L, address Prec, address P);
void deleteLast_1304212134(List &L, address P);
void showList_1304212134(List L);
void concat_1304212134(List L1, List L2, List &L3);
address findLagu_1304212134(string judul, List L);
void removeLagu_1304212134(string judul, List &L);

#endif // DLL_H_INCLUDED
