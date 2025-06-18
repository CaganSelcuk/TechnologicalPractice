#include<iostream>
#include<String>
#include<functional>
#include "Pencere.hpp"

using namespace std;

class deneme {


public:
	void tikla(sf::Event::MouseButtonEvent olay)
	{
		std::cout << "Týklama: " << olay.x << ", " << olay.y << " - Buton: " << olay.button << std::endl;
	}
void yaz(sf::Keyboard::Key tus)
{
	cout << "Merhaba" << endl;
}
void hareket(sf::Event::MouseMoveEvent fareOlayi)
{
	cout << fareOlayi.x << "-" << fareOlayi.y << endl;
}
};

void yaz1(sf::Keyboard::Key tus)
{
	cout << "hohoho" << endl;
}

//int main()
//{
//
//	Pencere pencere;
//	deneme yeniDeneme;
//
//	pencere.tusaBasFonksiyonuEkle([](sf::Keyboard::Key tus) {
//		std::cout << "tus:" << tus << std::endl;
//		});
//
//	pencere.fareHareketFonksiyonuEkle(
//		std::bind(&deneme::hareket, &yeniDeneme, std::placeholders::_1)
//	);
//	pencere.fareTiklanmaFonksiyonuEkle(
//		std::bind(&deneme::tikla, &yeniDeneme, std::placeholders::_1)
//	);
//	pencere.tusuBirakFonksiyonuEkle(yaz1);
//	sf::RectangleShape dikdortgen(sf::Vector2f(200, 200));
//	pencere.olustur(800, 800);
//	while (pencere.pencereAcikmi())
//	{
//		pencere.olaylariIsle();
//
//		pencere.temizle();
//		pencere.ciz(dikdortgen);
//		pencere.goster();
//	}
//}