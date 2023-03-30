#include "CKlasa.h"
import <iostream>;
import <string>;
import <cstdlib>;
import <locale>;
import <stdio.h>;
import <ctime>;
import <random>;
import <string>;
import <cstring>;



void stworz(Klienci*& klienci, size_t size_k) {
    klienci = new Klienci[size_k];

}

void usun(Klienci*& klienci, size_t size_k) {
    delete[] klienci;
    klienci = nullptr;
}

void tworzenie(Klienci*& klienci, size_t size_k, size_t size_p) {
    size_t max = 100000;
    size_t rocznik = 30;
    char string_buf[100];
    for (size_t i = 0; i < size_k; i++) {
        char id[100];
        klienci[i].id_klienta = rand() % max + 20000;
        klienci[i].rocznik = rand() % rocznik + 66;
        sprintf_s(string_buf, "%zd", i);
        strcpy_s(id, "Klient_");
        strcat_s(id, string_buf);
        strcpy_s(klienci[i].godnosc, id);
        stworz(klienci[i].produkty, size_p);
        tworzenie(klienci[i].produkty, size_p);
    }
    
}

void przypisanie(Klienci*& klienci) {
    
    std::string text;
    int numer;
    std::cout << "Podaj indeks klienta do zmiany: ";
    std::cin >> numer;
    system("cls");
    std::cout << "Podaj dane klienta do podmiany id_klienta  godnosc  rocznik  id_produktu cena  nazwe_produktu" << std::endl;
    //getline(std::cin, text);
    std::cin >> text;
    
    size_t pozition = text.find(";");
    std::string id_k = text.substr(0, pozition);
    text.erase(0, pozition + 1);


    size_t pozition2 = text.find(";");
    std::string godnosc = text.substr(0, pozition2);
    text.erase(0, pozition2 + 1);

    size_t pozition1 = text.find(";");
    std::string rocznik = text.substr(0, pozition1);
    text.erase(0, pozition1 + 1);

    size_t pozycja = text.find(";");
    std::string id_p = text.substr(0, pozycja);
    text.erase(0, pozycja + 1);

    size_t pozycja1 = text.find(";");
    std::string cena = text.substr(0, pozycja1);
    text.erase(0, pozycja1 + 1);

    size_t pozycja2 = text.find(";");
    std::string produkt = text.substr(0, pozycja2);
    
    //std::cout << id_p << "  " << cena << "  " << produkt;
    
    
    klienci[numer].id_klienta = std::stoi(id_k);

    strcpy_s(klienci[numer].godnosc, godnosc.c_str());

    klienci[numer].rocznik = std::stoi(rocznik);

    klienci[numer].produkty[numer]->id_produktu = std::stoi(id_p);

    klienci[numer].produkty[numer]->cena = std::stoi(cena);
    
    strcpy_s(klienci[numer].produkty[numer]->produkt, produkt.c_str());

    


}



void show(Klienci*& klienci, size_t size_k) {
    std::cout << "<=========== Klienci i ich produkty ===========>" << std::endl;
    std::cout << "id--Klienci--rocznik--id_produktu--cena--nazwa" << std::endl;
    for (size_t i = 0; i < size_k; i++) {
        std::cout << klienci[i].id_klienta << "\t" << klienci[i].godnosc
            << "\t" << klienci[i].rocznik << "\t" << klienci[i].produkty[0]->id_produktu << "\t" << klienci[i].produkty[0]->cena << "\t" <<  klienci[i].produkty[0]->produkt << std::endl;
    }
}




void dodaj(Klienci*& klienci, size_t& size_k) {
    Klienci* temp = new Klienci[size_k + 1];

    size_t max = 100000;
    char string_buf[100];
    char id[100];
    temp[size_k].id_klienta = rand() % max + 20000;
    temp[size_k].rocznik = rand() % (100 - 1 + 1) + 1;
    sprintf_s(string_buf, "%zd", size_k);
    strcpy_s(id, "Klient_");
    strcat_s(id, string_buf);
    strcpy_s(temp[size_k].godnosc, id);
    for (size_t i = 0; i < size_k; ++i)
        temp[i] = klienci[i];
    delete[] klienci;
    klienci = temp;
    ++size_k;

}


/*void dodaj(Klienci*& klienci, size_t& size_k) {
    Klienci* temp = new Klienci[size_k + 1];
    std::string text;
    
    std::cout << "Podaj dane noweg klienta id_klienta  godnosc  rocznik  id_produktu cena  nazwe_produktu" << std::endl;
    std::cin >> text;

    size_t pozition = text.find(";");
    std::string id_k = text.substr(0, pozition);
    text.erase(0, pozition + 1);

    size_t pozition2 = text.find(";");
    std::string godnosc = text.substr(0, pozition2);
    text.erase(0, pozition2 + 1);

    size_t pozition1 = text.find(";");
    std::string rocznik = text.substr(0, pozition1);
    text.erase(0, pozition1 + 1);

    size_t pozycja = text.find(";");
    std::string id_p = text.substr(0, pozycja);
    text.erase(0, pozycja + 1);

    size_t pozycja1 = text.find(";");
    std::string cena = text.substr(0, pozycja1);
    text.erase(0, pozycja1 + 1);

    size_t pozycja2 = text.find(";");
    std::string produkt = text.substr(0, pozycja2);

    //std::cout << id_p << "  " << cena << "  " << produkt;


    temp[size_k+1].id_klienta = std::stoi(id_k);

    strcpy_s(temp[size_k + 1].godnosc, godnosc.c_str());

    temp[size_k + 1].rocznik = std::stoi(rocznik);

    temp[size_k + 1].produkty[size_k + 1]->id_produktu = std::stoi(id_p);

    temp[size_k + 1].produkty[size_k + 1]->cena = std::stoi(cena);

    strcpy_s(temp[size_k + 1].produkty[size_k + 1]->produkt, produkt.c_str());



    for (size_t i = 0; i < size_k; ++i)
        temp[i] = klienci[i];
    delete[] klienci;
    klienci = temp;
    ++size_k;
}
*/

