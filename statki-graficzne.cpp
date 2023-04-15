#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <time.h>
//#include <Windows.h>

using namespace std;
using namespace sf;


//STALE OPISUJACE ROZMIAR INICJOWANEGO OKNA
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

const int BOARD_SIZE = 10;


//ROZMIAR JEDNEJ KOMORKI W PLANSZY
const int CELL_SIDE = 50;


//KLASA PLANSZA
class BOARD
{
public:

	bool BOARD_OF_BOOLS[BOARD_SIZE][BOARD_SIZE];//MACIERZ ZAWIERAJACA INFORMACJE CZY DANE POLE JEST KLIKNIETE//NA DOLE FUNKCJA ZERUJACA

	bool POSITIONS_OF_SHIPS[BOARD_SIZE][BOARD_SIZE];//TA MACIERZ INFORMUJE W JAKICH MIEJSCACH SA STATKI 0 - NIE MA || 1 - JEST

	bool FORBIDDEN_FIELDS[BOARD_SIZE][BOARD_SIZE];// TA MACIERZ PRZECHOWUJE INFORMACJE O POLACH ZAKAZANYCH DO KLIKNIECIA

	/*
	int POINT_OF_X[10][10];//MACIERZ ZAIWERAJACA WSPOLRZEDNE X-OWE KAZDEJ Z KOMOREK

	int POINT_OF_Y[10][10];//MACIERZ ZAWIERAJACA WSPOLRZEDNE Y-OWE KAZDEJ Z KOMOREK
	*/

	int X_POCZATKU, Y_POCZATKU;

	int SINGLE, DOUBLE, TRIPLE, QUADRA;//TYPY STATKOW



	sf::RectangleShape MATRIX[BOARD_SIZE][BOARD_SIZE];//UTWORZENIE 100 OBIEKTOW TYPU KWADRAT

	//INICJALIZACJA PLANSZY(MIEJSCA) W DANYM MIEJSCU NA EKRANIE//kontruktor
	BOARD(int x, int y)
	{
		this->X_POCZATKU = x;
		this->Y_POCZATKU = y;
	}

	//FUNKCJA USTAWIAJACA WARTOSCI KAZDEJ Z KOMOREK NA 0 , CZYLI NIE KLIKANO ZADNEJ Z NICH
	void Reset_Board()
	{
		int i, j;
		for (i = 0; i < BOARD_SIZE; i++)
		{
			for (j = 0; j < BOARD_SIZE; j++)
			{
				BOARD_OF_BOOLS[i][j] = false;
				FORBIDDEN_FIELDS[i][j] = false;
			}
		}
	}


	//FUNKCJA WYPISUJACA W KONSOLI WARTOSCI BOOLOWSKIE KOMOREK MACIERZY
	void wypisz()
	{
		int i, j;
		for (i = 0; i < BOARD_SIZE; i++)
		{
			for (j = 0; j < BOARD_SIZE; j++)
			{
				cout << BOARD_OF_BOOLS[i][j] << " ";
			}
			cout << "" << endl;
		}
	}


