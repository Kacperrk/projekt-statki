#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

#define WIERSZE 11
#define KOLUMNY 11

// czyszczenie konsoli niezalezne od systemu operacyjnego
void czysc_ekran(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// klasa z planszami zawierajaca metody do ich obslugi
class Plansza
{
private:

    char macierz[WIERSZE][KOLUMNY];

// ustawia wszystkie pola planszy na znak 'O'
    void czyszczenie_planszy(void)
    {
        for (int i = 0; i < WIERSZE; i++)
        {
            for (int j = 0; j < KOLUMNY; j++)
            {
                macierz[i][j] = 'O';
            }
        }
    }

// dodaje do planszy oznaczenia kolumn i wierszy
    void oznaczenia_planszy(void)
    {
        macierz[0][0] = ' ';

        char litera = 'A';
        char liczba = '0';

        for (int i = 1; i < WIERSZE; i++)
        {
            macierz[i][0] = litera;
            litera++;
        }

        for (int i = 1; i < KOLUMNY; i++)
        {
            macierz[0][i] = liczba;
            liczba++;
        }
    }

// funkcja sprawdza czy na planszy jest odpowiednia liczba statkow
    bool czy_statkow_jest_20(void)
    {
        int licznik = 0;
        for (int i = 1; i < WIERSZE; i++)
        {
            for (int j = 1; j < KOLUMNY; j++)
            {
                if (macierz[i][j] == '*')
                {
                    licznik++;
                }
            }
        }
        if (licznik == 20)
        {
            return true;
        }
        return false;
    }

// ustawienie czteromasztowca poziomo
    void czteromasztowce_poziomo(void)
    {
        // losowanie pierwszego od lewej elementu statku czteromasztowego poziomego

        // jest 10 pol od indeksu 1 do 10
        int wspolrzedna_pionowa = 1 + rand() % 10;
        // minus 3 bo statek czteromasztowy poziomy wyszedlby poza plansze
        int wspolrzedna_pozioma = 1 + rand() % 7;

        // narysowanie calego czteromasztowca poziomo
        for (int i = 0; i < 4; i++)
        {
            macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + i] = '*';
        }
    }

    void czteromasztowce_pionowo(void)
    {
        int wspolrzedna_pionowa = 1 + rand() % 7;
        int wspolrzedna_pozioma = 1 + rand() % 10;

        for (int i = 0; i < 4; i++)
        {
            macierz[wspolrzedna_pionowa + i][wspolrzedna_pozioma] = '*';
        }
    }

    void trojmasztowce_poziomo(void)
    {
        bool trojmasztowiec = false;
        int wspolrzedna_pionowa = 0;
        int wspolrzedna_pozioma = 0;

        // dopoki nie zostanie ustawiony w poprawnym miejscu
        while (!trojmasztowiec)
        {
            // losuj wspolrzedna pierwszego z lewej elementu statku
            wspolrzedna_pionowa = 1 + rand() % 10;
            wspolrzedna_pozioma = 1 + rand() % 8;

            // jesli na tym miejscu lub w poblizu jest juz statek
            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '*')
            {
                // zacznij petle od poczatku
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 2] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 3] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 0] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 2] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 3] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 0] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 2] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 3] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            trojmasztowiec = true;
        }

        if (trojmasztowiec)
        {
            for (int i = 0; i < 3; i++)
            {
                macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + i] = '*';
            }
        }
    }

    void trojmasztowce_pionowo(void)
    {
        bool trojmasztowiec = false;
        int wspolrzedna_pionowa = 0;
        int wspolrzedna_pozioma = 0;

        while (!trojmasztowiec)
        {
            wspolrzedna_pionowa = 1 + rand() % 8;
            wspolrzedna_pozioma = 1 + rand() % 10;

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 0] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 0] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 2][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 2][wspolrzedna_pozioma + 0] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 2][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 3][wspolrzedna_pozioma - 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 3][wspolrzedna_pozioma + 0] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 3][wspolrzedna_pozioma + 1] == '*')
            {
                trojmasztowiec = false;
                continue;
            }

            trojmasztowiec = true;
        }

        if (trojmasztowiec)
        {
            for (int i = 0; i < 3; i++)
            {
                macierz[wspolrzedna_pionowa + i][wspolrzedna_pozioma] = '*';
            }
        }
    }

    void dwumasztowce_poziomo(void)
    {
        bool dwumasztowiec = false;
        int wspolrzedna_pionowa = 0;
        int wspolrzedna_pozioma = 0;

        while (!dwumasztowiec)
        {
            wspolrzedna_pionowa = 1 + rand() % 10;
            wspolrzedna_pozioma = 1 + rand() % 9;

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 2] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 0] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 2] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 0] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 2] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            dwumasztowiec = true;

        }

        if (dwumasztowiec)
        {
            for (int i = 0; i < 2; i++)
            {
                macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + i] = '*';
            }
        }
    }

    void dwumasztowce_pionowo(void)
    {
        bool dwumasztowiec = false;
        int wspolrzedna_pionowa = 0;
        int wspolrzedna_pozioma = 0;

        while (!dwumasztowiec)
        {
            wspolrzedna_pionowa = 1 + rand() % 9;
            wspolrzedna_pozioma = 1 + rand() % 10;

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 0] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 0] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 2][wspolrzedna_pozioma - 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 2][wspolrzedna_pozioma + 0] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 2][wspolrzedna_pozioma + 1] == '*')
            {
                dwumasztowiec = false;
                continue;
            }

            dwumasztowiec = true;

        }

        if (dwumasztowiec)
        {
            for (int i = 0; i < 2; i++)
            {
                macierz[wspolrzedna_pionowa + i][wspolrzedna_pozioma] = '*';
            }
        }
    }

    void jednomasztowce(void)
    {
        bool jednomasztowiec = false;
        int wspolrzedna_pionowa = 0;
        int wspolrzedna_pozioma = 0;

        while (!jednomasztowiec)
        {
            wspolrzedna_pionowa = 1 + rand() % 10;
            wspolrzedna_pozioma = 1 + rand() % 10;

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma - 1] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + 1] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma - 1] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 0] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa - 1][wspolrzedna_pozioma + 1] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma - 1] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 0] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma + 1] == '*')
            {
                jednomasztowiec = false;
                continue;
            }

            jednomasztowiec = true;

        }

        if (jednomasztowiec)
        {
            macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] = '*';
        }
    }

