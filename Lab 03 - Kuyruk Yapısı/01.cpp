#include<iostream>
#include<iomanip>
using namespace std;

/** 
* \brief Kuyrugu bagli listelerle olusturuyoruz.
* \brief Hafizada yer acmaz.Sadece beyanda bulunur.
* \param deger : Kullanicinin kuyruga eklemek istedigi tam sayi
* \param *arka : Bir sonraki dugumun adresini tutacak pointer
*/
typedef struct bagli_liste {
	int deger;
	struct bagli_liste *arka;
}eleman;

/**
*\*ilk : Kuyruktaki ilk dugumun adresini tutan pointer.
*/
eleman *ilk = NULL;

/**
*\*son : Kuyruktaki son dugumun adresini tutan pointer.
*/
eleman *son = NULL;

/**
*\ boyut : Kuyrugun alabilecegi maksimum dugum sayisi.
*/
int boyut;

void Boyut();
void Menu();
void Ekle(int);
void Cikar();
void Listele();
int Say();

int main()
{
	/**
	* \brief Kuyruk (Queue) yapisini bagli listelerle (dugumlerle) olusturuyoruz. 
	* \brief Kuyruk uzerinde eleman ekleme, cikarma ve elemanlari listeleme, sayma islemlerini fonksiyonlar yardimiyla yapiyoruz.
	* \author Elif GENC
	*/
	Boyut();
	system("pause");
	return 0;
}

/**
* \brief Kuyruk veri modelinin kac tane eleman alacagini gosterir.
* \brief Fonksiyon iceresinde yeni bir degisken kullanilmiyor sadece global degisken uzerinde islem yapiliyor.Hafiza da gereksiz bir yer isgal etmemis oluyor.
* \brief Zaman karmasikligi O(1) 'dir.
*/
void Boyut() {
	cout << "OLUSTURACAGINIZ KUYRUGUN BOYUTUNU GIRINIZ: ";
	cin >> boyut;
	if (boyut < 0) {
		cout << "NEGATIF BIR SAYI GIREMEZSINIZ." << endl;
	}
	else if ('A' < boyut && boyut < 'Z') {
		cout << "HARF GIREMEZSINIZ." << endl;
	}
	else {
		Menu();
	}
}
void Menu() {
	int secim, sayi;
	do {
		cout << "\t\t**********MENU**********" << endl;
		cout << "\t\t[1]...EKLE(ENQUEUE)" << endl;
		cout << "\t\t[2]...CIKAR(DEQUEUE)" << endl;
		cout << "\t\t[3]...LISTELE" << endl;
		cout << "\t\t[4]...SAY" << endl;
		cout << "SECIMINIZ: ";
		cin >> secim;

		if (secim == 1) {
			cout << "KUYRUGA EKLEMEK ISTEDIGINIZ SAYIYI GIRINIZ: ";
			cin >> sayi;
			Ekle(sayi);
		}
		else if (secim == 2) {
			Cikar();
		}
		else if (secim == 3) {
			Listele();
		}
		else if (secim == 4) {
			sayi = Say();
			cout << "KUYRUKTA " << sayi << " TANE ELEMAN VARDIR." << endl;
		}
		
	} while (secim >= 1 && secim < 5);
}

