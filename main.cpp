#include <iostream>
#include "dll.h"

using namespace std;

int main()
{
    List L1, L2, L3;

    createList_1304212134(L1);
    createList_1304212134(L2);
    createList_1304212134(L3);

    address P, newP;
    infotype band;

    band.nama="AvengedSevenfold";
    band.judul="DearGod";
    newP = createNewElmt_1304212134(band, P);
    insertFirst_1304212134(L1, newP);

    band.nama="Paramore";
    band.judul="Decode";
    newP = createNewElmt_1304212134(band, P);
    insertLast_1304212134(L1, newP);

    band.nama="LinkinPark";
    band.judul="Numb";
    newP = createNewElmt_1304212134(band, P);
    insertLast_1304212134(L1, newP);

    band.nama="SystemOfADown";
    band.judul="Toxicity";
    newP = createNewElmt_1304212134(band, P);
    insertLast_1304212134(L1, newP);

    cout << "Isi L1: \n";
    showList_1304212134(L1);

    band.nama="Paramore";
    band.judul="TheOnlyException";
    newP = createNewElmt_1304212134(band, P);
    address Prec = findLagu_1304212134("Decode", L1);
    insertAfter_1304212134(L1, Prec, newP);

    cout << "\nIsi L1 setelah insertAfter Paramore-Decode: \n";
    showList_1304212134(L1);

    band.nama="BudiDoremi";
    band.judul="MesinWaktu";
    newP = createNewElmt_1304212134(band, P);
    insertFirst_1304212134(L2, newP);

    band.nama="Dewa19";
    band.judul="Satu";
    newP = createNewElmt_1304212134(band, P);
    insertLast_1304212134(L2, newP);

    band.nama="PayungTeduh";
    band.judul="Akad";
    newP = createNewElmt_1304212134(band, P);
    insertLast_1304212134(L2, newP);

    band.nama="Chrisye";
    band.judul="AnakSekolah";
    newP = createNewElmt_1304212134(band, P);
    insertLast_1304212134(L2, newP);

    cout << "\nIsi L2: \n";
    showList_1304212134(L2);

    band.nama="Raisa";
    band.judul="KaliKedua";
    newP = createNewElmt_1304212134(band, P);
    Prec = findLagu_1304212134("MesinWaktu", L2);
    insertAfter_1304212134(L2, Prec, newP);

    cout << "\nIsi L2 setelah insertAfter BudiDoremi-MesinWaktu: \n";
    showList_1304212134(L2);

    cout << "\nIsi L3 (Hasil penggabungan L1 dan L2: \n";
    concat_1304212134(L1, L2, L3);
    showList_1304212134(L3);

    string desiredTitle;
    cout << "\nMasukkan judul lagu yang ingin dihapus: ";
    cin >> desiredTitle;
    address found = findLagu_1304212134(desiredTitle, L3);
    if(!found)
    {
        cout << "Lagu tidak ditemukan\n";
    }
    else
    {
        removeLagu_1304212134(desiredTitle, L3);
        cout << "\nIsi L3 setelah penghapusan lagu " <<
        found->info.nama << " - " << found->info.judul <<": \n";
        showList_1304212134(L3);
    }
    return 0;
}