void usun_k(Klienci*& klienci, size_t& size_k) {
    size_t index = rand() % size_k;
    if (index < size_k) {
        Klienci* temp = new Klienci[size_k - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size_k; ++i)
            if (i != index) {
                ++j;
                temp[j] = klienci[i];
            }
        delete[] klienci;
        klienci = temp;
        --size_k;
    }
    else
        std::cout << "ERROR: Index jest nieprawidłowy ! " << std::endl;
}

void zestawienie(Klienci*& klienci, size_t size_k) {
    std::cout << "<========= Zestawienie klientów po urodzonych po 1990 =========>" << std::endl;
    std::cout << "id      Produkty      rocznik" << std::endl;
    for (size_t i = 0; i < size_k; i++) {
        if (klienci[i].rocznik >= 1990) {
            std::cout << klienci[i].id_klienta << "\t" << klienci[i].godnosc
                << "\t" << klienci[i].rocznik << std::endl;
        }
    }
}
void stworz(Produkty**& produkty, size_t size_p) {
    if (produkty = { nullptr }) {
    }
    else {
        produkty = new Produkty * [size_p];
        for (size_t i = 0; i < size_p; i++)
            produkty[i] = new Produkty;
    }
}

void usun(Produkty**& produkty, size_t& size_p) {

    for (size_t i = 0; i < size_p; i++) {

        delete produkty[i];
        delete[] produkty;
        produkty = nullptr;
        size_p = 0;
    }

}

void show(Produkty**& produkty, size_t size_p) {
    std::cout << "<========= Produkty =========>" << std::endl;
    std::cout << "id      Produkty      cena" << std::endl;
    for (size_t i = 0; i < size_p; i++) {
        std::cout << produkty[i]->id_produktu << "\t" << produkty[i]->produkt
            << "\t" << produkty[i]->cena << std::endl;
    }
}




void tworzenie(Produkty**& produkty, size_t size_p) {

    size_t max = 100000;
    char string_buf[100];
    for (size_t i = 0; i < size_p; i++) {
        char id[100];
        produkty[i]->id_produktu = rand() % max + 20000;
        produkty[i]->cena = rand() % (100 - 1 + 1) + 1;
        sprintf_s(string_buf, "%zd", i);
        strcpy_s(id, "Produkt_");
        strcat_s(id, string_buf);
        strcpy_s(produkty[i]->produkt, id);

    }
}

void dodaj(Produkty**& produkty, size_t& size_p) {
    Produkty** temp = new Produkty * [size_p + 1];
    size_t max = 100000;
    char string_buf[100];
    char id[100];
    if (size_p == 0) {
        temp[size_p] = new Produkty;
    }
    else
    {
        for (size_t i = 0; i < size_p; ++i)
            temp[i] = produkty[i];
        temp[size_p] = new Produkty;
        delete[] produkty;
    }
    temp[size_p]->id_produktu = rand() % max + 20000;
    temp[size_p]->cena = rand() % (100 - 1 + 1) + 1;
    sprintf_s(string_buf, "%zd", size_p);
    strcpy_s(id, "Produkt_");
    strcat_s(id, string_buf);
    strcpy_s(temp[size_p]->produkt, id);

    produkty = temp;
    ++size_p;

}



void usun_p(Produkty**& produkty, size_t& size_p) {
    size_t index = rand() % size_p;
    if (index < size_p) {
        Produkty** temp = new Produkty * [size_p - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size_p; ++i)
            if (i != index) {
                ++j;
                temp[j] = produkty[i];
            }
        delete[] produkty;
        produkty = temp;
        --size_p;
    }
    else
        std::cout << "ERROR: Index jest nieprawidłowy ! " << std::endl;
}

void zestawienie(Produkty**& produkty, size_t size_p) {
    std::cout << "<========= Zestawienie Produkty droższe niż 40zł  =========>" << std::endl;
    std::cout << "id      Produkty      cena" << std::endl;
    for (size_t i = 0; i < size_p; i++) {
        if (produkty[i]->cena >= 40) {
            std::cout << produkty[i]->id_produktu<< "\t" << produkty[i]->produkt
                << "\t" << produkty[i]->cena << std::endl;
        }
    }
}


size_t rozmiar(size_t begin, size_t end) {
    std::random_device seed;
    std::mt19937 engine(seed());
    std::uniform_int_distribution<size_t> uniformDist(begin, end);
    return uniformDist(engine);
}
