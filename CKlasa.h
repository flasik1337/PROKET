#pragma once


struct Produkty {
	size_t id_produktu;
	size_t cena;
	char produkt[100];


};

struct Klienci {
	size_t id_klienta;
	size_t rocznik;
	char godnosc[100];
	Produkty** produkty;


};


void stworz(Produkty**&, size_t);
void usun(Produkty**&, size_t&);
void show(Produkty**&, size_t);
void tworzenie(Produkty**&, size_t);
void dodaj(Produkty**&, size_t&);
void usun_p(Produkty**&, size_t&);
void zestawienie(Produkty**&, size_t);
size_t rozmiar(size_t begin, size_t end);


void stworz(Klienci*&, size_t);
void usun(Klienci*&, size_t);
void tworzenie(Klienci*&, size_t, size_t);
void show(Klienci*&, size_t);
void dodaj(Klienci*&, size_t&);
void usun_k(Klienci*&, size_t&);
void zestawienie(Klienci*&, size_t);
void przypisanie(Klienci*&);