public:

// konstruktor
    Plansza(void)
    {
        czyszczenie_planszy();
        oznaczenia_planszy();
    }

// destruktor
    ~Plansza(void)
    {

    }

// wypisuje plansze na ekranie
    void wypisz_plansze(void)
    {
        for (int i = 0; i < WIERSZE; i++)
        {
            for (int j = 0; j < KOLUMNY; j++)
            {
                cout << macierz[i][j] << " ";
            }
            cout << endl;
        }
    }

// spawdza czy na polu o podanych wspolrzednych jest statek
    bool czy_trafiony(char litera, int liczba)
    {
        int wiersze = 0;

        // zamienia podane litery od 'A' 'a' do 'J' 'j' na numer wiersza
        for (int i = 0; i < 10; i++)
        {
            if (litera == ('A' + i) || litera == ('a' + i))
            {
                wiersze = (1 + i);
            }
        }

        // jesli na podanym polu jest statek zmienia je na trafiony
        if (macierz[wiersze][liczba + 1] == '*' || macierz[wiersze][liczba + 1] == 'x')
        {
            // oznaczenie trafinego statku
            macierz[wiersze][liczba + 1] = 'x';
            return true;
        }
        // jesli na podanym polu nie ma statku zmienia je na pudlo
        else if (macierz[wiersze][liczba + 1] == 'O' || macierz[wiersze][liczba + 1] == '$')
        {
            // oznaczenie pudla
            macierz[wiersze][liczba + 1] = '$';
        }

        return false;
    }

// sprawdza czy gracz nie wpisal tego samego pola 2 razy
    bool czy_ponownie_to_samo_pole(char litera, int liczba)
    {
        int wiersze = 0;

        // zamienia podane litery od 'A' 'a' do 'J' 'j' na numer wiersza
        for (int i = 0; i < 10; i++)
        {
            if (litera == ('A' + i) || litera == ('a' + i))
            {
                wiersze = (1 + i);
            }
        }

        if (macierz[wiersze][liczba + 1] == 'x' || macierz[wiersze][liczba + 1] == '$')
        {
            return true;
        }

        return false;
    }

// sprawdza czy na planszy nie zostal zaden nietrafiony statek
    bool czy_wszystkie_trafione(void)
    {
        for (int i = 1; i < WIERSZE; i++)
        {
            for (int j = 1; j < KOLUMNY; j++)
            {
                if (macierz[i][j] == '*')
                {
                    return false;
                }
            }
        }
        return true;
    }

// zamienia wszystkie statki na pola trafione
    void wygraj_gre(void)
    {
        for (int i = 1; i < WIERSZE; i++)
        {
            for (int j = 1; j < KOLUMNY; j++)
            {
                if (macierz[i][j] == '*')
                {
                    macierz[i][j] = 'x';
                }
            }
        }
    }

// zamienia wszystkie statki na pola puste
    void przegraj_gre(void)
    {
        for (int i = 1; i < WIERSZE; i++)
        {
            for (int j = 1; j < KOLUMNY; j++)
            {
                if (macierz[i][j] == '*')
                {
                    macierz[i][j] = 'O';
                }
            }
        }
    }

