#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// odkomentuj tylko jesli nie chcesz czyszczenia konsoli
#define CZYSZCZENIE_EKRANU ;

// odkomentuj tylko jesli uzywasz systemu linux
//#define CZYSZCZENIE_EKRANU system("clear");

// odkomentuj tylko jesli uzywasz systemu windows
//#define CZYSZCZENIE_EKRANU system("cls");

#define WIERSZE 11
#define KOLUMNY 11

class Plansza
{
private:

char macierz[WIERSZE][KOLUMNY];

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
	int wspolrzedna_pionowa = 1+rand()%10;
	// minus 3 bo statek czteromasztowy poziomy wyszedlby poza plansze
	int wspolrzedna_pozioma = 1+rand()%7;

	// narysowanie calego czteromasztowca poziomo
	for (int i = 0; i < 4; i++)
	{
		macierz[wspolrzedna_pionowa][wspolrzedna_pozioma + i] = '*';
	}
}

void czteromasztowce_pionowo(void)
{
	int wspolrzedna_pionowa = 1+rand()%7;
	int wspolrzedna_pozioma = 1+rand()%10;

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
		wspolrzedna_pionowa = 1+rand()%10;
		wspolrzedna_pozioma = 1+rand()%8;

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

		if (macierz[wspolrzedna_pionowa + 1][wspolrzedna_pozioma  + 3] == '*')
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
		wspolrzedna_pionowa = 1+rand()%8;
		wspolrzedna_pozioma = 1+rand()%10;

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
		wspolrzedna_pionowa = 1+rand()%10;
		wspolrzedna_pozioma = 1+rand()%9;

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
		wspolrzedna_pionowa = 1+rand()%9;
		wspolrzedna_pozioma = 1+rand()%10;

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
		wspolrzedna_pionowa = 1+rand()%10;
		wspolrzedna_pozioma = 1+rand()%10;

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

Plansza(void)
{
	czyszczenie_planszy();
	oznaczenia_planszy();
}

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
			//cout << macierz[i][j] << "\t";
			cout << macierz[i][j] << " ";
		}
		cout << endl;
	}
}

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
	//for (int i = 0; i <= WIERSZE; i++)
	for (int i = 1; i < WIERSZE; i++)
	{
		//for (int j = 0; j <= KOLUMNY; j++)
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
	//for (int i = 0; i <= WIERSZE; i++)
	for (int i = 1; i < WIERSZE; i++)
	{
		//for (int j = 0; j <= KOLUMNY; j++)
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
		int losowanie = rand()%2;
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
			losowanie = rand()%2;
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
			losowanie = rand()%2;
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

void ustaw_statki_v2(void)
{
	int first_x = 0;
	int first_y = 0;
	int last_x = 0;
	int last_y = 0;

	for (int a = 1; a <= 4; a++)
	{
		cout << "PODAJ ZAKRES STATKU O ROZMIARZE " << a << ":\n";

		cin >> first_x;
		cin >> first_y;
		cin >> last_x;
		cin >> last_y;

		//for (int i = 0; i <= WIERSZE; i++)
		for (int i = 1; i < WIERSZE; i++)
		{
			//for (int j = 0; j <= KOLUMNY; j++)
			for (int j = 1; j < KOLUMNY; j++)
			{
				if (i == first_x && j == first_y)
				{
					if (first_x == last_x)
					{
						for (int k = j; k <= last_y; k++)
						{
							macierz[first_x][k] = '*';
						}
					}
					else if (first_y == last_y)
					{
						for (int k = i; k <= last_x; k++)
						{
							macierz[k][first_y] = '*';
						}
					}
					else
					{
						cout << "PODANO BLEDNY ZAKRES STATKU LUB STATEK NIE MOZE ZNAJDOWAC SIE W TYM MIEJSCU\n";
					}
				}
			}
		}
	}
}

};

int main(void)
{

	srand(time(NULL));

	Plansza plansza_przeciwnika_ukryta;
	Plansza plansza_przeciwnika_widoczna;
	Plansza plansza_gracza_ukryta;
	//Plansza plansza_gracza_widoczna;

	cout << "Statki:\n";
	cout << "O - puste pole\n";
	cout << "* - statek\n";
	cout << "x - trafiony\n";
	cout << "$ - pudlo\n\n";

	plansza_przeciwnika_ukryta.ustaw_statki_losowo();

	plansza_gracza_ukryta.ustaw_statki_losowo();

	//plansza_przeciwnika_ukryta.ustaw_statki_v2();

	cout << "Plansza przeciwnika ukryta:\n";
	plansza_przeciwnika_ukryta.wypisz_plansze();
	cout << endl;
	cout << "Plansza przeciwnika widoczna:\n";
	plansza_przeciwnika_widoczna.wypisz_plansze();
	cout << endl;
	cout << "Plansza gracza ukryta:\n";
	plansza_gracza_ukryta.wypisz_plansze();

	while (!plansza_przeciwnika_ukryta.czy_wszystkie_trafione())
	{
		cout << "\nPodaj wspolrzedne punktu (np. a1):\n";

		char litera = 0;
		int liczba = 0;
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
		} while (right_input == false);

		cout << litera;
		cout << liczba;
		cout << endl;

		if (plansza_przeciwnika_ukryta.czy_trafiony(litera, liczba))
		{
			CZYSZCZENIE_EKRANU;
			cout << endl;
			cout << "Plansza przeciwnika ukryta:\n";
			plansza_przeciwnika_ukryta.wypisz_plansze();
			cout << endl;



			plansza_przeciwnika_widoczna = plansza_przeciwnika_ukryta;
			plansza_przeciwnika_widoczna.przegraj_gre();



			cout << "Plansza przeciwnika widoczna:\n";
			plansza_przeciwnika_widoczna.wypisz_plansze();
			cout << "\nTrafiony\n";
		}
		else if (!plansza_przeciwnika_ukryta.czy_trafiony(litera, liczba))
		{
			CZYSZCZENIE_EKRANU;
			cout << endl;
			cout << "Plansza przeciwnika ukryta:\n";
			plansza_przeciwnika_ukryta.wypisz_plansze();
			cout << endl;



			// kopiowanie planszy przeciwnika dla trafionych i nietrafionych
			plansza_przeciwnika_widoczna = plansza_przeciwnika_ukryta;
			// usunienie skopiowanych statkow z planszy widocznej
			plansza_przeciwnika_widoczna.przegraj_gre();



			cout << "Plansza przeciwnika widoczna:\n";
			plansza_przeciwnika_widoczna.wypisz_plansze();
			cout << "\nNietrafiony\n";
		}
	}

	cout << "\nTrafiono wszystkie statki, gra skonczona\n";

	return 0;
}

