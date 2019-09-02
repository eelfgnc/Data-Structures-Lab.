#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void dizi_olusturma(int[], int);
void kopya_dizi_olusturma(int[], int[], int);
void Kabarcik_Bubblesort(int[], int);
void Arayasokma_Insertionsort(int[], int);
void Secmeli_Selectionsort(int[], int);
void Hizli_Quicksort(int[], int, int);
void Tarak_Combsort(int[], int);
void Sure_matrisi();
double Sure;
/**
* \brief TimeStart: Fonksiyonlarin baslangic zamani.
*/
clock_t TimeStart;
/**
* \brief TimeEnd: Fonksiyonlarin bitim zamani.
*/
clock_t TimeEnd;
/**
* \brief *A: Orjinal dizinin tutuldugu yeri gosteren pointer
*/
int *A;
/**
* \brief *Kopya_A: A pointerinin gosterdigi dizinin kopyasinin tutuldugu yeri gosteren pointer
*/
int *Kopya_A;
/**
* \brief Sure_veri[5][3]: Surelerin tutuldugu matris
*/
double Sure_veri[5][3];

int main()
{
	/**
	*\brief Siralama fonksiyonlarinin calisma surelerini hesaplama  
	*\author Elif GENC (01elifgenc@gmail.com)
	*\date 10.12.2017
	*/
	cout << setw(22) << right << " "
		<< "N=1000"
		<< setw(21) << right << "N=10000"
		<< setw(22) << right << "N=100000";
	Sure_matrisi();
	for (int i = 0;i < 5;i++) {
		if (i == 0) {
			cout << "\nBubble Sort";
			cout << setw(9) << right << " ";
		}
		if (i == 1) {
			cout << "\nInsertion Sort";
			cout << setw(6) << right << " ";
		}
		if (i == 2) {
			cout << "\nSelection Sort";
			cout << setw(6) << right << " ";
		}
		if (i == 3) {
			cout << "\nQuick Sort";
			cout << setw(10) << right << " ";
		}
		if (i == 4) {
			cout << "\nComb Sort";
			cout << setw(11) << right << " ";
		}
		for (int j = 0;j < 3;j++) {
			if (j == 0) {
				cout << setw(5) << right << Sure_veri[i][j];
				cout << " sec.";
			}
			if (j == 1) {
				cout << setw(16) << right << Sure_veri[i][j];
				cout << " sec.";
			}
			if (j == 2) {
				cout << setw(17) << right << Sure_veri[i][j];
				cout << " sec.";
			}
		}
	}
	cout << endl;
	system("pause");
	return 0;
}

/**
* \brief Dizi'nin elemanlari, kopya_dizi'sinin elemanlarina atanir.
* \brief Zaman karmasikligi O(n)'dir.
* \param kopya_dizi: Dizi parametresinin kopyasi olacak olan dizi
* \param dizi: Orjinal dizi
* \param n: Dizi boyutu
*/
void kopya_dizi_olusturma(int kopya_dizi[], int dizi[], int n) {
	for (int i = 0;i < n;i++) {
		kopya_dizi[i] = dizi[i];
	}
}

/**
* \brief Fonksiyona gonderilen dizinin elemanlari rastgele tam sayilardan olusturulur.
* \brief Zaman karmasikligi O(n)'dir.
* \param dizi: Elemanlari rand fonksiyonu ile olusturulan dizi
* \param n: Dizi boyutu
*/
void dizi_olusturma(int dizi[], int n) {
	int i;
	for (i = 0;i < n;i++) {
		dizi[i] = rand() % n;
	}
}

/**
* \brief Dizinin ilk elemani alinir.Bu eleman dizinin diger elemanlariyla tek tek karsilastirma yapilir.Eger elimizdeki eleman karsilastirdigimiz elemandan buyuk ise yer degistirme islemi yapilir.
* \brief Bu islem (eleman sayisi - 1) kere tekrar edilir.
* \brief Boylelikle dizinin elemanlari kucukten buguge dogru siaralanmis olur.
* \brief Kabarcik siralmanin zaman karmasikligi: O(n*n).
* \param dizi: Elemanlari siralanacak olan dizi
* \param diziboyutu: Dizinin boyutu
*/
void Kabarcik_Bubblesort(int dizi[], int diziboyutu) {
	int i, j, gecici;
	for (i = 0;i < diziboyutu - 1;i++) {
		for (j = 0;j < diziboyutu - 1;j++) {
			if (dizi[j] > dizi[j + 1]) {
				gecici = dizi[j];
				dizi[j] = dizi[j + 1];
				dizi[j + 1] = gecici;
			}
		}
	}
}

