#include <iostream>
#include "ppm.h"

int liczKolory(obraz &);

int main()
{
	obraz *ob;
	ob = new ppm("lena.ppm");
	int kolor;
	kolor = liczKolory(*ob);
	std::cout << "Kolorow: " << kolor;
	delete ob;
	system("pause");
	return 0;
}

int liczKolory(obraz& _obj)
{
	int i_quantity = 1;
	for (int i = 0; i < (_obj.get_i_width()*_obj.get_i_height())-1; i++)
	{
		if (_obj.get_i_colorsTabSort(i) == _obj.get_i_colorsTabSort(i + 1))
			continue;
		else
			i_quantity++;
	}
	return i_quantity;
}
