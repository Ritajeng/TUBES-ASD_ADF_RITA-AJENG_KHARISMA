#ifndef ADTNYA_H_INCLUDED
#define ADTNYA_H_INCLUDED
#include <iostream>

//  DEFINE DOKTER
/** Nama : KHARISMA OKTAVIANING HERWANDA & RITA AJENG NUGRAHENI
    NIM  : 1301154496 & 1301154524
**/


#define firstListDokter(P)      (P).firstDokter
#define lastListDokter(P)       (P).lastDokter
#define infoDokter(P)           (P).infoDokter
#define nextDokter(P)           (P)->nextDokter
#define prevDokter(P)           (P)->prevDokter
#define pasienDokterIni(P)      (P)->pasienDokterIni
#define namaDokter(P)           (P)->infoDokter.nama
#define spesialisDokter(P)      (P)->infoDokter.spesialis
#define NIPDokter(P)            (P)->infoDokter.NIP
#define tempatDinasDokter(P)    (P)->infoDokter.tempatDinas

// DEFINE PASIEN
#define firstListPasien(P)      (P).firstPasien
#define lastListPasien(P)       (P).lastPasien
#define infoPasien(P)           (P).infoPasien
#define nextPasien(P)           (P)->nextPasien
#define namaPasien(P)           (P)->infoPasien.nama_pasien
#define nama_penyakit(P)        (P)->infoPasien.nama_penyakit
#define alamat(P)               (P)->infoPasien.alamat
#define nomor_pelanggan(P)      (P)->infoPasien.nomor_pelanggan
#define usia(P)                 (P)->infoPasien.usia

#define null NULL
using namespace std;


typedef struct elmlist_C *address_C;
typedef struct elmlist_P *address_P;

struct ListDokter{
    address_P firstDokter;
    address_P lastDokter ;
};

typedef struct infotype_P {
    string  nama;
    string  spesialis;
    int     NIP;
    string  tempatDinas;
};

struct elmlist_P {
    infotype_P  infoDokter          ;
    address_P   nextDokter          ;
    address_P   prevDokter          ;
    address_C   pasienDokterIni     ;
};

struct ListPasien{
    address_C firstPasien;
    address_C lastPasien;
};

typedef struct infotype_C {
    string  nama_pasien;
    string  nama_penyakit;
    string  alamat;
    int     usia;
    int     nomor_pelanggan;
};

struct elmlist_C{
    infotype_C  infoPasien;
    address_C   nextPasien;
};



void createListDokter           (ListDokter &L);
void createListPasien           (ListPasien &L);
address_P alokasiDokter         ();
address_C alokasiPasien         ();
address_P findDokter            (ListDokter  L, int NIPDokterYangDicari);
address_C findPasien            (ListDokter  L, address_P dokterTujuan, int nomorPelangganPasien);
void insertFirstDokter          (ListDokter &L, address_P dokterBaru);
void insertLastDokter           (ListDokter &L, address_P dokterBaru);
void insertAfterDokter          (ListDokter &L, address_P dokterBaru, address_P dokterLama);
void insertDokter               (ListDokter &L, address_P dokterBaru);
void deleteDokter               (ListDokter &L, address_P dokterTujuan, address_P &deleted);
void insertFirstPasien          (ListDokter &L, address_P dokterTujuan, address_C pasienTujuan);
void insertLastPasien           (ListDokter &L, address_P dokterTujuan, address_C pasienTujuan);
void insertAfterPasien          (ListDokter &L, address_P dokterTujuan, address_C pasienSebelum , address_C pasienTujuan);
void insertPasien               (ListDokter &L);
void deletePasienDiSemuaDokter  (ListDokter &L, int nomorPelanggan);
void deletePasienDiDokter       (ListDokter &L, address_P dokterTujuan, int nomorPelanggan);


void viewDokterPasien           (ListDokter L,bool pasien);
void AscDokter                  (ListDokter &L);
void infoData                   (ListDokter L);
#endif // ADTNYA_H_INCLUDED
