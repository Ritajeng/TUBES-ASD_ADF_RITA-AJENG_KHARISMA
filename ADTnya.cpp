#include <iostream>
#include "adtNya.h"
using namespace std;

void createListDokter(ListDokter &L)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    firstListDokter(L)  = NULL;
    lastListDokter(L)   = NULL;
}

void createListPasien(ListPasien &L)
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    firstListPasien(L)  = NULL;
    lastListPasien(L)   = NULL;
}

address_P alokasiDokter()
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{

    string namaInputanDokter        ;
    string spesialisInputanDokter   ;
    int nipInputanDokter            ;
    string tempatInputanDinasDokter        ;

    cout<<"Masukkan nama Dokter         : ";
    cin>>namaInputanDokter;
    cout<<"Masukkan spesialis Dokter    : ";
    cin>>spesialisInputanDokter;
    cout<<"Masukkan NIP Dokter          : ";
    cin>>nipInputanDokter;
    cout<<"Masukkan Tempat Dinas        : ";
    cin>>tempatInputanDinasDokter;

    address_P dokterBaru ;
    dokterBaru = new elmlist_P;

    namaDokter(dokterBaru)          = namaInputanDokter;
    spesialisDokter(dokterBaru)     = spesialisInputanDokter;
    NIPDokter(dokterBaru)           = nipInputanDokter;
    tempatDinasDokter(dokterBaru)   = tempatInputanDinasDokter;

    nextDokter(dokterBaru)          = null;
    prevDokter(dokterBaru)          = null;
    pasienDokterIni(dokterBaru)     = null;
    return dokterBaru;
}

address_C alokasiPasien()
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    string namaInputanPasien        ;
    string nama_penyakit            ;
    string alamat                   ;
    int nomor_pelanggan             ;
    int usiaPasien                  ;

    cout<<"Masukkan nama Pasien             : ";
    cin>>namaInputanPasien  ;
    cout<<"Masukkan usia pasien             : ";
    cin>>usiaPasien         ;
    cout<<"Masukkan nama penyakit           : ";
    cin>>nama_penyakit      ;
    cout<<"Masukkan alamat pasien           : ";
    cin>>alamat             ;
    cout<<"Masukkan nomor pelanggan         : ";
    cin>>nomor_pelanggan    ;

    address_C pasienBaru ;
    pasienBaru = new elmlist_C;

    namaPasien(pasienBaru)          = namaInputanPasien;
    nama_penyakit(pasienBaru)       = nama_penyakit;
    alamat(pasienBaru)              = alamat;
    nomor_pelanggan(pasienBaru)     = nomor_pelanggan;
    usia(pasienBaru)                = usiaPasien;

    nextPasien(pasienBaru)          = null;
    return pasienBaru;
}

address_P findDokter(ListDokter L, int NIPDokterYangDicari)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    address_P   cekDokter;
    cekDokter   = firstListDokter(L);
    bool ketemu = false;

    while (!ketemu && cekDokter != null)
    {
        if(NIPDokterYangDicari == NIPDokter(cekDokter))
        {
            ketemu = true;
        }
        if (!ketemu)
        {
            cekDokter = nextDokter(cekDokter);
        }
    }

    if(!ketemu)
    {
        cekDokter = null;
    }
    return cekDokter;
}

address_C findPasien(ListDokter L,address_P dokterTujuan, int nomorPelangganPasien)
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    address_C cekPasien;
    address_C hasil;
    bool ketemu;
    cekPasien = pasienDokterIni(dokterTujuan);
    hasil = null;
    ketemu = false;

    while(!ketemu && cekPasien != null)
    {
        if(nomorPelangganPasien == nomor_pelanggan(cekPasien))
        {
            ketemu = true;
        }
        if(!ketemu)
        {
            cekPasien = nextPasien(cekPasien);
        }
    }

    if(!ketemu)
    {
        cekPasien = null;
    }
    return cekPasien;

}

void insertDokter(ListDokter &L, address_P dokterBaru)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    bool next = false;
    int     inputanUser;

    while(!next)
    {
        cout<<"1. insert first"<<endl;
        cout<<"2. insert last "<<endl;
        cout<<"3. insert after"<<endl;

        cout<<"pilih : ";
        cin>>inputanUser;
        if(inputanUser == 1)
        {
            insertFirstDokter(L,dokterBaru);
            next = true;
        }
        else if(inputanUser == 2)
        {
            insertLastDokter(L,dokterBaru);
            next = true;
        }
        else if (inputanUser == 3)
        {
            int nipDokterSebelum;
            address_P dokterSebelum;
            bool next2 = false;
            while(!next2)
            {
                cout<<"masukan id dokter ( dokter sebelum dokter yang akan di inputkan ) ";
                cin>>nipDokterSebelum;
                dokterSebelum = findDokter(L,nipDokterSebelum);
                if(dokterSebelum != null)
                {
                    insertAfterDokter(L,dokterBaru,dokterSebelum);
                    next2 = true;
                }
                else
                {
                    cout<<"dokter tidak ditemukan, silakan input nip dokter lagi"<<endl;
                }
            }
            next = true;
        }
        else
        {
            cout<<"inputan salah"<<endl;
        }
    }
}

