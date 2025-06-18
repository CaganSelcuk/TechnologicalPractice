#pragma once
#include <SFML/Graphics.hpp>
#include "FonksiyonTurleri.hpp"
#include <functional>

class Pencere
{
public:
	void olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& baslik = "SFML");
	void ciz(sf::Drawable& sekil);
	void olaylariIsle();
	bool pencereAcikmi();
	void temizle();
	void goster();
	void kapat();
	void olayFonksiyonlariniTemizle();

	void tusaBasFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon);
	void tusuBirakFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon);
	void fareHareketFonksiyonuEkle(FareHareketFonksiyonu yeniFonksiyon);
	void fareTiklanmaFonksiyonuEkle(FareTiklanmaFonksiyonu yeniFonksiyon);

private:
	KlavyeFonksiyonListesi           m_tusaBasFonksiyonlari;
	KlavyeFonksiyonListesi           m_tusuBirakFonksiyonlari;
	FareHareketFonkListesi      m_fareHareketFonksiyonlari;
	FareTiklanmaFonksiyonListesi     m_fareTiklanmaFonksiyonlari;

	sf::RenderWindow                 m_pencere;
};