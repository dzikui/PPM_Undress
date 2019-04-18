/*
________________________________________________________________________________________________________________________________
|  ____________________________________________________________________________________________________________________________  |
| |                                                                                                                            | |
| |       Program: Obraz(v2) zliczaj�cy ilo�� niepowtarzalnych kolor�w w danym pliku graficznym, oraz przekszta�caj�cy         | |
| |                                      ten plik na odcienie szaro�ci oraz sepiatone.                                         | |
| |                            AUTOR: MATEUSZ IDZIKOWSKI  mat.idzikowski@gmail.com  data:12.02.2019                            | |
| |____________________________________________________________________________________________________________________________| |
|  ____________________________________________________________________________________________________________________________  |
| |                                                                                                                            | |
| |                                                       INFO:                                                                | |
| |  Klasa obraz wykorzystuje dynamiczne alokowanie pamieci, wi�c zawiera konstruktor kopiuj�cy oraz operator=. Posiada        | |
| |  destruktor wirtualny, poniewa� wywoluje si� destruktor klasy dziecka. Zawiera dwie funkcje wykorzystywane do sortowania   | |
| |  tablicy kolor�w przechowywanej w zmiennej i_colorsTabSort. Tablica ta s�uzy do zliczania kolor�w w obrazie. Funkcja       | |
| |  toSave() s�u�y do zapisuobrazu konwertowanego przez funkcje toGray() oraz toSepia(). Ka�da z tych funkcji korzysta        | |
| |  z tablic osobnych dla ka�dego koloru. Klasa posiada r�wniez zmienne przechowuj�ce Nazw� pliku, iformacje o formacie,      | |
| |  informacje o autorze, wysokosci, szerokosci oraz najwiekszej warto�ci pojedynczego koloru.                                | |
| |  Klasa zosta�a stworzona z mysla o wielokrotnym i uniwerslanym wykorzystaniu kodu.                                         | |
| |  Wa�nym aspektem przy tworzeniu by�a r�wniez typizacja dancyh, kt�ra prze�o�y�a si� na czas wykonania programu ok. 15 sek  | |
| |____________________________________________________________________________________________________________________________| |
|  ____________________________________________________________________________________________________________________________  |
| |                                                                                                                            | |
| |                                                      ZMIANY:                                                               | |
| |     Obraz v1, Zape�nia pami�� w niekntrolowany spos�b.                                                                     | |
| |     Obraz v2, Posiada funkcje toGray(); toSepia(); Nie zapycha pami�ci. Zoptymalizowana typizacja. Zmienione wczytywanie.  | |
| |____________________________________________________________________________________________________________________________| |
|________________________________________________________________________________________________________________________________|
*/
#pragma once
#ifndef OBRAZ_H // zabezpieczenie pliku
#define OBRAZ_H
#include <iostream>
#include <string>
#include <fstream>

class obraz
{
public:
////////////////////////////////// KONSTRUKTORY< DESTRUKTORY
	obraz(); // konstruktor domyslny
	obraz(const obraz&); // konstruktor kopiujacy
	virtual ~obraz() {}; // destruktor virtualny

////////////////////////////////// METODY i OPERAOTRY
	const obraz&operator=(const obraz&); // operator =
	unsigned int toPartition(unsigned int[], unsigned int, unsigned int); // funkcja qsort dziel�ca tablice na dwie czesci
	void toQuicksort(unsigned int[], unsigned int, unsigned int); // funkcja qsort przestawiaj�ca kolory w tablicy
	void toSave(std::string); // funkcja zapisuj�ca zdjecia w nowych odcieniach
	void toGray(); // klonwersja zdj�cia na skal� szarosci
	void toSepia(); // konwersja zdj�cia do skali Sepii
	std::string get_s_fileName(); // zwraca nazwe pliku
	std::string get_s_fileVersion(); // zwraca infomacje o formacie
	std::string get_s_fileInfo(); // zwraca info od autora
	unsigned short int get_i_height(); // zwraca wysokosc
	unsigned short int get_i_width(); // zwraca szerokosc
	unsigned short int get_i_maxColor(); // zwraca kolor maksymalny
	unsigned int get_i_rTab(unsigned int); // zwraca kolory RED z tablicy 
	unsigned int get_i_gTab(unsigned int); // zwraca kolory GREEN z tablicy 
	unsigned int get_i_bTab(unsigned int); // zwraca kolory BLUE z tablicy 
	unsigned int get_i_colorsTab(unsigned int); // zwraca element tablicy przygotowanej do sortowania (tylko do zliczania, bo uleg�a utracie czesci danych)
	unsigned int get_i_colorsTabSort(unsigned int); // zwraca element tablicy posortowany, gotowy do zliczania kolor�w (tylko do zliczania, bo uleg�a utracie czescidanych)
	std::string get_s_colorsTab(unsigned int); // zwraca pe�na tablic� kolor�w

protected:
	////////////////////////////////// ZMIENNE 
	std::string s_fileVersion, s_fileInfo, s_fileName;
	std::string *s_colorsTab;
	unsigned short int i_height, i_width, i_maxColor;
	unsigned int *i_rTab;
	unsigned int *i_gTab;
	unsigned int *i_bTab;
	unsigned int *i_colorsTab;
	unsigned int *i_colorsTabSort;
};

#endif