void insertFirstDokter(ListDokter &L, address_P dokterBaru)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    if (firstListDokter(L) == NULL)
    {
        firstListDokter(L)              = dokterBaru;
        lastListDokter(L)               = dokterBaru;
        nextDokter(dokterBaru)          = null;
        prevDokter(dokterBaru)          = null;
    }
    else
    {
        nextDokter(dokterBaru)          = firstListDokter(L);
        prevDokter(firstListDokter(L))  = dokterBaru;
        firstListDokter(L)              = dokterBaru;
        prevDokter(dokterBaru)          = null;
    }
}

void insertLastDokter(ListDokter &L, address_P dokterBaru)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    if (firstListDokter(L) == NULL)
    {
        firstListDokter(L)                  = dokterBaru;
        lastListDokter(L)                   = dokterBaru;
        nextDokter(dokterBaru)              = null;
        prevDokter(dokterBaru)              = null;
    }
    else
    {
        prevDokter(dokterBaru)              = lastListDokter(L);
        nextDokter(lastListDokter(L))       = dokterBaru;
        lastListDokter(L)                   = dokterBaru;
        nextDokter(dokterBaru)              = null;
    }
}

void insertAfterDokter(ListDokter &L, address_P dokterBaru, address_P dokterLama)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    if (dokterLama == lastListDokter(L))
    {
        prevDokter(dokterBaru)              = lastListDokter(L);
        nextDokter(lastListDokter(L))       = dokterBaru;
        lastListDokter(L)                   = dokterBaru;
        nextDokter(dokterBaru)                    = null;
    }
    else
    {
        prevDokter(dokterBaru)              = dokterLama;
        prevDokter(nextDokter(dokterLama))  = dokterBaru;
        nextDokter(dokterBaru)              = nextDokter(dokterLama);
        nextDokter(dokterLama)              = dokterBaru;
    }
}

void deleteDokter (ListDokter &L, address_P dokterTujuan, address_P &deleted)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    if(firstListDokter(L) == null)
    {
        cout<<"list kosong"<<endl;

        // DELETE FIRST / DELETE LAST DENGAN ELEMENT LIST HANYA SATU ELEMENT
    }
    else if (firstListDokter(L) == dokterTujuan && nextDokter(dokterTujuan) == null)
    {
        deleted                                 = dokterTujuan;
        firstListDokter(L)                      = null;
        lastListDokter(L)                       = null;
        // DELETE FISRT DENGAN ELEMENT LEBIH DARI 1
    }
    else if (firstListDokter(L) == dokterTujuan && nextDokter(dokterTujuan) != null)
    {
        deleted                                 = dokterTujuan;
        firstListDokter(L)                      = nextDokter(firstListDokter(L));
        prevDokter(firstListDokter(L))          = null;
        nextDokter(deleted)                     = null;
        // DELETE LAST DENGAN ELEMENT LEBIH DARI SATU / DELETE AFTER DENGAN KONDISI ELEMENT TUJUAN DI AKHIR
    }
    else if (dokterTujuan == lastListDokter(L) && prevDokter(dokterTujuan) != null)
    {
        deleted                                 = lastListDokter(L);
        lastListDokter(L)                       = prevDokter(deleted);
        nextDokter(lastListDokter(L))           = null;
        prevDokter(deleted)                     = null;
        //DELETE AFTER DENGAN KONDISI DOKTER TUJUAN MEMILIKI ELEMENT DIDEPANNYA
    }
    else if (nextDokter(dokterTujuan) != null && prevDokter(dokterTujuan) != null)
    {
        deleted                                 = dokterTujuan;
        nextDokter(prevDokter(dokterTujuan))    = nextDokter(dokterTujuan);
        prevDokter(nextDokter(dokterTujuan))    = prevDokter(dokterTujuan);
        nextDokter(deleted)                     = null;
        prevDokter(deleted)                     = null;
    }
}

