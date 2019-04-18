#include "obraz.h"

obraz::obraz() :s_fileName("blackImg.ppm"), s_fileVersion("P3\n"), 
s_fileInfo("Created by Mateo\n"), i_height(4), i_width(4), i_maxColor(0) //lista inicjalizacyjna dla defaultowego konstruktora
{
	i_rTab = new unsigned int[i_height*i_width];
	i_gTab = new unsigned int[i_height*i_width];
	i_bTab = new unsigned int[i_height*i_width];
	for (unsigned int i = 0; i < i_width*i_height; i++)
	{
		i_rTab[i] = 0;
		i_gTab[i] = 0;
		i_bTab[i] = 0;
	};
	s_colorsTab = new std::string[i_height*i_width]; // tablica kolorow rgb w stringu
	i_colorsTab = new unsigned int[i_height*i_width]; // tablica kolorow rgb w int
	i_colorsTabSort = new unsigned int[i_height*i_width];
	for (unsigned int i = 0; i < i_height*i_width; i++)
	{
		s_colorsTab[i] = std::to_string(i_rTab[i]) + std::to_string(i_gTab[i]) + std::to_string(i_bTab[i]);
		i_colorsTabSort[i] = i_colorsTab[i] = stoul(s_colorsTab[i]);
	}
}

obraz::obraz(const obraz&_obj) // konstruktor kopiujacy
{
	delete[] i_rTab;
	delete[] i_gTab;
	delete[] i_bTab;
	delete[] i_colorsTab;
	delete[] s_colorsTab;
	delete[] i_colorsTabSort;
	this->s_fileName = _obj.s_fileName;
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
};

