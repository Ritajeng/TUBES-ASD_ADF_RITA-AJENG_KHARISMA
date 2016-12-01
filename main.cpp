#include <iostream>
using namespace std;
#include "adtNya.h"
#include <stdlib.h>

/** Nama : KHARISMA OKTAVIANING HERWANDA & RITA AJENG NUGRAHENI
    NIM  : 1301154496 & 1301154524
**/

int main()
{
    ListDokter L;
    bool exitApk = false;
    bool next = false;
    bool plusPasien;
    int inputanUser;
    int inputanIntUser;

    createListDokter(L);

    address_P iniDokter;
    address_P deletedDokter;
    address_P hasilFindDokter;
    address_C iniPasien;

    while (!exitApk){
        system("CLS");

        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout<<"~~        1. Input   Dokter                   ~~"<< endl;
        cout<<"~~        2. Delete  Dokter                   ~~"<< endl;
        cout<<"~~        3. Input   Pasien                   ~~"<< endl;
        cout<<"~~        4. Delete  Pasien                   ~~"<< endl;
        cout<<"~~        5. View    Dokter                   ~~"<< endl;
        cout<<"~~        6. View    Dokter dan Pasien        ~~"<< endl;
        cout<<"~~        7. Urutkan Dokter                   ~~"<< endl;
        cout<<"~~        8. Data                             ~~"<< endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
        cout <<"        PILIH : ";                           cin>>inputanUser;

        switch(inputanUser){
        case 1 :
            system("CLS");
            iniDokter = alokasiDokter();
            insertDokter(L,iniDokter);
            break;
        case 2 :
            system("CLS");
            next = false;
            while(!next){
                cout<<"masukan id dokter tujuan";   cin>>inputanIntUser;
                hasilFindDokter = findDokter(L,inputanIntUser);
                if(hasilFindDokter != null){
                    next = true;
                }
            }
            deleteDokter(L,hasilFindDokter,deletedDokter);
            break;
        case 3 :
            system("CLS");
            insertPasien(L);
            break;
        case 4 :
            system("CLS");
            cout<<"masukn id pasien yang akan didelete : ";     cin>>inputanIntUser;
            deletePasienDiSemuaDokter(L,inputanIntUser);
            break;
        case 5 :
            system("CLS");
            plusPasien = false;
            viewDokterPasien(L,plusPasien);
            system("pause");
            break;
        case 6 :
            system("CLS");
            plusPasien = true;
            viewDokterPasien(L,plusPasien);
            system("pause");
            break;
        case 7 :
            system("CLS");
            AscDokter(L);
            system("pause");
            break;
        case 8 :
            system("CLS");
            infoData(L);
            system("pause");
            break;
        }
    }
    return 0;
}