	//FUNKCJA USTAWIAJACA PODSTAWOWE PARAMETRY KWADRATOW (KOMOREK)
	void Przypisz_Polozenie()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				//POINT_OF_X[i][j] = (i+1) * CELL_SIDE; //OKAZALO SIE NIEPOTRZEBNE DEKLAROWANIE
				//POINT_OF_Y[i][j] = (j+1) * CELL_SIDE;
				MATRIX[i][j].setSize(sf::Vector2f(CELL_SIDE, CELL_SIDE));
				MATRIX[i][j].setFillColor(sf::Color::White);
				MATRIX[i][j].setOutlineThickness(4);
				MATRIX[i][j].setOutlineColor(sf::Color::Black);
				//PONIZEJ USTAWIANA JEST POZYCJA KAZDEJ Z KOMOREK CZYT. NP DLA I = 0  I+1 = 1 , 1*50 + 100(JEZELI PODANMY 100 JAKO X POCZATKU)
				//														KWADRAT RYSUJE SIE POPRAWNIE PONIEWAZ WCZESNIEJ ZADEKLAROWALISMY JEGO ROZMIAR
				//														PATRZ FUNKCJA SETSIZE
				MATRIX[i][j].setPosition(sf::Vector2f(((i+1)*CELL_SIDE)+X_POCZATKU,((j+1)*CELL_SIDE)+Y_POCZATKU));

			}
		}
	}

	//FUNKCJA USTAWIAJACA LICZBE DANYCH STATKOW NA WARTOSC STARTOWA !DLA KAZDEGO STATKU JEST TO INNA LICZBA NP 4 JEDNOMASZTOWCE!
	void Reset_Ships()
	{
		SINGLE = 4;
		DOUBLE = 3;
		TRIPLE = 2;
		QUADRA = 1;
	}


	//FUNKCJA SPRAWDZAJACA CZY STATKI SA JESZCZE NA PLANSZY
	bool Check_If_Ships_Are_Alive()
	{
		if ((SINGLE) || (DOUBLE) || (TRIPLE) || (QUADRA))
		{
			return 1;//ZYJA
		}
		else
		{
			return 0; // NIE ZYJA
		}
	}


	//WORK IN PROGRESS//
	/*
	bool Add_Ships()
	{
		bool COLISION;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (BOARD_OF_BOOLS[i][j] == true)
				{
					if()
				}
			}
		}
		if (COLISION)
		{
			return false;
		}
		return true;

	}
	*/





	//FUNKCJA STWORZONA PO TO ABY USTAWIAC NA MACIERZY POLA ZAKAZANE DO KLIKNIECIA
	void Set_To_Forbidden(int i,int j)
	{
		FORBIDDEN_FIELDS[i][j] = true;
	}

	//FUNKCJA STWORZONA DLA WYGODY ABY SZYBKO SPRAWDZIC CZY DANE POLE JEST ZAKAZANE
	bool Is_Set_To_Forbidden(int i, int j)
	{
		if (FORBIDDEN_FIELDS[i][j] == true)
		{
			return true;
		}
		return false;
	}






	int Detect_Ship_Size(int row, int col)
	{
		int shipSize = 0;

		// sprawdzenie w pionie
		int i = row;
		while (i >= 0 && BOARD_OF_BOOLS[i][col]) {
			shipSize++;
			i--;
		}
		i = row + 1;
		while (i < BOARD_SIZE && BOARD_OF_BOOLS[i][col]) {
			shipSize++;
			i++;
		}

		// sprawdzenie w poziomie
		int j = col;
		while (j >= 0 && BOARD_OF_BOOLS[row][j]) {
			shipSize++;
			j--;
		}
		j = col + 1;
		while (j < BOARD_SIZE && BOARD_OF_BOOLS[row][j]) {
			shipSize++;
			j++;
		}

		return shipSize - 1;


	}




	void Fill_The_Board()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				if (BOARD_OF_BOOLS[i][j] == false && FORBIDDEN_FIELDS[i][j] == false)
				{
					FORBIDDEN_FIELDS[i][j] = true;
					MATRIX[i][j].setFillColor(sf::Color::Red);

				}
			}
		}
	}





	//OGOLNIE W TEJ FUNKCJI CHODZI O TO
	//POBEIRA WSPOLRZEDNE PUNKTU KTORY WLASNIE WYBRAL UZYTKOWNIK, CZYLI TEGO KTORY WLASNIE ZAZNACZYL NA PLANSZY
	//SPRAWDZA CZY JEST TO NAJPIERW
	//CZTEROMASZTOWIEC
	//TRZYMASZTOWIEC
	//DWUMASZTOWIEC
	//JEDNOMASZTOWIEC
	//PO KOLEI
	//NAJPIERW SZUKA CZTEROMASZTOWCA, JEZELI OKAZE SIE ZE PO KLIKNIECIU PUNKTU
	//WYKRYTY ZOSTANIE CZTEROMASZTOWIEC TO FUNKCJA BLOKUJE POLE NA PRAWO LUB NA LEWO OD STRZELONEGO STATKU ORAZ 4-TE POLE NA LEWO LUB NA PRAWO
	/// NA LEWO CZY NA PRAWO----- JEST TO UZALEZNIONE OD TEGO Z KTOREJ STRONY STATEK SIE ZACZYNA A Z KTOREJ KONCZY
	void Forbide_Ends(int i,int j)
	{
		if (Detect_Ship_Size(i, j) == 4)
		{
			if (i - 1 >= 0)
			{
				if (BOARD_OF_BOOLS[i - 1][j])
				{
					if (i + 1 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i + 1][j] = true;
						MATRIX[i + 1][j].setFillColor(sf::Color::Red);
					}
					if (i - 4 >= 0)
					{
						FORBIDDEN_FIELDS[i - 4][j] = true;
						MATRIX[i - 4][j].setFillColor(sf::Color::Red);
					}

				}
			}

			if (i + 1 < BOARD_SIZE)
			{
				if (BOARD_OF_BOOLS[i + 1][j])
				{
					if (i - 1 >= 0)
					{
						FORBIDDEN_FIELDS[i - 1][j] = true;
						MATRIX[i - 1][j].setFillColor(sf::Color::Red);
					}
					if (i + 4 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i + 4][j] = true;
						MATRIX[i + 4][j].setFillColor(sf::Color::Red);
					}


				}
			}

			if (j - 1 >= 0)
			{
				if (BOARD_OF_BOOLS[i][j - 1])
				{
					if (j + 1 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i][j + 1] = true;
						MATRIX[i][j + 1].setFillColor(sf::Color::Red);
					}
					if (j - 4 >= 0)
					{
						FORBIDDEN_FIELDS[i][j - 4] = true;
						MATRIX[i][j - 4].setFillColor(sf::Color::Red);
					}


				}
			}


			if (j + 1 < BOARD_SIZE)
			{
				if (BOARD_OF_BOOLS[i][j + 1])
				{
					if (j - 1 >= 0)
					{
						FORBIDDEN_FIELDS[i][j - 1] = true;
						MATRIX[i][j - 1].setFillColor(sf::Color::Red);
					}
					if (j + 4 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i][j + 4] = true;
						MATRIX[i][j + 4].setFillColor(sf::Color::Red);
					}
				}

			}





		}


		if (Detect_Ship_Size(i, j) == 3 && !QUADRA)
		{
			if (i - 1 >= 0)
			{
				if (BOARD_OF_BOOLS[i - 1][j])
				{
					if (i + 1 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i + 1][j] = true;
						MATRIX[i + 1][j].setFillColor(sf::Color::Red);
					}

					if (i - 3 >= 0)
					{
						FORBIDDEN_FIELDS[i - 3][j] = true;
						MATRIX[i - 3][j].setFillColor(sf::Color::Red);
					}


				}
			}


			if (i + 1 < BOARD_SIZE)
			{
				if (BOARD_OF_BOOLS[i + 1][j])
				{
					if (i - 1 >= 0)
					{
						FORBIDDEN_FIELDS[i - 1][j] = true;
						MATRIX[i - 1][j].setFillColor(sf::Color::Red);
					}
					if (i + 3 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i + 3][j] = true;
						MATRIX[i + 3][j].setFillColor(sf::Color::Red);
					}


				}
			}


			if (j - 1 >= 0)
			{
				if (BOARD_OF_BOOLS[i][j - 1])
				{
					if (j + 1 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i][j + 1] = true;
						MATRIX[i][j + 1].setFillColor(sf::Color::Red);
					}
					if (j - 3 >= 0)
					{
						FORBIDDEN_FIELDS[i][j - 3] = true;
						MATRIX[i][j - 3].setFillColor(sf::Color::Red);
					}


				}
			}


			if (j + 1 < BOARD_SIZE)
			{
				if (BOARD_OF_BOOLS[i][j + 1])
				{
					if (j - 1 >= 0)
					{
						FORBIDDEN_FIELDS[i][j - 1] = true;
						MATRIX[i][j - 1].setFillColor(sf::Color::Red);
					}
					if (j + 3 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i][j + 3] = true;
						MATRIX[i][j + 3].setFillColor(sf::Color::Red);
					}

				}
			}




		}

		else if (Detect_Ship_Size(i, j) == 2 && !QUADRA && !TRIPLE)
		{
			if (i - 1 >= 0)
			{
				if (BOARD_OF_BOOLS[i - 1][j])
				{
					if (i + 1 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i + 1][j] = true;
						MATRIX[i + 1][j].setFillColor(sf::Color::Red);
					}

					if (i - 2 >= 0)
					{
						FORBIDDEN_FIELDS[i - 2][j] = true;
						MATRIX[i - 4][j].setFillColor(sf::Color::Red);
					}


				}
			}


			if (i + 1 < BOARD_SIZE)
			{
				if (BOARD_OF_BOOLS[i + 1][j])
				{
					if (i - 1 >= 0)
					{
						FORBIDDEN_FIELDS[i - 1][j] = true;
						MATRIX[i - 1][j].setFillColor(sf::Color::Red);
					}

					if (i + 2 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i + 2][j] = true;
						MATRIX[i + 4][j].setFillColor(sf::Color::Red);
					}


				}
			}

			if (j - 1 >= 0)
			{
				if (BOARD_OF_BOOLS[i][j - 1])
				{
					if (j + 1 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i][j + 1] = true;
						MATRIX[i][j + 1].setFillColor(sf::Color::Red);
					}

					if (j - 2 >= 0)
					{
						FORBIDDEN_FIELDS[i][j - 2] = true;
						MATRIX[i][j - 2].setFillColor(sf::Color::Red);
					}


				}
			}


			if (j + 1 < BOARD_SIZE)
			{
				if (BOARD_OF_BOOLS[i][j + 1])
				{
					if (j - 1 >= 0)
					{
						FORBIDDEN_FIELDS[i][j - 1] = true;
						MATRIX[i][j - 1].setFillColor(sf::Color::Red);
					}

					if (j + 2 < BOARD_SIZE)
					{
						FORBIDDEN_FIELDS[i][j + 2] = true;
						MATRIX[i][j + 2].setFillColor(sf::Color::Red);
					}

				}
			}



		}
	}



};