/**
* \brief Kullanicidan istenen sayi kuyruga eklenecektir.
* \brief Kuyruga eklenmek istenilen sayi olusturulacak ilk dugumun degeri olacaksa hafiza da bir tane dugum acariz.Ilk ve son pointer bu dugumun adresini gosterir.Fonksiyona gonderilen parametre ile dugumun degeri esit olur.
* \brief Kuyrukta en az bir tane dugum varsa en son dugum bulunur.Kuyrukta bulunan dugum sayisi kullanicinin girdigi boyuttan kucuk yada bir eksikse kuyruk uzerinde bulunan son dugum hafizada acilan yeni dugumu gosterecek sekilde birbirine baglanir.
* \brief Dugum sayisi girilen boyut sayisi kadarsa kuyruga yeni eleman eklenemez uyarisini verir.
* \brief Zaman karmasikligi O(1) 'dir.
* \brief Fonksiyona gonderilen deger icin hafiza da bir yer acilir.Bu yer parametre olarak gonderilen degisken ile ayni degere sahiptir.Fonksiyon ile isimiz bittiginde ise kopya yer hafizadan silinir.
* \param deger : Kuyruga eklenmek istenen yeni sayidir.
*/
void Ekle(int deger) {
	if (ilk == NULL) {
		ilk = (eleman *)malloc(sizeof(eleman));
		ilk->deger = deger;
		ilk->arka = NULL;
		son = ilk;
	}
	else {
		int count;
		count = Say();
		if (count == boyut) {
			cout << "KUYRUK DOLUDUR.YENI BIR ELEMAN EKLEYEMEZSINIZ." << endl;
		}
		if (0 < count && count < boyut) {
			eleman *p;
			p = (eleman *)malloc(sizeof(eleman));
			p->deger = deger;
			son->arka = p;
			son = p;
			son->arka = NULL;
		}
	}
}

/**
* \brief Ilgili sayi gosterilecek ve kuyruktan cikarilacaktir.
* \brief Kuyruktan eleman cikarilmak istendiginde bakilmasi gereken ilk yer dugumun bos olup olmamasidir.
* \brief Eger kuyruk bos ise fonksiyon kuyruk bostur uyarisini verir.
* \brief Kuyruk bos degil ise eleman cikarilirken ilk dugumden cikarilir.
* \brief Once ilk dugumun degeri ekrana yazilir.
* \brief Sonra da ilk pointeri bir sonraki dugumun adresini tutar.
* \brief Zaman karmasikligi O(1) 'dir.
*/
void Cikar() {
	if (ilk == NULL) {
		cout << "KUYRUK BOSTUR.CIKAR FONKSIYONUNU KULLANAMAZSINIZ." << endl;
	}
	else {
		cout << "CIKARILAN ELEMAN: ";
		cout << ilk->deger;
		ilk = ilk->arka;
	}
	cout << endl;
}

/**
* \brief Kuyrugun elemanlari listelenecektir.
* \brief Kuyrukta bulunan elemanlari listelerken once kuyruk bos mu diye kontrol edilir.
* \brief Eger kuyruk bos ise fonksiyon kuyruk bostur uyarisini verir.
* \brief Kuyruk bos degil ise yeni bir pointer uretilir.Bu pointer ilk pointerine esit olur.
* \brief Yeni pointer NULL degerine esit oluncaya kadar dugumler uzerinde hareket eder.
* \brief Dugumler uzerinde gezerken bulundugu dugumdeki degeri ekrana yazdirir.
* \brief Zaman karmasikligi O(n) 'dir.
*/
void Listele() {
	int count;
	eleman *p;
	p = ilk;
	count = Say();
	if (count == 0) {
		cout << "KUYRUK BOSTUR." << endl;
	}
	else {
		cout << "LISTELE: ";
		while (p != NULL) {
			cout << p->deger << "   ";
			p = p->arka;
		}
		cout << endl;
	}
}

/**
* \brief Toplam eleman sayisi gosterilecektir.
* \brief Yeni bir pointer uretilir.Bu pointer ilk pointerina esit olur.
* \brief Yeni pointer NULL degerine esit oluncaya kadar bagli listeler uzerinde hareket eder.
* \brief Liste uzerinde gezerken de kuyrukta kac tane eleman oldugunu sayar.
* \brief Zaman karmasikligi O(n) 'dir.
* \return Kuyrukta bulunan eleman sayisini dondurur.
*/
int Say() {
	
	int count = 0;
	eleman *p;
	p = ilk;
	while (p != NULL) {
		count++;
		p = p->arka;
	}
	return count;
}