const obraz & obraz::operator=(const obraz&_obj) // operator =
{
	if (&_obj == this) return *this; // sprawdza czy nie kopiuje samego siebie
	else
	{
		delete[] i_rTab;
		delete[] i_gTab;
		delete[] i_bTab;
		delete[] i_colorsTab;
		delete[] s_colorsTab;
		delete[] i_colorsTabSort;
		this->s_fileName = _obj.s_fileName;
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

unsigned int obraz::toPartition(unsigned int _table[], unsigned int p, unsigned int r) // Pierwsza z dwóch funkcji do qsorta
{
	unsigned int x = _table[p];												// obieramy x
	unsigned int i = p, j = r, w;											// i, j to indeksy w tabeli
	while (true)															// nieskonczona petla. wyjscie tylko przez return j
	{
		while (_table[j] > x)												// wykonuje siê dopoki elementy sa wieksze od x
			j--;
		while (_table[i] < x)												// wykonuje siê dopoki elementy sa mniejsze od x
			i++;
		if (i < j)															// zamiana miejscami gdy i < j
		{
			w = _table[i];
			_table[i] = _table[j];
			_table[j] = w;
			i++;
			j--;
		}
		else																// gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}

}

void obraz::toQuicksort(unsigned int _table[], unsigned int p, unsigned int r) // druga z dwóch funkcji do qsorta
{
	unsigned int q;
	if (p < r)
	{
		q = toPartition(_table, p, r);										// q to punkt podzialu tablicy na dwie czesci
		toQuicksort(_table, p, q);											// wywolanie rekurencyjne quicksorta dla jednej po³owy tablicy
		toQuicksort(_table, q + 1, r);										// wywolanie rekurencyjne dla drugiej po³owy tablicy 
	}
}

void obraz::toSave(std::string _fileName) // funkcja zapisuj¹ca przerobione zdjêcia do pliku. wywowlywana jedynie w funkcjach toGray() i toSepia()
{
	std::ofstream file;
	file.open(_fileName, std::ios::out); // plik otworzono
	if (file.is_open())
	{
		unsigned int counter = 0;
		file << s_fileVersion << std::endl << s_fileInfo +" edited by Mateo" << std::endl << i_width << " " << i_height << std::endl << i_maxColor << std::endl;
		for (unsigned int i = 0; i < i_height; i++)
		{
			for (unsigned int j = 0; j < i_width; j++)
			{
				file << i_rTab[counter] << " " << i_gTab[counter] << " " << i_bTab[counter] << "    ";
				counter++;
			}
			file << std::endl;
		}
	}
	else { std::cout << "Nie utworzono pliku.\n"; } // pliku nie otworzono
}

void obraz::toGray() // funkcja konwertujaca kolorowy obraz w odcienie szarosci
{
	std::string s_newFileName = "Gray" + s_fileName; // Okreslanie nowej nazwy dla nowego pliku
	std::string *s_colorsGrayTab = new std::string[i_width*i_height];
	for (unsigned int i = 0; i < i_width*i_height; i++)
	{
		s_colorsGrayTab[i] = std::to_string((i_rTab[i] + i_gTab[i] + i_bTab[i]) / 3); // algorytm na Gray scale
		i_rTab[i] = i_gTab[i] = i_bTab[i] = stoul(s_colorsGrayTab[i]);
	}
	toSave(s_newFileName);
	delete[] s_colorsGrayTab; // po zapisie zwolnienie pamieci
}

void obraz::toSepia() // funkcja konwertujaca kolorowy obraz w Sepia tony
{
	std::string s_newFileName = "Sepia" + s_fileName; // Okreslanie nowej nazwy dla nowego pliku
	unsigned int *i_colors_r_SepiaTab = new unsigned int[i_width*i_height];
	unsigned int *i_colors_g_SepiaTab = new unsigned int[i_width*i_height];
	unsigned int *i_colors_b_SepiaTab = new unsigned int[i_width*i_height];
	for (unsigned int i = 0; i < i_width*i_height; i++)
	{
		i_colors_r_SepiaTab[i] = (i_rTab[i] * 0.393) + (i_gTab[i] * 0.565) + (i_bTab[i] * 0.089); // Algorytm wlasny na Sepiatone popraty godzinami doœwiadczen :D
		i_colors_g_SepiaTab[i] = (i_rTab[i] * 0.349) + (i_gTab[i] * 0.479) + (i_bTab[i] * 0.068); // i litrami kawy :D
		i_colors_b_SepiaTab[i] = (i_rTab[i] * 0.172) + (i_gTab[i] * 0.234) + (i_bTab[i] * 0.031);
		i_rTab[i] = i_colors_r_SepiaTab[i];
		i_gTab[i] = i_colors_g_SepiaTab[i];
		i_bTab[i] = i_colors_b_SepiaTab[i];
	}
	toSave(s_newFileName);
	delete[]i_colors_r_SepiaTab; // po zapisie zwolnienie pamieci
	delete[]i_colors_g_SepiaTab;
	delete[]i_colors_b_SepiaTab;
}

/////////////////////////////////  GETERY ///////////////////////////////

std::string obraz::get_s_fileVersion() { return s_fileVersion; }

std::string obraz::get_s_fileInfo() { return s_fileInfo; }

unsigned short int obraz::get_i_height() { return i_height; }

unsigned short int obraz::get_i_width() { return i_width; }

unsigned short int obraz::get_i_maxColor() { return i_maxColor; }

unsigned int obraz::get_i_rTab(unsigned int i) { return i_rTab[i]; }

unsigned int obraz::get_i_gTab(unsigned int i) { return i_gTab[i]; }

unsigned int obraz::get_i_bTab(unsigned int i) { return i_bTab[i]; }

unsigned int obraz::get_i_colorsTab(unsigned int i) { return i_colorsTab[i]; }

std::string obraz::get_s_colorsTab(unsigned int i) { return s_colorsTab[i]; }

unsigned int obraz::get_i_colorsTabSort(unsigned int i) { return i_colorsTabSort[i]; }

std::string obraz::get_s_fileName() { return s_fileName; }