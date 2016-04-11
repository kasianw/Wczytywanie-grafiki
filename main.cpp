#include "imagereader.h" // do��czam bibliotek� i klas� do wczytania obrazka
#include <iostream>
#include <cstdlib> // tutaj jest system("pause")

// tutaj funkcja, ale mo�na to umie�ci� w klasie
// do demonstracji dzia�ania - czyli jak wczyta� obrazek
void read_image(string filepath)
{
	// jak skorzysta� z gotowego kodu wczytywania obrazka
	// ta linijka ni�ej wczytuje obrazek
	ImageReader* imagereader = new ImageReader(filepath);
	
	// pozosta�e linijki to robi� to czego potrzebujemy
	// czyli g��wnie kopiuj� nag��wek i kolory
	int width = imagereader->get_width();
	int height = imagereader->get_height();
	int headersize = imagereader->get_header_size();
	char* header = new char[headersize];
	
	// Skopiowanie nag��wka (poniewa� nie chcemy nadpisywa� oryginalnego obrazka)
	// nag��wek przyda si� do zapisu wyniku - tutaj umieszczamy go w lokalnej zmiennej,
	// ale lepiej to umieszcza� w zmiennej z klasy, do kt�rej b�dziemy mieli dost�p z ka�dej metody
	for ( int i = 0; i < headersize; i++ )
	{
		header[i] = imagereader->get_header_byte(i);
	}
	
	// Do test�w :) - zamiast na ekran mo�na zapisa� w tablicy, a potem t� tablic� przetwarza�
	// po przetworzeniu tablicy mo�na 
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