// funkcja ustawiajaca statki losowo
    void ustaw_statki_losowo(void)
    {
        // sprawdzanie czy wszystkie statki sa na planszy
        while (!czy_statkow_jest_20())
        {
            // ustawienie czteromasztowca pionowo lub poziomo
            int losowanie = rand() % 2;
            if (!losowanie)
            {
                czteromasztowce_poziomo();
            }
            else if (losowanie)
            {
                czteromasztowce_pionowo();
            }

            // losowanie trojmasztowcow
            for (int i = 0; i < 2; i++)
            {
                losowanie = rand() % 2;
                if (!losowanie)
                {
                    trojmasztowce_poziomo();
                }
                else if (losowanie)
                {
                    trojmasztowce_pionowo();
                }
            }

            // losowanie dwumasztowcow
            for (int i = 0; i < 3; i++)
            {
                losowanie = rand() % 2;
                if (!losowanie)
                {
                    dwumasztowce_poziomo();
                }
                else if (losowanie)
                {
                    dwumasztowce_pionowo();
                }
            }

            // losowanie jednomasztowcow
            for (int i = 0; i < 4; i++)
            {
                jednomasztowce();
            }
        }
    }

// ruch komputera
    void komputer_losuje_strzal(void)
    {
        int wspolrzedna_pionowa = 0;
        int wspolrzedna_pozioma = 0;

        // strzelaj az spodlujesz lub trafisz wszystkie
        bool czy_kazdy_trafiony = true;

        while (true)
        {
            // sprawdzanie czy wszystkie trafione
            czy_kazdy_trafiony = true;
            for (int i = 1; i < WIERSZE; i++)
            {
                for (int j = 1; j < KOLUMNY; j++)
                {
                    if (macierz[i][j] == '*')
                    {
                        czy_kazdy_trafiony = false;
                    }
                }
            }

            // jesli kazdy statek jest trafiony zakoncz petle
            if (czy_kazdy_trafiony)
            {
                break;
            }

            wspolrzedna_pionowa = 1 + rand() % 10;
            wspolrzedna_pozioma = 1 + rand() % 10;

            // jesli trafiono w statek
            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '*')
            {
                // oznacz go jako trafiony
                macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] = 'x';
                // strzel jeszcze raz
                continue;
            }

            // jesli trafiono juz w trafiony statek
            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == 'x' ||
                    macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == '$')
            {
                // strzel jeszcze raz
                continue;
            }

            // jesli spudlowano tracisz kolejke
            if (macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] == 'O')
            {
                macierz[wspolrzedna_pionowa][wspolrzedna_pozioma] = '$';
                break;
            }
        }
    }

// sprawdza czy wokol nie pozostaly nietrafione statki
    bool czy_zatopiony(char litera, int liczba)
    {
        int wiersze = 0;

        // zamienia podane litery od 'A' 'a' do 'J' 'j' na numer wiersza
        for (int i = 0; i < 10; i++)
        {
            if (litera == ('A' + i) || litera == ('a' + i))
            {
                wiersze = (1 + i);
            }
        }

        // jesli wokol trafionego statku jest inny statek
        if (macierz[wiersze - 1][liczba + 1] == '*')
        {
            // znaczy ze nie jest zatopiony
            return false;
        }

        if (macierz[wiersze][liczba + 1 - 1] == '*')
        {
            return false;
        }

        if (macierz[wiersze + 1][liczba + 1] == '*')
        {
            return false;
        }

        if (macierz[wiersze][liczba + 1 + 1] == '*')
        {
            return false;
        }

        return true;
    }

};

