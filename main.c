#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "list.h"
#include "stack.h"

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif

int main() {
    ListMeja mejaRestoran;
    Stack pesanan;
    char namaPelanggan[30], mejaDipilih[3];
    int pilihan;
    int totalHarga = 0;  // Tambahkan variabel untuk menghitung total harga

    // Inisialisasi
    CreateListMeja(&mejaRestoran);
    CreateStack(&pesanan);

    // Tambahkan meja dengan format "A1", "B1", "C1" dll.
    char baris[] = "ABCDE";
    int i = 0;
    while (i < 5) {
        int j = 1;
        while (j <= 5) {
            char kode[3];
            sprintf(kode, "%c%d", baris[i], j);
            TambahMeja(&mejaRestoran, kode);
            j++;
        }
        i++;
    }

    // **Input Nama Pelanggan**
    system(CLEAR_SCREEN);
    printf("=== SELAMAT DATANG DI RESTORAN ===\n");
    printf("Masukkan nama Anda: ");
    fgets(namaPelanggan, sizeof(namaPelanggan), stdin);
    namaPelanggan[strcspn(namaPelanggan, "\n")] = 0; // Menghapus newline
    system(CLEAR_SCREEN);

    // **Pilih Meja**
    while (1) {
        printf("Halo %s, berikut meja yang tersedia:\n", namaPelanggan);
        TampilkanMejaTersedia(mejaRestoran);
        printf("Pilih meja (contoh: A1, b2, C3): ");
        scanf("%s", mejaDipilih);

        // **Konversi huruf pertama menjadi huruf besar**
        mejaDipilih[0] = toupper(mejaDipilih[0]);

        if (PilihMeja(&mejaRestoran, mejaDipilih)) {
            printf("Meja %s telah dipilih.\n", mejaDipilih);
            system(CLEAR_SCREEN);
            break;
        } else {
            printf("Meja tidak tersedia! Pilih lagi.\n");
        }
    }

    // **Pilih Menu Makanan**
    while (1) {
        system(CLEAR_SCREEN); // Pindah ke halaman baru setiap memilih menu makanan
        printf("=== MENU MAKANAN ===\n");
        printf("1. Nasi Goreng - 20000\n");
        printf("2. Ayam Geprek - 25000\n");
        printf("3. Mie Ayam - 18000\n");
        printf("4. Sate Ayam - 30000\n");
        printf("5. Selesai Memesan\n");

        printf("\nPilih menu (1-5): ");
        scanf("%d", &pilihan);

        if (pilihan == 5) {
            system(CLEAR_SCREEN);
            break; // Keluar dari loop jika memilih "Selesai"
        }

        Makanan menu;
        switch (pilihan) {
            case 1:
                sprintf(menu.nama_makanan, "Nasi Goreng");
                menu.harga = 20000;
                break;
            case 2:
                sprintf(menu.nama_makanan, "Ayam Geprek");
                menu.harga = 25000;
                break;
            case 3:
                sprintf(menu.nama_makanan, "Mie Ayam");
                menu.harga = 18000;
                break;
            case 4:
                sprintf(menu.nama_makanan, "Sate Ayam");
                menu.harga = 30000;
                break;
            default:
                printf("Pilihan tidak valid!\n");
                continue;
        }

        Push(&pesanan, menu);
        totalHarga += menu.harga; // Tambahkan harga makanan ke total
        printf("%s telah ditambahkan ke pesanan.\n", menu.nama_makanan);
    }

    // **Ringkasan Pesanan**
    system(CLEAR_SCREEN);
    printf("=== RINGKASAN PESANAN ===\n");
    printf("Nama: %s\n", namaPelanggan);
    printf("Meja: %s\n", mejaDipilih);
    PrintStack(pesanan);
    printf("\nTotal Harga: Rp %d\n", totalHarga); // Menampilkan total harga
    printf("\nTerima kasih telah memesan di restoran kami!\n");

    return 0;
}

