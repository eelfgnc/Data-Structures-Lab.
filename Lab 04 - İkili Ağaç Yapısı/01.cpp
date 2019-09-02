#include<iostream>
#include<ctime>
using namespace std;
/**
* \author Elif GENC (01elifgenc@gmail.com)
* \date 05.11.2017
*/
typedef struct ikili_arama_agac {
	int veri;
	struct ikili_arama_agac *sol, *sag;
}eleman;
eleman* agac = NULL;
int *ptr;
int sayac = 0;

void Menu();
eleman* Ekle(eleman*, int);
eleman* Sil(eleman*, int);
void Koktensagadolas_preorder(eleman*);
void Soldansagadolas_inorder(eleman*);
void Soldankokedolas_postorder(eleman*);
int Enkucukdeger(eleman* agac);
int Enbuyukdeger(eleman* agac);

int main()
{
	Menu();
	system("pause");
	return 0;
}

void Menu() {
	int secim, kullaniciDegeri, once;
	do {
		cout << "\t\t**********MENU**********" << endl;
		cout << "\t\t[1]...EKLE" << endl;
		cout << "\t\t[2]...SIL" << endl;
		cout << "\t\t[3]...LISTELE" << endl;
		cout << "\t\t[4]...SAY" << endl;
		//cout << "\t\t[5]...DENGELE" << endl;
		cout << "\t\t[5]...CIKIS" << endl;
		cout << "SECIMINIZ: ";
		cin >> secim;

		if (secim == 1) {
			cout << "IKILI ARAMA AGACINA EKLEMEK ISTEDIGINIZ SAYIYI GIRINIZ: ";
			cin >> kullaniciDegeri;
			agac = Ekle(agac, kullaniciDegeri);
		}
		else if (secim == 2) {
			once = sayac;
			if (once == 0) {
				cout << "IKILI ARAMA AGACI BOSTUR.CIKARMA ISLEMINI YAPAMAZSINIZ." << endl;
			}
			else if (once != 0) {
				cout << "IKILI ARAMA AGACINDAN CIKARMAK ISTEDIGINIZ SAYIYI GIRINIZ: ";
				cin >> kullaniciDegeri;
				for (int i = 0;i < sayac;i++) {
					agac = Sil(agac, kullaniciDegeri);
				}
				if (once == sayac && once != 0) {
				cout << "CIKARMAK ISTEDIGINIZ ELEMAN IKILI ARAMA AGACINDA YOKTUR." << endl;
				}
			}
		}
		else if (secim == 3) {
			if (sayac == 0) {
				cout << "IKILI ARAMA AGACI BOSTUR.LISTELENEMEZ." << endl;
			}
			else {
				int ikincisecim;
				cout << "\t\t[1]...ONCE GEZINTI (PREORDER) DOLASMA" << endl;
				cout << "\t\t[2]...ARA GEZINTI (INORDER) DOLASMA" << endl;
				cout << "\t\t[3]...SONRA GEZINTI (POSTORDER) DOLASMA" << endl;
				cout << "SECIMINIZ: ";
				cin >> ikincisecim;
				if (ikincisecim == 1) {
					Koktensagadolas_preorder(agac);
					cout << endl;
				}
				else if (ikincisecim == 2) {
					Soldansagadolas_inorder(agac);
					cout << endl;
				}
				else if (ikincisecim == 3) {
					Soldankokedolas_postorder(agac);
					cout << endl;
				}
			}
		}
		else if (secim == 4) {
			cout << "IKILI ARAMA AGACINDA " << sayac << " TANE ELEMAN VARDIR." << endl;
		}

	} while (secim >= 1 && secim < 5);
}
/**
* \brief Kullanicinin verdigi tam sayiyi agaca ekleyen fonksiyondur.
* \brief Eger agac bos ise kullancinin verdigi tam sayi agacin verisine esit olur, agacin sag ve sol gostericileri NULL degerine esit olur, agac geri gonderilir.
* \brief Veirlen tam sayi agacin verisinden buyukse agacin sag tarafina degilse agacin sol tarafindan devam edilir.Bulunan uygun yere eklenir.
* \brief Zaman karmasikligi O(log(n))
* \param agac: Eleman ekleyecegimiz agac
* \param kullaniciDegeri: Kullanicinin ikili arama agacina eklemek istedigi tam sayi
*/
eleman* Ekle(eleman* agac, int kullaniciDegeri) {
	if (agac == NULL) {
		sayac++;
		eleman* kok = (eleman *)malloc(sizeof(eleman));
		kok->veri = kullaniciDegeri;
		kok->sag = NULL;
		kok->sol = NULL;
		return kok;
	}
	if (agac->veri < kullaniciDegeri) {
		agac->sag = Ekle(agac->sag, kullaniciDegeri);
	}
	else {
		agac->sol = Ekle(agac->sol, kullaniciDegeri);
	}
	return agac;
}