/**
* \brief Dizinin ilk elemani yerinde birakilir.Ikinci eleman alinir ve dizi sanki iki elemanliymis gibi bakilip, ilk iki eleman kendi icerisinde siralanir.
* \brief Ucuncu eleman ele alinip sanki dizi 3 elemanliymis gibi bakilip siralanir.Ele alinacak elemanin indisi her seferinde bir bir artar.Sirali kisim on taraf olurken, henuz siralanmamis kisim arka taraf olur.
* \brief Kisacasi araya sokulacak elemanin yeri blunur.Geri kalan elemanlar icin kaydirma islemi yapilir.
* \brief Eleman eklemenin zaman karmasikligi: O(n) iken diziyi tamemen siralamanin zaman karmasikligi ise O(n*n)' dir. 
* \param dizi: Elemanlari siralanacak olan dizi
* \param diziboyutu: Dizinin boyutu
*/
void Arayasokma_Insertionsort(int dizi[], int diziboyutu) {
	int i, j, ekle;
	for (i = 1;i < diziboyutu;i++) {
		ekle = dizi[i];
		for (j = i - 1;j >= 0 && ekle <= dizi[j];j--) {
			dizi[j + 1] = dizi[j];
		}
		dizi[j + 1] = ekle;
	}
}
/**
* \brief Dizinin ilk elemani alinir.Daha sonra dizi icerisindeki en kucuk eleman bulunur.
* \brief Buldugumuz en kucuk eleman ile ilk basta sectigimiz eleman yer degistirir.
* \brief Bu islem bittikten sonra ikinci eleman alinir.Bu eleman icinde dizideki ikinci en kucuk eleman bulunur ve bu eleman ile yer degistirilir.
* \brief Dizideki eleman bitinceye kadar bu islem devam eder.
* \brief Secmeli siralama algoritmasinin zaman karmasikligi O(n*n)'dir.
* \param dizi: Elemanlari siralanacak olan dizi
* \param diziboyutu: Dizinin boyutu
*/
void Secmeli_Selectionsort(int dizi[], int diziboyutu) {
	int enkucuk, i, j, indis;
	for (i = 0;i < diziboyutu;i++) {
		enkucuk = dizi[i];
		indis = i;
		for (j = i;j < diziboyutu;j++) {
			if (dizi[j] < enkucuk) {
				enkucuk = dizi[j];
				indis = j;
			}
		}
		dizi[indis] = dizi[i];
		dizi[i] = enkucuk;
	}
}

