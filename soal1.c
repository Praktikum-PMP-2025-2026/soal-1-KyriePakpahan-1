/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 2
 *   Hari dan Tanggal    : Senin, 20 April 2026 
 *   Nama (NIM)          : Kyrie Eleison Jacob Pakpahan (13224006)
 *   Nama File           : soal1.c
 *   Deskripsi           : Fungsi untuk mengembalikan nilai yang hilang pada array, kemudian mengembalikan nilai jumlah maksimum dari elemen array di dalamnya
 * 
 *   
 */
#include <stdio.h>
#include <stdlib.h>

int get_floor_avg(int sum){
    if (sum >0) {
        return sum / 2;
    }else {
        return (sum - 1) / 2; // untuk memastikan pembulatan ke bawah
    }
}

void recovery_array (int arr[], int N){
    // recovery array
    for (int i = 0; i < N; i++) {
        if (arr[i] == -1) {
            int has_left = 0, left_val = 0;
            int has_right = 0, right_val = 0;

            // cek tetangga kiri
            // lihat ke belakang untuk nilai pertama yang bukan -1
            if (i > 0) {
                has_left = 1;
                left_val = arr[i - 1]; 
            }

            // cek tetangga kanan
            // lihat ke depan untuk nilai pertama yang bukan -1
            for (int j = i + 1; j < N; j++) {
                if (arr[j] != -1) {
                    has_right = 1;
                    right_val = arr[j];
                    break;
                }
            }

            // terapkan aturan recovery 
            if (has_left && has_right) {
                arr[i] = get_floor_avg(left_val + right_val);
            } else if (has_left) {
                arr[i] = left_val;
            } else if (has_right) {
                arr[i] = right_val;
            } else {
                arr[i] = 0; // jika seluruh array awalnya -1
            }
        }
    }
}

void print_recovered_array (int arr[], int N){
    printf("RECOVERED");
    for (int i = 0; i < N; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

void print_max_sum (int arr[], int N){
    long long max_sum = arr[0];
    long long current_sum = arr[0];
    
    for (int i = 1; i < N; i++) {
        if (current_sum < 0) {
            current_sum = arr[i];
        } else {
            current_sum += arr[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("MAX_SUM %lld\n", max_sum);
}

 int main () {
    int N;

    // baca input dari user
    if (scanf("%d", &N) != 1){
        return 0;
    }

    if (N <= 0){
        printf("RECOVERED\n");
        printf("MAX_SUM 0\n");
        return 0;
    }

    // buat array untuk menyimpan nilai
    int arr[N];
    for (int i = 0;i < N;i++){
        if (scanf("%d", &arr[i]) != 1){
            return 0;
        }
    }

    recovery_array(arr, N);
    print_recovered_array(arr, N);
    print_max_sum(arr, N);

    return 0;
}