/**
* \brief Ikili arama agacindaki verileri preorder kuraliyla ekrana yazdirilir.
* \brief Preorder kuralinda once agacin koku, daha sonra sol tarafi ve en son agacin sag tarafi yazdirilarak listelenir.
* \brief Zaman karmasikligi O(log(n))
* \param agac: Verileri preorder kuraliyla yazdirilan agac
*/
void Koktensagadolas_preorder(eleman* agac) {
	if (agac == NULL) {
		return;
	}
	cout << agac->veri << "  ";
	Koktensagadolas_preorder(agac->sol);
	Koktensagadolas_preorder(agac->sag);
}

/**
* \brief Ikili arama agacindaki verileri inorder kuraliyla ekrana yazdirilir.
* \brief Inorder kuralinda once agacin sol tarafi, daha sonra koku ve en son agacin sag tarafi yazdirilarak listelenir.
* \brief Zaman karmasikligi O(log(n))
* \param agac: Verileri inorder kuraliyla yazdirilan agac
*/
void Soldansagadolas_inorder(eleman* agac) {
	if (agac == NULL) {
		return;
	}
	Soldansagadolas_inorder(agac->sol);
	cout << agac->veri << "  ";
	Soldansagadolas_inorder(agac->sag);
	
}

/**
* \brief Ikili arama agacindaki verileri postorder kuraliyla ekrana yazdirilir.
* \brief Postorder kuralinda once agacin sol tarafi, daha sonra sag taraf ve en son agacin kok dugumu yazdirilarak listelenir.
* \brief Zaman karmasikligi O(log(n))
* \param agac: Verileri postorder kuraliyla yazdirilan agac
*/
void Soldankokedolas_postorder(eleman* agac) {
	if (agac == NULL) {
		return;
	}
	Soldankokedolas_postorder(agac->sol);
	Soldankokedolas_postorder(agac->sag);
	cout << agac->veri << "  ";
}

/**
* \brief Kullanicinin istedigi tam sayiyi agactan cikaran fonksiyondur.
* \brief Eger agac bos ise fonksiyon NULL degeri gonderir.Ama cikarmak istenen sayi agac uzerindeyse 3 durum soz konusudur.
* \brief Agacin cocuklari yoksa  fonksiyon NULL degeri gonderir.Eger sag tarafta cocuklari varsa tercih edilen cikarilmak istenen yere cikarilmak istenen sayidan buyuk en kucuk tam sayiyi oraya eklemektir.
* \brief Sag tarafta cocuklari yoksa cikarilmak istenen yere o sayidan kucuk en buyuk tam sayiyi oraya yerlestirmektir.Bu yuzden agac uzerinde sol tarafa bakilir.
* \brief Zaman karmasiklligi O(n)
* \param agac: Eleman cikaracagimiz agac
* \param kullaniciDegeri: Kullanicinin ikili arama agacindan cikarmak istedigi tam sayi
*/
eleman* Sil(eleman* agac, int kullaniciDegeri) {
	if (agac == NULL)
	{
		return NULL;
	}
	if (kullaniciDegeri == agac->veri)
	{
		if (agac->sol == NULL && agac->sag == NULL)
		{
			sayac--;
			return NULL;
		}
		if (agac->sag != NULL)
		{
			agac->veri = Enkucukdeger(agac->sag);
			agac->sag = Sil(agac->sag, Enkucukdeger(agac->sag));
			return agac;
		}
		if (agac->sol != NULL)
		{
			agac->veri = Enbuyukdeger(agac->sol);
			agac->sol = Sil(agac->sol, Enbuyukdeger(agac->sol));
			return agac;
		}
	}
	if (kullaniciDegeri < agac->veri) {
		agac->sol = Sil(agac->sol, kullaniciDegeri);
		return agac;
	}
	else {
		agac->sag = Sil(agac->sag, kullaniciDegeri);
		return agac;
	}
}

/**
* \brief Ikili arama agacindaki en buyuk degeri dondurur.
* \brief En buyuk deger her zaman sag taraftadir.Bu yuzden bir gosterici verilen agactan baslayarak en sagdaki dugume gider ve dugumun verisini ekrana yazdirir.
* \brief Zaman karmasikligi O(n)
* \param agac: Uzerinde arama yapilan agac
*/
int Enbuyukdeger(eleman* agac)
{
	eleman* p = agac;
	while (p->sag != NULL)
		p = p->sag;
	return p->veri;
}

/**
* \brief Ikili arama agacindaki en kucuk degeri dondurur.
* \brief En kucuk deger her zaman sol taraftadir.Bu yuzden bir gosterici verilen agactan baslayarak en soldaki dugume gider ve dugumun verisini ekrana yazdirir.
* \brief Zaman karmasikligi O(n)
* \param agac: Uzerinde arama yapilan agac
*/
int Enkucukdeger(eleman* agac)
{
	eleman* p = agac;
	while (p->sol != NULL)
		p = p->sol;
	return p->veri;
}