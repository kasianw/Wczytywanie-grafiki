#include "imagereader.h" // do³¹czam bibliotekê i klasê do wczytania obrazka
#include <iostream>
#include <cstdlib> // tutaj jest system("pause")

// tutaj funkcja, ale mo¿na to umieœciæ w klasie
// do demonstracji dzia³ania - czyli jak wczytaæ obrazek
void read_image(string filepath)
{
	// jak skorzystaæ z gotowego kodu wczytywania obrazka
	// ta linijka ni¿ej wczytuje obrazek
	ImageReader* imagereader = new ImageReader(filepath);
	
	// pozosta³e linijki to robi¹ to czego potrzebujemy
	// czyli g³ównie kopiuj¹ nag³ówek i kolory
	int width = imagereader->get_width();
	int height = imagereader->get_height();
	int headersize = imagereader->get_header_size();
	char* header = new char[headersize];
	
	// Skopiowanie nag³ówka (poniewa¿ nie chcemy nadpisywaæ oryginalnego obrazka)
	// nag³ówek przyda siê do zapisu wyniku - tutaj umieszczamy go w lokalnej zmiennej,
	// ale lepiej to umieszczaæ w zmiennej z klasy, do której bêdziemy mieli dostêp z ka¿dej metody
	for ( int i = 0; i < headersize; i++ )
	{
		header[i] = imagereader->get_header_byte(i);
	}
	
	// Do testów :) - zamiast na ekran mo¿na zapisaæ w tablicy, a potem t¹ tablicê przetwarzaæ
	// po przetworzeniu tablicy mo¿na 
	for ( int i = 0; i < height; i++ )
	{
		for ( int j = 0; j < width; j++ )
		{
			cout << "Red: " << (int)imagereader->get_data_byte(i,j,ImageReader::RED);
			cout << " Blue: " << (int)imagereader->get_data_byte(i,j,ImageReader::BLUE);
			cout << " Green: " << (int)imagereader->get_data_byte(i,j,ImageReader::GREEN);
			cout << endl;
		}
	}
	
	delete header;
	delete imagereader;
}

int main()
{	
	read_image("lena.bmp");
	return 0;
}
