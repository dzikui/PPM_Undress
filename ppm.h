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
| |  Klasa ppm jest klas� pochodn� po klasie obraz. Poniewa� klasa do dzia�ania wykorzystuje alokowanie pami�ci w spos�b       | |
| |  dynamiczny, zawiera w sobie konstruktor kopiuj�cy wo�aj�cy kontruktor z klasy bazowej oraz operator=. Posiada r�wnie�     | |
| |  konstruktor bezparametryczny wo�aj�cy konstruktor z klasy bazowej oraz posiada w�asny destruktor. G�owne zadania wykonuje | |
| |  konstruktor z parametrem std::string, dzieki kt�remu wczytuje plik graficzny zawarty w folderze projektu, oraz pe�ni      | |
| |  funkcj� seter�w dla ka�dej warto�ci zwracanej przez getery zawarte w klasie obraz.                                        | |  
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
#ifndef PPM_H // zabezpieczenie pliku
#define PPM_H
#include "obraz.h"

class ppm :public obraz // klasa dziedziczy po klasie obraz
{
public:

////////////////////////////////// KONSTRUKTORY, DESTRUKTORY
	ppm(); // konstruktor defaultowy wo�aj�cy konstruktor z klasy bazowej
	ppm(const ppm&); // konstruktor kopiuj�cy wo�aj�cy konstruktor z klasy bazowej
	ppm(std::string); // konstruktor z parametrem std::string
	~ppm(); // destruktor

////////////////////////////////// OPARATORY
	ppm operator=(const ppm&); // operator =
};

#endif