#pragma once
#include <SFML/Graphics.hpp>
#include "Pencere.hpp"

class OyunSonuEkrani
{
public:
    void ayarla(float genislik, float yukseklik);
    void ciz(Pencere& pencere);
    bool tiklamaDenetle(sf::Vector2f tiklamaKonumu);
    bool tekrarDeneSecildi() const;

private:
    sf::Font m_font;
    sf::Text m_baslik;
    sf::Text m_tekrarDene;
    sf::Text m_cikis;

    bool m_tekrarDeneSecildi = false;
};