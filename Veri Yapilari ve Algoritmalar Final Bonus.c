#include <stdio.h>

// Baran Arda Banarli
// 2420161079
// https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=9XrtzwD6vo

void dizi_yazdir(int dizi[], int BOYUT) {
	int i;
	for (i=0; i<BOYUT; i++) {
		printf("%3d", dizi[i]);
	}
	printf("\n");
}

void takas(int *ap, int *bp) {
	int gecici = *ap;
	*ap = *bp;
	*bp = gecici;
}

// baloncuk siralama optimizasyonu
// takas olup olmadigi kontrol edilerek
// daha az iterasyon gerceklesmesi saglanabilir
void baloncuk_sirala(int dizi[], int BOYUT) {
	int i, j;
	int takas_oldu;  // bayrak (flag)
	
	for (i=1; i<BOYUT; i++) { // iterasyon islemleri
		takas_oldu = 0;    // bayrak sifirlama (reset)
		for (j=0; j<BOYUT-1; j++) {
			if (dizi[j] > dizi[j+1]) {
				takas(dizi+j , dizi+j+1);
				takas_oldu = 1;  // takas gerceklesti
			}
		}
		printf("iter.%2d: ", i);
		dizi_yazdir(dizi, BOYUT);
		if (takas_oldu == 0) {
			break;    // herhangi bir takas yoksa siralama bitmistir
		}
	}
}

int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
	int orta_ind = (ilk_ind + son_ind) / 2;
	
	// aradigimiz eleman dizinin orta indisli elemanina esit ise
	if (search == dizi[orta_ind]) {
		return orta_ind;
	}
	// aradigimiz eleman dizinin orta indisli elemanindan buyuk ise
	else if (search > dizi[orta_ind] && (son_ind-ilk_ind) > 0 ) {
		return ikili_arama(dizi, BOYUT, search, orta_ind+1, son_ind);
	}
	// aradigimiz eleman dizinin orta indisli elemanindan kucuk ise
	else if (search < dizi[orta_ind] && (son_ind-ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, 0, orta_ind-1);
	}
	// istenen kosullar saglanamadi --> aranan deger bulunamadi
	else {
		return -1;
	}
}

int main() {
	int A[] = {64, 11, 25, 9, 34, 90, 12, 5, 44, 73};
	int N = sizeof(A) / sizeof(A[0]);
	int aranan, sonuc;
	
	dizi_yazdir(A, N);      // orijinal dizi
	
	// once siralamamiz gerekiyor yoksa ikili arama calismaz
	baloncuk_sirala(A, N);  
	
	dizi_yazdir(A, N);      // siralanmis sonuc dizisi
	
	printf("Aramak istediginiz deger: ");
	scanf("%d", &aranan);
	
	// ikili_arama(dizi adi, eleman sayisi, aranan eleman, ilk indis, son indis)
	sonuc = ikili_arama(A, N, aranan, 0, N-1);
	
	if (sonuc == -1) {
		printf("Aradiginiz deger %d, dizide bulunamadi!\n", aranan);
	}
	else {
		printf("Aradiginiz deger %d, dizinin %d. indisinde bulundu!\n", aranan, sonuc);
	}
		
	return 0;
}
