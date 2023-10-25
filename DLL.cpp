#include "dll.h"
#include <iostream>

using namespace std;

bool isEmpty_1304212134(List L)
{
    return (L.First == NULL && L.Last == NULL);
}

void createList_1304212134(List &L)
{
    L.First = NULL;
    L.Last = NULL;
}

address createNewElmt_1304212134(infotype X, address P)
{
    P = new elmList;
    P->info = X;
    P->Next = NULL;
    P->Prev = NULL;
    return P;
}

void insertFirst_1304212134(List &L, address P)
{
    if (isEmpty_1304212134(L))
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        P->Next = L.First;
        L.First->Prev = P;
        L.First = P;
    }
}

void insertAfter_1304212134(List &L, address Prec, address P)
{
    P->Next = Prec->Next;
    Prec->Next->Prev = P;
    Prec->Next = P;
    P->Prev = Prec;
}

void insertLast_1304212134(List &L, address P)
{
    if (isEmpty_1304212134(L))
    {
        L.First = P;
        L.Last = P;
    }
    else
    {
        L.Last->Next = P;
        P->Prev = L.Last;
        L.Last = P;
    }
}

void deleteFirst_1304212134(List &L, address P)
{
    P = L.First;
    if (L.First == L.Last)
    {
        L.First = NULL;
        L.Last = NULL;
    }
    else
    {
        L.First = P->Next;
        P->Next = NULL;
        L.First->Prev = NULL;
    }
}

void deleteAfter_1304212134(List &L, address Prec, address P)
{
    P = Prec->Next;
    Prec->Next = P->Next;
    P->Next->Prev = Prec;
    P->Next = NULL;
    P->Prev = NULL;
}

void deleteLast_1304212134(List &L, address P)
{
    P = L.Last;
    if (L.First == L.Last)
    {
        L.First = NULL;
        L.Last = NULL;
    }
    else
    {
        L.Last = P->Prev;
        L.Last->Next = NULL;
        P->Prev = NULL;
    }
}

void showList_1304212134(List L)
{
    if (isEmpty_1304212134(L))
    {
        cout << "List kosong\n";
    }
    else
    {
        int i = 0;
        address P = L.First;
        while (P!=NULL)
        {
            cout << i+1 << ". " << P->info.nama
            << " - " << P->info.judul << "\n";
            P = P->Next;
            i++;
        }
    }
}

void concat_1304212134(List L1, List L2, List &L3)
{
    address P = L1.First;
    while(P!=NULL)
    {
        insertLast_1304212134(L3, P);
        P = P->Next;
    }

    address Q = L2.First;
    while(Q!=NULL)
    {
        insertLast_1304212134(L3, Q);
        Q = Q->Next;
    }
}

address findLagu_1304212134(string judul, List L)
{
    address curr = L.First;
    while (curr != NULL)
    {
        if (judul == curr->info.judul)
        {
            return curr;
        }
        curr = curr->Next;
    }
    return NULL;
}

void removeLagu_1304212134(string judul, List &L)
{
    address found = findLagu_1304212134(judul, L);
    if (!found)
    {
        cout << "Angka tidak ditemukan";
    }
    else
    {
        if (found->Prev == NULL)
        {
            deleteFirst_1304212134(L, found);
        }
        else if (found->Next && found->Prev)
        {
            deleteAfter_1304212134(L, found->Prev, found);
        }
        else if(found->Next == NULL)
        {
            deleteLast_1304212134(L, found);
        }
    }
}