/**
* \brief Bol ve Yonet politikasi uygulanir.
* \brief Dizi pivot (sinir) degerine gore iki alt diziye ayrilir.
* \brief Pivot elemanindan kucuk olanlar bir tarafa, buyuk olanlar ise diger tarafa toplanir.
* \brief En son birer eleman kalincaya kadar bol politikasi uygulanir.
* \brief Sol degeri sag degerinden buyuk olursa dizide bolunecek eleman kalmadigi anlasilir.Boylelikle rekursif cagirmaninda geri donusu yapildiktan sonra dizi siralanmis olur.
* \brief Hizli siralama algoritmasinin en kotu durumdaki zaman karmasikligi O(n*n)'dir.Ortalama zaman karmasikligi ise O(nlogn)'dir.
* \brief Uygulamalarda hizli siralama algoritmasi en kotu duruma pek fazla gitmemektedir ve rastgele ozellikte olan verilen maliyeti O(nlogn)'dir.
* \param dizi: Elemanlari siralanacak olan dizi
* \param sol: Dizinin siralamaya koyulacak parcasinin sol tarafinin indis degeri
* \param sag: Dizinin siralamaya koyulacak parcasinin sag tarafinin indis degeri
*/
void Hizli_Quicksort(int dizi[], int sol, int sag) {
	int k, j;
	int gecici, ortadaki;
	j = sag;
	k = sol;
	ortadaki = dizi[(sag + sol) / 2];
	do {
		while (dizi[k] < ortadaki && k < sag)
			k++;
		while (ortadaki < dizi[j] && j > sol)
			j--;
		if (k <= j) {
			gecici = dizi[k];
			dizi[k] = dizi[j];
			dizi[j] = gecici;
			k++;
			j--;
		}
	} while (k <= j);
	if (sol <= j) Hizli_Quicksort(dizi, sol, j);
	if (k <= sag) Hizli_Quicksort(dizi, k, sag);
}
/**
* \brief Dizinin boyutunu sabit olan sayiya bolup arama boslugunu(gap) buluruz.
* \brief Dizi icerindeki elemanlari karsilastirirken, karsilastirilan iki eleman indisleri farki arama boslugu olur.i indisli eleman (i+aramaboslugu) indisli elemandan buyukse bu ilki eleman yer degisitirilir.
* \brief Arama boslugu sayisini bulurken bir onceki arama boslugu sayisini kullanarak buluruz.Eger arama boslugu bire esit olursa dizi tamamen kucukten buyuge siralanmis olur.
* \brief Tarak siralama algoritmasinin zaman karmasikligi O(n*n)'dir.
* \param dizi: Elemanlari siralanacak olan dizi
* \param diziboyut: Dizinin boyutu
*/
void Tarak_Combsort(int dizi[], int diziboyut) {
	int gecici;
	int bosluk = diziboyut;
	while (bosluk > 1) {
		if (bosluk > 1) {
			bosluk = (int)((double)bosluk / 1.247330950103979);
		}
		for (int i = 0; bosluk + i < diziboyut; i++) {
			if (dizi[i] > dizi[i + bosluk] ) {
				gecici = dizi[i];
				dizi[i] = dizi[i + bosluk];
				dizi[i + bosluk] = gecici;
			}
		}
	}
}

/**
* \brief Dizi boyutunu 1000, 10000 ve 100000 yapar ve olusturulan dizi icinde kopya bir dizi olsuturur.
* \brief Olusturulan kopya dizinin elemanlari, elemanlari degismeyen dizinin kopyasidir.
* \brief Olusturulan diziler icin siralama algoritmalarini kullanilir.
* \brief Siralama algortimalari kullanilirken fonksiyonlarin calisma sureleri hesaplanir.Bu sureler bir matris icinde tutulur.
* \brief Bu fonksiyonun zaman karmasikligi O(n*n*n)'dir.
*/
void Sure_matrisi() {
	int j = 0, n;
	for (int i = 0;i < 3;i++) {
		if (i == 0) {
			n = 1000;
			A = new int[n];
			dizi_olusturma(A, n);
			Kopya_A = new int[n];
			kopya_dizi_olusturma(Kopya_A, A, n);
		}
		if (i == 1) {
			n = 10000;
			A = new int[n];
			dizi_olusturma(A, n);
			Kopya_A = new int[n];
			kopya_dizi_olusturma(Kopya_A, A, n);
		}
		if(i == 2) {
			n = 100000;
			A = new int[n];
			dizi_olusturma(A, n);
			Kopya_A = new int[n];
			kopya_dizi_olusturma(Kopya_A, A, n);
		}

		TimeStart = clock();
		Kabarcik_Bubblesort(Kopya_A, n);
		TimeEnd = clock();
		Sure_veri[j][i] = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
		j++;

		kopya_dizi_olusturma(Kopya_A, A, n);
		TimeStart = clock();
		Arayasokma_Insertionsort(Kopya_A, n);
		TimeEnd = clock();
		Sure_veri[j][i] = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
		j++;

		kopya_dizi_olusturma(Kopya_A, A, n);
		TimeStart = clock();
		Secmeli_Selectionsort(Kopya_A, n);
		TimeEnd = clock();
		Sure_veri[j][i] = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
		j++;

		kopya_dizi_olusturma(Kopya_A, A, n);
		TimeStart = clock();
		Hizli_Quicksort(Kopya_A, 0, n - 1);
		TimeEnd = clock();
		Sure_veri[j][i] = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
		j++;

		kopya_dizi_olusturma(Kopya_A, A, n);
		TimeStart = clock();
		Tarak_Combsort(Kopya_A, n);
		TimeEnd = clock();
		Sure_veri[j][i] = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;

		j = 0;
		delete[]A;
		delete[]Kopya_A;
	}
}