void insertPasien(ListDokter &L)
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    address_C iniPasien;
    address_P iniDokter;
    iniPasien = alokasiPasien();

    bool next = false;
    int inputanUserInt;
    while(!next)
    {
        cout<<" masukan id dokter tujuan ";
        cin>>inputanUserInt;
        iniDokter = findDokter(L,inputanUserInt);
        if(iniDokter != null)
        {
            next = true;
        }
        else
        {
            cout<<"dokter tidak ditemukan, silakang coba lagi"<<endl;
        }
    }

    next = false;
    while(!next)
    {
        cout<<"1. insert first pasien"<<endl;
        cout<<"2. insert last  pasien"<<endl;
        cout<<"3. insert after pasien"<<endl;
        cin>>inputanUserInt;

        switch(inputanUserInt)
        {
        case 1 :
            insertFirstPasien(L,iniDokter,iniPasien);
            next = true;
            break;
        case 2 :
            insertLastPasien(L,iniDokter,iniPasien);
            next = true;
            break;
        case 3 :
            address_C pasienSebelum;
            bool ketemu = false;
            int inputanUserInt2;
            while(!ketemu)
            {
                cout<<"masukan nomor pelanggan pasien sebelumnya : ";
                cin>>inputanUserInt2;
                pasienSebelum = findPasien(L,iniDokter,inputanUserInt2);
                if(pasienSebelum == null)
                {
                    cout<<"pasien sebelum dengan nomor pelanggan "<<inputanUserInt2<<" tidak ditemukan "<<endl;
                    cout<<"silakan coba lagi"<<endl;
                }
                else
                {
                    ketemu = true;
                }
            }
            insertAfterPasien(L,iniDokter,pasienSebelum,iniPasien);
            next = true;
            break;
        }
    }
}

void insertFirstPasien(ListDokter &L,address_P dokterTujuan, address_C pasienTujuan)
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    if(pasienDokterIni(dokterTujuan) == null)
    {
        pasienDokterIni(dokterTujuan)               = pasienTujuan;
    }
    else
    {
        nextPasien(pasienTujuan)                    = pasienDokterIni(dokterTujuan);
        pasienDokterIni(dokterTujuan)               = pasienTujuan;
    }
}

void insertLastPasien(ListDokter &L, address_P dokterTujuan, address_C pasienTujuan)
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    if(pasienDokterIni(dokterTujuan) == null)
    {
        pasienDokterIni(dokterTujuan)               = pasienTujuan;
    }
    else
    {
        address_C cekPasien;
        cekPasien = pasienDokterIni(dokterTujuan);

        while(nextPasien(cekPasien) != null)
        {
            cekPasien = nextPasien(cekPasien);
        }
        nextPasien(cekPasien)   = pasienTujuan;
    }
}

void insertAfterPasien(ListDokter &L, address_P dokterTujuan, address_C pasienSebelum, address_C pasienTujuan)
/** Nama : RITA AJENG NUGRAHENI
    NIM  : 1301154524
**/
{
    if(nextPasien(pasienSebelum) == null)
    {
        nextPasien(pasienSebelum)   = pasienTujuan;
    }
    else
    {
        nextPasien(pasienTujuan)    = nextPasien(pasienSebelum);
        nextPasien(pasienSebelum)   = pasienTujuan;
    }
}

void viewDokterPasien(ListDokter L,bool pasien)
/** Nama : RITA AJENG NUGRAHENI & KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154524 & 1301154496
**/
{
    address_P cekDokter;
    address_C cekPasien;

    cekDokter = firstListDokter(L);
    while(cekDokter != null)
    {
        cout<<"nama dokter              : "         <<namaDokter(cekDokter)<<endl;
        cout<<"spesialis dokter         : "         << spesialisDokter(cekDokter)<<endl;
        cout<<" nip dokter              : "         <<NIPDokter(cekDokter)<<endl;
        cout<<"tempat dinas dokter      : "         <<tempatDinasDokter(cekDokter)<<endl;
        cout<<endl;


        if(pasien)
        {
            cout<<"pasien :"<<endl;
            cekPasien = pasienDokterIni(cekDokter);
            while(cekPasien != null)
            {
                cout<<namaPasien(cekPasien)<<endl;
                cout<<nama_penyakit(cekPasien)<<endl;
                cout<<alamat(cekPasien)<<endl;
                cout<<nomor_pelanggan(cekPasien)<<endl;
                cout<<endl;

                cekPasien = nextPasien(cekPasien);
            }
        }
        cekDokter = nextDokter(cekDokter);
    }
}

