#include<iostream>
using namespace std;
void Menu();

//Kullanici tarafindan girilen degerin, dizide bulunan ilk bos yere atama isleminin yapildigi kýsým
void Ekle(int);

//Diziye en son yazilan elemani silen ve ekranda hangi elemani sildigini gosteren fonksiyon
void Getir();

//Elemanlari listeleyen kisim
void Listele();

//Eleman sayisini bulan fonksiyon
void Say();

int *ptr; //Olusturdugumuz dizimizin adresini tutar.
int boyut; //Dizimizin boyutu 
int indis = 0; //Diziye eklenen en son elemanin indisinden sonraki yeri tutan deger.

int main()
{
	cout << "YIGININ BOYUTUNU GIRINIZ: ";
	cin >> boyut;
	ptr = new int[boyut]; //Hafiza da fazla yer kaplamamak icin olusturdugumuz dizi DINAMIKTIR.
	//Hafiza da sadece kullanicinin girdigi boyut kadar eleman sayisina sahip bir dizi acilir.
	Menu();
	system("pause");
	return 0;
}
void Menu() {
	int secim;
	do {
		cout << "\t\t**********MENU**********" << endl;
		cout << "\t\t[1]...EKLE(PUSH)" << endl;
		cout << "\t\t[2]...GETIR(POP)" << endl;
		cout << "\t\t[3]...LISTELE" << endl;
		cout << "\t\t[4]...SAY" << endl;
		cout << "\t\t[5]...CIKIS" << endl;
		cout << "SECIMINIZ: ";
		cin >> secim;
		//system("cls"); 
		if (secim == 1) {
			int x;
			cout << "YIGINA EKLEMEK ISTEDIGINIZ SAYIYI GIRINIZ: ";
			cin >> x;
			Ekle(x);
		}
		else if (secim == 2) {
			Getir();
		}
		else if (secim == 3) {
			Listele();
		}
		else if (secim == 4) {
			Say();
		}
	} while (secim >= 1 && secim <= 4);
}
void Ekle(int x) { //Fonksiyonun zaman karmaskikligi: O(1)
	//Fonksiyona gonderilen sayi icin hafiza da yer acilir.Acilan bu yerin degeri fonksiyona gonderilen
	//sayi ile ayni olur.Fonksiyon bitiminde ise hafizadaki kopya yer silinir.
	if (indis > boyut - 1) { //Dizimiz dolu ise kullanicinin istedigi sayiyi diziye ekleyemeyiz.(UYARI MESAJI)
		cout << "UYARI: YIGIN DOLUDUR.YENI BIR ELEMAN EKLEYEMEZSINIZ." << endl;
	}
	else {
		ptr[indis] = x; //Boslugu gosteren indisimizin oldugu yere kullanicinin istedigi degeri atariz.
		indis++; //Indisin bir sonraki BOS yeri gostermesi gerektigi icin indis bir artar. 
	}
}
void Getir() {//Fonksiyonun zaman karmaskikligi: O(1)
	//Fonksiyon Global degiskenler üzerinden calisitigi icin hafizada sadece fonksiyonun tutuldugu yer vardir
	if (&ptr[indis] == &ptr[0]) { //indisin bulundugu adres ile sifirinci elemanin bulundugu adres ayni ise dizide eleman yoktur.
		cout << "UYARI: YIGIN BOSTUR.GETIR FONKSIYONUNU KULLANAMAZSINIZ." << endl;
	}
	else {
		indis = indis - 1; //Indis boslugu gosterdigi icin, indisten bir onceki elemanin indisini buluyoruz.
		cout << "YIGINDAN CIKARILAN ELEMAN: " << ptr[indis] << endl; //Cikarilan elemani ekrana yazdiriyoruz.
		ptr[indis] = NULL; //En son eklenen elemani cikardigimiz icin o indisteki deger NULL olur.
	}
}
void Listele() {//Fonksiyonun zaman karmaskikligi: O(n)
	//Fonksiyon Global degiskenler üzerinden calisitigi icin hafizada sadece fonksiyonun tutuldugu yer vardir
	if (&ptr[indis] == &ptr[0]) {//indisin bulundugu adres ile sifirinci elemanin bulundugu adres ayni ise dizide eleman yoktur.
		cout << "UYARI: YIGIN BOSTUR.LISTELENEMEZ." << endl;
	}
	else {
		for (int i = 0;i < indis;i++) { //Dizide eleman bulunan kisimlari (yani indise kadar olan kismi) yazdiran dongu
			cout << ptr[i] << " "; //Elemanlarin ekrana yazdirildigi kisim
		}
	}
	cout << endl;
}
void Say() { //Fonksiyonun zaman karmaskikligi: O(1)
	cout << "LISTEDE " << indis << " TANE ELEMAN VARDIR." << endl; 
	//Indis dizideki en son elemandan bir sonraki boslugu tutuyordu.
	//Dizilerin indisleri sifirdan basladigi icin indis kadar eleman vardir deriz.
}