import <iostream>;
import <string>;
import <cstdlib>;
import <locale>;
import <ctime>;
import <random>;
#include "CKlasa.h"




int main()
{
    setlocale(LC_CTYPE, "Polish");
    size_t size_k = rozmiar(1,3);
    size_t size_p = rozmiar(3,10);
    size_t choice = 1;
    Klienci* klienci = { nullptr };
    Produkty** produkty = { nullptr };



    while (choice < 8) {

        std::cout << "Witaj w naszym sklepie !" << std::endl;
        std::cout << "-----------------------------------------------------------------" << std::endl;
        std::cout << "1.Przydzielanie pamięci " << std::endl;
        std::cout << "2.Wypełnainie wartościami " << std::endl;
        std::cout << "3.Podmiana wartości " << std::endl;
        std::cout << "4.Wyświetlanie " << std::endl;
        std::cout << "5.Dodawanie użytkownika" << std::endl;
        std::cout << "6.Usuwanie użytkownika" << std::endl;
        //std::cout << "6.Przydzielanie pamięci wskaźników" << std::endl;
        //std::cout << "7.Wypełnianie wartościami tablicy wskaźników" << std::endl;
        //std::cout << "8.Wyświetlanie tablicy wskaźników" << std::endl;
        //std::cout << "9.Dodawanie użytkownika do tablicy wskaźników" << std::endl;
        //std::cout << "10.Usuwanie użytkownika do tablicy wskaźników" << std::endl;
        std::cout << "7.Zestawienie danych" << std::endl;
        //std::cout << "12.Zestawienie danych wskaźników" << std::endl;
        std::cout << "8.Wyjście" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1:
            stworz(klienci, size_k);
           
            system("cls");
            break;
        case 2:
            tworzenie(klienci, size_k,size_p);
            system("cls");
            break;
        case 3:
            przypisanie(klienci);
            system("cls");
            break;
        case 4:
            system("cls");
            show(klienci, size_k);
            break;
        case 5:
            dodaj(klienci,size_k);
            system("pause");
            break;
        case 6:
            usun_k(klienci, size_k);
            system("cls");
            break;
        /*case 6:
            stworz(produkty, size_p);
            system("cls");
            break;
        case 7:
            tworzenie(produkty, size_p);
            system("cls");
            break;
        case 8:
            system("cls");
            show(produkty, size_p);
            break;
        case 9:
            dodaj(produkty, size_p);
            system("cls");
            break;
        case 10:
            usun_p(produkty, size_p);
            system("cls");
         */   break;
        case 7:
            system("cls");
            zestawienie(klienci, size_k);
            break;
        //case 12:
        //    system("cls");
        //    zestawienie(produkty, size_p);

            break;
        case 8:
            system("cls");
            break;
        default:
            std::cout << "Błędny wybór. Powtórz\n";

        }
    }
    usun(klienci, size_k);
    //usun(produkty, size_p);
    return 0;


}