//PROSTA FUNKCJA SPRAWDZAJACA CZY DANE POLE JEST KLIKNIETE
bool Check_If_Clicked(BOARD& gracz, int i, int j)
{
	if (gracz.BOARD_OF_BOOLS[i][j] == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//FUNCKJA USTAWIAJACA MIEJSCE STATKOW NA PODSTAWIE KLIKNIETYCH PRZEZ GRACZA POL
void Set_Ships(BOARD &gracz)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (Check_If_Clicked(gracz, i, j))
			{
				gracz.POSITIONS_OF_SHIPS[i][j] = 1;
			}
		}
	}
}




//FUNKCJA WYPISUJACA NA EKRANIE PLANSZE
void Pokaz_Na_Ekranie(BOARD &gracz,sf::RenderWindow &okno)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			okno.draw(gracz.MATRIX[i][j]);
		}
	}
}


//FUNKCJA USTAWIAJACA POLE NA KLIKNIETE (OCZYWISCIE FUNKCJA DZIALA POD KONTROLA PROGRAMISTY, CZYLI PROGRAMISTA ZADBA O TO ZEBY POLE BYLO OZNACZONE JAKO KLIKNIETE
//TYLKO WTEDY KIEDY JEST MOZLIWOSC JEGO KLIKNIECIA
void Set_To_Clicked(BOARD &gracz,int i,int j)
{
	gracz.BOARD_OF_BOOLS[i][j] = 1;
}





