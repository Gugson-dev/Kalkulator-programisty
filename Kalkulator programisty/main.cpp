#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <cctype>
#include <regex>

using namespace std;

double wczytajLiczbeRzeczywista(string komunikat) {
  double liczba;
  string ciagZnakow;

  cout << komunikat;
  cin >> ciagZnakow;

  regex wzorzec("-?[0-9]*\\.?[0-9]+");
  bool czyPoprawne = regex_match(ciagZnakow, wzorzec);

  while (!czyPoprawne || cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Wprowadzono niepoprawne dane. Wprowadz ponownie liczbe rzeczywista: ";
    cin >> ciagZnakow;

    czyPoprawne = regex_match(ciagZnakow, wzorzec);
  }

  liczba = stod(ciagZnakow);
  return liczba;
}

int wczytajLiczbeCalkowita(string komunikat, bool wybor) {
  int liczba;
  string ciagZnakow;

  cout << komunikat;
  cin >> ciagZnakow;

  bool czyPoprawne = true;
  for (char znak : ciagZnakow) {
    if (!isdigit(znak)) {
      czyPoprawne = false;
      break;
    }
  }

  while (!czyPoprawne || cin.fail()) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (wybor == true) cout << "Wprowadzono niepoprawne dane. Wybierz opcje ponownie: ";
    else cout << "Wprowadzono niepoprawne dane. Wprowadz ponownie liczbe calkowita: ";
    cin >> ciagZnakow;

    czyPoprawne = true;
    for (char znak : ciagZnakow) {
      if (!isdigit(znak)) {
        czyPoprawne = false;
        break;
      }
    }
  }

  liczba = stoi(ciagZnakow);
  return liczba;
}

int main() {
  int wybor;

  double liczba1;
  double liczba2, wynik;

  int liczba3;

  string binarny, oktalny, heksadecymalny;

  do {
    cout << "Menu: " << endl;
    cout << "1) Dodawanie" << endl;
    cout << "2) Odejmowanie" << endl;
    cout << "3) Mnozenie" << endl;
    cout << "4) Dzielenie" << endl;
    cout << "5) Potegowanie" << endl;
    cout << "6) Silnia" << endl;
    cout << "7) System binarny (dwojkowy)" << endl;
    cout << "8) System oktalny (osemkowy)" << endl;
    cout << "9) System heksadecymalny (szesnastkowy)" << endl;
    cout << "10) Wyjscie z programu" << endl;

    wybor = wczytajLiczbeCalkowita("Wybierz opcje: ", true);

    switch (wybor) {
      case 1:
        liczba1 = wczytajLiczbeRzeczywista("\nWprowadz pierwsza liczbe rzeczywista: ");
        liczba2 = wczytajLiczbeRzeczywista("Wprowadz druga liczbe rzeczywista: ");
        wynik = liczba1 + liczba2;
        cout << "Wynik: " << wynik << endl;
        break;
    case 2:
        liczba1 = wczytajLiczbeRzeczywista("\nWprowadz pierwsza liczbe rzeczywista: ");
        liczba2 = wczytajLiczbeRzeczywista("Wprowadz druga liczbe rzeczywista: ");
        wynik = liczba1 - liczba2;
        cout << "Wynik: " << wynik << endl;
        break;
    case 3:
        liczba1 = wczytajLiczbeRzeczywista("\nWprowadz pierwsza liczbe rzeczywista: ");
        liczba2 = wczytajLiczbeRzeczywista("Wprowadz druga liczbe rzeczywista: ");
        wynik = liczba1 * liczba2;
        cout << "Wynik: " << wynik << endl;
        break;
    case 4:
        liczba1 = wczytajLiczbeRzeczywista("\nWprowadz pierwsza liczbe rzeczywista: ");
        liczba2 = wczytajLiczbeRzeczywista("Wprowadz druga liczbe rzeczywista: ");
        wynik = liczba1 / liczba2;
        cout << "Wynik: " << wynik << endl;
        break;
    case 5:
        liczba3 = wczytajLiczbeCalkowita("\nWprowadz liczbe calkowita: ", false);
        liczba2 = wczytajLiczbeRzeczywista("Wprowadz wykladnik: ");
        wynik = pow(liczba3, liczba2);
        cout << "Wynik: " << wynik << endl;
        break;
    case 6:
        liczba3 = wczytajLiczbeCalkowita("\nWprowadz liczbe calkowita: ", false);
        wynik = 1;
        for (int i = 2; i <= liczba3; i++) {
            wynik *= i;
        }
        cout << "Wynik: " << wynik << endl;
        break;
    case 7:
        liczba3 = wczytajLiczbeCalkowita("\nWprowadz liczbe calkowita: ", false);
        binarny = "";
        while (liczba3 > 0) {
            if (liczba3 % 2 == 0) {
                binarny = "0" + binarny;
            } else {
                binarny = "1" + binarny;
            }
            liczba3 /= 2;
        }
        cout << "Wynik: " << binarny << endl;
        break;
    case 8:
        liczba3 = wczytajLiczbeCalkowita("\nWprowadz liczbe calkowita: ", false);
        oktalny = "";
        while (liczba3 > 0) {
            oktalny = to_string(liczba3 % 8) + oktalny;
            liczba3 /= 8;
        }
        cout << "Wynik: " << oktalny << endl;
        break;
    case 9:
        liczba3 = wczytajLiczbeCalkowita("\nWprowadz liczbe calkowita: ", false);
        heksadecymalny = "";
        while (liczba3 > 0) {
            int reszta = liczba3 % 16;
            if (reszta < 10) {
                heksadecymalny = to_string(reszta) + heksadecymalny;
            } else {
                heksadecymalny = (char)('A' + reszta - 10) + heksadecymalny;
            }
            liczba3 /= 16;
        }
        cout << "Wynik: " << heksadecymalny << endl;
        break;
    case 10:
        break;
    default:
        cout << "Prosze wprowadzic prawidlowa liczbe" << endl;
        break;
    }
    cout << endl;
    } while (wybor != 10);

return 0;
}
