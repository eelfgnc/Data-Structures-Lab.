#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct bagliliste { //Global structure
	int deger;
	struct bagliliste *on;
	struct bagliliste *arka;
}eleman;

eleman *ilk = NULL, *son = NULL; //Global degiskenler

void menu();
void ekle(int);
void onden_listele();
void arkadan_listele();
int say();
eleman *sil(int);
eleman *arama(int);
void araya_ekle(int, int);
void kopyalari_sil();

int main()
{
	menu();
	system("pause");
	return 0;
}
void menu() {
	int secim, sayi, indis, x;
	do {
		cout << "\t\t**********MENU**********" << endl;
		cout << "\t\t[1]...EKLE" << endl;
		cout << "\t\t[2]...ARAYA EKLE" << endl;
		cout << "\t\t[3]...SIL" << endl;
		cout << "\t\t[4]...KOPYALARI SIL" << endl;
		cout << "\t\t[5]...LISTELE" << endl;
		cout << "\t\t[6]...SAY" << endl;
		cout << "\t\t[7]...CIKIS" << endl;
		cout << "Seciminiz: ";
		cin >> secim;

		if (secim == 1) {//Sona dugum ekleyen kisim
			cout << "Listeye eklemek istediginiz sayiyi giriniz: ";
			cin >> sayi;
			ekle(sayi);
		}
		else if (secim == 2) {//Kullanicinin istedigi sayiyi istedigi yere koyan kisim
			x = say();
			if (x == 0) {
				cout << "Listeniz bostur.Bu islem gerceklestirilemiyor." << endl;
			}
			else if (x == 1) {
				cout << "Listeye eklemek istediginiz sayiyi giriniz: ";
				cin >> sayi;
				cout << "UYARI -> Liste de 1 tane eleman vardir.Bu yuzden indisiniz 1 olmalidir." << endl;
				araya_ekle(1, sayi);
			}
			else {
				cout << "Listeye eklemek istediginiz sayiyi giriniz: ";
				cin >> sayi;
				cout << "UYARI -> Indisiniz 1 ile " << x << " arasinda olmalidir!" << endl;
				cout << "Listeye eklemek istediginiz sayinin indisini giriniz: ";
				cin >> indis;
				araya_ekle(indis, sayi);
			}
		}
		else if (secim == 3) {//Kullanicinin istedigi sayiyi listeden silen kisim
			cout << "Listeden silmek istediginiz sayiyi giriniz: ";
			cin >> sayi;
			sil(sayi);
		}
		else if (secim == 4) {//Listede birden fazla olan kopyalari silen kisim
			kopyalari_sil();
		}
		else if (secim == 5) {//Listedeki elemanlari belirli kurallara gore sýralayan kýsým
			sayi = say();
			if (sayi == 0) {
				cout << "Liste de eleman yoktur." << endl;
			}
			else {
				cout << "Eklenme sirasina gore:          ";
				onden_listele();
				cout << "Eklenme sirasinin tersine gore: ";
				arkadan_listele();
			}
		}
		else if (secim == 6) {//Liste de kac tane eleman oldugunu gosteren ksýým
			sayi = say();
			cout << "Liste de " << sayi << " tane eleman vardir." << endl;
		}
		cout << endl << endl;
	} while (secim >= 1 && secim < 7);
}
void ekle(int sayi) {
	eleman *p;
	p = (eleman *)malloc(sizeof(eleman)); //Hafiza da dugum yeri aciyoruz.
	if (ilk == NULL) { //Olusturulacak dugum, ilk dugum ise 
		ilk = p;  //Dugum hem ilk hemde son pointeri temsil eder.
		son = p;
		ilk->arka = NULL;//Tek dugum oldugu icin arka ve on pointeri NULL degerini gosterir.
		ilk->on = NULL;
		ilk->deger = sayi;//Kullanicidan istenen sayi dugume yerlestirilir.
	}
	else { //Olusturulacak dugum en arkaya baglaniyor.
		son->arka = p;
		p->on = son;
		son = p;//Olusturulan yeni dugum son pointer olur.
		son->arka = NULL;//Son pointerinin arkasi NULL degerini gosterir
		son->deger = sayi;//Kullanicidan istenen sayi dugume yerlestirilir.
	}
}
void onden_listele() { //Ilk pointerden son pointere dogru listeleme
	eleman *p;
	p = ilk;
	if (p == NULL) { //BOS LISTE
		cout << "Listede eleman yoktur." << endl;//Uyari mesaji
	}
	else { //DOLU LISTE
		while (p != NULL) {	//Listenin sonuna(NULL) degerine goturen dongu
			cout << p->deger << "  ";
			p = p->arka;//p pointeri her dongude yer degistirerek liste uzerinde gezer. 
		}
		cout << endl;
	}
}
void arkadan_listele() {	//Son pointerden ilk pointere dogru listeleme
	eleman *p;
	p = son;
	while (p != NULL) { //Listenin basina (null) degerine goturen dongu 
		cout << p->deger << "  ";
		p = p->on;//p pointeri her dongude yer degistirerek liste uzerinde gezer.
	}
	cout << endl;
}
int say() { //Listedeki eleman sayisini bulan fonksiyon
	eleman *p;
	int count = 0;
	p = ilk;
	while (p != NULL) { //Listenin en sondaki null degerine kadar giden dongu
		count++; 
		p = p->arka;//p pointeri liste uzerinde sirayla gezer.
	}
	return count;
}
eleman *sil(int x) {
	eleman *p;
	int i, y;
	y = say();
	p = arama(x);
	if (p == NULL) {//Silmek istenilen deger listede yoksa uyari mesaji verilir.
		cout << "Aradiginiz eleman liste de yoktur." << endl;
	}
	for (i = 0;i < y;i++) {
		p = arama(x);
		if (p == NULL) {
			return NULL; //Aranan eleman yoksa fonksiyon NULL degeri dondurur.
		}
		if (ilk == p) {//Silmek istenilen sayi ilk pointerinin degeri ise bir sonraki dugum ilk pointeri olur.
			if (ilk->arka != NULL) {//Liste tek dugumden olusuyor mu diye kontrol edilir.
				ilk = ilk->arka;
				ilk->on = NULL;
			}
			else {//Tek pointerdan olusuyorsa listede hic dugum olamaz 
				ilk = NULL;
				son = NULL;
			}
		}
		else {
			p->on->arka = p->arka;
			if (p == son) {
				son = son->on;
			}
			else {
				p->arka->on = p->on;
			}
		}
	}
}
eleman *arama(int x) {
	eleman *p;
	p = ilk;
	while (p != NULL) {
		if (p->deger == x) {//Aranan deger listede var ise bulundugu yerin adresini gonderen fonksiyon
			return p;
		}
		p = p->arka;//Liste uzerinde gezen fonksiyon
	}
	return NULL;//Aranan deger listede yoksa NULL degeri gonderilir.
}
void araya_ekle(int indis, int x) {
	eleman *k, *p, *q;
	int i, y;
	y = say();
	p = ilk;
	q = ilk;
	k = (eleman *)malloc(sizeof(eleman));//Hafizada dugum yeri acilir.
	if (indis == 1) {//Listeye eklenmek isteden deger ilk dugum olacaksa ilk pointer yeni olusturulan dugum olur. 
		k->arka = ilk;
		ilk->on = k;
		ilk = k;
		ilk->deger = x;
		ilk->on = NULL;//(ONEMLI) Ilk->on = NULL olmak zorunda
	}
	else if (indis > 1 && indis < y) {//Listenin ortasina eklenen dugum 
		for (i = 1;i < indis;i++) {//Ard arda gelen p ve q dugumleri
			q = q->arka;
		}
		for (i = 1;i < indis - 1;i++) {//Olustulan yeni dugum iki dugumun arasina
			p = p->arka;   //gelecegi icin liste uzerinde p ve q pointeri hareket ediyor.
		}
		k->on = p; //yeni olusturulan k pointeri p ve q pointerinin arasina yerlestirilir
		p->arka = k;
		k->arka = q;
		q->on = k;
		k->deger = x;

	}
	else if (indis == y) {//Listeye eklenmek isteden deger son dugum olacaksa son pointer yeni olusturulan dugum olur. 
		while (p->arka->arka != NULL) {//Son dugumden onceki dugumu bulan dongu.
			p = p->arka;
		}
		p->arka = k;//son dugumden onceki dugumu yeni olusturulan dugume baglamak icin p pointeri kullanilir.
		k->arka = son;
		son->on = k;
		k->on = p;
		k->deger = x;
	}

}
void kopyalari_sil() {
	eleman *p, *q;
	p = ilk;
	q = son;
	while (p != NULL) {//P pointeri listede bastan sona dogru gezmeye basliyor. 
		while (p != q) {//q pointeri da listenin sonundan basina dogru geziyor.
			if (q->deger != p->deger) {//P pointeri q pointeri ile hicbir zaman ayni olmuyor
				q = q->on;
			}
			else {
				if (q->arka == NULL) {//Silmek istenilen dugum son pointer ise
					(q->on)->arka = NULL;
					q = q->on;
					son = q;//(ONEMLI)q pointeri son pointer oluyor ve son->arka=NULL olmak zorunda
				}
				else {//Silmek istenilen dugum son pointer degil ise
					(q->on)->arka = q->arka;
					(q->arka)->on = q->on;
					q = q->on;
				}
			}
		}
		q = son;//q pointeri listeyi hep sondan basa dogru geziyor.
		p = p->arka;//p pointeri ise listeyi bastan sona dogru gezer.
	}
}