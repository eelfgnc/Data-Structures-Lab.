#include<iostream>
#include<ctime>
#include<ctime>
#include<iomanip>
using namespace std;
typedef struct dugumler {
	char ad[20];
};
dugumler A[10];
int **a;
int secim;
int d_sayisi;
void menu();
void dugum_Sayisi();
void dugum_Isimlendirme(dugumler[]);
void yol_mesafe();
void komsuluk_matrisi();
void isim_guncelleme();
void mesafe(int);
void dugum_ekle();
void dugum_cikar();
int main()
{
	/**
	* \brief Graf(graph) yapisini dinamik matris ve diziyle olusturuyoruz.
	* \brief Graf uzerinde dugum/yol ekleme/cikarma, dugum ismi/mesafe guncelleme, komsuluk matrisini yazdirma, en kýsa yolu bulup toplam maliyeti hesaplama gibi özellikleri fonksiyonlar yardimiyla yapan program.
	* \author Elif GENC
	*/
	srand(time(NULL));
	menu();
	system("pause");
	return 0;
}
void menu() {
	dugum_Sayisi();
	dugum_Isimlendirme(A);
	yol_mesafe();
	do {
		cout << "\t\t**********MENU**********" << endl;
		cout << "\t\t[1]...MESAFE GUNCELLEME" << endl;
		cout << "\t\t[2]...DUGUM ISMI GUNCELLEME" << endl;
		cout << "\t\t[3]...YOL EKLE" << endl;
		cout << "\t\t[4]...YOL CIKAR" << endl;
		cout << "\t\t[5]...DUGUM EKLE" << endl;
		cout << "\t\t[6]...DUGUM SIL" << endl;
		cout << "\t\t[7]...MESAFE BILGILERI" << endl;
		cout << "\t\t[8]...IKI DUGUM ARASINDAKI EN KISA YOL VE TOPLAM MALIYET" << endl;
		cout << "\t\t[9]...EXIT" << endl;
		cout << "Seciminiz: ";
		cin >> secim;

		if (secim == 1) {
			mesafe(1);
		}
		else if (secim == 2) {
			isim_guncelleme();
		}
		else if (secim == 3) {
			mesafe(2);
		}
		else if (secim == 4) {
			mesafe(3);
		}
		else if (secim == 5) {
			dugum_ekle();
		}
		else if (secim == 6) {
			dugum_cikar();
		}
		else if (secim == 7) {
			komsuluk_matrisi();
		}
		else if (secim == 8) {

		}
	} while (secim >= 1 && secim < 9);
}
/**
* \brief Grafa kullancinin girdigi dugum isminde bir dugum ekliyoruz.
* \brief Dugum isimlerinin tutuldugu diziye (A) kullanicinin girdigi ismi ekliyoruz.
* \brief Komsuluk matrisinde bir dugum artacagi icin matris uzerinde bir satir ve bir sutun artacaktir.Matrisin boyutu degistigi icin yeni olusturacagimiz boyutta dinamik bir matris olustururuz.
* \brief Eski matrisin elemanlarini yeni olusturdugumuz matris icerisine aktarilir.
* \brief Eski kucuk boyuttaki matris hafizada yer kaplamamasi icin silinir.
* \brief Kucuk matrisi tutan (suan hicbir yeri isaret etmeyen) pointer ise yeni matrisi tutacak sekilde ayarlanir.
* \brief Dugum isimlerinin tutuldugu dizi(A) de bir dugum artacagi icin dugum sayisi bir artacaktir.
* \brief Zaman karmasikligi O(n*n)
*/
void dugum_ekle() {
	char x[20];
	cout << "Dugum ismini giriniz. ";
	cin >> x;
	for (int i = 0;x[i] != '\0';i++) {
		A[d_sayisi].ad[i] = x[i];
	}
	int **yenialan;
	yenialan = new int*[d_sayisi + 1];
	for (int i = 0;i < d_sayisi + 1;i++) {
		yenialan[i] = new int[d_sayisi + 1];
	}
	for (int i = 0;i <= d_sayisi;i++) {
		for (int j = 0;j <= d_sayisi;j++) {
			if (i == d_sayisi || j == d_sayisi) {
				yenialan[i][j] = 10;
			}
			else {
				yenialan[i][j] = a[i][j];
			}
		}
	}
	for (int i = 0;i < d_sayisi;i++) {
		delete[] a[i];
	}
	delete a;
	d_sayisi = d_sayisi + 1;
	a = yenialan;
}
/**
* \brief Graf uzerinde bulunan dugumler ve bu dugumler arasindaki yollari gosteren bir matris turudur.
* \brief Dugumler arasindaki yollar cift yonlu,tek yonlu ya da dugumler arasinda yol olmayabilir.
* \brief Matris belirli bir olcude yazilip kulllaniciya sunulur.
* \brief Zaman karmasikligi O(n*n)
*/
void komsuluk_matrisi() {
	cout << endl << "    \t";
	for (int i = 0;i <= d_sayisi;i++) {
		cout << A[i].ad << "    \t";
	}
	cout << endl;
	for (int i = 0;i < d_sayisi;i++) {
		cout << A[i].ad << "    \t";
		for (int j = 0;j < d_sayisi;j++) {
			if (a[i][j] == 10) {
				cout << "-\t";
			}
			else {
				cout << a[i][j] << "\t";
			}
		}
		cout << endl;
	}
}
/**
* \brief KUllanicinin girdigi sayi, olusturulacak graf uzerindeki dugum sayisidir.
* \brief Dugum sayisi en fazla 10, en az 1 olabilir.
* \brief Dugum saysisi 10'dan fazla yada 1'den az ise kullaniciya uyari mesaji verilip tekrar dugum sayisi istenir.
* \brief Zaman karmasikligi O(n)
*/
void dugum_Sayisi() {
	cout << "Olusturdugunuz graf icin dugum sayisini giriniz -> ";
	cin >> d_sayisi;
	while (d_sayisi > 10 || d_sayisi < 1) {
		if (d_sayisi > 10) {
			cout << "Dugum sayisi 10'dan buyuk olamaz.\nYeniden dugum sayisini giriniz -> ";
		}
		else {
			cout << "Dugum sayisi 1'dan kucuk olamaz.\nYeniden dugum sayisini giriniz -> ";
		}
		cin >> d_sayisi;
	}
}
/**
* \brief KUllanicinin girdigi dugum sayisi kadar dugum olusturulur.
* \brief Bu dugumlere 'A' dan baslayarak sirasiyla isim verilir.Kullanici ilk basta dugumlere tek tek isim vererek ugrasmaz.
* \brief Zaman karmasikligi O(n)
*/
void dugum_Isimlendirme(dugumler A[]) {
	int a = 65;
	for (int i = 0;i < d_sayisi;i++) {
		A[i].ad[0] = char(a);
		a++;
	}
}
/**
* \brief Kullancinin girdigi dugum sayisinin karesi kadar boyutta dinamik bir matris olusturulur.Bu matris dugumler arasi mesafeleri tutan komsuluk matrisidir.
* \brief Dugumler arasi yollar tek ve ya cift yonlu olabilir.Veya dugumler arasinda yol olmayabilir.3 cesit yol olusturulabilir.
* \brief Zaman karmasikligi O(n*n)
*/
void yol_mesafe() {
	int z;
	a = new int*[d_sayisi];
	for (int i = 0;i < d_sayisi;i++) {
		a[i] = new int[d_sayisi];
	}
	for (int i = 0;i < d_sayisi;i++) {
		for (int j = 0;j <= i;j++) {
			z = rand() % 3;
			if (z % (d_sayisi*d_sayisi) == 0) {
				a[i][j] = a[j][i] = rand() % 9 + 1;
			}
			else if (z % (d_sayisi*d_sayisi) == 1) {
				a[i][j] = rand() % 9 + 1;
				a[j][i] = 10;
			}
			else {
				a[i][j] = a[j][i] = 10;
			}
		}
	}
}
/**
* \brief Kullanici iki tane dugum ismi girer.Ilki ismini degistirmek istedigi dugum ismi, ikincisi ise bu dugume vermek istedigi yeni isim.
* \brief Dugum isimlerini tutan dizide ismini degistirmek istedigi dugum ismi bulunur.Buldugumuz yere yeni isim aktarilir.
* \brief Zaman karmasikligi O(n*n)
*/
void isim_guncelleme() {
	cout << "Dugumler:";
	for (int i = 0;i < d_sayisi;i++) {
		cout << A[i].ad << "\t";
	}
	int sayac, j, i;
	char ilkisim[20], sonisim[20];
	cout << "\nHangi dugumun ismini degistirmek istersiniz -> ";
	cin >> ilkisim;

	cout << "\nDugume vereceginiz yeni isim -> ";
	cin >> sonisim;
	for (i = 0;i < d_sayisi;i++) {
		for (j = 0;ilkisim[j] != '\0';j++) {
			if (A[i].ad[j] == ilkisim[j])
				sayac = 0;
			else {
				sayac = 1;
				break;
			}
			if (sayac == 0) {
				for (j = 0;sonisim[j] != '\0';j++) {
					A[i].ad[j] = sonisim[j];
				}
				A[i].ad[j] = '\0';
			}
		}

	}
}

