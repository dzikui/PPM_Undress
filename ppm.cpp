#include "ppm.h"

ppm::ppm() :obraz() // konstruktor bezparametryczny wo³aj¹cy konstruktor klasy rodzica
{}

ppm::ppm(const ppm&_obj) : obraz(_obj) // konstruktor kopiujacy wo³aj¹cy konstruktor klasy rodzica
{}

ppm::ppm(std::string _fileName) // konstruktor z parametrem std::string
{
	std::fstream file;
	file.open(_fileName); // otwarcie pliku
	{
		if (file.is_open()) // jesli otworzony poprawnie
		{
			s_fileName = _fileName; // set s_fileName
			unsigned int i_counter = 0; // zmienna pomocnicza przy 
			getline(file, s_fileVersion);
			getline(file, s_fileInfo);
			file >> i_width >> i_height >> i_maxColor; // strumien wysylaj¹cy dane. set width, set height i set maxcolor
			i_rTab = new unsigned int[i_height*i_width]; // dynamiczna alokacja dla r[], poni¿ej g[] i b[]
			i_gTab = new unsigned int[i_height*i_width];
			i_bTab = new unsigned int[i_height*i_width];
			while (!file.eof()) // wykonuj dopóki nie napotkasz konca pliku
			{
				file >> i_rTab[i_counter]; // przesy³anie strumieniem dane o kolorach do tablicy
				file >> i_gTab[i_counter];
				file >> i_bTab[i_counter];
				i_counter++;
			}
		}
		else{std::cout << "Takiego pliku nie ma w folderze projektu.\n";} // jesli otworzony niepoprawnie

		s_colorsTab = new std::string[i_height*i_width]; // tablica kolorow rgb w stringu
		i_colorsTab = new unsigned int[i_height*i_width]; // tablica kolorow rgb w int
		i_colorsTabSort = new unsigned int[i_height*i_width]; // tablica posortowanych kolorow rgb w int
		for (unsigned int i = 0; i < i_height*i_width; i++)
		{
			s_colorsTab[i] = std::to_string(i_rTab[i]) + std::to_string(i_gTab[i]) + std::to_string(i_bTab[i]);
			i_colorsTabSort[i] = i_colorsTab[i] = stoul(s_colorsTab[i]);
		}
		toQuicksort(i_colorsTabSort, 0, (i_height*i_width) - 1);
		
		toSepia();
		toGray();
	}
}

ppm::~ppm()
{
	delete[] i_rTab; // zwalnianie pamieci alokowanej dynamicznie
	delete[] i_gTab;
	delete[] i_bTab;
	delete[] i_colorsTab;
	delete[] s_colorsTab;
	delete[] i_colorsTabSort;
}

ppm ppm::operator=(const ppm & _obj)
{
	if (&_obj == this) return *this; // sprawdza czy nie kopiuje samego siebie
	else
	{
		delete[] i_rTab; // usuwa to co bylo wczesniej
		delete[] i_gTab;
		delete[] i_bTab;
		delete[] i_colorsTab;
		delete[] s_colorsTab;
		delete[] i_colorsTabSort;
		this->s_fileName = _obj.s_fileName; // przypisuje now¹ wartoœc ze wskaznika this
		this->s_fileVersion = _obj.s_fileVersion;
		this->s_fileInfo = _obj.s_fileInfo;
		this->i_width = _obj.i_width;
		this->i_maxColor = _obj.i_maxColor;
		for (int i = 0; i < i_height*i_width; i++)
		{
			this->i_rTab[i] = _obj.i_rTab[i];
			this->i_gTab[i] = _obj.i_gTab[i];
			this->i_bTab[i] = _obj.i_bTab[i];
			this->i_colorsTab[i] = _obj.i_colorsTab[i];
			this->s_colorsTab[i] = _obj.s_colorsTab[i];
			this->i_colorsTabSort[i] = _obj.i_colorsTabSort[i];
		}
	}
	return *this;
}