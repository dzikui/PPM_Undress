/*
________________________________________________________________________________________________________________________________
|  ____________________________________________________________________________________________________________________________  |
| |                                                                                                                            | |
| |       Program: Obraz(v2) zliczaj¹cy iloœæ niepowtarzalnych kolorów w danym pliku graficznym, oraz przekszta³caj¹cy         | |
| |                                      ten plik na odcienie szaroœci oraz sepiatone.                                         | |
| |                            AUTOR: MATEUSZ IDZIKOWSKI  mat.idzikowski@gmail.com  data:12.02.2019                            | |
| |____________________________________________________________________________________________________________________________| |
|  ____________________________________________________________________________________________________________________________  |
| |                                                                                                                            | |
| |                                                       INFO:                                                                | |
| |  Klasa obraz wykorzystuje dynamiczne alokowanie pamieci, wiêc zawiera konstruktor kopiuj¹cy oraz operator=. Posiada        | |
| |  destruktor wirtualny, poniewa¿ wywoluje siê destruktor klasy dziecka. Zawiera dwie funkcje wykorzystywane do sortowania   | |
| |  tablicy kolorów przechowywanej w zmiennej i_colorsTabSort. Tablica ta s³uzy do zliczania kolorów w obrazie. Funkcja       | |
| |  toSave() s³u¿y do zapisuobrazu konwertowanego przez funkcje toGray() oraz toSepia(). Ka¿da z tych funkcji korzysta        | |
| |  z tablic osobnych dla ka¿dego koloru. Klasa posiada równiez zmienne przechowuj¹ce Nazwê pliku, iformacje o formacie,      | |
| |  informacje o autorze, wysokosci, szerokosci oraz najwiekszej wartoœci pojedynczego koloru.                                | |
| |  Klasa zosta³a stworzona z mysla o wielokrotnym i uniwerslanym wykorzystaniu kodu.                                         | |
| |  Wa¿nym aspektem przy tworzeniu by³a równiez typizacja dancyh, która prze³o¿y³a siê na czas wykonania programu ok. 15 sek  | |
| |____________________________________________________________________________________________________________________________| |
|  ____________________________________________________________________________________________________________________________  |
| |                                                                                                                            | |
| |                                                      ZMIANY:                                                               | |
| |     Obraz v1, Zape³nia pamiêæ w niekntrolowany sposób.                                                                     | |
| |     Obraz v2, Posiada funkcje toGray(); toSepia(); Nie zapycha pamiêci. Zoptymalizowana typizacja. Zmienione wczytywanie.  | |
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
	unsigned int toPartition(unsigned int[], unsigned int, unsigned int); // funkcja qsort dziel¹ca tablice na dwie czesci
	void toQuicksort(unsigned int[], unsigned int, unsigned int); // funkcja qsort przestawiaj¹ca kolory w tablicy
	void toSave(std::string); // funkcja zapisuj¹ca zdjecia w nowych odcieniach
	void toGray(); // klonwersja zdjêcia na skalê szarosci
	void toSepia(); // konwersja zdjêcia do skali Sepii
	std::string get_s_fileName(); // zwraca nazwe pliku
	std::string get_s_fileVersion(); // zwraca infomacje o formacie
	std::string get_s_fileInfo(); // zwraca info od autora
	unsigned short int get_i_height(); // zwraca wysokosc
	unsigned short int get_i_width(); // zwraca szerokosc
	unsigned short int get_i_maxColor(); // zwraca kolor maksymalny
	unsigned int get_i_rTab(unsigned int); // zwraca kolory RED z tablicy 
	unsigned int get_i_gTab(unsigned int); // zwraca kolory GREEN z tablicy 
	unsigned int get_i_bTab(unsigned int); // zwraca kolory BLUE z tablicy 
	unsigned int get_i_colorsTab(unsigned int); // zwraca element tablicy przygotowanej do sortowania (tylko do zliczania, bo uleg³a utracie czesci danych)
	unsigned int get_i_colorsTabSort(unsigned int); // zwraca element tablicy posortowany, gotowy do zliczania kolorów (tylko do zliczania, bo uleg³a utracie czescidanych)
	std::string get_s_colorsTab(unsigned int); // zwraca pe³na tablicê kolorów

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