//INICJALIZACJA GRACZY Z PARAMETRAMI PODSTAWOWYMI CZYTAJ STARTOWYMI
void INITIATE_PLAYERS(BOARD &gracz, BOARD &komputer)
{
	gracz.Reset_Board();

	gracz.wypisz();

	gracz.Przypisz_Polozenie();

	gracz.Reset_Ships();

	komputer.Reset_Board();

	komputer.wypisz();

	komputer.Przypisz_Polozenie();

	komputer.Reset_Ships();



}



//FUNKCJA SPRAWDZAJACA KTORA TURA JEST TERAZ
bool CHECK_TURN(bool *tura)
{
	if (*tura == false)
	{
		return false;
	}
	if (*tura == false)
	{
		return false;
	}
	return false;
}




void COLLISION_BLOCKS_RENDER_AND_SET(BOARD& gracz,int i,int j)
{
	if ((i - 1 >= 0) && (j - 1 >= 0))
	{
		gracz.MATRIX[i - 1][j - 1].setFillColor(sf::Color::Red);///PRAWY DOLNY KWADRAT RENDER
		gracz.Set_To_Forbidden(i - 1, j - 1);
	}
	if ((i - 1 >= 0) && (j + 1 < BOARD_SIZE))
	{
		gracz.MATRIX[i - 1][j + 1].setFillColor(sf::Color::Red);///LEWY DOLNY KWADRAT RENDER
		gracz.Set_To_Forbidden(i - 1, j + 1);
	}
	if ((i + 1 < BOARD_SIZE) && (j - 1 >= 0))
	{
		gracz.MATRIX[i + 1][j - 1].setFillColor(sf::Color::Red);///PRAWY GORNY KWADRAT RENDER
		gracz.Set_To_Forbidden(i + 1, j - 1);
	}
	if ((i + 1 < BOARD_SIZE) && (j + 1 < BOARD_SIZE))
	{
		gracz.MATRIX[i + 1][j + 1].setFillColor(sf::Color::Red);///LEWY GORNY KWADRAT RENDER
		gracz.Set_To_Forbidden(i + 1, j + 1);
	}
	if (true)////WARUNEK TRUE ABY NIE BURZYC KONSTRUKCJI
	{
		if ((j - 2 > 0) && (gracz.BOARD_OF_BOOLS[i][j - 2] == true) && (!gracz.BOARD_OF_BOOLS[i][j-1]))
		{
			gracz.MATRIX[i][j - 1].setFillColor(sf::Color::Red);
			gracz.Set_To_Forbidden(i, j - 1);
		}
		if ((i + 2 < BOARD_SIZE) && (gracz.BOARD_OF_BOOLS[i + 2][j] == true) && (!gracz.BOARD_OF_BOOLS[i+1][j]))
		{
			gracz.MATRIX[i + 1][j].setFillColor(sf::Color::Red);
			gracz.Set_To_Forbidden(i + 1, j);
		}
		if ((i - 2 > 0) && (gracz.BOARD_OF_BOOLS[i - 2][j] == true) && (!gracz.BOARD_OF_BOOLS[i-1][j]))
		{
			gracz.MATRIX[i - 1][j].setFillColor(sf::Color::Red);
			gracz.Set_To_Forbidden(i - 1, j);
		}
		if ((j + 2 > 0) && (gracz.BOARD_OF_BOOLS[i][j + 2] == true) && (!gracz.BOARD_OF_BOOLS[i][j+1]))
		{
			gracz.MATRIX[i][j + 1].setFillColor(sf::Color::Red);
			gracz.Set_To_Forbidden(i, j - +1);
		}

	}


}




