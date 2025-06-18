#include "OyunSonuEkrani.hpp"
#include <iostream>

void OyunSonuEkrani::ayarla(float genislik, float yukseklik)
{
    if (!m_font.loadFromFile("C:/Users/Lenovo/Desktop/sfmlyeni/bin/x64/Debug/arial.ttf"))
    {
        std::cerr << "Yazý tipi yüklenemedi!" << std::endl;
        return;
    }

    m_baslik.setFont(m_font);
    m_baslik.setString("Game Over!");
    m_baslik.setCharacterSize(40);
    m_baslik.setFillColor(sf::Color::Red);
    sf::FloatRect bRect = m_baslik.getLocalBounds();
    m_baslik.setOrigin(bRect.width / 2, bRect.height / 2);
    m_baslik.setPosition(genislik / 2, yukseklik / 2 - 100);

    m_tekrarDene.setFont(m_font);
    m_tekrarDene.setString("Try Again");
    m_tekrarDene.setCharacterSize(30);
    m_tekrarDene.setFillColor(sf::Color::Black);
    sf::FloatRect tRect = m_tekrarDene.getLocalBounds();
    m_tekrarDene.setOrigin(tRect.width / 2, tRect.height / 2);
    m_tekrarDene.setPosition(genislik / 2, yukseklik / 2);

    m_cikis.setFont(m_font);
    m_cikis.setString("Exit Game");
    m_cikis.setCharacterSize(30);
    m_cikis.setFillColor(sf::Color::Black);
    sf::FloatRect cRect = m_cikis.getLocalBounds();
    m_cikis.setOrigin(cRect.width / 2, cRect.height / 2);
    m_cikis.setPosition(genislik / 2, yukseklik / 2 + 60);
}

void OyunSonuEkrani::ciz(Pencere& pencere)
{
    pencere.ciz(m_baslik);
    pencere.ciz(m_tekrarDene);
    pencere.ciz(m_cikis);
}

bool OyunSonuEkrani::tiklamaDenetle(sf::Vector2f tiklamaKonumu)
{
    m_tekrarDeneSecildi = false;

    if (m_tekrarDene.getGlobalBounds().contains(tiklamaKonumu))
    {
        m_tekrarDeneSecildi = true;
        return true;
    }
    else if (m_cikis.getGlobalBounds().contains(tiklamaKonumu))
    {
        return true;
    }

    return false;
}

bool OyunSonuEkrani::tekrarDeneSecildi() const
{
    return m_tekrarDeneSecildi;
}