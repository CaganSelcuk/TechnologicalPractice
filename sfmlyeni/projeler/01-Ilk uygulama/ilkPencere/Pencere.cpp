#include "Pencere.hpp"


void Pencere::olustur(unsigned int genislik, unsigned int yukseklik, const sf::String& baslik)
{
    m_pencere.create(sf::VideoMode(genislik, yukseklik), baslik);
}


void Pencere::ciz(sf::Drawable& sekil)
{ 
    m_pencere.draw(sekil);
}

void Pencere::olaylariIsle()
{
    sf::Event olay;
    while (m_pencere.pollEvent(olay))
    {
        if (olay.type == sf::Event::Closed)
            m_pencere.close();

        if (olay.type == sf::Event::KeyPressed)
        {
            for (auto& siradaki : m_tusaBasFonksiyonlari)
            {
                if (siradaki) 
                    siradaki(olay.key.code);
            }

        }
        if (olay.type == sf::Event::KeyReleased)
        {
            for (auto& siradaki : m_tusuBirakFonksiyonlari)
            {
                if (siradaki)
                    siradaki(olay.key.code);
            }
        }
        if (olay.type == sf::Event::MouseMoved)
        {
            for (auto& siradaki : m_fareHareketFonksiyonlari)
            {
                if (siradaki)
                    siradaki(olay.mouseMove);
            }
        }
        if (olay.type == sf::Event::MouseButtonPressed)
        {
            for (auto& fonk : m_fareTiklanmaFonksiyonlari)
            {
                if (fonk)
                    fonk(olay.mouseButton);  
            }
        }
    }
}

bool Pencere::pencereAcikmi()
{
    return m_pencere.isOpen();
}

void Pencere::temizle()
{
    m_pencere.clear(sf::Color::White);
}

void Pencere::goster()
{
    m_pencere.display();
}

void Pencere::kapat()
{
    m_pencere.close();
}

void Pencere::olayFonksiyonlariniTemizle()
{
    m_tusaBasFonksiyonlari.clear();
    m_tusuBirakFonksiyonlari.clear();
    m_fareHareketFonksiyonlari.clear();
    m_fareTiklanmaFonksiyonlari.clear();
}

void Pencere::tusaBasFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon)
{
    if (yeniFonksiyon) 
        m_tusaBasFonksiyonlari.push_back(yeniFonksiyon);
}

void Pencere::tusuBirakFonksiyonuEkle(KlavyeFonksiyonu yeniFonksiyon)
{
    if (yeniFonksiyon)
        m_tusuBirakFonksiyonlari.push_back(yeniFonksiyon);

}

void Pencere::fareHareketFonksiyonuEkle(FareHareketFonksiyonu yeniFonksiyon)
{
    if (yeniFonksiyon)
        m_fareHareketFonksiyonlari.push_back(yeniFonksiyon);
}

void Pencere::fareTiklanmaFonksiyonuEkle(FareTiklanmaFonksiyonu yeniFonksiyon)
{
    if (yeniFonksiyon)
        m_fareTiklanmaFonksiyonlari.push_back(yeniFonksiyon);

}