void SHIPS_OCCUR(BOARD &gracz,int i, int j)
{
	if (gracz.Detect_Ship_Size(i, j) == 4 && gracz.QUADRA)
	{
		cout << "FOUR DETECTED" << endl;
		gracz.QUADRA--;
	}
	else if (gracz.Detect_Ship_Size(i, j) == 3 && gracz.TRIPLE && gracz.QUADRA == 0)
	{
		cout << "TRIPLE DETECTED" << endl;
		gracz.TRIPLE--;
	}
	else if (gracz.Detect_Ship_Size(i, j) == 2 && gracz.DOUBLE && gracz.QUADRA == 0 && gracz.TRIPLE == 0)
	{
		cout << "DOUBLE DETECTED" << endl;
		gracz.DOUBLE--;
	}
	else if (gracz.Detect_Ship_Size(i, j) == 1 && gracz.SINGLE && gracz.QUADRA == 0 && gracz.TRIPLE == 0 && gracz.DOUBLE == 0)
	{
		cout << "SINGLE DETECTED" << endl;
		gracz.SINGLE--;
	}
}






int main()
{
	bool tura = true;



	// WYRENDERUJ NA EKRANIE OBIEKT 'OKNO' O ROZMIARACH ZDEFINIOWANYCH NA SAMEJ GORZE, OKNO MA SIE NAZYWAC 'STATKI'
	sf::RenderWindow okno(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "STATKI");



	//STWORZENIE GRACZA KTOREGO PLANSZA ZACZYNA SIE OD MIEJSCA 100X100 NA OSI WSPOLRZEDNYCH

	BOARD gracz(100, 100);



	//STWORZENIE GRACZA KOMPUTER KTOREGO PLANSZA ZACZYNA SIE OD MIEJSCA 900X100 NA OSI WSPOLRZEDNYCH

	BOARD komputer(900, 100);


	//PODSTAWOWE OPERACJE STARTOWE DLA KAZDEJ Z PLANSZ
	INITIATE_PLAYERS(gracz, komputer);


	sf::Event zdarzenie, WYBOR;

	Pokaz_Na_Ekranie(gracz, okno); // Wywołanie funkcji Pokaz_Na_Ekranie()

	//TAK DLUGO JAK OKNO JEST OTWARTE
	while (okno.isOpen())
	{
		while (okno.pollEvent(WYBOR)&&(tura))///ZROBILEM TUTAJ NIESKONCZONA PETLE, PRZEZ TO ZE DODALEM IF TURA KTORA JEST ZAWSZE PRAWDA DOPOKI NIE ZACZNIEMY ROZGRYWKI
		{											////BO W TRAKCIE ROZGRYWKI DOPIERO SIE PRZELACZA. TO ROZWIAZANIE CHWILOWE
			if (WYBOR.type == sf::Event::Closed)//JEZELI KLIKNIEMY X NA PASKU TO OKNO SIE WYLACZY (FUNKCJA CLOSE(); )
			{
				okno.close();
				cout << endl;
				gracz.wypisz();
				cout << endl;
				komputer.wypisz();
			}

			if (WYBOR.type == sf::Event::MouseButtonPressed)
			{
				if (WYBOR.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i pozycja_myszy = sf::Mouse::getPosition(okno);
					for (int i = 0; i < 10; i++)
					{
						for (int j = 0; j < 10; j++)
						{//GETGLOBALBOUNDS.CONTAINS ZWRACA WARTOSC//TRUE JEZELI DANE POLE MIESCI SIE W RAMACH INNEGO POLA
							if ((gracz.MATRIX[i][j].getGlobalBounds().contains(pozycja_myszy.x, pozycja_myszy.y)) && (!gracz.Is_Set_To_Forbidden(i,j)))
							{
								// obsłuż kliknięcie na polu planszy
								// np. zmień kolor pola na niebieski
								if (gracz.BOARD_OF_BOOLS[i][j] == false && gracz.Check_If_Ships_Are_Alive())
								{

									gracz.MATRIX[i][j].setFillColor(sf::Color::Yellow);
									Set_To_Clicked(gracz, i, j);
									COLLISION_BLOCKS_RENDER_AND_SET(gracz, i, j);
									SHIPS_OCCUR(gracz, i, j);

									gracz.Forbide_Ends(i, j);




								}
								if (!gracz.Check_If_Ships_Are_Alive())
								{
									gracz.Fill_The_Board();
								}



								//ZADBANIE O TO ABY FORBIDDEN NIE WYCHODZILO POZA ZAKRES POLA








							}
						}

					}

				}

			}
			okno.clear();//SKASUJ POPRZEDNIA KLATKE

			Pokaz_Na_Ekranie(gracz, okno);

			Pokaz_Na_Ekranie(komputer, okno);

			okno.display(); //WYRENDERUJ NOWA KLATKE

		}






		/////TRWAJA PRACE NAD KODEM WYBIERAJACYM STATKI DO GRY WIEC TA LINIA JEST ZAWIESZONA ( WORK IN PROGRESS )
			/*
			while (okno.pollEvent(zdarzenie))//PRZYPISZ ZALEZNOSC OD ZDARZENIA
			{
				if (zdarzenie.type == sf::Event::Closed)//JEZELI KLIKNIEMY X NA PASKU TO OKNO SIE WYLACZY (FUNKCJA CLOSE(); )
				{
					okno.close();
					cout << endl;
					gracz.wypisz();
					cout << endl;
					komputer.wypisz();
				}

				if (zdarzenie.type == sf::Event::MouseButtonPressed)
				{
					if (zdarzenie.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i pozycja_myszy = sf::Mouse::getPosition(okno);
						for (int i = 0; i < 10; i++)
						{
							for (int j = 0; j < 10; j++)
							{//GETGLOBALBOUNDS.CONTAINS ZWRACA WARTOSC//TRUE JEZELI DANE POLE MIESCI SIE W RAMACH INNEGO POLA
								if ((gracz.MATRIX[i][j].getGlobalBounds().contains(pozycja_myszy.x, pozycja_myszy.y)) && (CHECK_TURN(&tura)))
								{
									// obsłuż kliknięcie na polu planszy
									// np. zmień kolor pola na niebieski
									gracz.MATRIX[i][j].setFillColor(sf::Color::Blue);
									Set_To_Clicked(gracz, i, j);
									tura = false;//TUTAJ DZIALA TO TROCHE JAK PRZELACZNIK, CZYLI JEZELI POLE ZOSTANIE KLIKNIETE TO TURA ZOSTAJE ZMIENIONA
									//NA DRUGIEGO GRACZA I NA ODWROT

								}

								if ((komputer.MATRIX[i][j].getGlobalBounds().contains(pozycja_myszy.x, pozycja_myszy.y))&&(!CHECK_TURN(&tura)))
								{
									// obsłuż kliknięcie na polu planszy
									// np. zmień kolor pola na niebieski
									komputer.MATRIX[i][j].setFillColor(sf::Color::Blue);
									Set_To_Clicked(komputer, i, j);
									tura = true;//OPIS WYZEJ

								}

							}
						}
					}
				}


				okno.clear();//WYCZYSZCZENIE OKNA

				Pokaz_Na_Ekranie(gracz, okno);

				Pokaz_Na_Ekranie(komputer, okno);

				okno.display(); //RENDER

			}
			*/



		}



		return 0;
	}

