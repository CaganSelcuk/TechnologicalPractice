#pragma once
#include"Pencere.hpp"
#include "Yilan.hpp"
#include "Izgara.hpp"
#include "OyunSonuEkrani.hpp"
#include <SFML/Audio.hpp>

class Uygulama
{
public:
	Uygulama();
	void insaEt(int genislik, int yukseklik);
	void baslat(int fps = 60);
private:

	void cerceveOlustur();
	void cizimFonksiyonu();
	void sahneGuncelle();

	void tusBasildi(sf::Keyboard::Key tus);
	void tusBirakildi(sf::Keyboard::Key tus);
	void fareHareket(sf::Event::MouseMoveEvent olay);
	void fareTiklandi(sf::Event::MouseButtonEvent olay);

	Yilan        m_yilan;
	Izgara       m_izgara;
	Pencere      m_pencere;
	OyunSonuEkrani    m_oyunSonuEkrani;
	sf::Clock    m_saat;
	sf::Time     m_cerceveSuresi;
	sf::Time     m_gecenSure;
	sf::Music    m_muzik;

	int m_pencereGenislik;
	int m_pencereYukseklik;
	bool m_oyunBitti = false;

	
};