int main(void)
{

    cout << "GRA W STATKI\n\n";
    cout << "W gre gra jednoczesnie jeden gracz i komputer\n";
    cout << "Gracz wybiera pole, w ktore chce strzelic\n";
    cout << "Jesli trafi, strzela jeszcze raz\n";
    cout << "Jesli nie trafi, kolejke dostaje komputer\n";
    cout << "Gra konczy sie, gdy ktorys z graczy zatopi wszystkie statki drugiego\n\n";

    cout << "Statki na planszy:\n";
    cout << " -jeden czteromasztowiec\n";
    cout << " -dwa trojmasztowce\n";
    cout << " -trzy dwumasztowce\n";
    cout << " -cztery jednomasztowce\n\n";

    cout << "Oznaczenia na planszy:\n";
    cout << " O - puste pole\n";
    cout << " * - statek\n";
    cout << " x - trafiony\n";
    cout << " $ - pudlo\n\n";

    cout << "Skoro znasz juz zasady, naciscij enter, aby kontunuowac:\n";

    getchar();

    czysc_ekran();

    srand(time(NULL));

    // przygotowanie plansz
    Plansza plansza_przeciwnika_ukryta;
    Plansza plansza_przeciwnika_widoczna;
    Plansza plansza_gracza;

    // losowanie statkow na planszach
    plansza_przeciwnika_ukryta.ustaw_statki_losowo();
    plansza_gracza.ustaw_statki_losowo();

    // wypisanie plansz
    cout << "Plansza przeciwnika:\n";
    plansza_przeciwnika_widoczna.wypisz_plansze();
    cout << "\nTwoja plansza:\n";
    plansza_gracza.wypisz_plansze();

    // graj dopoki nie zbijesz wszystkich statkow przeciwnika
    // jesli to przeciwnik wygra zostanie wywolany break
    while (!plansza_przeciwnika_ukryta.czy_wszystkie_trafione())
    {
        char litera = 0;
        int liczba = 0;

        cout << "\nPodaj wspolrzedne punktu (np. a1):\n";

        // test na poprawnosc wprowadzonych wspolrzednych
        bool right_input = false;
        do
        {
            cin >> litera;
            cin >> liczba;
            if (cin.fail())
            {
                cout << "\nPodano nieprawidlowa wartosc\n";
                cout << "Podaj wspolrzedne punktu (np. a1):\n";
                cin.clear();
                cin.ignore(1000, '\n');
                right_input = false;
            }
            else
            {
                right_input = true;
            }
        }
        while (!right_input);

        // jesli uzytkownik poda kolejny raz to samo pole
        if (plansza_przeciwnika_ukryta.czy_ponownie_to_samo_pole(litera, liczba))
        {
            cout << "\nPodawales juz to pole, podaj inne!\n";
            continue;
        }

        // jesli trafisz w statek
        else if (plansza_przeciwnika_ukryta.czy_trafiony(litera, liczba))
        {
            czysc_ekran();

            // kopiowanie planszy przeciwnika dla trafionych i nietrafionych
            plansza_przeciwnika_widoczna = plansza_przeciwnika_ukryta;
            // usunienie skopiowanych statkow z planszy widocznej
            plansza_przeciwnika_widoczna.przegraj_gre();

            // wypisz po strzale
            cout << "Plansza przeciwnika:\n";
            plansza_przeciwnika_widoczna.wypisz_plansze();


// todo 1 begin

            cout << "Plansza przeciwnika ukryta:\n";
            plansza_przeciwnika_ukryta.wypisz_plansze();

// todo 1 end









            cout << "\nTwoja plansza:\n";
            plansza_gracza.wypisz_plansze();
            cout << endl;

            if (plansza_przeciwnika_ukryta.czy_zatopiony(litera, liczba))
            {
                cout << "Trafiony zatopiony\n";
            }

            if (!plansza_przeciwnika_ukryta.czy_zatopiony(litera, liczba))
            {
                cout << "Trafiony\n";
            }

            if (!plansza_przeciwnika_ukryta.czy_wszystkie_trafione())
            {
                cout << "Strzelasz ponownie\n";
            }
        }
        // jesli nie trafisz w statek
        else if (!plansza_przeciwnika_ukryta.czy_trafiony(litera, liczba))
        {
            czysc_ekran();

            // kopiowanie planszy przeciwnika dla trafionych i nietrafionych
            plansza_przeciwnika_widoczna = plansza_przeciwnika_ukryta;
            // usunienie skopiowanych statkow z planszy widocznej
            plansza_przeciwnika_widoczna.przegraj_gre();

            // kolej komputera
            plansza_gracza.komputer_losuje_strzal();

            // wypisz po strzale
            cout << "Plansza przeciwnika:\n";
            plansza_przeciwnika_widoczna.wypisz_plansze();






            // todo 2 begin

            cout << "Plansza przeciwnika ukryta:\n";
            plansza_przeciwnika_ukryta.wypisz_plansze();

            // todo 2 end






            cout << "\nTwoja plansza:\n";
            plansza_gracza.wypisz_plansze();
            cout << endl;

            cout << "Nietrafiony\n";
            cout << "Przeciwnik wykonal swoj ruch\n";

            // jesli komputer trafi wszystkie statki
            if (plansza_gracza.czy_wszystkie_trafione())
            {
                break;
            }
        }
    }

    // sprawdzenie kto wygral i wypisanie na ekran
    if (plansza_przeciwnika_ukryta.czy_wszystkie_trafione())
    {
        cout << "\n\n\nTRAFILES WSZYSTKIE STATKI, WYGRYWASZ!!!\n";
    }
    else if (plansza_gracza.czy_wszystkie_trafione())
    {
        cout << "\n\n\nKOMPUTER WYGRYWA!!!\n";
    }

    // zeby okno konsoli nie zamknelo sie od razu
    cout << "\n\n\nNacisnij enter, zeby zakonczyc program:\n";
    getchar();

    return 0;
}

