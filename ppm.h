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
| |  Klasa ppm jest klas¹ pochodn¹ po klasie obraz. Poniewa¿ klasa do dzia³ania wykorzystuje alokowanie pamiêci w sposób       | |
| |  dynamiczny, zawiera w sobie konstruktor kopiuj¹cy wo³aj¹cy kontruktor z klasy bazowej oraz operator=. Posiada równie¿     | |
| |  konstruktor bezparametryczny wo³aj¹cy konstruktor z klasy bazowej oraz posiada w³asny destruktor. G³owne zadania wykonuje | |
| |  konstruktor z parametrem std::string, dzieki któremu wczytuje plik graficzny zawarty w folderze projektu, oraz pe³ni      | |
| |  funkcjê seterów dla ka¿dej wartoœci zwracanej przez getery zawarte w klasie obraz.                                        | |  
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
#ifndef PPM_H // zabezpieczenie pliku
#define PPM_H
#include "obraz.h"

class ppm :public obraz // klasa dziedziczy po klasie obraz
{
public:

////////////////////////////////// KONSTRUKTORY, DESTRUKTORY
	ppm(); // konstruktor defaultowy wo³aj¹cy konstruktor z klasy bazowej
	ppm(const ppm&); // konstruktor kopiuj¹cy wo³aj¹cy konstruktor z klasy bazowej
	ppm(std::string); // konstruktor z parametrem std::string
	~ppm(); // destruktor

////////////////////////////////// OPARATORY
	ppm operator=(const ppm&); // operator =
};

#endif