void AscDokter(ListDokter &L)
/** Nama : KHARISMA OKTAVIANING HERWANDA
    NIM  : 1301154496
**/
{
    ListDokter listDokterBaru;
    createListDokter(listDokterBaru);

    address_P cekDokter0;
    address_P cekDokter;
    address_P cekDokter2;

    address_P dokterPindah;
    address_P cekDokterNipTerkecil;

    cekDokterNipTerkecil = firstListDokter(L);

    while(cekDokterNipTerkecil != null)
    {
        cekDokter = nextDokter(cekDokterNipTerkecil);
        while(cekDokter != null)
        {
            if(NIPDokter(cekDokterNipTerkecil) > NIPDokter(cekDokter))
            {
                cekDokterNipTerkecil = cekDokter;
            }
            cekDokter = nextDokter(cekDokter);
        }
        deleteDokter(L,cekDokterNipTerkecil,dokterPindah);
        insertLastDokter(listDokterBaru,dokterPindah);
        cekDokterNipTerkecil = firstListDokter(L);
    }
    firstListDokter(L)  = firstListDokter(listDokterBaru);
    lastListDokter(L)   = lastListDokter(listDokterBaru);
    bool pasienbool = false;
    viewDokterPasien(listDokterBaru,pasienbool);
    cout<<" dokter telah tersusun berdasarkan NIP "<<endl;
}

void infoData(ListDokter L)
/** Nama : KHARISMA OKTAVIANING HERWANDA & RITA AJENG NUGRAHENI
    NIM  : 1301154496 & 1301154524
**/
{
    int banyakDokter    = 0;
    int banyakPasien    = 0;
    int banyakMinPasien = 999;
    int banyakMaxPasien = 0;
    int usiaTermuda     = 999;
    int banyakPasienSementara = 0;

    address_P cekDokter;
    address_C cekPasien;

    cekDokter = firstListDokter(L);
    while(cekDokter != null)
    {
        banyakDokter++;
        cekPasien = pasienDokterIni(cekDokter);
        banyakPasienSementara = 0;
        while(cekPasien != null)
        {
            banyakPasien++;
            banyakPasienSementara++;
            if(usia(cekPasien) < usiaTermuda)
            {
                usiaTermuda = usia(cekPasien);
            }
            cekPasien = nextPasien(cekPasien);

        }
        if(banyakPasienSementara < banyakMinPasien)
        {
            banyakMinPasien = banyakPasienSementara;
        }
        if(banyakPasienSementara > banyakMaxPasien)
        {
            banyakMaxPasien = banyakPasienSementara;
        }

        cekDokter = nextDokter(cekDokter);
    }

    cout<<"banyak Dokter            : "<<banyakDokter<<" dokter "<<endl;
    cout<<"banyak Pasien            : "<<banyakPasien<<" pasien "<<endl;
    if(usiaTermuda != 999)
    {
        cout<<"Usia pasien termuda      : "<<usiaTermuda<<" tahun "<<endl;
    }
    else
    {
        cout<<"Usia pasien termuda      : 0 tahun "<<endl;
    }

    if(banyakMinPasien != 999)
    {
        cout<<"min pasien per dokter    : "<<banyakMinPasien<<" pasien "<<endl;
    }
    else
    {
        cout<<"min pasien per dokter    : 0 pasien "<<endl;
    }

    cout<<"max pasien per dokter    : "<<banyakMaxPasien<<" pasien "<<endl;
}

void deletePasienDiDokter(ListDokter &L, address_P dokterTujuan, int nomorPelanggan)
/** Nama : KHARISMA OKTAVIANING HERWANDA & RITA AJENG NUGRAHENI
    NIM  : 1301154496 & 1301154524
**/
{
    address_C cekPasien;
    address_C pasienSebelumnya;
    pasienSebelumnya    = null;
    cekPasien           = pasienDokterIni(dokterTujuan);
    while(cekPasien != null)
    {
        if(nomorPelanggan = nomor_pelanggan(cekPasien))
        {
            if(cekPasien == pasienDokterIni(dokterTujuan))
            {
                pasienDokterIni(dokterTujuan) = nextPasien(cekPasien);
                nextPasien(cekPasien) = null;
                // delete
            }
            else if (cekPasien != pasienDokterIni(dokterTujuan) && nextPasien(cekPasien) != null)
            {
                nextPasien(pasienSebelumnya)    = nextPasien(cekPasien);
                nextPasien(cekPasien)           = null;
                //delete
            }
            else if (nextPasien(cekPasien) == null)
            {
                nextPasien(pasienSebelumnya)    = null;
                //delete
            }
        }
        pasienSebelumnya = cekPasien;
        cekPasien = nextPasien(cekPasien);
    }
}

void deletePasienDiSemuaDokter(ListDokter &L, int nomorPelanggan)
/** Nama : KHARISMA OKTAVIANING HERWANDA & RITA AJENG NUGRAHENI
    NIM  : 1301154496 & 1301154524
**/
{
    address_P cekDokter;
    cekDokter = firstListDokter(L);

    while(cekDokter != null)
    {
        deletePasienDiDokter(L,cekDokter,nomorPelanggan);
        cekDokter = nextDokter(cekDokter);
    }
}