/**
* \brief Secilen iki tane dugum arasindaki mesafe degerini guncellemek, yolu silmek veya yol eklemek icin kullanilan fonksiyon.
* \brief Secilen dugumlerin dizideki konumlari bulunup hafizada tutulur.Matris uzerinde bu konumlari kullanarak bu dugumler arasinda yol var mi diye bakilir.
* \brief Kullanici guncelleme yapmak isterse bu dugumler arasinda yol varsa kullanicinin girdigi mesafe degeri matris uzerindeki yerine atanir.Ama bu dugumler arasinda yol yoksa uyari mesaji verilir.
* \brief Kullanici yol silmek isterse bu dugumler arasinda yol varsa matris uzerinde bu mesafe degeri temizlenir.Ama bu dugumler arasinda yol yoksa uyari mesaji verilir.
* \brief Kullanici yol eklemek isterse bu dugumler arasinda yol yoksa kullanicinin girdigi mesafe degeri matrise aktarilir.Ama bu dugumler arasinda yol varsa uyari mesaji verilir.
* \brief Zaman karmasikligi O(n*n)
*/
void mesafe(int p) {
	char ilkisim[20], sonisim[20];
	cout << "Baslangic Dugumleri: ";
	for (int i = 0;i < d_sayisi;i++) {
		cout << setw(10) << right << A[i].ad;
	}
	cout << "\nBaslangic dugumunu seciniz -> ";
	cin >> ilkisim;
	cout << "\nBitis Dugumleri: ";
	for (int i = 0;i < d_sayisi;i++) {
		cout << A[i].ad << "\t";
	}
	cout << "\nBitis dugumunu seciniz -> ";
	cin >> sonisim;
	int x = 0, y = 0, z, sayac, i, j, k;
	if (p == 1 || p == 2) {
		cout << "Yeni mesafe: ";
		cin >> z;
	}
	for (i = 0;i < d_sayisi;i++) {
		for (j = 0;ilkisim[j] != '\0';j++) {
			if (A[i].ad[j] == ilkisim[j]) {
				sayac = 0;
			}
			else {
				sayac = 1;
				break;
			}
		}
		if (sayac == 0) {
			x = i;
		}
	}
	for (i = 0;i < d_sayisi;i++) {
		for (j = 0;sonisim[j] != '\0';j++) {
			if (A[i].ad[j] == sonisim[j]) {
				sayac = 0;
			}
			else {
				sayac = 1;
				break;
			}
		}
		if (sayac == 0) {
			y = i;
		}
	}
	if (p == 1) {
		if (a[x][y] == 10) {
			cout << "Sectigin dugumler arasinda yol yoktur.Mesafe guncellemesi yapamazsin." << endl;
		}
		else {
			a[x][y] = z;
		}
	}
	else if (p == 2) {
		if (a[x][y] == 10) {
			a[x][y] = z;
		}
		else {
			cout << "Sectigin dugumler arasina yol ekleyemezsin.Zaten bu dugumler arasinda bir yol vardir." << endl;
		}
	}
	else if (p == 3) {
		if (a[x][y] != 10) {
			a[x][y] = 10;
		}
		else {
			cout << "Sectigin dugumler arasinda yol yoktur.Yol cikar fonksiyonunu kullanamazsin." << endl;
		}
	}
}
/**
* \brief Grafta bulunan ve kullanicinin girdigi dugumu graftan cýkariyoruz.
* \brief Dugum isimlerinin tutuldugu dizide (A) kullanicinin girdigi ismi ve ismin bulundugu konumu buluyoruz.
* \brief Dugum isimlerinin tutuldugu dizi(A) de bir dugum eksilecegi icin dugum isimlerini yeniden dizi uzerinde konumlandiriyoruz.
* \brief Komsuluk matrisinde bir dugum azalacagi icin matris uzerinde bir satir ve bir sutun azalacak.Matrisin boyutu degistigi icin yeni olusturacagimiz boyutta dinamik bir matris olustururuz.
* \brief Buyuk boyuttaki matrisin elemanlarin (silinecek dugum elemanlari haric) yeni olusturdugumuz matris icerisine aktarilir.
* \brief Eski buyuk boyuttaki matris hafizada yer kaplamamasi icin silinir.
* \brief Buyuk matris tutan (suan hicbir yeri isaret etmeyen) pointer ise yeni matrisi tutacak sekilde ayarlanir.
* \brief Dugum isimlerinin tutuldugu dizi(A) de bir dugum azalacagi icin dugum sayisi bir artacaktir.
* \brief Zaman karmasikligi O(n*n)
*/
void dugum_cikar() {
	char x[20];
	cout << "Silmek istedigniz dugum ismini giriniz -> ";
	cin >> x;

	int konum, dogru, t;
	for (int j = 0;j < d_sayisi;j++) {
		for (int i = 0;x[i] != '\0';i++) {
			if (A[j].ad[i] == x[i]) {
				dogru = 0;
			}
			else {
				dogru = 1;
				break;
			}
		}
		if (dogru == 0) {
			konum = j;
		}
	}
	for (int i = konum + 1;i < d_sayisi;i++) {
		for (int j = 0;A[i].ad[j] != '\0';j++) {
			A[i - 1].ad[j] = A[i].ad[j];
		}
		A[i].ad[0] = '\0';
	}
	int **yenialan;
	yenialan = new int*[d_sayisi - 1];
	for (int i = 0;i < d_sayisi - 1;i++) {
		yenialan[i] = new int[d_sayisi - 1];
	}
	d_sayisi = d_sayisi - 1;
	int q = 0;
	int w = 0;
	for (int i = 0;i < d_sayisi+1;i++) {
		if (i != konum) {
			for (int j = 0;j < d_sayisi+1;j++) {
				if (j != konum && a[i][j] != 10) {
					yenialan[q][w] = a[i][j];
					w++;
				}
				else if (j != konum && a[i][j] == 10) {
					yenialan[q][w] = 10;
					w++;
				}
			}
			q++;
		}
		w = 0;
	}
	for (int i = 0;i < d_sayisi;i++) {
		delete[] a[i];
	}
	delete a;
	a = yenialan;

}